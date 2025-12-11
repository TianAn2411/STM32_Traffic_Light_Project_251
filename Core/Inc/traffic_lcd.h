/*
 * traffic_lcd.h
 *
 *  Created on: Dec 9, 2025
 *      Author: Admin
 */

#ifndef INC_TRAFFIC_LCD_H_
#define INC_TRAFFIC_LCD_H_

#include "i2c_lcd.h"
#include "global.h"
#include <stdio.h>

void Traffic_LCD_Init(I2C_LCD_HandleTypeDef *lcd_handle);
void Traffic_LCD_Display_Task(void);

#endif
