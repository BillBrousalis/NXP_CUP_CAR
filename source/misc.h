#pragma once
//----------------------
float fabs(float x);
//----------------------
float fmax(float x, float y);
int16_t max(int16_t x, int16_t y);
//----------------------
float fmin(float x, float y);
int16_t min(int16_t x, int16_t y);
//----------------------
float fmap(float in, float in_low, float in_high, float out_low, float out_high);
int16_t map(int16_t in, int16_t in_low, int16_t in_high, int16_t out_low, int16_t out_high);
//----------------------
int fsame_sign(float x, float y);
int same_sign(int16_t x, int16_t y);
//----------------------
void mysrand(uint8_t seed);
//----------------------
uint8_t myrand(uint8_t threshold);
