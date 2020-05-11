#include "mbed.h"

#define BRIGHTNESS_THRESHOLD	0.6

Serial pc(USBTX, USBRX);
AnalogIn cds_sensor(A0);		// CDS sensor
DigitalOut myled(PA_13);		// Green LED

double meas;

int main() {
		pc.baud(115200);
	  myled = 0;
	
    while(1) {
			meas = cds_sensor;
			pc.printf("Darkness = %.0f %%\n", meas * 100);
			
			if (meas > BRIGHTNESS_THRESHOLD) {
				myled = 1;
			}
			else {
				myled = 0;
			}
			
			wait(1);
    }
		
}
