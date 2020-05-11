#include "mbed.h"

DigitalIn button(PA_14);		// the first push-button
DigitalOut myled(PA_13);		// Green Led

typedef enum {
	NO_EDGE = 0, RISING_EDGE, FALLING_EDGE
} edge_t;

edge_t detectBtnEdge() {
	static int prevState = 1;
	edge_t edge = NO_EDGE;
	
	if (button != prevState) {
			wait(0.05);		// Debouncing delay
			if (button != prevState) {
					if (button == 0)  edge = FALLING_EDGE;
				  else edge = RISING_EDGE;
					prevState = button;
			}
	}
	
	return edge;
}
		
int main() {
		myled = 0;		// Green led initially off
    
	  while(1) {
				if (detectBtnEdge() == FALLING_EDGE) {
					myled = !myled;		// toggle led state
				}
    }
}
