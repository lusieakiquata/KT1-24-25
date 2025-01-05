#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <ArduinoJson.h>
HardwareSerial MySerial(1);

/* 1. Define the WiFi credentials */
#define WIFI_SSID "wifiwifi"
#define WIFI_PASSWORD "matkhaula"

/* 2. Define the API Key */
#define API_KEY "AIzaSyCguAoNfRl4DCl7crkcvVR2qeiPUg1sXKg"

/* 3. Define the RTDB URL */
#define DATABASE_URL "kt1--25-default-rtdb.firebaseio.com" 

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "dongneww@gmail.com"
#define USER_PASSWORD "Dong02032007@"

// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;
String st = "",rq="";
void setup() {
 //Serial.begin(9600);
 MySerial.begin(9600, SERIAL_8N1, 16, 17);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
  }

 /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  // Comment or pass false value when WiFi reconnection will control by your code or third party library e.g. WiFiManager
  Firebase.reconnectNetwork(true);

  // Since v4.4.x, BearSSL engine was used, the SSL buffer need to be set.
  // Large data transmission may require larger RX buffer, otherwise connection issue or data read time out can be occurred.
  fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);

  // Limit the size of response payload to be collected in FirebaseData
  fbdo.setResponseSize(2048);

  Firebase.begin(&config, &auth);

  Firebase.setDoubleDigits(5);

  config.timeout.serverResponse = 10 * 1000;
}


void chay (){
    if (MySerial.available())
    {
        // DOC DU LIEU TU ADN MEGA
        st =  MySerial.readString();
        rq=st[0];
        // THUC THI CAU LENH
        if (rq == "u")
            updb();
        if(rq== "g")
            upg();
        if(rq== "d")
        downdb();
    }
}
void updb (){

}
void upg(){
  int gia[6];
  String so="";
  int p=0;
        for(int i=1;i<st.length();i++){
            
            if(st[i]==' '){
              p+=1;
              gia[p]=so.toInt();

              //Serial.println(gia[p]);
              so="";
            }
            else so = so + String(st[i]);
        }
        Firebase.RTDB.setInt(&fbdo, "/gia/giacarot", gia[1]);
        Firebase.RTDB.setInt(&fbdo, "/gia/giakhoaitay", gia[2]);
        Firebase.RTDB.setInt(&fbdo, "/gia/giabi", gia[3]);
        Firebase.RTDB.setInt(&fbdo, "/gia/giabapcai", gia[4]);
}
int a1;int d=0;
void downdb(){
    if(Firebase.RTDB.getInt(&fbdo, "/gia/giacarot", &a1))
        { Serial.println(a1);}
    if(Firebase.RTDB.getInt(&fbdo, "/gia/giakhoaitay", &a1))
        { Serial.println(a1);}
    if(Firebase.RTDB.getInt(&fbdo, "/gia/giabi", &a1))
        { Serial.println(a1);}
    if(Firebase.RTDB.getInt(&fbdo, "/gia/giabapcai", &a1))
        { Serial.println(a1);}

    d++;
    Firebase.RTDB.setInt(&fbdo, "/text/text",d);
}
void loop() {
  chay();
}