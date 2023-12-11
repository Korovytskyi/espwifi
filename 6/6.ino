#include <WiFi.h>

// Replace with your network credentials (STATION)
const char* ssid = "TP-Link_4C71";
const char* password = "19535937";

String hostname = "ESP32-Node-Temperature";

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
  WiFi.setHostname(hostname.c_str()); // Define hostname
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  initWiFi();
  Serial.print("Hostname: ");
  Serial.println(WiFi.getHostname());
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  // Your main code here, to run repeatedly:
}