//==============================================================================
//!	misc.c
//==============================================================================
#include "includes.h"
//==============================================================================
//
//==============================================================================
float fabs(float x) {
	return x >= 0 ? x : -x;
}
//==============================================================================
//
//==============================================================================
float max(float x, float y) {
	return x >= y ? x : y;
}
//==============================================================================
//
//==============================================================================
float min(float x, float y) {
	return x <= y ? x : y;
}
//==============================================================================
//
//==============================================================================
float map(float in, float in_low, float in_high, float out_low, float out_high) {
	return out_low + ((out_high - out_low) / (in_high - in_low)) * (in - in_low);
}
//==============================================================================
//
//==============================================================================
int same_sign(float x, float y) {
	return ((x >= 0.0f && y >= 0.0f) || (x <= 0.0f && y <= 0.0f)) ? 1 : 0;
}

//==============================================================================
//              Pseydorandom number generator
//==============================================================================
static uint8_t a = 71;       // some initializers
static uint8_t b = 19;
static uint8_t d = 0;
//===========================================================================
//    mysrand initializes the random number generator with a seed
//===========================================================================
void mysrand(uint8_t seed) {
  d = seed;
}
//===========================================================================
//  myrand generates a pseudorandom sequence
//===========================================================================
uint8_t myrand(uint8_t threshold) {
  uint8_t x = d;
  x = (a*x + b) % threshold;
  d = x;                                   // advance with each function call
  return(x);
}
