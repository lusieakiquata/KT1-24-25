#include <WiFi.h>
#include <FirebaseESP32.h>
#include <ArduinoJson.h>

const char* ssid = "wifiwifi";
const char* password = "matkhaula";

// Replace these with your Firebase credentials
#define DATABASE_URL "https://kt1--25-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyCguAoNfRl4DCl7crkcvVR2qeiPUg1sXKg"
FirebaseData fb;
int a1,a2,a3,a4;
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Connect to Firebase
  Firebase.begin(DATABASE_URL, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}
void readCommand(){
  downloadData();
  delay(2000);
}

void downloadData(){
     if (Firebase.getInt(fb,"/gia/giacarot"))
        a1 = fb.intData();
    
    if (Firebase.getInt(fb,"/gia/giakhoaitay"))
        a2 = fb.intData();
  
        if (Firebase.getInt(fb,"/gia/giabi"))
        a3 = fb.intData();

    if (Firebase.getInt(fb,"/gia/bapcai"))
        a4 = fb.intData();
    Serial.println(a1);
    Serial.println(a2);
    Serial.println(a3);
    Serial.println(a4);
}

void loop()
{
    readCommand();
}
