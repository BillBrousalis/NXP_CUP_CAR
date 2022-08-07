//===========================================================================================
//!		defines.h
//===========================================================================================
#define IDLE_TASK_PRIO 		(configMAX_PRIORITIES - 4)
#define LOW_TASK_PRIO 		(configMAX_PRIORITIES - 3)
#define DEFAULT_TASK_PRIO 	(configMAX_PRIORITIES - 2)
#define MAX_TASK_PRIO 		(configMAX_PRIORITIES - 1)
//===========================================================================================
#define         GetSystemTimer  	xTaskGetTickCount
#define			osDelay(r)			vTaskDelay(pdMS_TO_TICKS(r))
//===========================================================================================
//===========================================================================================
