/*
 * global.c
 *
 *  Created on: Nov 5, 2025
 *      Author: Admin
 */
#include "global.h"

int mode = INIT;
int red_time = 9, green_time = 6, yellow_time = 3;
int road1_state = NORMAL_RED, road2_state = NORMAL_GREEN;
int road1_counter, road2_counter;
int manual_blink_mode = INIT;
int config_mode = CONFIG_RED;
int counter = 0;
int temp_duration = 0;

int keyReg0[MAX_BUTTON];
int keyReg1[MAX_BUTTON];
int keyReg2[MAX_BUTTON];
int keyReg3[MAX_BUTTON];
int longPressedTime[MAX_BUTTON];
int button_flag[MAX_BUTTON];
int button_long_flag[MAX_BUTTON];

int t_road1 = 0;
int t_road2 = 0;
int t_1s = 100;
int t_blink = 0;
