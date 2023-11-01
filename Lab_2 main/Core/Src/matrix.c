/*
 * matrix.c
 *
 *  Created on: Oct 31, 2023
 *      Author: DELL F89F
 */
#include "matrix.h"
#include "main.h"

const int MAX_LED_MATRIX = 8;

uint8_t matrix_buffer[8] = {0x00, 0xff, 0xff, 0x18, 0x18, 0xff, 0xff, 0x00};

uint16_t select_pin(int idx){
	return matrix_buffer[idx] << 8;
}

void reset_matrix(){
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
}

void set_row(){
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
}

void updateLEDMatrix(int index){
	uint16_t pin = 0x0000;
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
			pin = select_pin(index);
			HAL_GPIO_WritePin(GPIOB, pin , RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
			pin = select_pin(index);
			HAL_GPIO_WritePin(GPIOB, pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
			pin = select_pin(index);
			HAL_GPIO_WritePin(GPIOB, pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
			pin = select_pin(index);
			HAL_GPIO_WritePin(GPIOB, pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
			pin = select_pin(index);
			HAL_GPIO_WritePin(GPIOB, pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
			pin = select_pin(index);
			HAL_GPIO_WritePin(GPIOB, pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
			pin = select_pin(index);
			HAL_GPIO_WritePin(GPIOB, pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
			pin = select_pin(index);
			HAL_GPIO_WritePin(GPIOB, pin, RESET);
			break;
		default:
			break;
	}
	return;
}

void shift_matrix(){
	uint8_t tmp = matrix_buffer[7];
	for (int i = 7; i > 0; i--){
		matrix_buffer[i] = matrix_buffer[i-1];
	}
	matrix_buffer[0] = tmp;
}
