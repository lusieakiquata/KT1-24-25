#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

// #define SSID "Cong Ty Gach Quoc Tan"
// #define PASSWORD "qn123456"
// #define SSID "quannetcotrang"
// #define PASSWORD "khongchodau1"
#define SSID "HienHoaHome"
#define PASSWORD "chucvuive123"

#define FIREBASE_AUTH "SF4W263OaMsxIxG4CWHsWdzKXrmC4S6h6rIwnTst"
#define DATABASE_URL "kt1-2023-2024-db-default-rtdb.firebaseio.com"

FirebaseData fbdo;
FirebaseJson json;

int x = 0, y = 0;
char stVal[20];
String request = "", st = "", class_name = "", operatorr = "", type = "", track[6];
bool check;

void setup()
{
    Serial.begin(9600);
    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }

    Firebase.begin(DATABASE_URL, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);
}

void readCommand()
{
    if (Serial.available())
    {
        request = "";
        st = "";
        class_name = "";
        operatorr = "";
        type = "";
        // DOC DU LIEU TU ADN MEGA
        st = Serial.readString();

        // PHAN TACH CHUOI THANH CAC CHUOI CON MANG TEN TRUONG
        request = request + st[0];
        class_name = class_name + st[1] + st[2] + st[3] + st[4];
        operatorr = st[5];
        type = st[6];

        // THUC THI CAU LENH
        if (request == "u")
            uploadData();
        else
            downloadData();
    }
}

void uploadData()
{
    x = 0;
    check = true;
    // UPDATE DIEM TONG
    if (Firebase.getInt(fbdo, "/" + class_name + "/score"))
        x = fbdo.intData();
    if (operatorr == "+")
        Firebase.setInt(fbdo, "/" + class_name + "/score", x + 1);
    else
        Firebase.setInt(fbdo, "/" + class_name + "/score", x - 1);

    // UPDATE SO LUONG CHAI/LON
    if (type == "c")
    {
        if (Firebase.getInt(fbdo, "/" + class_name + "/chai"))
            x = fbdo.intData();
        Firebase.setInt(fbdo, "/" + class_name + "/chai", x + 1);
    }
    else
    {
        if (Firebase.getInt(fbdo, "/" + class_name + "/lon"))
            x = fbdo.intData();
        Firebase.setInt(fbdo, "/" + class_name + "/lon", x + 1);
    }

    // UPDATE CHUOI 5
    if (Firebase.getString(fbdo, "/" + class_name + "/track1"))
        track[1] = fbdo.stringData();
    if (Firebase.getString(fbdo, "/" + class_name + "/track2"))
        track[2] = fbdo.stringData();
    if (Firebase.getString(fbdo, "/" + class_name + "/track3"))
        track[3] = fbdo.stringData();
    if (Firebase.getString(fbdo, "/" + class_name + "/track4"))
        track[4] = fbdo.stringData();
    if (Firebase.getString(fbdo, "/" + class_name + "/track5"))
        track[5] = fbdo.stringData();
    for (int i = 1; i <= 5; i++)
        if (track[i] == "/")
        {
            track[i] = operatorr;
            check = false;
            break;
        }
    if (check == true)
    {
        for (int i = 1; i < 5; i++)
            track[i] = track[i + 1];
        track[5] = operatorr;
    }
    Firebase.setString(fbdo, "/" + class_name + "/track1", track[1]);
    Firebase.setString(fbdo, "/" + class_name + "/track2", track[2]);
    Firebase.setString(fbdo, "/" + class_name + "/track3", track[3]);
    Firebase.setString(fbdo, "/" + class_name + "/track4", track[4]);
    Firebase.setString(fbdo, "/" + class_name + "/track5", track[5]);
}

void downloadData()
{
    y = 0;
    if (Firebase.getInt(fbdo, "/" + class_name + "/score"))
        y = fbdo.intData();
    itoa(y, stVal, 10);
    String st = "";
    st = st + stVal;
    Serial.print(st);
}

void loop()
{
    readCommand();
}