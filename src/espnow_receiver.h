#ifndef ESPNOW_RECEIVER_H
#define ESPNOW_RECEIVER_H

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>

// Cấu trúc dữ liệu nhận từ tay cầm
typedef struct {
  char command[10];  // "TIEN", "LUI", "TRAI",...
} DataReceived;

void initESPNowReceiver();
String getReceivedCommand();

#endif