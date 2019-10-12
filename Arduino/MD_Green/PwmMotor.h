#ifndef PwmMotor_h
#define PwmMotor_h
#include "arduino.h"

class PwmMotor
{
public:
  PwmMotor(int R1pin, int R2pin, int PWMpin);
  void speed(int speed);

private:
  int R1pinNo;
  int R2pinNo;
  int PWMpinNo;
};

#endif
