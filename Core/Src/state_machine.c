/*
 * state_machine.c
 *
 *  Created on: Nov 5, 2025
 *      Author: Admin
 */

#include "global.h"
//int temp_duration;

void fsm_run(){
	updateCounter();
	switch (mode){
		case INIT:
			mode = AUTO_STATE;
			t_road1 = red_time * 100;
			t_road2 = green_time * 100;
			t_1s = 100;
			t_blink = 50;
			road1_counter = red_time;
			road2_counter = green_time;
			break;
		case AUTO_STATE:
			displayAutoTrafficLight(0);
			if(isButtonPressed(0)){
				mode = MANUAL_STATE;
				manual_blink_mode = BLINK_RED_GREEN;
				t_blink = 500;
				clearLED();
				break;
			}
			break;
		case MANUAL_STATE:
			switch (manual_blink_mode){
				case BLINK_RED_GREEN:
					if (manual_blink_mode != BLINK_RED_GREEN){
						manual_blink_mode = BLINK_RED_GREEN;
					}
					if(isButtonPressed(1)){
						manual_blink_mode = BLINK_RED_YELLOW;
						t_blink = 300;
						break;
					}
					break;
				case BLINK_RED_YELLOW:
					if(t_blink <= 0){
						manual_blink_mode = BLINK_GREEN_RED;
						t_blink  = 500;
						break;
					}
					break;
				case BLINK_GREEN_RED:
					if (manual_blink_mode != BLINK_GREEN_RED){
						manual_blink_mode = BLINK_GREEN_RED;
					}
					if(isButtonPressed(1)){
						manual_blink_mode = BLINK_YELLOW_RED;
						t_blink = 300;
						break;
					}
					break;
				case BLINK_YELLOW_RED:
					if(t_blink <= 0){
						manual_blink_mode = BLINK_RED_GREEN;
						t_blink  = 500;
						break;
					}
					break;
				default:
					break;

			}
			displayBlinkTrafficLight(manual_blink_mode);
			if (isButtonPressed(0)){
				mode = CONFIG_STATE;
				config_mode = CONFIG_RED;
				manual_blink_mode = BLINK_RED;
				t_blink = 50;
				clearLED();
				temp_duration = red_time;
				break;
			}
			break;
		case CONFIG_STATE:{
			switch (config_mode){
				case CONFIG_RED:
					if (manual_blink_mode != BLINK_RED){
						manual_blink_mode = BLINK_RED;
						clearLED();
					}
					displayBlinkTrafficLight(manual_blink_mode);
					if (isButtonPressed(1)){
						temp_duration++;
						if (temp_duration > 99){
							temp_duration = 0;
						}
					}
					if (isButtonPressed(2)){
						temp_duration--;
						if (temp_duration < 0){
							temp_duration = 99;
						}
					}
					if (isButtonPressed(3)){
						red_time = temp_duration;
						break;
					}
					if (isButtonPressed(0)){
						config_mode = CONFIG_GREEN;
						manual_blink_mode = BLINK_GREEN;
						temp_duration = green_time;
						t_blink = 50;
						clearLED();
						break;
					}
					break;
				case CONFIG_GREEN:
					if (manual_blink_mode != BLINK_GREEN){
						manual_blink_mode = BLINK_GREEN;
						clearLED();
					}
					displayBlinkTrafficLight(manual_blink_mode);
					if (isButtonPressed(1)){
						temp_duration++;
						if (temp_duration > 99){
							temp_duration = 0;
						}
					}
					if (isButtonPressed(2)){
						temp_duration--;
						if (temp_duration < 0){
							temp_duration = 99;
						}
					}
					if (isButtonPressed(3)){
						green_time = temp_duration;
						break;
					}
					if (isButtonPressed(0)){
						config_mode = CONFIG_YELLOW;
						temp_duration = yellow_time;
						manual_blink_mode = BLINK_YELLOW;
						t_blink = 50;
						clearLED();
						break;
					}
					break;
				case CONFIG_YELLOW:
					if (manual_blink_mode != BLINK_YELLOW){
						manual_blink_mode = BLINK_YELLOW;
						clearLED();
					}
					displayBlinkTrafficLight(manual_blink_mode);
					if (isButtonPressed(1)){
						temp_duration++;
						if (temp_duration > 99){
							temp_duration = 0;
						}
					}
					if (isButtonPressed(2)){
						temp_duration--;
						if (temp_duration < 0){
							temp_duration = 99;
						}
					}
					if (isButtonPressed(3)){
						yellow_time = temp_duration;

						break;
					}
					if (isButtonPressed(0)){
						mode = AUTO_STATE;
						road1_counter = red_time;
						road2_counter = green_time;
						road1_state = NORMAL_RED;
						road2_state = NORMAL_GREEN;
						t_road1 = red_time * 100;
						t_road2 = green_time * 100;
						updateTrafficLight(0);
						break;
					}
					break;
				default:
					break;
			}
			break;
		}
		default:
			break;

	}
}
