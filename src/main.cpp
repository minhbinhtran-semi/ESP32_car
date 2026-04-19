#include <Arduino.h>
#include "motor.h"
#include "espnow_receiver.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  initMotor();
  initESPNowReceiver();
  
  Serial.println("\n✅ XE MECANUM ĐÃ SẴN SÀNG (ESP-NOW)!");
}

void loop() {
  String cmd = getReceivedCommand();
  handleManualControl(cmd);
  delay(20);
}

// yyffuiigihh