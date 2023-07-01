#include "../Inc/i2c.h"

#define PE_EN (1<<0)
#define I2C1_EN (1<<21)
#define GPIOB_EN (1<<1)
#define ALT_MODE_EN (2<<12) | (2<<14)
#define OPEN_DRAIN_EN (1<<6) | (1<<7)
#define PIN_SPEED_VH (3<<12) | (3<<14)
#define PULL_UP (1<<12) | (1<<14)
#define ALT_MODE_I2C (4<<24) | (4<<28)
#define I2C_FREQ (0x307075B1U) 					//100kHz generated by STM32CubeMX tool
#define AUTOEND_EN (1<<25)
#define ADD10 (1<<11)
#define I2C_START (1<<13)

typedef enum Direction {WRITE, READ}Direction;

void I2C1_Master_Init(void){
	I2C1->CR1 &= ~PE_EN; 						//Ensure software reset for I2C1
	RCC->APB1LENR |= I2C1_EN; 					//Peripheral clock enable for I2C1
	RCC->AHB4ENR |= GPIOB_EN; 					//GPIOB clock enable
	GPIOB->MODER |= ALT_MODE_EN; 				//Enable alternate function for PB6 and PB7
	GPIOB->OTYPER |= OPEN_DRAIN_EN; 			//Configure PB6 and PB7 to work as open-drain
	GPIOB->OSPEEDR |= PIN_SPEED_VH; 			//Set output speed of PB6 and PB7 as very high
	//GPIOB->PUPDR |= PULL_UP; 					//Enable pull-up resistors for PB6 and PB7 // is this done externally?
	GPIOB->AFR[0] |= ALT_MODE_I2C; 				//Set alternate function as I2C1 for pins PB6 and PB7 (SCL and SDA)
	I2C1->TIMINGR |= I2C_FREQ; 					//Set I2C1 speed frequency
	I2C1->CR1 |= PE_EN;	 						//Enable I2C1

	I2C1->CR2 |= AUTOEND_EN;					//Enable auto-end feature
	I2C1->CR2 &= ~ADD10;						//7-bit addressing mode
}

void I2C1_Start(Direction dir, uint8_t addr, uint8_t size){
	I2C1->CR2 &= 0x00; 							//Clear address. //Disc. CR2 bit0 is don't care
	I2C1->CR2 |= addr<<1;						//Set slave address
	I2C1->CR2 |= size<<16;						//Number of bytes to read/write
	if(dir == WRITE) I2C1->CR2 &= ~(1<<10);		//Write Request
	else if (dir == READ) I2C1->CR2 |= 1<<10;	//Read request
	I2C1->CR2 |= I2C_START;						//Start communication
}

void I2C1_Master_Write(uint8_t addr, uint32_t *msg, uint8_t size){
	I2C1_Start(WRITE, addr, size);
	for(uint8_t stage=0;stage<size;stage++){	//Writing remaining bytes
		while( !(I2C1->ISR & (1<<0) ) );
		I2C1->TXDR = (*msg) & ( 0xFF<<(stage*8) );
	}
	//Automatic end mode closes transmission after NBYTES are sent
}

void I2C1_Master_Read(uint8_t addr, uint32_t *buf, uint8_t size){
	I2C1_Start(READ, addr, size);
	for(uint8_t stage=0;stage<size;stage++){	//Reading remaining bytes
		while( !(I2C1->ISR & (1<<2) ) );
		*buf = (I2C1->TXDR)<<(stage*8);
	}
	//Automatic end mode closes transmission after NBYTES are read
}

void I2C1_GC(uint32_t *data, uint8_t size){
	I2C1_Master_Write(0x00, data, size);		//I2C1 general call function
}



