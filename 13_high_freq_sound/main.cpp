#include "mbed.h"

#define	PULSE_DELAY		28		// delay tine for 16KHz Sound

DigitalOut myled(PA_13);		// Green LED
PwmOut sound(PC_9);				// buzzer => PWMOut

int main() {
//		sound.period(0.0000625);
		sound.period(0.000956);
		sound.write(0.5);
	
    while(1) {
			myled = 1;
			wait(1);
			myled = 0;
			wait(1);
    }
		
}
