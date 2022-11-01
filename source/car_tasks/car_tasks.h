#ifndef CAR_TASKS_H_
#define CAR_TASKS_H_
//-----------------------------------------
#define BASE_SPEED			(int16_t)35
#define CAR_CONTROL_PERIOD	(pdMS_TO_TICKS(20))
//-----------------------------------------
void Housekeeping_task(void *pvParaments);
void Car_task(void *pvParameters);
void NativeControl_task(void *pvParameters);
void TestCam_task(void *pvParameters);
void LineCam_task(void *pvParameters);
void Commands_task(void *pvParameters);
void PotsBatUpdate_task(void *pvParameters);
void IMU_Task(void *pvParameters);

#endif
