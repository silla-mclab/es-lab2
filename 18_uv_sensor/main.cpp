#include "mbed.h"

Serial pc(USBTX, USBRX);
AnalogIn UVSensor(A4);

double filterUVvalue(double value) {
	static double values[10];
	static int in = 0;
	static double sum = 0;
	
	sum -= values[in];
	values[in] = value;
	sum += value;
	in = (++in) % 10;
	
	return sum / 10;
}	

int main() {
		// initialize...
		pc.baud(115200);
		printf("UV Sensor Test...\r\n");
		
		double value = 0;
	
		// mainloop
    while(1) {
			value = UVSensor;
			value = filterUVvalue(value);
			printf("\rUV value = %5.2f%%", value*100);
			wait(0.25);
    }		
}
