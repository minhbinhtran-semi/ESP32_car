#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

// ==================== CHÂN ĐỘNG CƠ (ESP32 30 CHÂN) ====================
// L298N #1 - Bên trái
#define FL_ENA 32
#define FL_IN1 25
#define FL_IN2 33
#define RL_ENB 12
#define RL_IN3 27
#define RL_IN4 14

// L298N #2 - Bên phải
#define FR_ENA 4
#define FR_IN1 16
#define FR_IN2 17
#define RR_ENB 22
#define RR_IN3 19
#define RR_IN4 21

// Khai báo hàm
void initMotor();
void setWheel(int inA, int inB, int pwmPin, int speed, bool forward);
void moveForward(int speed);
void moveBackward(int speed);
void strafeLeft(int speed);
void strafeRight(int speed);
void spinLeft(int speed);
void spinRight(int speed);
void stopMotor();
void handleManualControl(String command);

#endif