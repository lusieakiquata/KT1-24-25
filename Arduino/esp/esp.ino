#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <ArduinoJson.h>
HardwareSerial MySerial(1);

/* 1. Define the WiFi credentials */
#define WIFI_SSID "quannetcotrang"
#define WIFI_PASSWORD "choNsole"

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
Serial.begin(9600);
 MySerial.begin(9600, SERIAL_8N1, 16, 17);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connecting to Wi-Fi");
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
  Serial.println("done");
   downdb();
}

int gia[6];
void chay (){
    if (Serial.available())
    {
        // DOC DU LIEU TU ADN MEGA
        st =  Serial.readString();
        rq=st[0];
        // THUC THI CAU LENH
        if (rq=="u")
            updb();
        if(rq== "g")
            upg();
        if(rq== "d")
        downdb();
    }
}
void updb (){
String so="";
int upgt[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float upkl[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  int p=0,j=1;
  
        for(int i=1;i<st.length();i++){
            
            if(st[i]==' '){ 
              p+=1;
              upgt[p]=so.toInt();
              upkl[p]=so.toInt();
              
              so="";
            }
            else so = so + String(st[i]);
        }
Serial.println(st);
// hoa don1//
Firebase.RTDB.setInt(&fbdo, "/hoadon1/kl/carot", upkl[1]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon1/kl/khoaitay", upkl[2]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon1/kl/bi", upkl[3]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon1/kl/bapcai", upkl[4]/1000); 

Firebase.RTDB.setInt(&fbdo, "/hoadon1/tien/tiencr", ((gia[1]*upgt[1])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon1/tien/tienkt",((gia[2]*upgt[2])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon1/tien/tienbi", ((gia[3]*upgt[3])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon1/tien/tienbc",((gia[4]*upgt[4])/1000));

Firebase.RTDB.setInt(&fbdo, "/hoadon1/tongtien",((gia[1]*upgt[1])/1000)+((gia[2]*upgt[2])/1000)+((gia[3]*upgt[3])/1000)+((gia[4]*upgt[4])/1000)); 
//hoa don2//
Firebase.RTDB.setInt(&fbdo, "/hoadon2/kl/carot", upkl[5]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon2/kl/khoaitay", upkl[6]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon2/kl/bi", upkl[7])/1000; 
Firebase.RTDB.setInt(&fbdo, "/hoadon2/kl/bapcai", upkl[8]/1000); 

Firebase.RTDB.setInt(&fbdo, "/hoadon2/tien/tiencr", ((gia[1]*upgt[5])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon2/tien/tienkt",((gia[2]*upgt[6])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon2/tien/tienbi", ((gia[3]*upgt[7])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon2/tien/tienbc",((gia[4]*upgt[8])/1000)); 

Firebase.RTDB.setInt(&fbdo, "/hoadon2/tongtien",((gia[1]*upgt[5])/1000)+((gia[2]*upgt[6])/1000)+((gia[3]*upgt[7])/1000)+((gia[4]*upgt[8])/1000));
//hoa don3

Firebase.RTDB.setInt(&fbdo, "/hoadon3/kl/carot", upkl[9]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon3/kl/khoaitay", upkl[10]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon3/kl/bi", upkl[11]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon3/kl/bapcai", upkl[12]/1000); 

Firebase.RTDB.setInt(&fbdo, "/hoadon3/tien/tiencr", ((gia[1]*upgt[9])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon3/tien/tienkt",((gia[2]*upgt[10])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon3/tien/tienbi", ((gia[3]*upgt[11])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon3/tien/tienbc",((gia[4]*upgt[12])/1000)); 

Firebase.RTDB.setInt(&fbdo, "/hoadon3/tongtien",((gia[1]*upgt[9])/1000)+((gia[2]*upgt[10])/1000)+((gia[3]*upgt[11])/1000)+((gia[4]*upgt[12])/1000));
//hoa don4
Firebase.RTDB.setInt(&fbdo, "/hoadon4/kl/carot", upkl[13]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon4/kl/khoaitay", upkl[14]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon4/kl/bi", upkl[15]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon4/kl/bapcai", upkl[16]/1000); 

Firebase.RTDB.setInt(&fbdo, "/hoadon4/tien/tiencr", ((gia[1]*upgt[13])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon4/tien/tienkt",((gia[2]*upgt[14])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon4/tien/tienbi", ((gia[3]*upgt[15])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon4/tien/tienbc",((gia[4]*upgt[16])/1000)); 

Firebase.RTDB.setInt(&fbdo, "/hoadon4/tongtien",((gia[1]*upgt[13])/1000)+((gia[2]*upgt[14])/1000)+((gia[3]*upgt[15])/1000)+((gia[4]*upgt[16])/1000));
//hoa don 5
Firebase.RTDB.setInt(&fbdo, "/hoadon5/kl/carot", upkl[17]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon5/kl/khoaitay", upkl[18]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon5/kl/bi", upkl[19]/1000); 
Firebase.RTDB.setInt(&fbdo, "/hoadon5/kl/bapcai", upkl[20]/1000); 

Firebase.RTDB.setInt(&fbdo, "/hoadon5/tien/tiencr", ((gia[1]*upgt[17])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon5/tien/tienkt",((gia[2]*upgt[18])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon5/tien/tienbi", ((gia[3]*upgt[19])/1000)); 
Firebase.RTDB.setInt(&fbdo, "/hoadon5/tien/tienbc",((gia[4]*upgt[20])/1000)); 

Firebase.RTDB.setInt(&fbdo, "/hoadon5/tongtien",((gia[1]*upgt[17])/1000)+((gia[2]*upgt[18])/1000)+((gia[3]*upgt[19])/1000)+((gia[4]*upgt[20])/1000));
}
void upg(){

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
int a1;int d=0;String s;
void downdb(){
  s="";
    if(Firebase.RTDB.getInt(&fbdo, "/gia/giacarot", &a1))
                  gia[1]=a1;
        {s=s+String(a1)+  " "; }
    if(Firebase.RTDB.getInt(&fbdo, "/gia/giakhoaitay", &a1))
       {s=s+String(a1)+  " "; } gia[2]=a1;
    if(Firebase.RTDB.getInt(&fbdo, "/gia/giabi", &a1))
       {s=s+String(a1)+  " "; } gia[3]=a1;
    if(Firebase.RTDB.getInt(&fbdo, "/gia/giabapcai", &a1))
        {s=s+String(a1)+  " "; } gia[4]=a1;
  
    Serial.println(s);
}
void loop() {
  chay();
}