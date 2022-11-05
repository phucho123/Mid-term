/*
 * fsm_automatic.c
 *
 *  Created on: Nov 3, 2022
 *      Author: ADMIN
 */
#include "main.h"
#include "fsm_automatic.h"


int num = 9;

void fsm_automatic_run(){
	switch(status){
		case INIT:
			setTimer2(1000);
			display_7segment(num);
			status = COUNTDOWN;
			break;
		case COUNTDOWN:
			if(timer_flag2 == 1){
				setTimer2(1000);
				if(num > 0) num--;
				display_7segment(num);
			}
			if(button_flag[0] == 1){
				button_flag[0] = 0;
				status = RESETMODE;
				num = 0;
				display_7segment(num);
				setTimer3(5000);
			}
			break;
		case RESETMODE:
			if(timer_flag3 == 1){
				status = INIT;
			}
			if(button_flag[1] == 1){
				button_flag[1] = 0;
				num = (num+1)%10;
				display_7segment(num);
				setTimer3(5000);
			}
			if(button_flag[2] == 1){
				button_flag[2] = 0;
				num = (num-1+10)%10;
				display_7segment(num);
				setTimer3(5000);
			}
			if(ispressed(1)){
				setTimer2(1000);
				status = PRESSINC;
			}
			if(ispressed(2)){
				setTimer2(1000);
				status = PRESSDEC;
			}
			break;
		default:
			break;
	}
}

void fsm_button_pressed(){
	switch(status){
		case PRESSINC:
			if(ispressed(1) == 0){
				button_flag[1] = 0;
				status = RESETMODE;
				setTimer3(5000);
			}
			if(timer_flag2){
				setTimer2(1000);
				num = (num+1)%10;
				display_7segment(num);
			}
			break;
		case PRESSDEC:
			if(ispressed(2) == 0){
				button_flag[2] = 0;
				status = RESETMODE;
				setTimer3(5000);
			}
			if(timer_flag2){
				setTimer2(1000);
				num = (num-1+10)%10;
				display_7segment(num);
			}
			break;
		default:
			break;
	}
}





