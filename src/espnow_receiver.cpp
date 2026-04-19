#include "espnow_receiver.h"

static DataReceived myData;
static String currentCommand = "DUNG";

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  currentCommand = String(myData.command);
  
  static String lastCmd = "";
  if (currentCommand != lastCmd) {
    lastCmd = currentCommand;
    Serial.print("📥 Nhận lệnh: ");
    Serial.println(currentCommand);
  }
}

void initESPNowReceiver() {
  WiFi.mode(WIFI_STA);
  
  if (esp_now_init() != ESP_OK) {
    Serial.println("❌ Lỗi khởi tạo ESP-NOW");
    return;
  }
  
  esp_now_register_recv_cb(OnDataRecv);
  Serial.println("✅ ESP-NOW Receiver sẵn sàng!");
}

String getReceivedCommand() {
  return currentCommand;
}