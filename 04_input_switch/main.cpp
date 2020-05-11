#include "mbed.h"

DigitalIn button(PA_14);		// the first push-button
DigitalOut myled(PA_13);		// Green Led

int main() {
		myled = 0;
    
	  while(1) {
				if (!button) {
					myled = 1; 	// LED is ON
					wait(5); 		// 5 sec
					myled = 0; // LED is OFF
				}
    }
}
