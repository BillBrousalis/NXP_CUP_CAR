#include "includes.h"
#include "globals.h"
#include <stdbool.h>

#include "pid.h"

pid_ctrl pid_create(pid_ctrl pid, float* in, Drive_PID *pid_params) {
	pid->input = in;
	pid->output = &pid_params->out;
	pid->setpoint = &pid_params->setpoint;
	pid->automode = true;

	pid_limits(pid, pid_params->min, pid_params->max);
	pid->sampletime = pid_params->dt;
	pid_direction(pid, E_PID_DIRECT);
	pid_tune(pid, pid_params->kp, pid_params->ki, pid_params->kd, pid_params->dt);
	return pid;
}

// no need to call
/*
bool pid_need_compute(pid_ctrl pid) {
	// Check if the PID period has elapsed
	return(tick_get() - pid->lasttime >= pid->sampletime) ? true : false;
}
*/

void pid_compute(pid_ctrl pid) {
	// Check if control is enabled
	//if (!pid->automode)
	//	return false;

	float in = *(pid->input);
	// Compute error
	float error = (*(pid->setpoint)) - in;
	// Compute integral
	pid->iterm += (pid->Ki * error);
	if (pid->iterm > pid->omax)
		pid->iterm = pid->omax;
	else if (pid->iterm < pid->omin)
		pid->iterm = pid->omin;
	// Compute differential on input
	float dinput = in - pid->lastin;
	// Compute PID output
	float out = pid->Kp * error + pid->iterm - pid->Kd * dinput;
	// Apply limit to output value
	if (out > pid->omax)
		out = pid->omax;
	else if (out < pid->omin)
		out = pid->omin;
	// Output to pointed variable
	(*pid->output) = out;
	// Keep track of some variables for next execution
	pid->lastin = in;
	//pid->lasttime = tick_get();;
}

void pid_tune(pid_ctrl pid, float kp, float ki, float kd, float dt) {
	// Check for validity
	if (kp < 0 || ki < 0 || kd < 0)
		return;

	//Compute sample time in seconds
	//float ssec = ((float) pid->sampletime) / ((float) TICK_SECOND);
	float ssec = dt;

	pid->Kp = kp;
	pid->Ki = ki * ssec;
	pid->Kd = kd / ssec;

	if (pid->direction == E_PID_REVERSE) {
		pid->Kp = 0 - pid->Kp;
		pid->Ki = 0 - pid->Ki;
		pid->Kd = 0 - pid->Kd;
	}
}

void pid_sample(pid_ctrl pid, uint32_t time) {
	if (time > 0) {
		float ratio = (float) (time * (TICK_SECOND / 1000)) / (float) pid->sampletime;
		pid->Ki *= ratio;
		pid->Kd /= ratio;
		pid->sampletime = time * (TICK_SECOND / 1000);
	}
}

void pid_limits(pid_ctrl pid, float min, float max) {
	if (min >= max) return;
	pid->omin = min;
	pid->omax = max;
	//Adjust output to new limits
	if (pid->automode) {
		if (*(pid->output) > pid->omax)
			*(pid->output) = pid->omax;
		else if (*(pid->output) < pid->omin)
			*(pid->output) = pid->omin;

		if (pid->iterm > pid->omax)
			pid->iterm = pid->omax;
		else if (pid->iterm < pid->omin)
			pid->iterm = pid->omin;
	}
}
/*
void pid_auto(pid_ctrl pid) {
	// If going from manual to auto
	if (!pid->automode) {
		pid->iterm = *(pid->output);
		pid->lastin = *(pid->input);
		if (pid->iterm > pid->omax)
			pid->iterm = pid->omax;
		else if (pid->iterm < pid->omin)
			pid->iterm = pid->omin;
		pid->automode = true;
	}
}
*/

void pid_manual(pid_ctrl pid) {
	pid->automode = false;
}

void pid_direction(pid_ctrl pid, enum pid_control_directions dir) {
	if (pid->automode && pid->direction != dir) {
		pid->Kp = (0 - pid->Kp);
		pid->Ki = (0 - pid->Ki);
		pid->Kd = (0 - pid->Kd);
	}
	pid->direction = dir;
}
