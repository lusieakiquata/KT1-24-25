#include <FireBase32.h>

FireBase32 db("https://kt1--25-default-rtdb.firebaseio.com", "a7ad375ed8ab716c79056513b10bc739f43e1bd0");
int dataDB;

void setup() {
  Serial.begin(115200);
  db.wifi("wifiwifi", "matkhaula");
  db.WriteData(DATA_TO_SEND, "PATH_IN_DB");
}

void loop() {
  db.GetData("PATH_IN_DB", &dataDB);
  Serial.println();
  Serial.print(dataDB);
  delay(50);
}