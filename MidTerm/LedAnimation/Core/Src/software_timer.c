/*
 * software_timer.c
 *
 *  Created on: Nov 3, 2022
 *      Author: ADMIN
 */

#include "software_timer.h"
#define TICK 10

int timer_flag1 = 0;
int timer_cnt1 = 0;

int timer_flag2 = 0;
int timer_cnt2 = 0;

int timer_flag3 = 0;
int timer_cnt3 = 0;

void setTimer1(int duration){
	timer_cnt1 = duration/TICK;
	timer_flag1 = 0;
}
void setTimer2(int duration){
	timer_cnt2 = duration/TICK;
	timer_flag2 = 0;
}
void setTimer3(int duration){
	timer_cnt3 = duration/TICK;
	timer_flag3 = 0;
}
void timerRun(){
	if(timer_cnt1>0){
		timer_cnt1--;
		if(timer_cnt1<=0){
			timer_flag1 = 1;
		}
	}
	if(timer_cnt2 > 0){
		timer_cnt2--;
		if(timer_cnt2<=0){
			timer_flag2 = 1;
		}
	}
	if(timer_cnt3 > 0){
		timer_cnt3--;
		if(timer_cnt3 <= 0){
			timer_flag3 = 1;
		}
	}
}
