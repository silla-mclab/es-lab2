#include "mbed.h"
#include "motordriver.h"

Motor motorA(D11, PC_8);

int main() {
    while(1) {
			for (double s = 0; s <= 1.0; s += 0.1) {
				motorA.forward(s);
				wait(2);
			}
			motorA.stop();
			wait(2);
			for (double s = 0; s <= 1.0; s += 0.1) {
				motorA.backward(s);
				wait(2);
			}
			motorA.stop();
			wait(2);
    }		
}
