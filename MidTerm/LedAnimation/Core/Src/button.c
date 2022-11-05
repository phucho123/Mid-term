/*
 * button.c
 *
 *  Created on: Nov 3, 2022
 *      Author: ADMIN
 */

#include "button.h"

int KeyReg0[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[3] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};


int button_flag[3] = {0,0,0};
int is_pressed[3] = {0,0,0};
int Timeout[3] = {0,0,0};

int ispressed(int index){
	return is_pressed[index];
}

void getKeyInput(){
	for(int i = 0;i<3;i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		if(i == 0){
			KeyReg0[i] = HAL_GPIO_ReadPin(Button1_GPIO_Port,Button1_Pin);
		}
		else if(i == 1){
			KeyReg0[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port,Button2_Pin);
		}
		else{
			KeyReg0[i] = HAL_GPIO_ReadPin(Button3_GPIO_Port,Button3_Pin);
		}
		if((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg3[i] == PRESSED_STATE){
					Timeout[i] = 300;
					button_flag[i] = 1;
				}
				else{
					is_pressed[i] = 0; //release button
					button_flag[i] = 0;
				}
			}
			else{
				if(Timeout[i] > 0){
					Timeout[i]--;
				}
				if(KeyReg3[i] == PRESSED_STATE && Timeout[i] == 0){
					KeyReg3[i] = NORMAL_STATE;
					is_pressed[i] = 1; // over 3s button is pressed
				}
			}
		}
	}
}
