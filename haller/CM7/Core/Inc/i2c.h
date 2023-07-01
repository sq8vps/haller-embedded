#ifndef __I2C_H
#define __I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "stm32h745xx.h"

void I2C1_Master_Init(void);
void I2C1_Master_Write(uint8_t addr, uint32_t *msg, uint8_t size);
void I2C1_Master_Read(uint8_t addr, uint32_t *buf, uint8_t size);
void I2C1_GC(uint32_t *data, uint8_t size);

#ifdef __cplusplus
}
#endif

#endif

