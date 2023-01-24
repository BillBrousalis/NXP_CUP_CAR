#ifndef MISC_H_
#define MISC_H_
//------------------------------------
//#define abs(x)		(x >= 0 ? x : -x)
#define float_abs(x) 	(x >= 0 ? x : -x)
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


//==============================================================================
#define         MAX_MAV_LENGTH          16
//==============================================================================
struct MAV{
  uint8_t MaxTaps;
  uint8_t cnt;
  int32_t filter[MAX_MAV_LENGTH];
  uint16_t OVS;                         // oversampling
  uint16_t id;
};

struct MAVF{
  uint8_t MaxTaps;
  uint8_t cnt;
  float filter[MAX_MAV_LENGTH];
  uint16_t OVS;                         // oversampling
  uint16_t id;
};

#define MAVINIT   0xDEAD

#endif
