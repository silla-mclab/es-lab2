#include "mbed.h"

Serial pc1(USBTX, USBRX);
AnalogIn IrDistance(PC_5);		// IR Distance sensor
DigitalOut Led1(PA_4);		// Red LED
int f_sen = 0;

void flip() {
	float t1 = 0, t2 = 0;
	float data, distance;
	
	t1 = IrDistance;
	wait(0.01);
	t2 = IrDistance;
	data = (t1 + t2) / 2;
	
	if ((0.121 <= data) && (data <= 0.97)) {
		distance = 26.663 * pow((data * 3.3), -1.25);
		printf("Distance : %5.2f cm\r\n", distance);
		f_sen = 1;
	}
	else {
		printf("Distance : ------ cm\r\n");
		f_sen = 0;
	}
}

void test2() {
	// initailize...
	pc1.baud(115200);
	printf("IR Distance Sensor Test...\r\n\n");
	
	// main loop
	while (1) {
		flip();
		Led1 = f_sen;
		wait(1);
	}
}
