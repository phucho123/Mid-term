/*
 * software_timer.h
 *
 *  Created on: Nov 3, 2022
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void timerRun();

extern int timer_flag1;
extern int timer_flag2;
extern int timer_flag3;


#endif /* INC_SOFTWARE_TIMER_H_ */
