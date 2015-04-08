/*
  display.h - Library for an Arduino Smartwatch GUI.
  Created by Arvi Gjoka, March 12, 2015.
  Released into the public domain.
*/

#include "Arduino.h"
#include "PID_test.h"

/* void PID_test(int motorpins[4]);
void update_pid();
void set_k(double Kp, double Kd, double Ki);
double get_value();
void function_value();
void integrate();
void derivate();

double _integral;
double _derivative;
double error[3];
double _Kp;
double _Kd;
double _Ki;
double _dt;
double _time;
    
double _function_value;

int _motorpins[4];
*/



PID_test::PID_test(int motorpins[4]) {
	for (int i=0; i<4; i++) {
		_motorpins[i] = motorpins[i];
	}
	
	for (int i=0; i<3; i++) {
		error[i] = 0;
	}
	
	_derivative = 0;
	_integral = 0;
	_Kp = 0;
	_Kd = 0;
	_Ki = 0;
	_function_value = 0;
	_time = 0;
	_dt = 0;
}

void PID_test::update_pid() {
	//do this last to consolidate all of the private functions
	
}

void PID_test::set_k(double Kp, double Kd, double Ki) {
	_Kp = Kp;
	_Kd = Kd;
	_Ki = Ki;
}

void PID_test::get_error(double expected, double reading, double time) {
	for (int i=1; i<3; i++) {
		error[i-1] = error[i];
	}
	
	error[2] = expected - reading;
	_dt = time - _time;
	_time = time;
	
}

double PID_test::get_value() {
	return _function_value;
}

void PID_test::function_value() {
	_function_value = _Kp*error[0] + _Kd*_derivative + _Ki*_integral;
}

void PID_test::integrate() { //called after error is updated
	_integral = 0.9*(_integral) + (error[2] * _dt);
}

void PID_test::derivate() {	// called after error is updated
	_derivative = (error[2] - error[1])/(_dt);
}
