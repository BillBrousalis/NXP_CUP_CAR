//================================================================================================
//
//================================================================================================
// Time base 15625 Hz    FTM1   64uS/timer tick
//	Wheel circumference -> 21cm -> 0.21m
//	Encoder resolution -> 8 PPR  -> 26.25mm / pulse
//  1km -> 4762 revolutions -> ~38100 pulses
//  1km/hour ~10.5 Pulses/sec
//  Usable encoder range 110mS -> 7mS period
//  7mS -> 140Hz
//  140Hz = 13.2 Km/h
//================================================================================================
#include "includes.h"
#include "globals.h"
#include "base_drivers/gpio.h"
#include "base_drivers/WheelEncoder.h"
#include "fsl_ftm.h"
//================================================================================================
#define	 WHEEL_CIRC			0.21F							// Wheel diameter in meters
#define  ENCODER_PPR		8.0F							// encoder pulses per revolution
#define	 WHEEL_STEP			(WHEEL_CIRC / ENCODER_PPR)		//
#define	 TIME_PER_TICK		0.000064						// 64uS/tick
#define  MAX_PPS			2000							// Maximum number of count expected at minimum speed - Lower than that is considered zero speed
#define	 SPEED_FLTR_LEN		3								// Speed averaging filter length -
//================================================================================================
uint32_t     RealPosLeft, RealPosRight;
uint32_t	 EstTimeL,EstTimeR;
float        EstSpeedL,EstSpeedR;
uint32_t 	 EncWrapTimes = 0;

int32_t cntL,cntR;
static int32_t cntm1L,cntm1R;
//================================================================================================
uint32_t arrVL[SPEED_FLTR_LEN];
uint32_t arrVR[SPEED_FLTR_LEN];
//================================================================================================
//
//================================================================================================
void WheelEncoderInit(void)
{
	RealPosLeft = 0;
	RealPosRight = 0;
	EstSpeedL = 0.0;
	EstSpeedR = 0.0;
	EstTimeL = 0;
	EstTimeR = 0;
	EncWrapTimes = 0;
}
//================================================================================================
//
//================================================================================================
void WheelEncoderProcess(void)
{
	uint32_t tmpV,i;

	static uint32_t iL,iR;
	uint32_t tmp = GPIO_PortGetInterruptFlags(BOARD_INITPINS_MOTA_ENC_GPIO);		// Get port interrupt mask - If there is a pending encoder state change, it is flagged here

    //-------------------------------------------------------
	//  Check the case of previous zero speed
	if( EncWrapTimes > 1)															// Counter wrapped around more than once due to long waiting time - calculations are invalid
	{
		EncWrapTimes = 0;
		for(i = 0;i < SPEED_FLTR_LEN; i++)
		{
			arrVL[i] = 0;															// Filter values are meaningless after wrap
			arrVR[i] = 0;
		}
		tmpV = FTM_GetCurrentTimerCount(FTM1_PERIPHERAL);							// Get current free running timer count
		cntm1L = tmpV; 																// Invalidate previous count since it is invalid anyway
		cntm1R = tmpV;
		EstSpeedL = 0.0;
		EstSpeedR = 0.0;

		return;
	}

	EncWrapTimes = 0;

	//------------ MOTOR A -------
	if(tmp & BOARD_INITPINS_MOTA_ENC_GPIO_PIN_MASK)								// MOTA has stepped
	{
		RealPosLeft++;															// increase position accumulator
		cntL = FTM_GetCurrentTimerCount(FTM1_PERIPHERAL);						// Get current free running timer count
		if(cntL >= cntm1L)														// if current less than previous then counter was wrapped around 0xFFFF
		{
			tmpV = cntL - cntm1L;												// Time elapsed since last step
		}
		else
		{
			tmpV = (65535 - cntm1L) + cntL;
		}
		cntm1L = cntL;

		//-------- MAV filter -----------
		if(iL >= SPEED_FLTR_LEN)iL = 0;
		arrVL[iL++] = tmpV;
		tmpV = 0;
		for(i = 0;i < SPEED_FLTR_LEN; i++)
		{
			tmpV+=arrVL[i];
		}

		//-------- Speed is too low - considered zero
		if(tmpV > MAX_PPS) tmpV = MAX_PPS;

		EstTimeL  = tmpV / SPEED_FLTR_LEN;
	}

	//------------ MOTOR B -------
	if(tmp & BOARD_INITPINS_MOTB_ENC_GPIO_PIN_MASK)
	{
		RealPosRight++;
		cntR = FTM_GetCurrentTimerCount(FTM1_PERIPHERAL);
		if(cntR >= cntm1R)
		{
			tmpV = cntR - cntm1R;
		}
		else
		{
			tmpV = (65535 - cntm1R) + cntR;
		}
		cntm1R = cntR;

		if(iR >= SPEED_FLTR_LEN)iR = 0;
		arrVR[iR++] = tmpV;
		tmpV = 0;
		for(i = 0;i < SPEED_FLTR_LEN; i++)
		{
			tmpV+=arrVR[i];
		}

		if(tmpV > MAX_PPS) tmpV = MAX_PPS;

		EstTimeR  = tmpV / SPEED_FLTR_LEN;

	}
}
//================================================================================================
//
//================================================================================================
void WrapAround(void)
{
	EncWrapTimes++;
	if(EncWrapTimes > 1) {
		EstSpeedR = 0.0;
		EstSpeedL = 0.0;
	}
}
//================================================================================================
//		Return the car wheels speed in m/s
//================================================================================================
void WheelEncoderGetSpeed(float *SpeedL, float *SpeedR)
{
	if(EstTimeL != 0) {												// avoid the possible divison by zero
		*SpeedL = WHEEL_STEP/ (TIME_PER_TICK * (float)EstTimeL);
	}
	else {
		EstSpeedL = 0.0;
	}

	if(EstTimeR != 0) {
		*SpeedR = WHEEL_STEP/ (TIME_PER_TICK * (float)EstTimeR);
	}
	else {
		EstSpeedR = 0.0;
	}
}

//================================================================================================
//================================================================================================
