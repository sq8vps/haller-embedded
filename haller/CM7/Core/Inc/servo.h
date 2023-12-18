#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include <stdint.h>

/* Pin configuration:
 * TIM3:
 * 	CH1 - PC6
 * 	CH2 - PC7
 * 	CH3 - PC8
 * 	CH4 - PC9
 * TIM4:
 * 	CH1 - PD12
 * 	CH2 - PD13
 * 	CH3 - PD14
 * 	CH4 - PD15
 * TIM15:
 * 	CH1 - PE5
 * 	CH2 - PE6
 */

#define SERVO_DEFAULT_POSITION 150
#define SERVO_MIN_POSITION 50
#define SERVO_MAX_POSITION 250
#define SERVO_DIFF (SERVO_MAX_POSITION - SERVO_DEFAULT_POSITION)

void Servo_init(void);

void Servo_parse(char* dataBuffer, uint8_t size);

#endif /* INC_SERVO_H_ */
