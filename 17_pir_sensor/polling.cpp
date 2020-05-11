#include "mbed.h"

Serial pc(USBTX, USBRX);	// Default serial port
DigitalIn motion1(D5);		// PIR Sensor
DigitalOut redLed(PA_4);	// Red LED

int motion_flag = 0;

void polling() {
	// initailzie...
	pc.baud(115200);
	printf("PIR Sensor Test...\r\n");
	
	redLed = 0;
	
	int value = 0;
	
	// main loop
	while (1) {
		value = motion1;
		if (value) {
			redLed = 1;
			printf(" Motion detected ==> LED on\r\n");
			wait(2);
		}
		else {
			redLed = 0;
		}
	}		
}	
