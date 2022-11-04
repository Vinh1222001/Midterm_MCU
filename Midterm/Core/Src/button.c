/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#include "button.h"

int KeyReg0[AMOUNT_OF_BUTTON] = {NORMAL_STATE};
int KeyReg1[AMOUNT_OF_BUTTON] = {NORMAL_STATE};
int KeyReg2[AMOUNT_OF_BUTTON] = {NORMAL_STATE};
int KeyReg3[AMOUNT_OF_BUTTON] = {NORMAL_STATE};

int TimeOutForKeyPress =  TIMEOUT;

int button_flag[AMOUNT_OF_BUTTON]={0}; //Mảng chứa các button_flag tương ứng


int isButtonPressed(int index){
	if(button_flag[index]==1){
		button_flag[index]=0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	if(KeyReg3[index] == PRESSED_STATE){
		button_flag[index]=1;
	}
}
void getKeyInput(){
	//Thực hiện tuần tự các nút nhấn
	for(int i=0; i < AMOUNT_OF_BUTTON; i++){

	  KeyReg2[i] = KeyReg1[i];
	  KeyReg1[i] = KeyReg0[i];

	  switch(i){
	  //Gán tín hiệu nút tương ứng
		  case 0:
			  KeyReg0[i] = HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin);
			  break;
		  default:
			  break;
	  }

	  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
		if (KeyReg2[i] != KeyReg3[i]){
		  KeyReg3[i] = KeyReg2[i];

		  if (KeyReg3[i] == PRESSED_STATE){
			TimeOutForKeyPress = TIMEOUT;
			subKeyProcess(i);
		  }
		}else{
		   TimeOutForKeyPress --;
			if (TimeOutForKeyPress == 0){
			  KeyReg3[i] = NORMAL_STATE;
			}
		}
	  }
	}

}

