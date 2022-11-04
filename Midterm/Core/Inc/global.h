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


enum Button{ 						//Chứa tên các Button cần dùng
	TestButton =0,
};

enum Timer{							//Chứa tên các Timer cần dùng
	Timer1=0,
	Timer2,
	Timer3
};

#endif /* INC_GLOBAL_H_ */
