#ifndef NEUTON_MODEL_MODEL_H
#define NEUTON_MODEL_MODEL_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Model info */
#define NEUTON_MODEL_HEADER_VERSION 3
#define NEUTON_MODEL_QLEVEL 8
#define NEUTON_MODEL_FLOAT_SUPPORT 0
#define NEUTON_MODEL_TASK_TYPE 1  // binary classification
#define NEUTON_MODEL_NEURONS_COUNT 33
#define NEUTON_MODEL_WEIGHTS_COUNT 230
#define NEUTON_MODEL_INPUTS_COUNT 187
#define NEUTON_MODEL_INPUTS_COUNT_ORIGINAL 1
#define NEUTON_MODEL_INPUT_LIMITS_COUNT 1
#define NEUTON_MODEL_OUTPUTS_COUNT 2
#define NEUTON_MODEL_LOG_SCALE_OUTPUTS 0
#define NEUTON_MODEL_HAS_CLASSES_RATIO 0
#define NEUTON_MODEL_HAS_NEGPOS_RATIO 0

/* Preprocessing */
#define NEUTON_PREPROCESSING_ENABLED 1
#define NEUTON_MODEL_WINDOW_SIZE 187
#define NEUTON_DROP_ORIGINAL_FEATURES 0
#define NEUTON_BITMASK_ENABLED 1
#define NEUTON_INPUTS_IS_INTEGER 1
#define NEUTON_MODEL_SA_PRECISION 15

/* Types */
typedef int16_t input_t;
typedef int32_t extracted_feature_t;
typedef uint8_t coeff_t;
typedef int8_t weight_t;
typedef int32_t acc_signed_t;
typedef uint32_t acc_unsigned_t;
typedef uint8_t sources_size_t;
typedef uint8_t weights_size_t;
typedef uint8_t neurons_size_t;

/* Scaling */
static const input_t modelInputScaleMin[] = { -32768 };
static const input_t modelInputScaleMax[] = { 32767 };

static const extracted_feature_t extractedFeaturesScaleMin[] = { };
static const extracted_feature_t extractedFeaturesScaleMax[] = { };

/* Limits */
static const uint8_t modelUsedInputsMask[] = {
	0x5f, 0x07, 0xd4, 0xfe, 0x7f, 0x86, 0xb3, 0x57, 0x10, 0x89, 0xc4, 0x14,
	0x61, 0x0b, 0x61, 0x11, 0xd0, 0x7b, 0x31, 0x18, 0x30, 0xb0, 0x02, 0x03 };

/* Structure */
static const weight_t modelWeights[] = {
	59, -128, 61, 43, 30, -4, 124, 61, -65, -65, -65, -2, 103, 2, -41, -79,
	-128, -67, 31, 46, 85, -56, -23, -12, -128, -69, -100, -119, 2, 25, -1,
	13, -128, -128, -14, 127, -36, 44, 10, -54, -99, 125, -34, -128, -6, 72,
	-126, 8, 65, -59, -13, -15, 122, 12, 58, -128, 11, -42, 1, 94, -104, 2,
	1, -3, -23, 95, 127, -62, -1, 64, -6, 124, -54, 62, -87, -55, 91, 34, -10,
	-128, -128, -79, -61, -55, 24, -91, -93, 127, 115, -30, 0, -18, -128, 63,
	80, -68, -34, -39, -83, -128, 125, -80, -40, -3, -91, -128, 125, -128,
	-119, -4, 22, -128, -72, 67, -12, 54, -128, -30, 122, -113, -83, -45, 0,
	-127, -98, -56, 88, 12, -14, 116, -128, -124, 100, -128, 89, 0, -56, 70,
	-128, -47, 125, -3, 29, -55, -116, 63, -116, 0, -22, 113, 92, 122, -128,
	80, -128, 5, 121, -50, -4, -59, -87, -92, 39, -116, -118, 56, 2, -110,
	-6, -122, 96, -13, -5, 61, -125, -94, -128, -128, -128, -4, -128, 123,
	-127, 12, -7, -68, 91, -22, 123, -83, -34, -53, 124, -128, -128, -128,
	-128, -65, 59, -31, 107, 61, 4, -59, 36, 90, -15, 56, 24, 124, 78, -29,
	122, -93, -45, 125, 87, 124, 116, -43, -35, -26, -100, -128, 33, 94, -107,
	-17, 124, -19 };

static const sources_size_t modelLinks[] = {
	4, 31, 53, 62, 68, 187, 0, 3, 27, 53, 134, 187, 29, 82, 87, 124, 137, 187,
	0, 36, 48, 56, 124, 139, 185, 187, 1, 3, 25, 58, 124, 187, 25, 28, 32,
	35, 48, 148, 187, 6, 8, 47, 55, 148, 187, 5, 6, 27, 30, 35, 105, 187, 4,
	28, 32, 58, 135, 187, 2, 20, 29, 49, 105, 187, 5, 8, 9, 8, 29, 165, 187,
	2, 7, 10, 32, 35, 38, 87, 187, 1, 8, 72, 96, 101, 187, 25, 33, 57, 87,
	140, 187, 0, 2, 4, 7, 10, 13, 187, 9, 52, 56, 86, 156, 187, 9, 8, 30, 34,
	104, 187, 11, 2, 23, 37, 75, 144, 10, 12, 18, 47, 62, 120, 187, 1, 6, 1,
	49, 105, 187, 9, 20, 22, 25, 36, 42, 187, 7, 68, 82, 102, 172, 187, 10,
	20, 26, 72, 141, 187, 13, 23, 105, 155, 173, 175, 187, 6, 1, 90, 137, 149,
	187, 30, 33, 79, 107, 139, 187, 11, 35, 38, 52, 118, 187, 37, 60, 124,
	142, 164, 177, 187, 12, 27, 92, 96, 112, 187, 8, 10, 41, 57, 79, 187, 86,
	117, 132, 141, 184, 187, 5, 0, 8, 60, 136, 187, 1, 3, 5, 6, 8, 9, 11, 12,
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 187 };

static const weights_size_t modelIntLinksBoundaries[] = {
	0, 7, 12, 18, 28, 32, 39, 47, 52, 58, 67, 74, 81, 85, 97, 99, 105, 111,
	118, 125, 129, 137, 144, 149, 156, 161, 168, 173, 181, 186, 192, 199, 229 };
static const weights_size_t modelExtLinksBoundaries[] = {
	6, 12, 18, 26, 32, 39, 45, 52, 58, 64, 71, 79, 85, 91, 98, 104, 110, 116,
	123, 129, 136, 142, 148, 155, 161, 167, 173, 180, 186, 192, 198, 204, 230 };

static const coeff_t modelFuncCoeffs[] = {
	134, 157, 105, 138, 153, 159, 160, 80, 158, 144, 160, 56, 145, 159, 32,
	157, 160, 157, 149, 156, 160, 160, 160, 140, 86, 145, 82, 157, 157, 157,
	146, 148, 72 };
static const uint8_t modelFuncTypes[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0 };

static const neurons_size_t modelOutputNeurons[] = { 14, 32 };

#ifdef __cplusplus
}
#endif

#endif // NEUTON_MODEL_MODEL_H

