/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#include "software_timer.h"

int timer_counter[AMOUNT_OF_TIMER]={0,0,0}; //Mảng lưu các timer_counter của các Timer tương ứng
int timer_flag[AMOUNT_OF_TIMER]={0,0,0}; //Mảng lưu các timer_flag của các Timer tương ứng

int loopTimer(int duration, int index){
	// Nếu timer_flag == 1 thì sẽ thiết lập lại duration rồi trả về 1
	if(timer_flag[index]==1){
		setTimer(duration, index);
		return 1;
	}
	return 0;
}

void setTimer(int duration, int index){
	timer_counter[index]= duration;
	timer_flag[index] = 0;
}

void timerRun(){
	//Thực hiện tuần tự các Timer
	for(int i =0; i < AMOUNT_OF_TIMER; i++){
		if(timer_counter[i]>0){
			timer_counter[i]--;
			if(timer_counter[i]==0){
				timer_flag[i]=1;
			}
		}
	}
}
