#include "servo.h"
#include "stm32h7xx_hal.h"
#include <math.h>

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim15;

void Servo_init(void){

	htim3.Instance->CCR1 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

	htim3.Instance->CCR2 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);

	htim3.Instance->CCR3 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);

	htim3.Instance->CCR4 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);

	htim4.Instance->CCR1 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

	htim4.Instance->CCR2 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);

	htim4.Instance->CCR3 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);

	htim4.Instance->CCR4 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4);

	htim15.Instance->CCR1 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_1);

	htim15.Instance->CCR2 = SERVO_DEFAULT_POSITION;
	HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_2);


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
		case 2:
			htim3.Instance->CCR3 = val;
			break;
		case 3:
			htim3.Instance->CCR4 = val;
			break;
		case 4:
			htim4.Instance->CCR1 = val;
			break;
		case 5:
			htim4.Instance->CCR2 = val;
			break;
		case 6:
			htim4.Instance->CCR3 = val;
			break;
		case 7:
			htim4.Instance->CCR4 = val;
			break;
		case 8:
			htim15.Instance->CCR1 = val;
			break;
		case 9:
			htim15.Instance->CCR2 = val;
			break;
		default:
			break;
	}
}
