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
    DDRC = 0xFF; PORTC = 0x00;

    //unsigned char tmpB = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char cntavail;		// number of available spots
    unsigned char carsParked = 0x00;	// number of parked cars
    unsigned char i;			// number of bits to go through
    /* Insert your solution below */
    while (1) {
	tmpA = PINA & 0x0F;			// bit masks because we are only working with bits 0 - 3
	carsParked = 0x00;
	for(i = 0; i < 4; i++){
	    if(((tmpA >> i) & 0x01) == 0x01) {	// Shifts the bits and masks to see if a car is in a spot
		carsParked++;			// Increments number of parked cars
	    }
	}

	cntavail = (4 - carsParked) & 0x0F;
	PORTC = cntavail;
    }
    return 0;
}
