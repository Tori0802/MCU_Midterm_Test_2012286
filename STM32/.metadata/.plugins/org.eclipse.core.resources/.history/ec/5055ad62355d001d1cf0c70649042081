/*
 * fsm_manual.c
 *
 *  Created on: Nov 5, 2022
 *      Author: dell
 */

#include "fsm_midterm.h"

void fsm_simple_buttons_run() {
	switch(status) { 					// Xet bien the hien trang thai hien gio cua finite state machine

	case INIT: // INIT
		display7SEG(counter); 			// Hien thi gia tri counter ra LED 7 doan
		status = CURRENT;				// Trang thai tiep theo: CURRENT
		break;

	case CURRENT: // CURRENT
		display7SEG(counter);			// Hien thi gia tri counter ra LED 7 doan
		if (isButtonPressed(0) == 1) { 	// Neu nut RES duoc nhan, chuyen trang thai status sang RESET_STATE, dong thoi ta dat lai setTimer cho dieu kien chuyen sang trang thai AUTO sang 10s
			status = RESET_STATE;
		}
		if (isButtonPressed(1) == 1) { 	// Neu nut INC duoc nhan, chuyen trang thai status sang ADD, dong thoi ta dat lai setTimer cho dieu kien chuyen sang trang thai AUTO sang 10s
			status = ADD;
		}
		if (isButtonPressed(2) == 1) {	// Neu nut DEC duoc nhan, chuyen trang thai status sang SUB, dong thoi ta dat lai setTimer cho dieu kien chuyen sang trang thai AUTO sang 10s
			status = SUB;
		}
		break;

	case RESET_STATE: // RESET_STATE
		counter = 0;					// Reset "counter" ve 0
		display7SEG(counter);			// Hien thi gia tri counter ra LED 7 doan
		status = CURRENT;				// Chuyen trang thai "status" ve CURRENT
		break;

	case ADD: // ADD
		counter++;						// Neu gia tri "counter" la 9, thi gia tri "counter" tiep theo se la 0, nguoc lai tang gia tri "counter"
		if (counter > 9) counter = 0;
		display7SEG(counter);			// Hien thi gia tri counter ra LED 7 doan
		status = CURRENT;				// Chuyen trang thai "status" ve CURRENT
		break;

	case SUB: // SUB
		counter--;						// Neu gia tri "counter" la 0, thi gia tri "counter" tiep theo se la 9, nguoc lai giam gia tri "counter"
		if (counter < 0) counter = 9;
		display7SEG(counter);			// Hien thi gia tri counter ra LED 7 doan
		status = CURRENT;				// Chuyen trang thai "status" ve CURRENT
		break;

	default:
		break;
	}
}
