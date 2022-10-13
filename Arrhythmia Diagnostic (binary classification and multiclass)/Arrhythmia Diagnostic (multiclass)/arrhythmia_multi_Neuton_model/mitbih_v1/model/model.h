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
#define NEUTON_MODEL_NEURONS_COUNT 95
#define NEUTON_MODEL_WEIGHTS_COUNT 672
#define NEUTON_MODEL_INPUTS_COUNT 188
#define NEUTON_MODEL_INPUTS_COUNT_ORIGINAL 1
#define NEUTON_MODEL_INPUT_LIMITS_COUNT 1
#define NEUTON_MODEL_OUTPUTS_COUNT 5
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
typedef uint16_t weights_size_t;
typedef uint8_t neurons_size_t;

/* Scaling */
static const input_t modelInputScaleMin[] = { -32768 };
static const input_t modelInputScaleMax[] = { 32767 };

static const extracted_feature_t extractedFeaturesScaleMin[] = { -32768 };
static const extracted_feature_t extractedFeaturesScaleMax[] = { -21889 };

/* Limits */
static const uint8_t modelUsedInputsMask[] = {
	0xff, 0xff, 0x7f, 0x7f, 0xff, 0xfb, 0xfe, 0xbf, 0x7f, 0x67, 0xff, 0x7f,
	0x9f, 0x8b, 0x9a, 0x1f, 0x24, 0x94, 0xcf, 0x5a, 0xd3, 0x91, 0xe8, 0x07 };

/* Structure */
static const weight_t modelWeights[] = {
	65, -81, -13, -5, -128, -5, 123, -51, -86, 115, -29, 21, 111, -94, -2,
	-58, -78, -128, 16, 111, -42, 124, 124, 1, 124, -128, 47, 1, 124, -12,
	-25, 74, -128, -53, 80, 34, -2, -128, -40, -93, -15, 121, 30, 8, -75, 56,
	35, -128, 15, 21, -51, -128, 77, 125, -113, 125, -35, -39, -56, -76, 82,
	125, 125, 10, -46, 47, 122, -74, -125, -58, 77, 0, -118, 66, -30, -40,
	-126, 79, 18, -47, -122, 124, 57, 113, -27, -16, -42, 47, -122, -128, 14,
	93, -121, 77, -85, -104, -86, -128, -128, 26, -128, -128, -20, 0, 27, -52,
	111, -128, 19, -14, -127, -94, 111, -35, 11, 5, -41, 124, -73, 75, 59,
	6, -125, -111, 63, -72, 5, 4, -128, 77, -98, -78, -128, -83, 0, -116, -124,
	-63, 47, -42, -124, 1, 17, -28, -128, -40, -93, 9, -128, -35, 125, -128,
	-128, -3, -90, -128, -79, 35, -71, 12, -106, 114, -128, 65, 24, -33, -128,
	32, -81, 0, -114, 28, -18, 29, -117, 83, -84, -4, -19, 24, -111, 127, 23,
	-4, -65, 61, 61, -65, -128, 124, -65, -44, 84, 45, 16, -67, 18, -119, -128,
	21, 124, -40, -108, 57, 9, -67, 99, -112, -91, -96, -94, -14, -38, 28,
	-32, -123, 78, 1, -86, 120, -55, 6, 17, -30, -43, -35, -29, 120, -39, -60,
	4, -31, 77, -128, -128, 6, 71, -34, -26, -97, -29, -128, 119, -67, 5, -83,
	-15, -128, 1, 59, -128, 0, -16, -128, -55, 24, -69, 12, -96, 54, -10, 37,
	-110, -43, -84, 64, -119, -62, 25, -4, -76, -118, 125, -109, 20, -60, -11,
	-78, -124, 32, 18, 9, -30, -2, -71, -31, -44, 40, 125, -31, -2, 28, 28,
	-47, -78, 124, 124, -106, 42, -44, 33, -84, 56, 124, 29, -64, 49, -36,
	-91, 115, 88, -94, 35, 105, 8, 24, -126, -115, -4, 87, -29, 82, -128, -8,
	-22, -106, 123, 1, -127, -26, 18, 66, -128, -122, 80, 31, 5, 92, -42, -120,
	107, -128, -37, -42, -126, 114, -11, -128, -6, -77, 125, 42, -8, -128,
	-46, -10, 66, -118, 126, -113, -81, 90, 118, 74, -26, -112, -73, -125,
	-104, -68, -128, 0, -128, -4, -85, -123, 14, 77, -106, 73, -14, 15, -48,
	-78, 74, 108, 118, -81, -65, -2, -128, -2, -65, -2, 0, 40, 74, -89, 9,
	123, -20, -43, 91, -126, -38, -7, 61, -8, 76, 46, -104, 20, 37, -128, 124,
	-56, -94, 23, 7, 14, -116, -128, -24, 117, -128, -128, 0, -128, -128, -128,
	-36, -87, 84, -128, -4, -70, -128, -20, -112, 120, 59, -3, -30, 37, -96,
	-110, 124, 10, -128, -20, -128, -82, -80, -128, 0, 109, -83, 61, -16, 93,
	-3, 117, -47, -110, -120, -128, 17, 127, 113, -121, -109, 31, -73, 125,
	-81, 12, -58, -53, 80, 26, 71, -32, -78, 125, -128, -122, -30, 99, -122,
	-48, -46, -3, -66, -86, 77, -112, -32, -41, -128, 1, -79, -128, -119, 110,
	4, -7, 125, -22, 125, -56, -128, -66, -128, 109, -113, 28, -98, -3, -128,
	-88, 92, -40, 37, -7, 124, 19, -128, 89, 34, -29, -32, -125, -116, -76,
	-128, -4, -35, -74, -42, 122, -128, -5, -80, -128, 114, -23, -128, 10,
	-128, -29, -125, 7, -128, -8, 121, -122, 112, -33, -128, -128, -81, -112,
	25, -31, 24, 80, -96, -34, 127, -42, 40, -33, -119, -128, -58, 72, -52,
	-128, -128, -105, -128, -128, -31, -128, -128, 126, 70, -44, -59, 44, -120,
	121, 35, -128, -128, -2, -2, -128, -128, -33, -35, -128, -128, -9, 76,
	-128, -128, -71, -22, -83, -123, 124, 17, 0, -128, -120, -124, -82, 23,
	-128, 71, 121, -12, -67, -80, 60, 109, -4, -114, 79, -73, 64, -78, -128,
	30, -89, 46, 41, -23, -33, 48, -66, -128, 36, 124, -54, -76, -21, -24,
	2, -2, -13, -2, 121, -25, -83, -55, -55, -125, -70, -4, -34, 60, 28, 24,
	-77, 124, -128, 37, -128, -128, -10 };

static const sources_size_t modelLinks[] = {
	1, 3, 34, 46, 179, 188, 3, 16, 37, 61, 184, 188, 0, 3, 13, 150, 172, 188,
	2, 18, 50, 93, 94, 188, 0, 2, 8, 74, 133, 188, 1, 5, 10, 12, 16, 17, 188,
	1, 6, 28, 86, 87, 90, 188, 2, 1, 11, 24, 65, 116, 188, 8, 19, 122, 146,
	182, 188, 4, 96, 104, 130, 138, 143, 188, 2, 7, 10, 18, 19, 20, 25, 188,
	2, 6, 1, 4, 6, 22, 188, 0, 26, 40, 85, 164, 188, 1, 2, 3, 8, 158, 188,
	1, 19, 46, 78, 81, 188, 5, 9, 21, 22, 25, 29, 188, 2, 14, 21, 51, 68, 188,
	3, 15, 72, 84, 185, 188, 4, 15, 26, 44, 164, 188, 2, 5, 13, 34, 66, 188,
	13, 15, 18, 26, 32, 33, 188, 20, 9, 10, 20, 32, 119, 188, 2, 10, 30, 40,
	47, 188, 21, 3, 14, 26, 85, 188, 2, 18, 5, 34, 94, 188, 20, 50, 55, 82,
	100, 188, 16, 2, 18, 26, 27, 122, 188, 18, 5, 30, 38, 123, 188, 0, 4, 5,
	68, 153, 188, 6, 78, 87, 121, 150, 188, 0, 1, 2, 3, 19, 41, 188, 21, 24,
	26, 0, 6, 22, 188, 4, 31, 7, 14, 130, 160, 188, 28, 45, 59, 64, 181, 188,
	0, 2, 5, 33, 133, 188, 11, 16, 2, 15, 27, 40, 188, 3, 10, 28, 35, 10, 34,
	188, 0, 2, 34, 3, 11, 45, 188, 12, 69, 73, 77, 87, 183, 188, 3, 8, 5, 87,
	111, 188, 2, 3, 1, 6, 13, 188, 10, 26, 38, 40, 145, 188, 14, 4, 16, 28,
	46, 91, 188, 35, 8, 34, 98, 167, 188, 0, 5, 10, 11, 12, 13, 14, 15, 16,
	17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 37, 38, 39, 40, 41,
	42, 43, 188, 0, 2, 3, 4, 35, 188, 37, 0, 2, 4, 22, 188, 0, 5, 28, 33, 107,
	188, 12, 50, 51, 68, 87, 188, 27, 47, 2, 69, 175, 188, 17, 6, 8, 54, 113,
	188, 16, 42, 41, 46, 167, 188, 4, 35, 61, 72, 80, 188, 12, 21, 43, 0, 10,
	188, 13, 28, 30, 77, 111, 119, 188, 16, 7, 8, 15, 33, 40, 188, 0, 1, 2,
	3, 13, 42, 188, 2, 3, 7, 41, 14, 89, 188, 11, 43, 0, 2, 105, 147, 188,
	22, 45, 0, 150, 179, 188, 0, 1, 2, 3, 18, 188, 7, 54, 2, 57, 68, 188, 2,
	31, 47, 10, 39, 166, 188, 34, 46, 48, 1, 9, 36, 186, 188, 5, 23, 51, 91,
	124, 156, 188, 4, 13, 6, 33, 58, 188, 5, 20, 49, 24, 36, 160, 188, 21,
	3, 60, 91, 144, 188, 19, 46, 5, 29, 155, 188, 7, 1, 13, 43, 58, 188, 34,
	2, 18, 49, 91, 120, 188, 4, 5, 17, 29, 155, 188, 9, 25, 8, 97, 105, 188,
	16, 17, 53, 65, 5, 17, 122, 188, 2, 27, 29, 53, 67, 188, 2, 5, 17, 19,
	168, 188, 15, 27, 33, 63, 57, 188, 6, 22, 56, 99, 116, 188, 22, 62, 1,
	52, 115, 188, 5, 7, 35, 38, 161, 188, 3, 0, 8, 103, 181, 188, 1, 43, 52,
	88, 151, 188, 10, 34, 35, 105, 179, 188, 1, 12, 14, 35, 140, 188, 4, 9,
	60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
	78, 79, 80, 81, 82, 83, 188, 0, 1, 2, 3, 72, 188, 33, 75, 70, 78, 83, 92,
	175, 188, 21, 22, 38, 77, 74, 84, 188, 3, 8, 85, 86, 87, 188, 0, 1, 2,
	3, 24, 107, 188, 29, 27, 47, 56, 63, 179, 188, 2, 7, 30, 31, 32, 34, 36,
	45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 89, 90, 188, 0, 1, 2, 4, 28,
	188, 5, 2, 16, 124, 164, 188, 1, 6, 33, 35, 56, 57, 58, 59, 92, 93, 188 };

static const weights_size_t modelIntLinksBoundaries[] = {
	0, 6, 12, 19, 26, 31, 38, 45, 51, 58, 66, 74, 79, 86, 91, 99, 104, 110,
	118, 124, 131, 136, 144, 149, 156, 160, 167, 174, 180, 185, 196, 201, 207,
	212, 218, 226, 235, 241, 245, 254, 260, 266, 271, 278, 312, 317, 320, 325,
	332, 339, 344, 351, 357, 364, 368, 375, 387, 392, 397, 404, 413, 416, 423,
	430, 437, 444, 451, 456, 463, 468, 474, 481, 488, 496, 501, 508, 516, 518,
	526, 533, 537, 542, 549, 554, 586, 592, 595, 605, 613, 619, 622, 648, 654,
	656, 671 };
static const weights_size_t modelExtLinksBoundaries[] = {
	6, 12, 18, 24, 30, 37, 44, 51, 57, 64, 72, 79, 85, 91, 97, 104, 110, 116,
	122, 128, 135, 142, 148, 154, 160, 166, 173, 179, 185, 191, 198, 205, 212,
	218, 224, 231, 238, 245, 252, 258, 264, 270, 277, 283, 313, 319, 325, 331,
	337, 343, 349, 355, 361, 367, 374, 381, 388, 395, 402, 408, 414, 420, 427,
	435, 442, 448, 455, 461, 467, 473, 480, 486, 492, 500, 506, 512, 518, 524,
	530, 536, 542, 548, 554, 560, 587, 593, 601, 608, 614, 621, 628, 649, 655,
	661, 672 };

static const coeff_t modelFuncCoeffs[] = {
	157, 157, 18, 157, 146, 157, 160, 157, 101, 52, 158, 160, 154, 145, 144,
	160, 134, 156, 157, 150, 160, 149, 157, 156, 158, 146, 150, 155, 148, 92,
	111, 133, 55, 139, 129, 123, 64, 157, 155, 159, 144, 151, 146, 103, 56,
	156, 62, 158, 125, 62, 156, 158, 138, 101, 158, 150, 113, 160, 134, 65,
	158, 109, 160, 95, 151, 157, 158, 160, 157, 107, 147, 71, 156, 108, 157,
	154, 157, 153, 119, 154, 132, 157, 158, 157, 94, 62, 81, 157, 160, 160,
	155, 65, 120, 135, 82 };
static const uint8_t modelFuncTypes[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static const neurons_size_t modelOutputNeurons[] = { 44, 94, 91, 88, 84 };

#ifdef __cplusplus
}
#endif

#endif // NEUTON_MODEL_MODEL_H

