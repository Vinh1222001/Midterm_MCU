/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 *
 *  Các file .h cần thiết khác sẽ được #include trong file này để tiện kiểm soát.
 *  Trong file main.c sẽ chỉ #include file global.h
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"
#include "state_machine.h"

#define INIT 1000
#define START 1001
#define AUTOMATIC_COUNTDOWN 1002

#define WAITING_TIME 200

enum Button{ 						//Chứa tên các Button cần dùng
	TestButton =0,
	ResetButton,
	IncButton,
	DecButton
};

enum Timer{							//Chứa tên các Timer cần dùng
	SwitchingAutomatinTimer=0,
	OneSecondTimer,
	OneSecondTimer1
};

extern int counter;
extern int status;

#endif /* INC_GLOBAL_H_ */
