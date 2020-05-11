#include "mbed.h"

Serial pc1(USBTX, USBRX);
InterruptIn motion2(D5);		// PIR Sensor
DigitalOut greenLed(PA_13);		// Green LED
DigitalOut led1(PA_4);		// Red LED

volatile int cnt = 0;				// Motion detection count

void rising_irq_handler() {
	cnt++;
	led1 = 1;
}

void falling_irq_handler() {
	led1 = 0;
}

void interrupt() {
	// initialize...
	pc1.baud(115200);
	printf("PIR Sensor Test by Interrupt...\r\n");
	
	motion2.rise(&rising_irq_handler);
	motion2.fall(&falling_irq_handler);
	cnt = 0;
	led1 = 0;
	
	int last_cnt = 0;
	
	// main loop
	while (1) {
		if (cnt != last_cnt) {
			printf("Motion detected at %d times since reset\r\n", cnt);
			last_cnt = cnt;
		}
		
		// toggle green LED
		greenLed = !greenLed;
		wait(0.5);
	}	
}
