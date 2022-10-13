#include "DSPSI16.h"
#include <stdlib.h>
#include "float16.h"

/**
 * \brief Common Data buffer
 */
typedef struct
{
	const int16_t* Data;

	size_t Size;

	int32_t AmpP2PHF;

	int32_t AmpP2PLF;

	uint16_t MeanCrossing;

	uint16_t NegMeanCrossing;

	uint16_t PosMeanCrossing;

	int16_t Min;

	int16_t Max;

	Float16 Mean;

	Float16 Moments[3];

} TDataBufferSI16;

static TDataBufferSI16 DataBufferSI16;

void SaPrecalcStatDataSI16(
	const uint16_t* p_ExtractedFeatures,
	uint16_t p_ExtractedFeaturesCount,
	uint16_t p_ColIdx,
	const int16_t* p_Data,
	size_t p_Size)
{
	DataBufferSI16.Data = p_Data;
	DataBufferSI16.Size = p_Size;

	const int32_t dataSize = p_Size;
	CalcBitMask calcBitMask = 0;
	int8_t moment = 0;

	PopulateFeatureMask(p_ExtractedFeatures, p_ExtractedFeaturesCount, p_ColIdx, &calcBitMask);

	if (BITMASK_MEAN & calcBitMask)
	{
		Float16 sum = sumSI16(DataBufferSI16.Data, dataSize);
		Float16 data;
		InitF16(&data, dataSize, 0, 0);
		DataBufferSI16.Mean = div16(&sum, &data);
	}	

	if (BITMASK_MOMENT_4 & calcBitMask)
	{
		moment = 3;
	}
	else if (BITMASK_MOMENT_3 & calcBitMask)
	{
		moment = 2;
	}
	else if (BITMASK_MOMENT_2 & calcBitMask)
	{
		moment = 1;
	}

	if (moment > 0)
	{
		for (int32_t i = moment - 1; i >= 0; i--)
			InitF16(&DataBufferSI16.Moments[i], 0, 0, 0);

		MomentsSI16(FixExpF16(&DataBufferSI16.Mean, 0), DataBufferSI16.Data, dataSize, DataBufferSI16.Moments, moment);
	}

	if (BITMASK_ZERO_CROSSING & calcBitMask)
	{
		const int16_t mean = FixExpF16(&DataBufferSI16.Mean, 0);
		DataBufferSI16.NegMeanCrossing = 0;
		DataBufferSI16.PosMeanCrossing = 0;
		int16_t value = DataBufferSI16.Data[0];
		
		for (size_t i = 1; i < dataSize; ++i)
		{
			const int16_t nextValue = DataBufferSI16.Data[i];

			if (value > mean && nextValue <= mean)
				DataBufferSI16.NegMeanCrossing++;
			else
			{
				if (value < mean && nextValue >= mean)
					DataBufferSI16.PosMeanCrossing++;
			}
			value = nextValue;
		}
		
		DataBufferSI16.MeanCrossing = DataBufferSI16.NegMeanCrossing + DataBufferSI16.PosMeanCrossing;
	}

	if (BITMASK_MIN & calcBitMask)
	{
		int16_t minValue = DataBufferSI16.Data[0];
		
		for (size_t i = 1; i < DataBufferSI16.Size; ++i)
		{
			const int16_t value = DataBufferSI16.Data[i];
			if (minValue > value)
				minValue = value;
		}
		
		DataBufferSI16.Min = minValue;
	}

	if (BITMASK_MAX & calcBitMask)
	{
		int16_t maxValue = DataBufferSI16.Data[0];
		
		for (size_t i = 1; i < DataBufferSI16.Size; ++i)
		{
			const int16_t value = DataBufferSI16.Data[i];
			if (maxValue < value)
				maxValue = value;
		}
		
		DataBufferSI16.Max = maxValue;
	}

	if (BITMASK_MOOVING_AVERAGE & calcBitMask)
	{
		const int32_t* inputParamPtr = GetFeatureInputParams(p_ColIdx, EF_PARAM_AMP_FREQUENCY_P2P);

		const uint8_t windowSize = (*inputParamPtr) > dataSize ? (uint8_t)dataSize : (uint8_t)(*inputParamPtr);		
		const uint8_t halfWs = windowSize >> 1;
		int32_t maLSum = 0;
		
		for (uint8_t i = 0; i < windowSize; i++) 
		{
			maLSum += DataBufferSI16.Data[i];
		}
		
		int32_t lfMin = maLSum;
		int32_t lfMax = maLSum;
		int32_t hfMin = DataBufferSI16.Data[halfWs] * windowSize - maLSum;
		int32_t hfMax = hfMin;
		const size_t maSize = dataSize - windowSize;
		
		for (size_t i = 0; i < maSize; i++) 
		{
			maLSum = maLSum - DataBufferSI16.Data[i] + DataBufferSI16.Data[i + windowSize];
			
			if (BITMASK_AMP_LOW_FREQUENCY_P2P & calcBitMask)
			{
				if (lfMin > maLSum)
					lfMin = maLSum;
				if (lfMax < maLSum)
					lfMax = maLSum;
			}
			if (BITMASK_AMP_HIGH_FREQUENCY_P2P & calcBitMask)
			{
				const int32_t maHSum = DataBufferSI16.Data[i + halfWs + 1] * windowSize - maLSum;
				if (hfMin > maHSum)
					hfMin = maHSum;
				if (hfMax < maHSum)
					hfMax = maHSum;
			}
		}

		DataBufferSI16.AmpP2PLF = (lfMax - lfMin) << 8 / windowSize;
		DataBufferSI16.AmpP2PHF = (hfMax - hfMin) << 8 / windowSize;
	}

}

int32_t MinSI16()
{
	return DataBufferSI16.Min;
}

int32_t MaxSI16()
{
	return DataBufferSI16.Max;
}

int32_t MeanSI16()
{
	return FixExpF16(&DataBufferSI16.Mean, -15);
}

int32_t RootMeanSquareSI16()
{
	Float16 result = sqrt16(&DataBufferSI16.Moments[MOMENT_2]);
	return FixExpUF16(&result, -15);
}

int32_t VarianceSI16()
{
	return FixExpUF16(&DataBufferSI16.Moments[MOMENT_2], 0);
}

int32_t PetrosianFractalDimensionSI16()
{
	Float16 n, nd, sc;
	InitF16(&n, DataBufferSI16.Size, 0, 0);
	InitF16(&nd, 103, -8, 0);
	InitF16(&sc, DataBufferSI16.MeanCrossing, 0, 0);
	Float16 res = mul16(&nd, &sc);
	res = add16(&n, &res);
	res = div16(&n, &res);
	res = log10_16(&res);

	Float16 lgn = log10_16(&n);

	res = add16(&lgn, &res);
	res = div16(&lgn, &res);

	return FixExpF16(&res, -16);
}

int32_t SkewnessSI16()
{
	if (DataBufferSI16.Moments[MOMENT_2].mantissa == 0)
		return 0;

	Float16 root = sqrt16(&DataBufferSI16.Moments[MOMENT_2]);

	Float16 denom = mul16(&root, &root);

	denom = mul16(&denom, &root);

	Float16 result = div16(&DataBufferSI16.Moments[MOMENT_3], &denom);

	return FixExpF16(&result, -12) + 32768;
}

int32_t KurtosisSI16()
{
	if (DataBufferSI16.Moments[MOMENT_2].mantissa == 0)
		return 0;

	Float16 denom = mul16(&DataBufferSI16.Moments[MOMENT_2], &DataBufferSI16.Moments[MOMENT_2]);
	Float16 result = div16(&DataBufferSI16.Moments[MOMENT_4], &denom);

	return FixExpUF16(&result, -12);
}

int32_t NegMeanCrossingSI16()
{
	return DataBufferSI16.NegMeanCrossing;
}

int32_t PosMeanCrossingSI16()
{
	return DataBufferSI16.PosMeanCrossing;
}

int32_t AmplitudeGlobalP2pHighFrequencySI16()
{
	return DataBufferSI16.AmpP2PHF;
}

int32_t AmplitudeGlobalP2pLowFrequencySI16()
{
	return DataBufferSI16.AmpP2PLF;
}

int32_t MeanCrossingSI16()
{
	return DataBufferSI16.MeanCrossing;
}
