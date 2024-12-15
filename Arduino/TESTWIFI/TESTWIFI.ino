#include <WiFi.h>
#include <FirebaseESP32.h>

// Thông tin Wi-Fi
const char* ssid = "wifiwifi";
const char* password = "matkhaula";

// Thông tin Firebase
#define FIREBASE_HOST "kt1--25-default-rtdb.firebaseio.com"  // URL Realtime Database của bạn
#define FIREBASE_AUTH "rn2Vtv9n5S8r3VPSOmlFCC9gw6YNPrrivWxeWLeW"  // API Key của bạn

FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);
  
  // Kết nối Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi");

  // Thiết lập Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  int value = 123;  // Giá trị dữ liệu
  
  // Gửi dữ liệu lên Firebase
  if (Firebase.setInt(firebaseData, "/khoi luong", value)) {
    Serial.println("Data sent successfully");
  } else {
    Serial.println("Failed to send data");
    Serial.println("REASON: " + firebaseData.errorReason());
  }

  delay(2000);  // Gửi dữ liệu mỗi 2 giây
}
