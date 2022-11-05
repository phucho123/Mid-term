/*
 * fsm_automatic.c
 *
 *  Created on: Nov 3, 2022
 *      Author: ADMIN
 */
#include "main.h"
#include "fsm_automatic.h"
#include "display_7segment.h"


int num = 9;

void fsm_automatic_run(){
	switch(status){
		case INIT:
			setTimer1(1000);
			display_7segment(num);
			status = MODE0;
			break;
		case MODE0:
			if(timer_flag1 == 1){
				setTimer1(1000);
				if(num > 0) num--;
				HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
				display_7segment(num);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = MODE1;
				num = 0;
				display_7segment(num);
				setTimer2(5000);
			}
			break;
		case MODE1:
			if(timer_flag1 == 1){
				setTimer1(1000);
				HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
			}
			if(timer_flag2 == 1){
				status = INIT;
			}
			if(button_flag[1] == 1){
				button_flag[1] = 0;
				setTimer2(5000);
				num = (num+1)%10;
				display_7segment(num);
			}
			if(button_flag[2] == 1){
				button_flag[2] = 0;
				setTimer2(5000);
				num = (num-1+10)%10;
				display_7segment(num);
			}
			break;
		default:
			break;
	}
}