/*
  Example from WiFi > WiFiScan
  Complete details at https://RandomNerdTutorials.com/esp32-useful-wi-fi-functions-arduino/
*/

#include "WiFi.h"

void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop() {
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");

    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print("SSID: ");
      Serial.print(WiFi.SSID(i));
      Serial.print(", RSSI: ");
      Serial.print(WiFi.RSSI(i));
      Serial.print(", Encryption: ");

      switch(WiFi.encryptionType(i)) {
        case WIFI_AUTH_OPEN:
          Serial.print("Open");
          break;
        case WIFI_AUTH_WEP:
          Serial.print("WEP");
          break;
        case WIFI_AUTH_WPA_PSK:
          Serial.print("WPA-PSK");
          break;
        case WIFI_AUTH_WPA2_PSK:
          Serial.print("WPA2-PSK");
          break;
        case WIFI_AUTH_WPA_WPA2_PSK:
          Serial.print("WPA/WPA2-PSK");
          break;
        default:
          Serial.print("Unknown");
          break;
      }

      Serial.println();
      delay(10);
    }
  }

  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
}