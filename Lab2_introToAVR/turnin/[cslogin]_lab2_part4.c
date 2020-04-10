/*	Author: mlee212
 *  Partner(s) Name: Matthew Lee
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0x00; PORTD = 0x00;

    //unsigned char tmpB = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char tmpD = 0x00;
    unsigned short totW = 0x00;
    unsigned char shiftTot = 0x00;
    unsigned char balW = 0x00;
    
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
	tmpD = 0x00;

	totW = tmpA + tmpB + tmpC;
	
	if(totW > 0x8C) {
	    tmpD = tmpD | 0x80;
	}
	
	if(tmpA > tmpC) {
	    balW = tmpA - tmpC;
	}
	else {
	    balW = tmpC - tmpA;
	}
	
	if(balW > 0x50) {
	    tmpD = tmpD | 0x40;
	}
	
	shiftTot = totW;	
	
	tmpD = tmpD | (shiftTot >> 2);
	
	PORTD = tmpD;
    }
    return 0;
}
