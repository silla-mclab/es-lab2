#include "mbed.h"

BusOut ledBus(PA_13, PB_10, PA_4);

int ledMasks[] ={
	0b00000001,		// only Green LED on
	0b00000010,		// only Yellow LED on
	0b00000100		// only Red LED on
};

int main() {
	  ledBus = 0;		// all Leds off
	
    while(1) {
				for (int i=0; i<3; i++) {
					ledBus = ledMasks[i];
					wait(2.0);
				}
    }
}
