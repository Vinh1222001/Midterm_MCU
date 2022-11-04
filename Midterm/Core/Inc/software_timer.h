/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define AMOUNT_OF_TIMER 3 //Số lượng Timer được dùng

extern int timer_flag[AMOUNT_OF_TIMER]; //Mảng chứa các cờ của các Timer

int loopTimer(int duration, int index); //Dùng cho các xử lý dùng lại nhiều lần hàm setTimer()
void setTimer(int duration, int index); //Cài đặt thời gian cho Timer, với tham số index là Timer cần dùng
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
