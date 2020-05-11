#include "mbed.h"

Serial pc(USBTX, USBRX);		// Default Serial Port
AnalogIn IRSensor(PC_5);		// ID Distance Sensor
int dist = 0;
double a, volt;

double map(double x, double in_min, double in_max, double out_min, double out_max) {
	double scale = (x - in_min)/(in_max - in_min);
	return scale * (out_max - out_min) + out_min;
}

void test1() {
	// initialize...
	pc.baud(115200);
	printf("IR Distance Sensor Test...\r\n");
	
	while (1) {
		wait(1);
		a = IRSensor;
		printf("IR Sensor value : %3.2f\r\n", a);
		
		// convert sensor value(0.0~1.0) to voltage value
		volt = map(a, 0.0, 1.0, 0.0, 3200);
		printf("Input Voltage: %4.2f mV\r\n", volt);
		dist = (int)((27.61 / (volt - 0.1696)) * 1000);
		printf("Distance : %d cm\r\n\n", dist);
	}
}
