#include "mbed.h"

DigitalOut myled1(PA_13);		// Green Led
DigitalOut myled2(PB_10);		// Yellow Led
DigitalOut myled3(PA_4);		// Red Led

int main() {
		myled1 = 0;
		myled2 = 0;
		myled3 = 0;
	
    while(1) {
        myled1 = 1; // Green LED is ON
        wait(1.0); 	// 1000 ms
        myled1 = 0; // Green LED is OFF
        myled2 = 1; // Yellow LED is ON
        wait(1.0); 	// 1 sec
        myled2 = 0; // Green LED is OFF
        myled3 = 1; // Red LED is ON
        wait(1.0); 	// 1 sec
        myled3 = 0; // Red LED is OFF
    }
}
