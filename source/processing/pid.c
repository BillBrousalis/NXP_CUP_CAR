#include "includes.h"
#include "globals.h"
#include <stdbool.h>

#include "pid.h"

pid_ctrl pid_create(pid_ctrl pid, float *in, float *out, float *set, float kp, float ki, float kd, float min, float max) {
	pid->input = in;
	pid->output = out;
	pid->setpoint = set;
	pid_limits(pid, min, max);
	pid_direction(pid, E_PID_DIRECT);
	pid->Kp = kp;
	pid->Ki = ki;
	pid->Kd = kd;
	if (pid->direction == E_PID_REVERSE) {
		pid->Kp = 0 - pid->Kp;
		pid->Ki = 0 - pid->Ki;
		pid->Kd = 0 - pid->Kd;
	}
	return pid;
}

void pid_compute(pid_ctrl pid) {
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
}

void pid_tune(pid_ctrl pid, float kp, float ki, float kd, float dt) {
	// Check for validity
	if (kp < 0 || ki < 0 || kd < 0) return;
	pid->Kp = kp;
	pid->Ki = ki * dt;
	pid->Kd = kd / dt;
	if (pid->direction == E_PID_REVERSE) {
		pid->Kp = 0 - pid->Kp;
		pid->Ki = 0 - pid->Ki;
		pid->Kd = 0 - pid->Kd;
	}
}

void pid_limits(pid_ctrl pid, float min, float max) {
	if (min >= max) return;
	pid->omin = min;
	pid->omax = max;
	//Adjust output to new limits
	if (*(pid->output) > pid->omax)
		*(pid->output) = pid->omax;
	else if (*(pid->output) < pid->omin)
		*(pid->output) = pid->omin;

	if (pid->iterm > pid->omax)
		pid->iterm = pid->omax;
	else if (pid->iterm < pid->omin)
		pid->iterm = pid->omin;
}

void pid_direction(pid_ctrl pid, enum pid_control_directions dir) {
	if (pid->direction != dir) {
		pid->Kp = (0 - pid->Kp);
		pid->Ki = (0 - pid->Ki);
		pid->Kd = (0 - pid->Kd);
	}
	pid->direction = dir;
}
