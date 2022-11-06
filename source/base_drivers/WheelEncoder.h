#ifndef WHEEL_ENCODER_H_
#define WHEEL_ENCODER_H_
//------------------------
void WheelEncoderInit(void);
void WheelEncoderProcess(void);
void WrapAround(void);
void WheelEncoderGetSpeed(float *SpeedL, float *SpeedR);

extern float EstSpeedL,EstSpeedR;

#endif
