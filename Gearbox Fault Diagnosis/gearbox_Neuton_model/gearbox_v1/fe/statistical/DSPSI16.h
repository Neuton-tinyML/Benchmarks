#ifndef NEUTON_FE_STATISTICAL_DSPSI16_H
#define NEUTON_FE_STATISTICAL_DSPSI16_H

#include "Common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Init common data buffer to optimize calculations
 * \param p_ExtractedFeatures Array of ExtractedFeatures enum values. (extracted features for current axis)
 * \param p_ExtractedFeaturesCount Number of elements in p_ExtractedFeatures array
 * \param p_ColIdx Current axis index. Used to get input parameters for some features
 * \param p_Data Pointer to processed memory buffer
 * \param p_Size Size of the buffer
 */
void SaPrecalcStatDataSI16(
	const uint16_t* p_ExtractedFeatures,
	uint16_t p_ExtractedFeaturesCount,
	uint16_t p_ColIdx,
	const int16_t* p_Data, 
	size_t p_Size);
	
/**
 * \brief Compute the minimum values simultaneously.
 */
int32_t MinSI16();

/**
 * \brief Compute the maximum values simultaneously.
 */
int32_t MaxSI16();

/**
 * \brief Compute the arithmetic mean.
 */
int32_t MeanSI16();

/**
 * \brief Compute the root mean square, [RMS](https://en.wikipedia.org/wiki/Root_mean_square).
 */
int32_t RootMeanSquareSI16();

/**
 * \brief Count the number of sign changes
 */
int32_t MeanCrossingSI16();

/**
 * \brief Count the number of mean crossing in down direction
 */
int32_t NegMeanCrossingSI16();

/**
 * \brief Count the number of mean crossing in up direction
 */
int32_t PosMeanCrossingSI16();

/**
 * \brief Compute the variance
 */
int32_t VarianceSI16();

/**
 * \brief Compute the Petrosian fractal dimension, PFD.
 */
int32_t PetrosianFractalDimensionSI16();

/**
 * \brief Compute the [skewness](https://en.wikipedia.org/wiki/Skewness)
 */
int32_t SkewnessSI16();

/**
 * \brief  Compute the [kurtosis](https://en.wikipedia.org/wiki/Kurtosis)
 */
int32_t KurtosisSI16();

/**
 * \brief Calculates the peak-to-peak (min-max) of the curve after subtracting the low-frequency component (smoothed curve with a nsmooth parameter)
 */
int32_t AmplitudeGlobalP2pHighFrequencySI16();

/**
 * \brief Calculates the peak-to-peak (min-max) of the smoothed curve with a nsmooth parameter
 */
int32_t AmplitudeGlobalP2pLowFrequencySI16();

#ifdef __cplusplus
}
#endif

#endif // NEUTON_FE_STATISTICAL_DSPSI16_H
