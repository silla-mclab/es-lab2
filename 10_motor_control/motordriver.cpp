#include "motordriver.h"

Motor::Motor(PinName pwm, PinName dir):
	_pwm(pwm), _dir(dir)
{
	_pwm.period(0.001);	// PWM period = 1msec ==> freq. = 1KHz
	_pwm = 0;

	_dir = 0;
	sign = 0;
}

void Motor::forward(double speed) {
	if (sign == -1) {
		_pwm = 0;		// motor stop
		wait(0.1);
	}
	
	_dir = 1;
	_pwm = abs(speed);
	sign = 1;
}

void Motor::backward(double speed) {
	if (sign == 1) {
		_pwm = 0;		// motor stop
		wait(0.1);
	}
	
	_dir = 0;
	_pwm = abs(speed);
	sign = -1;
}

void Motor::stop() {
	_pwm = 0;
	sign = 0;
}
