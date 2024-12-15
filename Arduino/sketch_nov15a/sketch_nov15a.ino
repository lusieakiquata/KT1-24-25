

// Khai báo địa chỉ I2C và kích thước của LCD (0x27 là địa chỉ thông thường của LCD I2C)
LiquidCrystal_I2C lcd(0x27, 16, 2);


// Khai báo module HX711 với chân DT và SCK
const int HX711_dout = 4;  // Chân DT của HX711
const int HX711_sck = 5;   // Chân SCK của HX711
byte rowPins[4] = {45, 43, 41, 39};
byte colPins[4] = {53, 51, 49, 47};

HX711_ADC LoadCell(HX711_dout, HX711_sck);
char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins,4, 4);

void setup() {
  Serial.begin(9600);  // Thiết lập giao tiếp Serial
  lcd.init();  // Khởi động LCD
  lcd.backlight();  // Bật đèn nền
  LoadCell.begin();  // Khởi động cảm biến
  //delay(1000);  // Chờ 1 giây để cảm biến ổn định
  LoadCell.start(2000);  // Khởi tạo và hiệu chỉnh cảm biến trong 2 giây
  LoadCell.setCalFactor(69600.0);  // Đặt hệ số hiệu chỉnh (calibration factor)
 // Serial.println("HX711 setup complete");
 
}

void loop() {
  
  LoadCell.update();
  lcd.clear();
  lcd.print("nhat D de start");
  char key = keypad.waitForKey();
  char key1;
  Serial.println (key);
  //if (key!)
  if (key=='D'){
     key1='P';
    while(key1!='#'){
     
    lcd.clear();
    lcd.print("nhat 1,2,3 :");
    
      
      key = keypad.waitForKey();
      
      char luu=key;
    while (key != 'C' && key1 !='#'){
      
      lcd.clear();
      int vp=0;
      
      switch(luu){
        case '1':
          vp=1; 
          lcd.print("carot");break;
        case '2':
          vp=2;
          lcd.print("khoai tay");break;
        case  '3':
        vp=3;
        lcd.print("dau van");break;
      }
      if (vp==0) {
        if (key=='#'){key1='#';break;delay(500);}
        lcd.print("khong co mon do");delay(500);
      break;}
      lcd.setCursor(0, 1);
      bool kt=false;
      float kl;
      int i=0;
      int b[10000];
      int a[21];
      a[10]=1;
    while (kt != true ){
      i++;
      LoadCell.update();
      if(a[i]!=0)
        b[a[i]]--;
    a[i] = LoadCell.getData();
        b[a[i]]++;

      if (b[a[i]]==20) {kt=true;kl=a[i];}
  if (i>20) i=0;

  key=keypad.getKey();
      if (key=='C') {break;}
      if (key=='#'){key1='#';break;}

  
  delay (100);
  }
    if(key !='C' && key !='#'){
    lcd.print(kl);
    lcd.print("kg");
    for(int j=1;j<=200;j++){
    key=keypad.getKey();
      if (key=='C') {break;}
      if (key=='#'){key1='#';break;}
      delay(10);
    }}
  }
    lcd.clear();
    if (key!='C') lcd.print("xin cam on");
    delay(1000);
      }
  
  }
  delay(100);
}
