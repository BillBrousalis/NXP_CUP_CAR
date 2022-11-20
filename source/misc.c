//==============================================================================
//!	misc.c
//==============================================================================
#include "includes.h"
#include "globals.h"
#include "defines.h"
#include "misc.h"
#include "base_drivers/linescan.h"
#include "base_drivers/uart.h"
#include "base_drivers/motors.h"
#include "base_drivers/servo.h"
#include "base_drivers/pot_bat.h"
#include "base_drivers/gpio.h"
#include "base_drivers/led.h"
#include "processing/peak_detector.h"
#include "processing/control.h"
#include "processing/pid.h"
#include <imu.h>



//==============================================================================
//              Pseudo-random number generator
//==============================================================================
static uint8_t a = 71;       // some initializers
static uint8_t b = 19;
static uint8_t d = 0;

//===========================================================================
//   initializes the random number generator with a seed
//===========================================================================
void mysrand(uint8_t seed) {
	d = seed;
}

//===========================================================================
//  generates a pseudo-random sequence
//===========================================================================
uint8_t myrand(uint8_t threshold) {
	uint8_t x = d;
	x = (a*x + b) % threshold;
	d = x;                                   // advance with each function call
	return(x);
}

//==============================================================================
// Variable length MAV filter with oversampling Capabillity
//==============================================================================
uint32_t MAVFilter(struct MAV *a,int32_t in,uint8_t length,uint16_t OVS)
{
  long long accu;
  uint8_t i;

  if(a->id != 0xDEAD){                                                          // MAV is used for first time -> init filter
    for(i=0;i < MAX_MAV_LENGTH;i++){
     a->filter[i] = in;
    }
    a->id = 0xDEAD;
    a->MaxTaps = length;
    a->OVS = OVS;                                                              // initialize oversampling (always >= 1)
    return(in);
  }

  if(a->MaxTaps != length)a->MaxTaps = length;
  if(a->MaxTaps > MAX_MAV_LENGTH)a->MaxTaps =  MAX_MAV_LENGTH;

  accu=0;
  if(a->cnt >= a->MaxTaps)a->cnt = 0;
  a->filter[a->cnt++] = in;
  for(i=0;i < a->MaxTaps;i++){
    accu = accu + a->filter[i];
  }
  accu/=(uint32_t)(a->MaxTaps/a->OVS);                                          // x4 oversampling
  return((int32_t)accu);                                                       // FIX ME
}

//==============================================================================
// Variable length MAV_F filter with oversampling Capabillity
//==============================================================================
float MAVF_Filter(struct MAVF *a, float in,uint8_t length,uint16_t OVS)
{
  double accu;
  uint8_t i;

  if(a->id != 0xDEAD){                                                          // MAV is used for first time -> init filter
    for(i=0;i < MAX_MAV_LENGTH;i++){
     a->filter[i] = in;
    }
    a->id = 0xDEAD;
    a->MaxTaps = length;
    a->OVS = OVS;                                                              // initialize oversampling (always >= 1)
    return(in);
  }

  if(a->MaxTaps != length)a->MaxTaps = length;
  if(a->MaxTaps > MAX_MAV_LENGTH)a->MaxTaps =  MAX_MAV_LENGTH;

  accu=0.0;
  if(a->cnt >= a->MaxTaps)a->cnt = 0;
  a->filter[a->cnt++] = in;
  for(i=0;i < a->MaxTaps;i++){
    accu = accu + (double)a->filter[i];
  }
  accu/=(float)((float)a->MaxTaps/(float)a->OVS);                               // x4 oversampling
  return((float)accu);                                                          // FIX ME
}
