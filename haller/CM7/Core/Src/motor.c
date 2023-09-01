#include "motor.h"
#include "i2c.h"
#include "stm32f7xx_hal.h"

void Motor_init(){
	I2C1_Master_Init();

	float data[MOTOR_COUNT] = {0};

	I2C1_Master_Write(0x00, data, 4*MOTOR_COUNT);
};

void Motor_parse(char* dataBuffer, uint8_t size){

	I2C1_Master_Write(0x00, dataBuffer, size);

};
