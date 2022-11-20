#ifndef PID_H_
#define PID_H_

//-----------------------------------
#define TICK_SECOND	pdMS_TO_TICKS(1000)
//-----------------------------------
enum pid_control_directions {
	E_PID_DIRECT,
	E_PID_REVERSE,
};
//-----------------------------------
struct pid_controller {
	// Input, output and setpoint
	float * input; //!< Current Process Value
	float * output; //!< Corrective Output from PID Controller
	float * setpoint; //!< Controller Setpoint
	// Tuning parameters
	float Kp; //!< Stores the gain for the Proportional term
	float Ki; //!< Stores the gain for the Integral term
	float Kd; //!< Stores the gain for the Derivative term
	// Output minimum and maximum values
	float omin; //!< Maximum value allowed at the output
	float omax; //!< Minimum value allowed at the output
	// Variables for PID algorithm
	float iterm; //!< Accumulator for integral term
	float lastin; //!< Last input value for differential term
	// Operation mode
	enum pid_control_directions direction;
};
//-----------------------------------
typedef struct pid_controller *pid_ctrl;
//-----------------------------------
pid_ctrl pid_create(pid_ctrl pid, float *in, float *out, float *set, float kp, float ki, float kd, float min, float max);
void pid_compute(pid_ctrl pid);
void pid_tune(pid_ctrl pid, float kp, float ki, float kd, float dt);
void pid_limits(pid_ctrl pid, float min, float max);
void pid_direction(pid_ctrl pid, enum pid_control_directions dir);

#endif
