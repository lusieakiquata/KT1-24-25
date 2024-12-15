#include <WiFi.h>

const char* ssid = "Your_SSID";
const char* password = "Your_Password";

void setup() {
  Serial.begin(115200);
  Serial.println();

  // Set up the Wi-Fi Access Point (AP)
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
}

void loop() {
  // No need to add code here for the basic hotspot functionality
}
