/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#include "button.h"

int KeyReg0[AMOUNT_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[AMOUNT_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[AMOUNT_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[AMOUNT_OF_BUTTON] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimeOutForKeyPress[AMOUNT_OF_BUTTON];

int button_flag[AMOUNT_OF_BUTTON]={0,0,0,0}; //Mảng chứa các button_flag tương ứng
int button_long_flag[AMOUNT_OF_BUTTON]={0,0,0,0};


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
	//Thuc hien tuan tu cac nut nhan
	for(int i=0; i < AMOUNT_OF_BUTTON; i++){

	  KeyReg2[i] = KeyReg1[i];
	  KeyReg1[i] = KeyReg0[i];

	  switch(i){
	  //Gan tin hieu nut tuong ung
		  case 0:
			  KeyReg0[i] = HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin);
			  break;
		  case 1:
			  KeyReg0[i] = HAL_GPIO_ReadPin(RESET_BUTTON_GPIO_Port, RESET_BUTTON_Pin);
			  break;
		  case 2:
			  KeyReg0[i] = HAL_GPIO_ReadPin(INC_BUTTON_GPIO_Port, INC_BUTTON_Pin);
			  break;
		  case 3:
			  KeyReg0[i] = HAL_GPIO_ReadPin(DEC_BUTTON_GPIO_Port, DEC_BUTTON_Pin);
			  break;
		  default:
			  break;
	  }

	  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
		if (KeyReg2[i] != KeyReg3[i]){
		  KeyReg3[i] = KeyReg2[i];

		  if (KeyReg3[i] == PRESSED_STATE){
			  if(button_long_flag[i]==1){ 				//Bien button_long_flag[i]=1 dung de cho biet hien tai nut nhan da duoc giu du 3 giay
				  TimeOutForKeyPress[i]=TIMEOUT-200;
			  }else{

				TimeOutForKeyPress[i] = TIMEOUT;
			  }
			subKeyProcess(i);
		  }
		}else{
		   TimeOutForKeyPress[i] --;
			if (TimeOutForKeyPress[i] == 0){
				button_long_flag[i]=1;
			  KeyReg3[i] = NORMAL_STATE;
			}
		}
	  }else{
		  button_long_flag[i]=0;
	  }
	}

}

