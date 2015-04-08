/*
	PID_test.h
	Created by Arvi Gjoka, March 12, 2015.
	Released into the public domain.

*/

#ifndef PID_test_h
#define PID_test_h

#include "Arduino.h"


class PID_test {
  public:
    PID_test(int[]);
	void update_pid(void);
	void set_k(double Kp, double Kd, double Ki);
	void get_error(double expected,double reading,double time);
	double get_value();
	void function_value(void);
	
  private:
    double _integral;
    double _derivative;
    double error[3];
    double _Kp;
    double _Kd;
    double _Ki;
    double _dt;
    double _time;
    
    double _function_value;
    
    
    
    void derivate();
    void integrate();
    
    //void output_calc(void);
    
    int _motorpins[4];
};

#endif