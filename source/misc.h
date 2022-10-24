#ifndef MISC_H_
#define MISC_H_
//------------------------------------
//#define abs(x)		(x >= 0 ? x : -x)
#define float_abs(x)		(x >= 0 ? x : -x)
//------------------------------------
#define max(x, y)	(x >= y ? x : y)
//------------------------------------
#define min(x, y) 	(x <= y ? x : y)
//------------------------------------
#define map(in, in_low, in_high, out_low, out_high) 	(out_low + ((out_high - out_low) / (in_high - in_low)) * (in - in_low))
//------------------------------------
#define same_sign(x, y)  (((x >= 0 && y >= 0) || (x <= 0 && y <= 0)) ? 1 : 0)
//------------------------------------
void mysrand(uint8_t seed);
//------------------------------------
uint8_t myrand(uint8_t threshold);

#endif
