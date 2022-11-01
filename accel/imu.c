//================================================================================
//	FXO8700 accelerometer driver
//================================================================================
#include <imu.h>
#include "peripherals.h"
#include "fsl_fxos.h"
#include "fsl_i2c_freertos.h"
#include "fsl_debug_console.h"
//================================================================================
// FXOS8700CQ I2C address
#define 	FXOS8700CQ_SLAVE_ADDR 0x1E // with pins SA0=0, SA1=0
#define 	ACCEL_INIT		0xBEEFDEAD

#define 	SCALE_2G		0.244F
#define 	SCALE_4G		0.488F
#define 	SCALE_8G		0.976F
//================================================================================
i2c_master_transfer_t acc_t;
static fxos_config_t config = {0};
static fxos_handle_t fxosHandle = {0};				// Accelerometer

static fxos_config_t fxasConfig = {0};
static fxos_handle_t fxasHandle = {0};				// Gyroscope

static float dataScale = 0;
//================================================================================
static const uint8_t g_accel_address[] = { /* different I2C device addresses, depending on SA1/SA0 Pin */
	           /* SA1 SA0 */
		0x1EU, /* 0   0 */
	//	0x1DU, /* 0   1 */
	//	0x1CU, /* 1   0 */
	//	0x1FU  /* 1   1 */
};

static const uint8_t g_gyro_address[] = { /* different I2C device addresses, depending on SA0 Pin */
	           /* SA0 */
		0x20U, /* 0 */
	//	0x21U, /* 1 */
};

//================================================================================
float	accVecX, accVecY, accVecZ;
uint32_t  Accel_Is_Init = 0;

//================================================================================
//
//================================================================================
void IMU_init(void)
{
	if(ACCEL_Init() == 0)
	{
		Accel_Is_Init = ACCEL_INIT;
	}
}
//================================================================================
//
//================================================================================
void IMU_loop(void)
{
	int	ax,ay,az;

	if(Accel_Is_Init == ACCEL_INIT)
	{
		if(ACCEL_GetAccelData(&ax, &ay, &az) == 0)
		{
			accVecX = (float)ax * dataScale;
			accVecY = (float)ay * dataScale;
			accVecZ = (float)az * dataScale;
		}
	}
}
//================================================================================
//
//================================================================================
status_t BOARD_Accel_I2C_Send(uint8_t deviceAddress, uint32_t subAddress, uint8_t subaddressSize, uint32_t txBuff)
{

	uint8_t data = (uint8_t)txBuff;


	acc_t.direction = 0;
	acc_t.data = &data;
	acc_t.dataSize = 1;
	acc_t.slaveAddress = FXOS8700CQ_SLAVE_ADDR;
	acc_t.subaddress = subAddress;
	acc_t.subaddressSize = subaddressSize;


	return( I2C_RTOS_Transfer(&I2C0_rtosHandle, &acc_t) );
}
//================================================================================
//
//================================================================================
status_t BOARD_Accel_I2C_Receive(uint8_t deviceAddress, uint32_t subAddress, uint8_t subaddressSize, uint8_t *rxBuff, uint8_t rxBuffSize)
{

		acc_t.direction = 1;
		acc_t.data = rxBuff;
		acc_t.dataSize = rxBuffSize;
		acc_t.slaveAddress = FXOS8700CQ_SLAVE_ADDR;
		acc_t.subaddress = subAddress;
		acc_t.subaddressSize = subaddressSize;

		return( I2C_RTOS_Transfer(&I2C0_rtosHandle, &acc_t) );
}

//================================================================================
//
//================================================================================
int ACCEL_Init(void) {
	uint8_t array_addr_size = 0;
	uint8_t i = 0;
	status_t result;
    uint8_t sensorRange = 0;

    config.I2C_SendFunc = BOARD_Accel_I2C_Send;
    config.I2C_ReceiveFunc = BOARD_Accel_I2C_Receive;

    /* Initialize sensor devices */
    array_addr_size = sizeof(g_accel_address) / sizeof(g_accel_address[0]);
    for (i = 0; i < array_addr_size; i++)
    {
        config.slaveAddress = g_accel_address[i];
        /* Initialize accelerometer sensor */
        result = FXOS_Init(&fxosHandle, &config);
        if (result == kStatus_Success)
        {
            break;
        }
    }

    if (result != kStatus_Success)
    {
        PRINTF("\r\nSensor device initialize failed!\r\n");
        return -1;
    }

    /* Get sensor range */
    if (FXOS_ReadReg(&fxosHandle, XYZ_DATA_CFG_REG, &sensorRange, 1) != kStatus_Success)
    {
        return -1;
    }

    if (sensorRange == 0x00)		// 2G
    {
        dataScale = SCALE_2G;
    }
    else if (sensorRange == 0x01)	// 4G
    {
        dataScale = SCALE_4G;
    }
    else if (sensorRange == 0x10)	// 8G
    {
        dataScale = SCALE_8G;
    }
    else
    {
    }
    return 0;
}
//================================================================================
//
//================================================================================
int ACCEL_GetAccelData(int *xp, int *yp, int *zp) {
    fxos_data_t sensorData = {0};
	int16_t xData, yData, zData;

	/* Get new accelerometer data. */
    if (FXOS_ReadSensorData(&fxosHandle, &sensorData) != kStatus_Success)
    {
        return -1; /* failed */
    }
    /* Get the X and Y data from the sensor data structure in 14 bit left format data*/
    xData = (int16_t)((uint16_t)((uint16_t)sensorData.accelXMSB << 8) | (uint16_t)sensorData.accelXLSB) / 4U;
    yData = (int16_t)((uint16_t)((uint16_t)sensorData.accelYMSB << 8) | (uint16_t)sensorData.accelYLSB) / 4U;
    zData = (int16_t)((uint16_t)((uint16_t)sensorData.accelZMSB << 8) | (uint16_t)sensorData.accelZLSB) / 4U;

    *xp = xData;
    *yp = yData;
    *zp = zData;
    return 0;
}

//================================================================================
//================================================================================
#if 0

int ACCEL_Init(void) {
	uint8_t array_addr_size = 0;
	uint8_t i = 0;
	status_t result;
    uint8_t sensorRange = 0;

    config.I2C_SendFunc = BOARD_Accel_I2C_Send;
    config.I2C_ReceiveFunc = BOARD_Accel_I2C_Receive;

    /* Initialize sensor devices */
    array_addr_size = sizeof(g_accel_address) / sizeof(g_accel_address[0]);
    for (i = 0; i < array_addr_size; i++)
    {
        config.slaveAddress = g_accel_address[i];
        /* Initialize accelerometer sensor */
        result = FXOS_Init(&fxosHandle, &config);
        if (result == kStatus_Success)
        {
            break;
        }
    }

    if (result != kStatus_Success)
    {
        PRINTF("\r\nSensor device initialize failed!\r\n");
        return -1;
    }

    /* Get sensor range */
    if (FXOS_ReadReg(&fxosHandle, XYZ_DATA_CFG_REG, &sensorRange, 1) != kStatus_Success)
    {
        return -1;
    }

    if (sensorRange == 0x00)		// 2G
    {
        dataScale = SCALE_2G;
    }
    else if (sensorRange == 0x01)	// 4G
    {
        dataScale = SCALE_4G;
    }
    else if (sensorRange == 0x10)	// 8G
    {
        dataScale = SCALE_8G;
    }
    else
    {
    }
    return 0;
}

#endif
