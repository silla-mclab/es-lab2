#include "mbed.h"

DigitalIn button(PA_14);		// the first push-button
DigitalOut myled(PA_13);		// Green Led

int main() {
		myled = 0;		// Green led initially off
    
	  while(1) {
				if (!button) {
					myled = !myled;
					wait(0.5);		// debouncing delay
				}
    }
}
