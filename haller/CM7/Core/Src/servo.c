#include "servo.h"
#include "stm32f7xx_hal.h"
#include <math.h>

extern TIM_HandleTypeDef htim3;

void Servo_init(void){

	htim3.Instance->CCR1 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

	htim3.Instance->CCR2 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);

}

void Servo_parse(char* dataBuffer, uint8_t size){

	uint8_t num = *(uint8_t*)dataBuffer;
	dataBuffer += sizeof(num);

	float angle = *(float*)dataBuffer;
	dataBuffer += sizeof(angle);

	float val = angle*SERVO_DIFF*2/M_PI + SERVO_DEFAULT_POSITION;

	if (val < SERVO_MIN_POSITION){
		val = SERVO_MIN_POSITION;
	}

	if (val > SERVO_MAX_POSITION){
		val = SERVO_MAX_POSITION;
		}
	val = (uint16_t)val;

	switch (num){
		case 0:
			htim3.Instance->CCR1 = val;
			break;
		case 1:
			htim3.Instance->CCR2 = val;
			break;
		default:
			break;
	}
}
