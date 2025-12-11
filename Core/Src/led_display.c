/*
 * led_display.c
 *
 *  Created on: Nov 5, 2025
 *      Author: Admin
 */

#include "global.h"
int one_sec_tick = 0;
int is_yellow = 0;
int is_green = 0;
int is_red = 0;
void updateTrafficLight(int state) {
	if (mode == AUTO_STATE){
		HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_RESET);
		switch (road1_state){
			case NORMAL_RED:
				HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);
				break;
			case NORMAL_GREEN:
				HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
//				HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_RESET);
				break;
			case NORMAL_YELLOW:
//				HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);
				break;
			default:
				break;
		}

		HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_RESET);
		switch (road2_state){
			case NORMAL_RED:
				HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);
				break;
			case NORMAL_GREEN:
				HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
//				HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_RESET);
				break;
			case NORMAL_YELLOW:
//				HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);
				break;
			default:
				break;
		}
	}else if (mode == MANUAL_STATE || (mode == CONFIG_STATE)){
		switch (state){
			case INIT:
//				HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
//				HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
//				HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
//				HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
//				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
//				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				break;
			case BLINK_RED_GREEN:
				clearLED();
				HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_RESET);
				break;
			case BLINK_RED_YELLOW:
				clearLED();
				HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);
				break;
			case BLINK_YELLOW_RED:
				clearLED();
				HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);
				break;
			case BLINK_GREEN_RED:
				clearLED();
				HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);
				break;
			case BLINK_RED:
				if (is_red == 0){
					HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);
					is_red = 1;
				}else{
					clearLED();
					is_red = 0;
				}
				break;
			case BLINK_YELLOW:
				if (is_yellow == 0){
					HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_SET);
					is_yellow = 1;
				}else{
					clearLED();
					is_yellow = 0;
				}
				break;
			case BLINK_GREEN:
				if (is_green == 0){
					HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_RESET);
					is_green = 1;
				}else{
					clearLED();
					is_green = 0;
				}

				break;
			default:
				break;
		}
	}
}
void displayAutoTrafficLight(){
	updateTrafficLight(0);
	switch (road1_state){
		case NORMAL_RED:
//			updateLEDBuffer(1, road1_counter);
			if (t_road1 == 0){
				road1_state = NORMAL_GREEN;
//				setTimer(0, green_time * 100);
				t_road1 = green_time * 100;
				road1_counter = green_time;
//				updateLEDBuffer(1, road1_counter);
			}
			break;
		case NORMAL_GREEN:
//			updateLEDBuffer(1, road1_counter);
			if (t_road1 == 0){
				road1_state = NORMAL_YELLOW;
//				setTimer(0, yellow_time * 100);
				t_road1 = yellow_time * 100;
				road1_counter = yellow_time;
//				updateLEDBuffer(1, road1_counter);
			}
			break;
		case NORMAL_YELLOW:
//			updateLEDBuffer(1, road1_counter);
			if (t_road1 == 0){
				road1_state = NORMAL_RED;
//				setTimer(0, red_time * 100);
				t_road1 = red_time * 100;
				road1_counter = red_time;
//				updateLEDBuffer(1, road1_counter);
			}
			break;
		default:
			break;
	}
	switch (road2_state){
		case NORMAL_RED:
//			updateLEDBuffer(2, road2_counter);
			if (t_road2 == 0){
				road2_state = NORMAL_GREEN;
//				setTimer(1, green_time * 100);
				t_road2 = green_time * 100;
				road2_counter = green_time;
//				updateLEDBuffer(2, road2_counter);
			}
			break;
		case NORMAL_GREEN:
//			updateLEDBuffer(2, road2_counter);
			if (t_road2 == 0){
				road2_state = NORMAL_YELLOW;
//				setTimer(1, yellow_time * 100);
				t_road2 = yellow_time * 100;
				road2_counter = yellow_time;
//				updateLEDBuffer(2, road2_counter);
			}
			break;
		case NORMAL_YELLOW:
//			updateLEDBuffer(2, road2_counter);
			if (t_road2 == 0){
				road2_state = NORMAL_RED;
//				setTimer(1, red_time * 100);
				t_road2 = red_time * 100;
				road2_counter = red_time;
//				updateLEDBuffer(2, road2_counter);
			}
			break;
		default:
			break;
	}
}

void updateCounter(){
	if (t_1s == 0){ // Timer 3 là timer 1 giây
		t_1s = 100;
		road1_counter--;
		road2_counter--;

		one_sec_tick = 1;
	}
	if(one_sec_tick == 1){
		one_sec_tick = 0;
//		updateLEDBuffer(1, road1_counter);
//		updateLEDBuffer(2, road2_counter);
	}
}

void clearLED(){
	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, GPIO_PIN_RESET);
}

void displayBlinkTrafficLight(int state){
	switch (state){
		case BLINK_RED_GREEN:
//			if (t_blink <= 0){
////				setTimer(5,500);
//				t_blink = 500;
				updateTrafficLight(BLINK_RED_GREEN);
//			}
			break;
		case BLINK_RED_YELLOW:
//			if (t_blink <= 0){
//				t_blink = 200;
				updateTrafficLight(BLINK_RED_YELLOW);
//			}
			break;
		case BLINK_YELLOW_RED:
//			if (t_blink <= 0){
//				t_blink = 200;
				updateTrafficLight(BLINK_YELLOW_RED);
//			}
			break;
		case INIT:
			if (t_blink <= 0){
//				setTimer(5,25);
				t_blink = 25;
				updateTrafficLight(INIT);
			}
			break;
		case BLINK_GREEN_RED:
//			if (t_blink <= 0){
//				t_blink = 500;
				updateTrafficLight(BLINK_GREEN_RED);
//			}
			break;
		case BLINK_RED:
			if (t_blink <= 0){
//				setTimer(5,50);
				t_blink = 50;
				updateTrafficLight(BLINK_RED);
			}
			break;
		case BLINK_GREEN:
			if (t_blink <= 0){
//				setTimer(5,50);
				t_blink = 50;
				updateTrafficLight(BLINK_GREEN);
			}
			break;
		case BLINK_YELLOW:
			if (t_blink <= 0){
//				setTimer(5,50;
				t_blink = 50;
				updateTrafficLight(BLINK_YELLOW);
			}
			break;
		default:
			break;
	}

}
