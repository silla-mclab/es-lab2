#include "mbed.h"

Serial pc(USBTX, USBRX);
AnalogIn laudness(A5);			// Sound sessor
DigitalOut myled(PA_13);		// Green LED

double i;

int main() {
		pc.baud(115200);		// set baudrate to 115200
		myled = 0;
	
    while(1) {
			i = laudness;
			if (i > 0.79) {
				pc.printf("Laudness = %.0f\n", i*100);
//				myled = 1;
//				wait(2);
//				myled = 0;
				myled = !myled;
			}
			wait(0.1);
    }
		
}
