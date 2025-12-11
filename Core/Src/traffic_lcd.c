/*
 * traffic_lcd.c
 *
 *  Created on: Dec 9, 2025
 *      Author: Admin
 */


#include "traffic_lcd.h"

static I2C_LCD_HandleTypeDef *h_lcd;
static char lcd_buffer[20];

void Traffic_LCD_Init(I2C_LCD_HandleTypeDef *lcd_handle) {
    h_lcd = lcd_handle;
    lcd_init(h_lcd);
    lcd_clear(h_lcd);
}

void Traffic_LCD_Display_Task(void) {
    // Dòng 1: Hiển thị Mode
    lcd_gotoxy(h_lcd, 0, 0);
    switch (mode) {
        case INIT:        lcd_puts(h_lcd, "MODE: INIT      "); break;
        case AUTO_STATE:  lcd_puts(h_lcd, "MODE: AUTO      "); break;
        case MANUAL_STATE:lcd_puts(h_lcd, "MODE: MANUAL    "); break;
        case CONFIG_STATE:lcd_puts(h_lcd, "MODE: CONFIG    "); break;
        default:          lcd_puts(h_lcd, "MODE: ERROR     "); break;
    }

    // Dòng 2: Hiển thị thông số
    lcd_gotoxy(h_lcd, 0, 1);
    if (mode == AUTO_STATE) {
        sprintf(lcd_buffer, "R1:%02d  R2:%02d   ", road1_counter, road2_counter);
        lcd_puts(h_lcd, lcd_buffer);
    }
    else if (mode == MANUAL_STATE) {
        switch (manual_blink_mode) {
            case BLINK_RED_GREEN: lcd_puts(h_lcd, "MAN: RED-GRN    "); break;
            case BLINK_RED_YELLOW:lcd_puts(h_lcd, "MAN: RED-YEL    "); break;
            case BLINK_GREEN_RED: lcd_puts(h_lcd, "MAN: GRN-RED    "); break;
            case BLINK_YELLOW_RED:lcd_puts(h_lcd, "MAN: YEL-RED    "); break;
            default:              lcd_puts(h_lcd, "MAN: ---        "); break;
        }
    }
    else if (mode == CONFIG_STATE) {
        // Hiển thị giá trị đang cài đặt (temp_duration)
        switch (config_mode) {
            case CONFIG_RED:    sprintf(lcd_buffer, "CFG RED: %02d    ", temp_duration); break;
            case CONFIG_GREEN:  sprintf(lcd_buffer, "CFG GRN: %02d    ", temp_duration); break;
            case CONFIG_YELLOW: sprintf(lcd_buffer, "CFG YEL: %02d    ", temp_duration); break;
            default:            lcd_puts(h_lcd, "CFG: ???        "); break;
        }
        lcd_puts(h_lcd, lcd_buffer);
    }
}
