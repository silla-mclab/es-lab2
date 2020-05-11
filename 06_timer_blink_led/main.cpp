#include "mbed.h"

DigitalIn button(PA_14);		// the first switch 
DigitalOut myled(PA_13);		// Green LED
Timer tm;
int i;

int main() {
		tm.start();
    while(1) {
				if (!button) {
						tm.reset();
						while (!button){ wait(0.3); };
						i = tm.read_ms() - 300;
						
						tm.reset();
						while (tm.read_ms() < i) {
								myled = 1; // LED is ON
								wait(0.5); // 500 mssec
								myled = 0; // LED is OFF
								wait(0.5); // 500 msec
						}	
				}
    }
}
