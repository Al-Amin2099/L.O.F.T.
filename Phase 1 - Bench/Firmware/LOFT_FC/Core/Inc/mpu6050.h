#ifndef MPU6050_H
#define MPU6050_H

#include <stdint.h>

#define MPU6050_ADDR			0x68
#define MPU6050_REG_SMPLRT_DIV		0x19
#define MPU6050_REG_CONFIG		0x1A
#define MPU6050_REG_GYRO_CONFIG		0x1B
#define MPU6050_REG_ACCEL_CONFIG	0x1C
#define MPU6050_REG_ACCEL_XOUT_H	0x3B
#define MPU6050_REG_PWR_MGMT_1		0x6B
#define MPU6050_REG_WHO_AM_I		0x75
#define MPU6050_WHO_AM_I_VALUE		0x68

typedef struct
{
	float accel_x_g;
	float accel_y_g;
	float accel_z_g;
	float accel_temp_c;
	float temp_c;
	float gyro_x_dps;
	float gyro_y_dps;
	float gyro_z_dps;
} mpu650_data_t;

/* Sensor Functions */

uint8_t mpu6050_init(void);

uint8_t mpu6050_who_am_i(uint8_t *out);

uint_t mpu6050_read_all(mpu6050_data_t *data);

#endif
