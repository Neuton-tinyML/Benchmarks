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
#define NEUTON_MODEL_NEURONS_COUNT 42
#define NEUTON_MODEL_WEIGHTS_COUNT 242
#define NEUTON_MODEL_INPUTS_COUNT 603
#define NEUTON_MODEL_INPUTS_COUNT_ORIGINAL 3
#define NEUTON_MODEL_INPUT_LIMITS_COUNT 603
#define NEUTON_MODEL_OUTPUTS_COUNT 10
#define NEUTON_MODEL_LOG_SCALE_OUTPUTS 0
#define NEUTON_MODEL_HAS_CLASSES_RATIO 0
#define NEUTON_MODEL_HAS_NEGPOS_RATIO 0

/* Preprocessing */
#define NEUTON_PREPROCESSING_ENABLED 1
#define NEUTON_MODEL_WINDOW_SIZE 200
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
typedef uint16_t sources_size_t;
typedef uint8_t weights_size_t;
typedef uint8_t neurons_size_t;

/* Scaling */
static const input_t modelInputScaleMin[] = { -2619, -5324, -926 };
static const input_t modelInputScaleMax[] = { 4789, 7758, 9132 };

static const extracted_feature_t extractedFeaturesScaleMin[] = {
	-2619, -5324, -926 };
static const extracted_feature_t extractedFeaturesScaleMax[] = { 331, 215, 3812 };

/* Limits */
static const uint8_t modelUsedInputsMask[] = {
	0x0f, 0x00, 0x10, 0x24, 0x70, 0x24, 0x44, 0x80, 0xe5, 0x19, 0x10, 0x40,
	0x48, 0x42, 0x19, 0x08, 0x8c, 0xc0, 0x88, 0x08, 0x20, 0x01, 0x70, 0x18,
	0x2b, 0x11, 0x56, 0x82, 0x4a, 0x21, 0x04, 0x96, 0x07, 0x04, 0x32, 0x00,
	0x00, 0x04, 0x3a, 0xda, 0x00, 0x04, 0x00, 0x01, 0x00, 0x10, 0x00, 0x32,
	0x80, 0x11, 0x00, 0x00, 0x00, 0x10, 0x50, 0x01, 0x00, 0x00, 0x1b, 0x61,
	0x00, 0x80, 0x0a, 0x20, 0x40, 0x00, 0x41, 0x04, 0x80, 0x40, 0x00, 0x00,
	0x10, 0x04, 0x82, 0x07 };

/* Structure */
static const weight_t modelWeights[] = {
	-72, 127, 36, 2, -38, -20, -96, 124, -62, 123, 92, -119, 25, -16, 66, -92,
	124, -67, 12, -28, -87, 1, 78, -34, 114, 2, -128, 101, 123, -128, -79,
	91, 92, 88, -57, -89, 126, -54, 36, -119, 72, 125, -100, -121, 93, 105,
	104, -38, -55, -127, 51, -24, 123, -100, -120, 76, 40, 17, -16, -51, -50,
	70, 34, 10, 125, 125, -124, -128, 47, -125, 26, 105, -128, -98, -109, 116,
	-5, -128, -44, -52, 57, 74, -20, -122, 123, 16, -128, 126, -2, -105, 61,
	-103, 0, -114, -128, 125, 109, 125, -67, -128, -128, 48, 48, 119, -13,
	-127, -11, -41, 121, 60, 0, -124, -122, -12, -128, 36, 22, -61, 50, 5,
	-21, 84, 126, -63, -51, -128, -109, 82, 120, 44, -62, -124, 98, 64, -52,
	14, -10, 124, -121, 108, -125, 0, 124, -128, 58, 73, -116, -128, 41, -23,
	-18, 111, 12, -116, -11, -75, 102, 122, 24, -128, 97, 90, -128, -125, 58,
	-69, -128, -128, -128, 39, -128, -49, -50, 123, 14, 86, -114, -128, -128,
	-128, -126, 49, -14, 16, 3, -128, -128, 121, -80, -33, -98, -33, 125, 59,
	-115, 40, 97, 53, -128, 19, 81, 123, -125, -63, -90, 34, -128, -128, 49,
	15, -15, -87, 71, -94, 122, -66, -89, -93, 115, 52, -40, -29, -116, -127,
	85, 79, -112, -128, -128, 54, 76, -10, 112, -23, 45, -95, -97, -89, 121,
	125, -108, 43 };

static const sources_size_t modelLinks[] = {
	26, 168, 252, 477, 558, 603, 1, 64, 99, 217, 381, 601, 603, 1, 37, 330,
	392, 586, 603, 155, 200, 227, 232, 277, 309, 603, 1, 1, 123, 195, 436,
	602, 603, 54, 182, 273, 344, 600, 603, 84, 165, 313, 377, 391, 603, 71,
	256, 318, 364, 600, 603, 6, 193, 225, 396, 464, 580, 603, 50, 181, 242,
	495, 499, 603, 110, 131, 187, 192, 249, 593, 603, 3, 70, 102, 315, 538,
	603, 1, 29, 38, 428, 558, 603, 1, 12, 603, 0, 131, 143, 223, 255, 305,
	603, 66, 69, 115, 142, 214, 603, 4, 15, 603, 9, 116, 180, 250, 319, 603,
	0, 1, 2, 3, 298, 603, 7, 18, 603, 5, 45, 94, 200, 497, 599, 603, 8, 130,
	258, 438, 478, 603, 2, 36, 105, 212, 237, 603, 7, 42, 72, 188, 551, 603,
	10, 11, 257, 465, 509, 518, 603, 75, 112, 204, 308, 330, 603, 3, 14, 25,
	603, 197, 230, 266, 307, 308, 603, 9, 21, 22, 27, 603, 5, 440, 472, 528,
	599, 603, 2, 10, 23, 24, 29, 603, 0, 1, 2, 3, 15, 603, 0, 1, 2, 3, 76,
	603, 151, 168, 180, 210, 258, 603, 112, 147, 499, 534, 601, 603, 8, 20,
	34, 603, 20, 209, 276, 467, 602, 603, 6, 33, 36, 603, 135, 315, 316, 380,
	468, 603, 5, 17, 31, 38, 603, 0, 1, 3, 4, 63, 603, 0, 11, 32, 40, 603 };

static const weights_size_t modelIntLinksBoundaries[] = {
	0, 6, 14, 19, 27, 33, 39, 45, 52, 58, 64, 71, 78, 85, 86, 93, 101, 103,
	112, 116, 118, 125, 130, 137, 144, 149, 158, 159, 169, 171, 181, 187, 192,
	194, 200, 209, 210, 219, 220, 230, 235, 241 };
static const weights_size_t modelExtLinksBoundaries[] = {
	6, 13, 19, 26, 33, 39, 45, 51, 58, 64, 71, 77, 83, 86, 93, 99, 102, 108,
	114, 117, 124, 130, 136, 142, 149, 155, 159, 165, 170, 176, 182, 188, 194,
	200, 206, 210, 216, 220, 226, 231, 237, 242 };

static const coeff_t modelFuncCoeffs[] = {
	157, 157, 119, 143, 69, 157, 144, 157, 140, 137, 160, 157, 151, 157, 158,
	157, 82, 157, 144, 125, 151, 157, 157, 158, 158, 145, 97, 160, 160, 157,
	160, 138, 156, 157, 103, 158, 157, 104, 157, 146, 75, 133 };
static const uint8_t modelFuncTypes[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static const neurons_size_t modelOutputNeurons[] = {
	41, 13, 30, 26, 16, 39, 37, 19, 35, 28 };

#ifdef __cplusplus
}
#endif

#endif // NEUTON_MODEL_MODEL_H

