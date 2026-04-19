#include "motor.h"

void initMotor() {
  pinMode(FL_IN1, OUTPUT);
  pinMode(FL_IN2, OUTPUT);
  pinMode(RL_IN3, OUTPUT);
  pinMode(RL_IN4, OUTPUT);
  ledcAttach(FL_ENA, 5000, 8);
  ledcAttach(RL_ENB, 5000, 8);

  pinMode(FR_IN1, OUTPUT);
  pinMode(FR_IN2, OUTPUT);
  pinMode(RR_IN3, OUTPUT);
  pinMode(RR_IN4, OUTPUT);
  ledcAttach(FR_ENA, 5000, 8);
  ledcAttach(RR_ENB, 5000, 8);
}

void setWheel(int inA, int inB, int pwmPin, int speed, bool forward) {
  if (speed == 0) {
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);
  } else {
    digitalWrite(inA, forward ? HIGH : LOW);
    digitalWrite(inB, forward ? LOW : HIGH);
  }
  ledcWrite(pwmPin, speed);
}

void moveForward(int s) {
  setWheel(FL_IN1, FL_IN2, FL_ENA, s, true);
  setWheel(FR_IN1, FR_IN2, FR_ENA, s, true);
  setWheel(RL_IN3, RL_IN4, RL_ENB, s, true);
  setWheel(RR_IN3, RR_IN4, RR_ENB, s, true);
}

void moveBackward(int s) {
  setWheel(FL_IN1, FL_IN2, FL_ENA, s, false);
  setWheel(FR_IN1, FR_IN2, FR_ENA, s, false);
  setWheel(RL_IN3, RL_IN4, RL_ENB, s, false);
  setWheel(RR_IN3, RR_IN4, RR_ENB, s, false);
}

void strafeLeft(int s) {
  setWheel(FL_IN1, FL_IN2, FL_ENA, s, false);
  setWheel(FR_IN1, FR_IN2, FR_ENA, s, true);
  setWheel(RL_IN3, RL_IN4, RL_ENB, s, true);
  setWheel(RR_IN3, RR_IN4, RR_ENB, s, false);
}

void strafeRight(int s) {
  setWheel(FL_IN1, FL_IN2, FL_ENA, s, true);
  setWheel(FR_IN1, FR_IN2, FR_ENA, s, false);
  setWheel(RL_IN3, RL_IN4, RL_ENB, s, false);
  setWheel(RR_IN3, RR_IN4, RR_ENB, s, true);
}

void spinLeft(int s) {
  setWheel(FL_IN1, FL_IN2, FL_ENA, s, false);
  setWheel(FR_IN1, FR_IN2, FR_ENA, s, true);
  setWheel(RL_IN3, RL_IN4, RL_ENB, s, false);
  setWheel(RR_IN3, RR_IN4, RR_ENB, s, true);
}

void spinRight(int s) {
  setWheel(FL_IN1, FL_IN2, FL_ENA, s, true);
  setWheel(FR_IN1, FR_IN2, FR_ENA, s, false);
  setWheel(RL_IN3, RL_IN4, RL_ENB, s, true);
  setWheel(RR_IN3, RR_IN4, RR_ENB, s, false);
}

void stopMotor() {
  moveForward(0);
}

void handleManualControl(String command) {
  int s = 220;
  
  if (command == "TIEN") moveForward(s);
  else if (command == "LUI") moveBackward(s);
  else if (command == "TRAI") strafeLeft(s + 30);
  else if (command == "PHAI") strafeRight(s + 30);
  else if (command == "X_TRAI") spinLeft(s - 20);
  else if (command == "X_PHAI") spinRight(s - 20);
  else stopMotor();
}