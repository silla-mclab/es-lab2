#include "mbed.h"

#define NOTE_c_DELAY		1915	// usec

int note_delays[8] = {
	1915, 1700, 1519, 1432, 1275, 1136, 1014, 956
};

DigitalOut buzzer(PC_9);

int main() {
	
    while(1) {
			for (int i=0; i<8; i++) {
				for (int k=0; k<500; k++) {	// pules number
					buzzer = 1;		// buzzer HIGH
					wait_us(note_delays[i]);
					buzzer = 0;		// buzzer LOW
					wait_us(note_delays[i]);
				}
				wait(0.5);				
			}	
//			buzzer = 1;		// buzzer HIGH
//			wait_us(NOTE_c_DELAY);
//			buzzer = 0;		// buzzer LOW
//			wait_us(NOTE_c_DELAY);
    }
		
}
