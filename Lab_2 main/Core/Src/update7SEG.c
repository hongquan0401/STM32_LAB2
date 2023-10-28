/*
 * update7SEG.c
 *
 *  Created on: 28 thg 10, 2023
 *      Author: DELL F89F
 */

#include "display_7seg.h"
#include "update7SEG.h"
#include "main.h"

int led_buffer[4] = {1, 2, 3, 4};

void update7seg(int idx) {
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	switch (idx) {
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			display(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			display(led_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			display(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			display(led_buffer[3]);
			break;
		default:
			break;
	}
}
