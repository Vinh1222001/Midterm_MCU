/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define TIMEOUT 500
#define AMOUNT_OF_BUTTON 1 //Số lượng Button được sử dụng

int isButtonPressed(int index); //Kiểm tra tín hiệu của nút nhấn
void getKeyInput();

#endif /* INC_BUTTON_H_ */
