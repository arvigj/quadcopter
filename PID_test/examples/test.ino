#include <PID_test.h>

int a[] = {0,0,0,0};
PID_test * pid = new PID_test(a);

void setup() {
  // put your setup code here, to run once:
  
  
  pid->set_k(1,1,1);
  
  pid->get_error(20,15,1);
  pid->get_error(20,16,1.2);
  pid->get_error(20,17,1.4);
  pid->get_error(20,18,1.6);
  
  pid->function_value();
  
  Serial.begin(9600);
  delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(pid->get_value());
}
