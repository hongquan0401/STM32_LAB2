/*
 * softwareTimer.h
 *
 *  Created on: Oct 26, 2023
 *      Author: DELL F89F
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int timer1_flag, timer2_flag, timer3_flag, timer4_flag;

void setTimer1(int duration);
void timer1Run();

void setTimer2(int duration);
void timer2Run();

void setTimer3(int duration);
void timer3Run();

#endif /* INC_SOFTWARETIMER_H_ */
