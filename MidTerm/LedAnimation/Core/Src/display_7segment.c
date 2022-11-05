/*
 * display_7segment.c
 *
 *  Created on: Nov 4, 2022
 *      Author: ADMIN
 */

#include "display_7segment.h"

int arr[10] = {
	0x00C0,  //0
	0x00F9,  //1
	0x00A4,  //2
	0x00B0,  //3
	0x0099,  //4
	0x0092,  //5
	0x0082,  //6
	0x00F8,  //7
	0x0080,  //8
	0x0090,  //9
};

void display_7segment(int num){
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,(arr[num]>>0)&0x01);
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,(arr[num]>>1)&0x01);
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,(arr[num]>>2)&0x01);
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,(arr[num]>>3)&0x01);
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,(arr[num]>>4)&0x01);
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,(arr[num]>>5)&0x01);
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,(arr[num]>>6)&0x01);
	GPIOB->ODR = arr[num];
}
