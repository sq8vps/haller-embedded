#include "../Inc/i2c.h"

void I2C1_Init(void){
	I2C1->CR1 &= ~(1<<0); //Ensure software reset for I2C1
	RCC->APB1LENR |= (1<<21); //I2C1EN peripheral clock enable
	RCC->AHB4ENR |= (1<<1); //GPIOB clock enable
	GPIOB->MODER |= ( (2<<12) | (2<<14) ); //Enable alternate function for PB6 and PB7
	GPIOB->OTYPER |= ( (1<<6) | (1<<7) ); //Configure PB6 and PB7 to work as open-drain
	GPIOB->OSPEEDR |= ( (3<<12) | (3<<14) ); //Set output speed of PB6 and PB7 as very high
	//GPIOB->PUPDR |= ( (1<<12) | (1<<14) ); //Enable pull-up resistors for PB6 and PB7 // is this done externally?
	GPIOB->AFR[0] |= ( (4<<24) | (4<<28) ); //Set alternate function as I2C1 for pins PB6 and PB7 (SCL and SDA)
	I2C1->TIMINGR |= 0x307075B1; //Set I2C speed frequency to 100kHz (max in standard mode)
	I2C1->CR1 |= (1<<0); //Enable I2C
}
