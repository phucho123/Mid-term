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
			setTimer2(1000); //set timer2 1s for counting down every 1s
			display_7segment(num); //display num in led 7
			status = COUNTDOWN; //set status to COUNTDOWN STATE
			break;
		case COUNTDOWN:
			if(timer_flag2 == 1){
				setTimer2(1000); //set timer2 to 1s again
				if(num > 0) num--; // value of led 7 counting down every 1s
				display_7segment(num); //display num in led 7
			}
			if((button_flag[0] == 1) || (button_flag[1] == 1) || (button_flag[2] == 1)){
				status = SETTIME; //set status to SETTIME STATE if have button down
				setTimer3(10000); //set timer3 to 10s for if not have button down in SETTIME STATE then status return to COUNTDOWN STATE
			}
			break;
		case SETTIME:
			if(timer_flag3 == 1){
				status = INIT; //if after 10s not have button down or pressed then return to INIT and go to COUNTDOWN
			}
			if(button_flag[0] == 1){ //button RESET down
				button_flag[0] = 0; //set button flag to 0
				num = 0; // set value of led 7 to 0
				display_7segment(num); //display num in led 7
				setTimer3(10000); //set timer3 to 10s again because just have button RESET down
			}
			if(button_flag[1] == 1){ //button INC down
				button_flag[1] = 0; //set button INC flag to 0
				num = (num+1)%10; //increase value of num
				display_7segment(num); //display num in led 7
				setTimer3(10000); //set timer3 to 10s again because just have button INC down
			}
			if(button_flag[2] == 1){ //button DEC down
				button_flag[2] = 0; //set button DEC flag to 0
				num = (num-1+10)%10; // decrease value of num
				display_7segment(num); //display num in led 7
				setTimer3(10000); //set timer3 to 10s again because just have button DEC down
			}
			if(ispressed(1)){ //if button INC is pressed over 3s
				setTimer2(1000); //set timer2 to 1s for increase num every 1s in pressed state
				status = PRESSED_INC; //set status to pressed inc state
			}
			if(ispressed(2)){ //if button DEC is pressed over 3s
				setTimer2(1000); //set timer2 to 1s for decrease num every 1s in pressed state
				status = PRESSED_DEC; //set status to pressed dec state
			}
			break;
		default:
			break;
	}
}

void fsm_button_pressed(){
	switch(status){
		case PRESSED_INC: //pressed inc button state
			if(ispressed(1) == 0){ //if not press button INC
				button_flag[1] = 0; //set button INC flag to 0
				status = SETTIME; //set status to SETTIME state
				setTimer3(10000); //set timer3 to 10s again because we just release button
			}
			if(timer_flag2){ //if have timer2 flag
				setTimer2(1000); //set timer to 1s
				num = (num+1)%10; //num increase every 1s
				display_7segment(num); //display in led7
			}
			break;
		case PRESSED_DEC: //pressed dec button state
			if(ispressed(2) == 0){ //if not press button DEC
				button_flag[2] = 0; //set button DEC flag to 0
				status = SETTIME; //set status to SETTIME state
				setTimer3(10000); //set timer3 to 10s again because we just release button
			}
			if(timer_flag2){ //if have timer2 flag
				setTimer2(1000); //set timer to 1s
				num = (num-1+10)%10; //num decrease every 1s
				display_7segment(num); //display in led7
			}
			break;
		default:
			break;
	}
}






