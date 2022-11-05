/*
 * state_machine.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "state_machine.h"

void fsm_simple_buttons_run(){
	if(timer_flag[OneSecondTimer1]==1){
		HAL_GPIO_TogglePin(TESTING_LED_GPIO_Port, TESTING_LED_Pin);
		setTimer(100,OneSecondTimer1);
	}
	switch(status){
		case INIT:
			status=START;
			setTimer(WAITING_TIME, SwitchingAutomatinTimer);
			break;
		case START:
			if(timer_flag[SwitchingAutomatinTimer]==1){
				status=AUTOMATIC_COUNTDOWN;
				setTimer(100, OneSecondTimer);
			}

			if(isButtonPressed(ResetButton)){
				counter=0;
				setTimer(WAITING_TIME, SwitchingAutomatinTimer);
			}

			if(isButtonPressed(IncButton)){
				counter++;
				if(counter>9){
					counter = 0;
				}
				setTimer(WAITING_TIME, SwitchingAutomatinTimer);
			}

			if(isButtonPressed(DecButton)){
				counter--;
				if(counter<0){
					counter=9;
				}
				setTimer(WAITING_TIME, SwitchingAutomatinTimer);
			}

			display7SEG(counter);
			break;
		case AUTOMATIC_COUNTDOWN:

			if(timer_flag[OneSecondTimer]==1){


				if(counter>0){
					counter--;
					setTimer(100, OneSecondTimer);
				}else{
					counter=0;
				}
			}

			display7SEG(counter);
			if(counter==0){
				if(isButtonPressed(IncButton)){
					status=INIT;
					counter++;
					if(counter>9){
						counter = 0;
					}
					setTimer(WAITING_TIME, SwitchingAutomatinTimer);
				}

				if(isButtonPressed(DecButton)){
					status=INIT;
					counter--;
					if(counter<0){
						counter=9;
					}
					setTimer(WAITING_TIME, SwitchingAutomatinTimer);
				}

			}

			break;
		default:
			display7SEG(404); //Led 7 Segment will display "o" if the system have error
			break;

	}


}

