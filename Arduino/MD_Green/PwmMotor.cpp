#include "arduino.h"
#include "PwmMotor.h"

PwmMotor::PwmMotor(int R1pin, int R2pin, int PWMpin)
{
  pinMode(R1pin, OUTPUT);
  pinMode(R2pin, OUTPUT);
  pinMode(PWMpin, OUTPUT);
  R1pinNo = R1pin;
  R2pinNo = R2pin;
  PWMpinNo = PWMpin;
}

void PwmMotor::speed(int speed)
{
  digitalWrite(R1pinNo, speed > 15);
  digitalWrite(R2pinNo, speed < -15);
  analogWrite(PWMpinNo, abs(speed));
}
