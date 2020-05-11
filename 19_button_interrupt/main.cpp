#include "mbed.h"

extern void test1();
//extern void test2();

InterruptIn button(PA_14);	// the first button
DigitalOut led(PA_13);			// Green LED

// Button interrupt handler
void button_ISR() {
	led = !led;			// LED toggling
}

int main() {
	// initialize Interrupt
	button.fall(&button_ISR);
	
	test1();
//		test2();
}
