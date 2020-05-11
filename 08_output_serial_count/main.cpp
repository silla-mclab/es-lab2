#include "mbed.h"

Serial pc(USBTX, USBRX);

int cnt = 0;

int main() {
	
    while(1) {
				pc.printf("\rCounter = %d  ", cnt);
				cnt++;
				wait(1.0);			
    }
		
}
