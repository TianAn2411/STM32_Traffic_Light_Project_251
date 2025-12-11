/*
 * led_display.h
 *
 *  Created on: Dec 11, 2025
 *      Author: Admin
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "global.h"

void updateTrafficLight(int state);
void displayAutoTrafficLight();
void displayBlinkTrafficLight(int state);
void displayTime();
void updateCounter();
void clearLED();

#endif /* INC_LED_DISPLAY_H_ */
