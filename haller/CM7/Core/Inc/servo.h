#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "stm32f7xx_hal.h"

#define SERVO_DEFAULT_POSITION 75
#define SERVO_MIN_POSITION 25
#define SERVO_MAX_POSITION 125
#define SERVO_DIFF (SERVO_MAX_POSITION - SERVO_DEFAULT_POSITION)

void Servo_init(void);

void Servo_parse(char* dataBuffer, uint8_t size);

#endif /* INC_SERVO_H_ */
