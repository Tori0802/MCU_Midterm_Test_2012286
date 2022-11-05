/*
 * fsm_manual.c
 *
 *  Created on: Nov 5, 2022
 *      Author: dell
 */

#include "fsm_midterm.h"

void led_blinky() {
	// Cu sau 1s, den RED_LED se chuyen doi trang thai
	if (timer_flag[1] == 1) {
		setTimer(1, 1000);
		HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
	}
}

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
			setTimer(0, 10000);			// 10s
		}
		if (isButtonPressed(1) == 1) { 	// Neu nut INC duoc nhan, chuyen trang thai status sang ADD, dong thoi ta dat lai setTimer cho dieu kien chuyen sang trang thai AUTO sang 10s
			status = ADD;
			setTimer(0, 10000);			// 10s
		}
		if (isButtonPressed(2) == 1) {	// Neu nut DEC duoc nhan, chuyen trang thai status sang SUB, dong thoi ta dat lai setTimer cho dieu kien chuyen sang trang thai AUTO sang 10s
			status = SUB;
			setTimer(0, 10000);			// 10s
		}
		if (timer_flag[0] == 1) {		// Neu sau 10s khong co nut nao duoc nhan, ta chuyen sang trang thai AUTO
			status = AUTO;
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

	case AUTO: // AUTO
		if (counter > 0) counter--;		// Neu gia tri "counter" > 0, thi gia tri "counter" tiep theo se giam di 1 don vi
										// Con neu "counter" == 0, thì "counter" se duoc giu nguyen
		display7SEG(counter);			// Hien thi gia tri counter ra LED 7 doan
		setTimer(0,1000);				// setTimer cho nhung lan tu dong thay doi "counter" tiep theo la 1s
		status = CURRENT;				// Neu trong qua trinh nay khong xay ra nhan nut nao, thi "status" se duoc chuyen ve CURRENT
		if (isButtonPressed(0) == 1) {	// Neu nut RES duoc nhan, chuyen trang thai status sang RESET_STATE, dong thoi ta dat lai setTimer cho dieu kien chuyen sang trang thai AUTO thanh 10s
			status = RESET_STATE;
			setTimer(0, 10000);
		}
		if (isButtonPressed(1) == 1) {	// Neu nut INC duoc nhan, chuyen trang thai status sang ADD, dong thoi ta dat lai setTimer cho dieu kien chuyen sang trang thai AUTO thanh 10s
			status = ADD;
			setTimer(0, 10000);
		}
		if (isButtonPressed(2) == 1) {	// Neu nut DEC duoc nhan, chuyen trang thai status sang SUB, dong thoi ta dat lai setTimer cho dieu kien chuyen sang trang thai AUTO thanh 10s
			status = SUB;
			setTimer(0, 10000);
		}
		break;

	default:
		break;
	}
}
