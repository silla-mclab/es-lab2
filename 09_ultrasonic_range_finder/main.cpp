#include "mbed.h"

Serial pc(USBTX, USBRX);

DigitalOut trig(D10);		// PB_6
DigitalIn echo(D7);			// PA_8
Timer tmr;
float i;

#define	TRANSFORM_CONSTANT	0.01724		// 1/58

int main() {
		tmr.start();
		pc.printf("---[ Ultrasonic Range Finder(SRF-04) ]---\n");
	
    while(1) {
			// send trig signal to SRF-04
			trig = 1;
			wait(0.00004);		// 40usec
			trig = 0;
			
			// receive echo signal and measure high-time
			while(!echo);
			
			tmr.reset();
			while(echo);
			i = tmr.read_us();
			
			// output time value and distance
			pc.printf("Pulse length %6.0f uSec\r\n", i);
			i = i * TRANSFORM_CONSTANT;
			pc.printf("Distance %4.1f cm\r\n\n", i);
			
			wait(2.0);
    }
}
