#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f7xx_hal.h"

#define MOTOR_COUNT 5

void Motor_init();

void Motor_parse(char* dataBuffer, uint8_t size);

#endif /* INC_MOTOR_H_ */
