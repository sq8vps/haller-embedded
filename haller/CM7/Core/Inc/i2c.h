#ifndef __I2C_H
#define __I2C_H

#include <stdint.h>
#include "stm32h745xx.h"

/*****************************************************************************************************
* @fn 					- I2C1_Master_Init
 *
 * @brief				- Setting proper bits in control registers to initialize I2C1 as Master with enabled auto-end feature and
 * 						7-bit addressing mode
 *
 * @param[in]			- none
 *
 * @return				- none
 *
 * @Note				- none
 *
 *****************************************************************************************************/
void I2C1_Master_Init(void);
/*****************************************************************************************************
* @fn 					- I2C1_Master_Write
 *
 * @brief				- Send up to 4 bytes to slave device of known address.
 *
 * @param[in]			- slave address
 * @param[in]			- pointer to the message buffer
 * @param[in]			- size of message in bytes
 * @param[in]			-
 *
 * @return				- none
 *
 * @Note				- none
 *
 *****************************************************************************************************/
void I2C1_Master_Write(uint8_t addr, uint32_t *msg, uint8_t size);
/*****************************************************************************************************
* @fn 					- I2C1_Master_Read
 *
 * @brief				- Receive up to 4 bytes from slave device of known address.
 *
 * @param[in]			- slave address
 * @param[in]			- pointer to the buffer where the data will be stored
 * @param[in]			- size of data to be read in bytes
 * @param[in]			-
 *
 * @return				- none
 *
 * @Note				- none
 *
 *****************************************************************************************************/
void I2C1_Master_Read(uint8_t addr, uint32_t *buf, uint8_t size);
/*****************************************************************************************************
* @fn 					- I2C1_GC
 *
 * @brief				- General call function, writing to all devices connected to i2c1 bus.
 *
 * @param[in]			- pointer to the message buffer
 * @param[in]			- size of message in bytes
 * @param[in]			-
 *
 * @return				- none
 *
 * @Note				- none
 *
 *****************************************************************************************************/
void I2C1_GC(uint32_t *data, uint8_t size);

#endif /* __I2C_H */
