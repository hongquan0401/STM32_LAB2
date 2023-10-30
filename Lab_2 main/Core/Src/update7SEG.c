/*
 * update7SEG.c
 *
 *  Created on: 28 thg 10, 2023
 *      Author: DELL F89F
 */

#include "display_7seg.h"
#include "update7SEG.h"
#include "main.h"

int clock_buffer[4] = {0, 0, 0, 0};
int hour = 6, min = 3, sec = 50;
void update7seg(int idx) {
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	updateClockBuffer();
	switch (idx) {
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			display(clock_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			display(clock_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			display(clock_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			display(clock_buffer[3]);
			break;
		default:
			break;
	}
}

void updateClockBuffer(){
	clock_buffer[0] = hour / 10;
	clock_buffer[1] = hour % 10;
	clock_buffer[2] = min / 10;
	clock_buffer[3] = min % 10;
}
