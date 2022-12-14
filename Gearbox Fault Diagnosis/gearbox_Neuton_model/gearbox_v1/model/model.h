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
#define NEUTON_MODEL_TASK_TYPE 0  // multiclass classification
#define NEUTON_MODEL_NEURONS_COUNT 59
#define NEUTON_MODEL_WEIGHTS_COUNT 393
#define NEUTON_MODEL_INPUTS_COUNT 52
#define NEUTON_MODEL_INPUTS_COUNT_ORIGINAL 4
#define NEUTON_MODEL_INPUT_LIMITS_COUNT 1
#define NEUTON_MODEL_OUTPUTS_COUNT 6
#define NEUTON_MODEL_LOG_SCALE_OUTPUTS 0
#define NEUTON_MODEL_HAS_CLASSES_RATIO 0
#define NEUTON_MODEL_HAS_NEGPOS_RATIO 0

/* Preprocessing */
#define NEUTON_PREPROCESSING_ENABLED 1
#define NEUTON_MODEL_WINDOW_SIZE 144
#define NEUTON_DROP_ORIGINAL_FEATURES 1
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
typedef uint16_t weights_size_t;
typedef uint8_t neurons_size_t;

/* Scaling */
static const extracted_feature_t extractedFeaturesScaleMin[] = {
	137380, 2230, 10176256, 2911, -32768, 66404, 1015424, 33019904, 24625,
	8469, 24, 12, 12, 269016, 4278, 14204928, 5375, -32768, 66438, 3380480,
	60247040, 24700, 8356, 25, 13, 12, 199551, 5640, 66306048, 7582, -32768,
	66474, 3127168, 57946112, 26965, 9161, 26, 13, 13, 199912, 4993, -197308416,
	2265, -32768, 66368, 2650240, 53345280, 28268, 9214, 23, 11, 12 };
static const extracted_feature_t extractedFeaturesScaleMax[] = {
	7083342, 61820, 26237952, 32766, -1699, 68408, 133783552, 379011072, 37066,
	57914, 83, 41, 42, 7559079, 86144, 42614784, 32766, -2819, 69020, 83972096,
	300277760, 38177, 58197, 102, 51, 51, 6615599, 93905, 97284096, 31674,
	-2244, 68278, 111267840, 345645056, 36393, 60104, 79, 39, 40, 7301014,
	81810, -61515776, 32767, -6167, 68080, 94515200, 318570496, 42032, 58250,
	73, 36, 37 };

/* Limits */
static const uint8_t modelUsedInputsMask[] = {
	0xff, 0xbf, 0xff, 0x7f, 0xff, 0xff, 0x0b };

/* Structure */
static const weight_t modelWeights[] = {
	-105, -61, -23, 111, 78, 9, 43, 124, 27, -49, -52, -11, -48, 66, -114,
	-65, 84, 45, -22, 124, 85, -47, 66, -22, -65, -128, 61, -2, 61, -2, -6,
	102, 34, 57, -123, -2, 93, -55, -89, 24, -30, 14, -93, 117, 26, -79, 102,
	-69, -120, -35, -71, 95, -128, 58, -48, 122, -122, 120, -111, -3, -50,
	43, 95, -45, 41, -128, -58, -128, -128, 31, -18, -19, -106, 36, 17, 15,
	119, -84, 41, 123, -128, 124, -92, 7, -6, 32, -17, -13, -128, 122, -114,
	59, -86, -6, 63, -77, -12, 92, -53, 5, 18, 54, 124, 6, -62, 118, -122,
	121, 74, -71, -77, 88, 27, -71, -57, -108, 51, -28, -125, 52, -128, -128,
	61, -65, -2, -2, 61, -65, -114, 32, 95, 1, 125, 94, -53, -111, -46, 2,
	-86, -36, -66, 117, 33, -104, 12, 22, -128, -48, -48, -13, -64, 106, -40,
	76, -97, -128, -4, -11, 67, -128, 80, -29, -89, -60, -119, 87, -8, 69,
	23, -128, -116, 61, 62, -56, -3, -29, -36, 45, -59, 2, -27, -26, 46, -35,
	28, -123, 59, 21, -30, 106, -79, -126, -24, -10, -110, -26, -107, -58,
	-73, 50, 59, -113, 29, 70, 125, -118, -55, 124, 124, -52, 19, -8, -128,
	-128, -128, 29, -36, -55, -6, 22, -37, 112, -10, -128, -58, 8, -128, 2,
	-84, -87, 27, -128, -128, -2, -37, -9, 1, -69, -128, -62, -42, -97, 85,
	51, 124, -12, -115, -69, 88, 36, 35, -128, 22, 24, -99, 39, 124, -109,
	-124, -26, 124, 122, -10, -26, 63, -11, -3, -53, -44, 77, 125, -75, -73,
	54, 21, -128, -79, 33, 8, -128, 7, -128, 31, -120, 28, -13, -44, 48, -123,
	-71, 119, -113, -128, -88, -74, 94, 0, 20, -128, -72, 15, -36, -53, 71,
	-128, -32, -108, 98, -37, -128, 0, -128, -99, 52, -128, -88, -6, -116,
	-128, 15, -89, 69, -77, -30, -128, -128, -74, -53, -98, -3, -128, -128,
	-80, 41, -105, -3, 57, 70, -99, -127, -128, -2, -126, 6, -71, -54, -116,
	-4, 117, -110, -71, 2, 88, -83, -26, -28, -39, -57, 73, -30, -123, -119,
	-122, 124, 110, 125, 124, -128, 124, -6, 11, -62, -9, -55, 82, -121, 24,
	-101, -28, -128, 93, -128, -109, -46, -5, -128, 27, -112, 26, -128, -115,
	105, -6 };

static const sources_size_t modelLinks[] = {
	7, 9, 25, 32, 45, 52, 3, 7, 25, 35, 47, 52, 1, 1, 3, 10, 29, 52, 0, 6,
	25, 38, 47, 52, 6, 7, 9, 11, 19, 52, 3, 6, 11, 45, 46, 52, 8, 21, 28, 48,
	51, 52, 6, 2, 22, 45, 48, 52, 0, 2, 4, 12, 33, 52, 1, 8, 6, 19, 45, 52,
	5, 1, 5, 19, 29, 35, 52, 9, 6, 16, 17, 21, 22, 25, 52, 0, 1, 2, 3, 8, 52,
	8, 22, 40, 43, 46, 52, 3, 8, 8, 21, 39, 52, 9, 14, 19, 35, 45, 48, 52,
	0, 1, 2, 3, 6, 4, 52, 14, 1, 11, 41, 48, 52, 8, 9, 22, 36, 39, 47, 52,
	17, 22, 32, 38, 45, 52, 0, 1, 33, 40, 48, 52, 14, 26, 30, 32, 47, 52, 0,
	1, 2, 3, 28, 52, 4, 10, 20, 22, 35, 52, 0, 1, 2, 3, 12, 11, 52, 1, 2, 3,
	28, 34, 52, 10, 4, 7, 11, 30, 52, 4, 17, 22, 5, 49, 52, 6, 7, 15, 20, 48,
	52, 17, 18, 26, 7, 10, 37, 52, 3, 4, 26, 7, 12, 52, 11, 21, 28, 8, 33,
	52, 0, 1, 2, 3, 8, 52, 15, 19, 27, 0, 2, 52, 5, 21, 22, 18, 47, 48, 52,
	0, 1, 2, 3, 12, 52, 2, 31, 27, 47, 48, 52, 8, 35, 16, 27, 35, 52, 1, 8,
	15, 25, 26, 37, 52, 22, 0, 11, 17, 20, 45, 52, 4, 10, 16, 17, 18, 19, 20,
	39, 52, 19, 25, 13, 24, 35, 52, 0, 1, 2, 3, 19, 52, 0, 7, 32, 35, 36, 42,
	52, 17, 21, 35, 36, 1, 9, 52, 2, 6, 22, 23, 28, 29, 30, 31, 41, 44, 52,
	0, 1, 2, 3, 19, 44, 52, 22, 26, 29, 37, 33, 46, 52, 6, 17, 28, 0, 27, 52,
	5, 8, 10, 17, 12, 30, 52, 12, 33, 46, 7, 48, 52, 19, 46, 12, 40, 41, 52,
	18, 23, 42, 45, 46, 52, 8, 32, 9, 16, 35, 52, 0, 1, 15, 32, 44, 52, 3,
	9, 12, 13, 14, 33, 34, 46, 47, 48, 49, 50, 51, 52, 53, 54, 52, 0, 1, 3,
	4, 27, 52, 18, 30, 32, 34, 42, 56, 15, 52, 5, 11, 21, 24, 27, 56, 57, 52 };

static const weights_size_t modelIntLinksBoundaries[] = {
	0, 6, 13, 19, 24, 30, 36, 43, 51, 56, 61, 68, 80, 82, 89, 95, 105, 108,
	113, 121, 126, 133, 142, 147, 155, 160, 164, 172, 177, 184, 191, 197, 205,
	209, 215, 223, 227, 233, 243, 245, 259, 262, 270, 278, 283, 296, 301, 308,
	314, 321, 327, 332, 337, 344, 350, 370, 375, 383, 392 };
static const weights_size_t modelExtLinksBoundaries[] = {
	6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 67, 75, 81, 87, 93, 100, 107, 113,
	120, 126, 132, 138, 144, 150, 157, 163, 169, 175, 181, 188, 194, 200, 206,
	212, 219, 225, 231, 237, 244, 251, 260, 266, 272, 279, 286, 297, 304, 311,
	317, 324, 330, 336, 342, 348, 354, 371, 377, 385, 393 };

static const coeff_t modelFuncCoeffs[] = {
	153, 101, 61, 105, 92, 118, 87, 51, 106, 160, 107, 146, 62, 107, 64, 152,
	45, 109, 94, 150, 126, 89, 157, 122, 54, 75, 136, 154, 77, 117, 70, 154,
	104, 113, 158, 157, 69, 155, 77, 140, 107, 115, 143, 56, 84, 59, 160, 41,
	46, 74, 157, 74, 148, 113, 160, 151, 44, 79, 151 };
static const uint8_t modelFuncTypes[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static const neurons_size_t modelOutputNeurons[] = { 43, 38, 45, 55, 40, 58 };

#ifdef __cplusplus
}
#endif

#endif // NEUTON_MODEL_MODEL_H

