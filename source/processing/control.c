#include "includes.h"
#include "globals.h"

void drive_control(void) {



}

/*
 * func():
 	put state machine here:
	 state certain:
		 pass calculated error to pid
		 update prev error
		 update outputs with pid_out
	 state uncertain:
	 	 pass prev error to pid
	 	 update outputs with pid_out

*/
