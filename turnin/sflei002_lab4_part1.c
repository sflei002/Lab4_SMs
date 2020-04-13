/*	Author: sflei002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum SM1_States { SM1_Start, SM1_1, SM1_2, SM1_3, SM1_4 } SM1_State;
void Tick();

int main(void){
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRB = 0xFF; 
	PORTB = 0x01;
	SM1_State = SM1_Start;

	while(1){
		Tick();
}
}

void Tick(){
  switch(SM1_State) {   // Transitions
     case SM1_Start:  // Initial transition
        SM1_State = SM1_Start;
        break;

     case SM1_Start:
        SM1_State = SM1_1;
        break;

     case SM1_1:
        if (A0) {
           SM1_State = SM1_2;
        }
        else if (!A0) {
           SM1_State = SM1_1;
        }
        break;

     case SM1_2:
        if (A0) {
           SM1_State = SM1_2;
        }
        else if (!A0) {
           SM1_State = SM1_3;
        }
        break;

	case SM1_3:
        if (A0) {
           SM1_State = SM1_4;
        }
        else if (!A0) {
           SM1_State = SM1_3;
        }
        break;

	case SM1_4:
        if (A0) {
           SM1_State = SM1_4;
        }
        else if (!A0) {
           SM1_State = SM1_1;
        }
        break;

     default:
        SM1_State = SM1_Start;
        break;
  } // Transitions

  switch(SM1_State) {   // State actions
     case SM1_Start:
        B = 0;
        break;

     case SM1_1:
	B = 0x01
        break;

     case SM1_2:
        B = 0x02;
        break;

     case SM1_3:
	B = 0x02;
        break;

     case SM1_4:
	B = 0x01;
        break;

     default:
        break;
   } // State actions
}
