#include "CytronMotorDriver.h"
// Configure the motor driver.
CytronMD motor(PWM_DIR, 5, 4);  // PWM = Pin 3, DIR = Pin 4.
double Kp = 1;
double Ki = 0;
double Kd = 0;
int encoderpinA = 2;
int encoderpinB = 3;
volatile long currentPosition = 0;
int i = 0;
int out;



double error;
double lastError;
double input, output, setPoint;
double sum_error, rate_of_error;
void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(encoderpinA, INPUT_PULLUP);
  pinMode(encoderpinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderpinA), A, RISING);
  int setpoint = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  input = currentPosition;
  output = CPID(input);
  if (out > 0) {
    digitalWrite(4, HIGH);
    analogWrite(3, abs(out));
  }
  else {
    digitalWrite(4, LOW);
    analogWrite(3, abs(out));
  }
  if (out == 0) {
    motor.setSpeed(0);
  }
}
double CPID(double inp) {
  error = setPoint - inp;  //offset
  sum_error = sum_error + error; // integral term
  rate_of_error = (error - lastError); //derivative term

  double out = Kp * error + Ki * sum_error + Kd * rate_of_error;//PID EQUATION ******IMPORTANT******
  lastError = error;

  return out;

}
void A() {
  if (digitalRead(encoderpinA) != digitalRead(encoderpinB)) {
    currentPosition = currentPosition + 1;
    //    Serial.println(currentPosition);
  }
  else {
    currentPosition = currentPosition - 1;
    //    Serial.println(currentPosition);
  }
  Serial.println(currentPosition);
  Serial.print("ENCODER EXAMPLE");
}
