#include "Common.h"

const uint16_t featuresCalculationRequestedMask[] = {
	0,	// Resources to evaluate EF_STAT_UNUSED
	BITMASK_MEAN, //Resources to evaluate EF_STAT_MEAN
	BITMASK_MAX, //Resources to evaluate EF_STAT_MAX
	BITMASK_MIN, //Resources to evaluate EF_STAT_MIN
	BITMASK_MEAN | BITMASK_ZERO_CROSSING, //Resources to evaluate EF_STAT_PFD
	BITMASK_MOMENT_2 | BITMASK_MEAN, //Resources to evaluate EF_STAT_VARIANCE
	BITMASK_MOMENT_2| BITMASK_MEAN, //Resources to evaluate EF_STAT_RMS
	BITMASK_MEAN | BITMASK_MOMENT_2 | BITMASK_MOMENT_3, //Resources to evaluate EF_STAT_SKEWNESS
	BITMASK_MEAN | BITMASK_MOMENT_2 | BITMASK_MOMENT_3 | BITMASK_MOMENT_4, //Resources to evaluate EF_STAT_KURTOSIS
	BITMASK_ZERO_CROSSING| BITMASK_MEAN, //Resources to evaluate EF_STAT_MEAN_CROSSING
	BITMASK_ZERO_CROSSING | BITMASK_MEAN, //REF_STAT_NEGATIVE_MEAN_CROSSING
	BITMASK_ZERO_CROSSING | BITMASK_MEAN, //REF_STAT_POSITIVE_MEAN_CROSSING	
	BITMASK_AMP_HIGH_FREQUENCY_P2P | BITMASK_MOOVING_AVERAGE, //Resources to evaluate EF_AMP_HIGH_FREQUENCY_P2P
	BITMASK_AMP_LOW_FREQUENCY_P2P | BITMASK_MOOVING_AVERAGE, //Resources to evaluate EF_AMP_LOW_FREQUENCY_P2P
	BITMASK_MEAN | BITMASK_FFT_ANY, //Resources to evaluate EF_FFT_POWER0
	BITMASK_MEAN | BITMASK_FFT_ANY, //Resources to evaluate EF_FFT_FREQ0
	BITMASK_MEAN | BITMASK_FFT_ANY, //Resources to evaluate EF_FFT_POWER1
	BITMASK_MEAN | BITMASK_FFT_ANY, //Resources to evaluate EF_FFT_FREQ1
	BITMASK_MEAN | BITMASK_FFT_ANY, //Resources to evaluate EF_FFT_POWER2
	BITMASK_MEAN | BITMASK_FFT_ANY //Resources to evaluate EF_FFT_FREQ2
};

#if (NEUTON_PREPROCESSING_ENABLED == 1)

#ifndef PYTHON_LIB

// Functions called on predictions

#include "DSP.h"

static uint8_t dspIsInited = 0;
static DSP_AXIS_INFO dspAxisInfo[NEUTON_MODEL_USED_ORIGINAL_INPUTS_COUNT] = { 0 };

///
/// \brief Initializes extracted features input parameters array for one input axis.
/// \param p_ExtractedFeatures - array of extracted features for axis
/// \param p_ExtractedFeaturesCount - number of elements in array
/// \param p_FeatureIdx - Index of first feature parameter for current axis from global array
/// modelExtractedFeaturesParamsOffset. Must be incremented on amount of required
/// parameters by particular extracted feature during feature parsing
/// \param p_CurrentAxis - current axis information (to store feature parameter index)
///
void InitInputParamsForExtractedFeatures(
	const uint16_t* p_ExtractedFeatures, 
	uint16_t p_ExtractedFeaturesCount, 
	uint16_t p_FeatureIdx,
	DSP_AXIS_INFO* p_CurrentAxis)
{	

	for (uint16_t efIdx = 0; efIdx < p_ExtractedFeaturesCount; efIdx++)
	{
		if (p_ExtractedFeatures[efIdx] != EF_STAT_UNUSED)
		{
			switch (p_ExtractedFeatures[efIdx])
			{
				// separate case if all 3 params must be applied (commented code below)
			case EF_STAT_MEAN_CROSSING:
			case EF_STAT_POSITIVE_MEAN_CROSSING:
			case EF_STAT_NEGATIVE_MEAN_CROSSING:
				p_CurrentAxis->efParamIdx[EF_PARAM_STAT_MEAN_CROSSING] = p_FeatureIdx;

				// moving Index to one param forward for next functions,
				// number of params maybe changed for some cases in future
				p_FeatureIdx += 1;

				break;

				// separate case if all 2 params must be applied (commented code below)
			case EF_AMP_HIGH_FREQUENCY_P2P:
			case EF_AMP_LOW_FREQUENCY_P2P:
				p_CurrentAxis->efParamIdx[EF_PARAM_AMP_FREQUENCY_P2P] = p_FeatureIdx;

				p_FeatureIdx += 1;

				break;
				
			/*
			case EF_STAT_NEGATIVE_MEAN_CROSSING:
				p_CurrentAxis->efParamIdx[EF_PARAM_STAT_NEGATIVE_MEAN_CROSSING] = p_FeatureIdx;

				p_FeatureIdx += 1;

				break;

			case EF_STAT_POSITIVE_MEAN_CROSSING:
				p_CurrentAxis->efParamIdx[EF_PARAM_STAT_POSITIVE_MEAN_CROSSING] = p_FeatureIdx;

				p_FeatureIdx += 1;

				break;

			case EF_AMP_HIGH_FREQUENCY_P2P:
				p_CurrentAxis->efParamIdx[EF_PARAM_AMP_HIGH_FREQUENCY_P2P] = p_FeatureIdx;

				p_FeatureIdx += 1;

				break;

			case EF_AMP_LOW_FREQUENCY_P2P:
				p_CurrentAxis->efParamIdx[EF_PARAM_AMP_LOW_FREQUENCY_P2P] = p_FeatureIdx;

				p_FeatureIdx += 1;

				break;
*/
			default:
				break;

			} // switch
		} // if (p_ExtractedFeatures[efIdx] != EF_STAT_UNUSED)
	} // for p_ExtractedFeaturesCount
}

void dsp_init_lib()
{
	// init global DSP array	

	if (dspIsInited == 0)
	{
		for (uint16_t column = 0; column < NEUTON_MODEL_USED_ORIGINAL_INPUTS_COUNT; ++column)
		{
			const uint16_t efNumForCol = modelExtractedFeaturesCountForAxle[column];

			if (efNumForCol > 0)
			{
				const uint32_t efStartIdx = modelExtractedFeaturesStartIdxForAxle[column];

				InitInputParamsForExtractedFeatures(
					modelExtractedFeatures + efStartIdx,
					efNumForCol,
					modelExtractedFeaturesParamsOffset[column],
					&dspAxisInfo[column]);
			}

			dspAxisInfo[column].calcBitMask = 0;
		}

		dspIsInited = 1;
	}
}

void PopulateFeatureMask(
	const uint16_t* p_ExtractedFeatures,
	uint16_t p_ExtractedFeaturesCount,
	uint16_t p_ColIdx,
	CalcBitMask* p_CalcBitMask)
{		
	if (dspAxisInfo[p_ColIdx].calcBitMask == 0)
	{
		CalcBitMask mask = 0;
		
		if (!p_ExtractedFeatures)
		{
			mask = 0xFFFF;
		}
		else
		{
			mask = 0;

			for (uint16_t efIdx = 0; efIdx < p_ExtractedFeaturesCount; efIdx++)
			{
				if (p_ExtractedFeatures[efIdx] != EF_STAT_UNUSED)
				{
					mask |= featuresCalculationRequestedMask[p_ExtractedFeatures[efIdx]];
				}
			}
		}

		dspAxisInfo[p_ColIdx].calcBitMask = mask;
	}

	*p_CalcBitMask = dspAxisInfo[p_ColIdx].calcBitMask;
}

const int32_t* GetFeatureInputParams(uint16_t axisIdx, ExtractedFeaturesParams paramToGet)
{
	return &modelExtractedFeaturesParams[dspAxisInfo[axisIdx].efParamIdx[paramToGet]];
}

#else // else not PYTHON_LIB

// Functions used in python library during training

void PopulateFeatureMask(
	const uint16_t* p_ExtractedFeatures,
	uint16_t p_ExtractedFeaturesCount,
	uint16_t p_ColIdx,
	CalcBitMask* p_CalcBitMask)
{
	*p_CalcBitMask = 0xFFFF;
}

extern int32_t* g_FeatureParameterPtrs[];

const int32_t* GetFeatureInputParams(uint16_t axisIdx, ExtractedFeaturesParams paramToGet)
{
	return g_FeatureParameterPtrs[paramToGet];
}

#endif // PYTHON_LIB

#else

// Stub functions, should not be called

void PopulateFeatureMask(
	const uint16_t* p_ExtractedFeatures,
	uint16_t p_ExtractedFeaturesCount,
	uint16_t p_ColIdx,
	CalcBitMask* p_CalcBitMask)
{
	*p_CalcBitMask = 0xFFFF;
}

extern int32_t* g_FeatureParameterPtrs[];

const int32_t* GetFeatureInputParams(uint16_t axisIdx, ExtractedFeaturesParams paramToGet)
{
	return NULL;
}


#endif //#if (NEUTON_PREPROCESSING_ENABLED == 1)
