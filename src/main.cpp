#include <Arduino.h>

// ============ CHÂN ĐỘNG CƠ (L298N) ============
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

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Khởi tạo chân động cơ
  pinMode(FL_IN1, OUTPUT);
  pinMode(FL_IN2, OUTPUT);
  pinMode(RL_IN3, OUTPUT);
  pinMode(RL_IN4, OUTPUT);
  pinMode(FR_IN1, OUTPUT);
  pinMode(FR_IN2, OUTPUT);
  pinMode(RR_IN3, OUTPUT);
  pinMode(RR_IN4, OUTPUT);
  
  // Khởi tạo PWM
  ledcAttach(FL_ENA, 5000, 8);
  ledcAttach(RL_ENB, 5000, 8);
  ledcAttach(FR_ENA, 5000, 8);
  ledcAttach(RR_ENB, 5000, 8);
  
  Serial.println("✅ ESP32 Car Ready!");
}

void loop() {
  // Test: chạy tới 2 giây, dừng 2 giây

  //Test hàm mới ở đây
  testNewFeature();  // Thêm dòng này
  delay(1000);
  //Kết thúc test hàm mới

  moveForward(200);
  delay(2000);
  stopMotor();
  delay(2000);
}

// ============ HÀM ĐIỀU KHIỂN ============
void setWheel(int inA, int inB, int pwmPin, int speed, bool forward) {
  digitalWrite(inA, forward ? HIGH : LOW);
  digitalWrite(inB, forward ? LOW : HIGH);
  ledcWrite(pwmPin, speed);
}

void moveForward(int speed) {
  setWheel(FL_IN1, FL_IN2, FL_ENA, speed, true);
  setWheel(FR_IN1, FR_IN2, FR_ENA, speed, true);
  setWheel(RL_IN3, RL_IN4, RL_ENB, speed, true);
  setWheel(RR_IN3, RR_IN4, RR_ENB, speed, true);
  Serial.println("TIEN");
}

void stopMotor() {
  setWheel(FL_IN1, FL_IN2, FL_ENA, 0, true);
  setWheel(FR_IN1, FR_IN2, FR_ENA, 0, true);
  setWheel(RL_IN3, RL_IN4, RL_ENB, 0, true);
  setWheel(RR_IN3, RR_IN4, RR_ENB, 0, true);
  Serial.println("DUNG");
}

// Minh test hàm mới 
void testNewFeature() {
    Serial.println("Testing new feature from develop branch!");
    delay(1000);
}