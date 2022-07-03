#include "misc.h"

float fabs(float x) {
	return x >= 0 ? x : -x;
}

float max(float x, float y) {
	return x >= y ? x : y;
}

float min(float x, float y) {
	return x <= y ? x : y;
}

float map(float in, float in_low, float in_high, float out_low, float out_high) {
	return out_low + ((out_high - out_low) / (in_high - in_low)) * (in - in_low);
}

int same_sign(float x, float y) {
	return ((x >= 0.0f && y >= 0.0f) || (x <= 0.0f && y <= 0.0f)) ? 1 : 0;
}
