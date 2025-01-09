#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <U8glib.h>
#include <HX711_ADC.h>
#include <Keypad.h>
#include <Arduino.h>
// #include<bits/stdc++.h>
#define ok "dong"
// Khai bao can //
HX711_ADC can1(7, 6); // dt,sck
HX711_ADC can2(9, 8);
HX711_ADC can3(11, 10);
HX711_ADC can4(13, 12);
HX711_ADC can5(15, 14);
String sgui;
// khai bao lcd 128x64//
U8GLIB_ST7920_128X64 u8g(5, 4, 3, 2); // Chân RS=13, E=11, PSB (CS)=1, RST

// khai bao lcd 1602//
LiquidCrystal_I2C lcd(0x27, 16, 2); // scl, sda

// khai bao ban phim 4x4//
byte rowPins[4] = {A12, A13, A14, A15};
byte colPins[4] = {A8, A9, A10, A11};
char keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
Keypad phim4x4 = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

// khai bao ban phim 4x1//
char keyys[4][1] = {
    {'1'},
    {'2'},
    {'3'},
    {'4'}};
byte phim1r[4] = {23, 22, 25, 24};
byte phim1c[1] = {26};
Keypad phim1 = Keypad(makeKeymap(keyys), phim1r, phim1c, 4, 1); // gắn từ trái sang  gắn theo tăng dần của số

byte phim2r[4] = {28, 27, 30, 29};
byte phim2c[1] = {31};
Keypad phim2 = Keypad(makeKeymap(keyys), phim2r, phim2c, 4, 1);

byte phim3r[4] = {33, 32, 35, 34};
byte phim3c[1] = {36};
Keypad phim3 = Keypad(makeKeymap(keyys), phim2r, phim2c, 4, 1);

byte phim4r[4] = {38, 37, 40, 39};
byte phim4c[1] = {41};
Keypad phim4 = Keypad(makeKeymap(keyys), phim4r, phim4c, 4, 1);

byte phim5r[4] = {43, 42, 45, 44};
byte phim5c[1] = {46};
Keypad phim5 = Keypad(makeKeymap(keyys), phim5r, phim5c, 4, 1);
String st = "";
String xemten(char x);
int gia[5] = {0, 0, 0, 0, 0};
void setup()
{
  Serial.begin(9600);
  // khoi dong can//
  can1.begin();
  can2.begin();
  can3.begin();
  can4.begin();
  can5.begin();
  can1.setCalFactor(182);
  can2.setCalFactor(180);
  can3.setCalFactor(180);
  can4.setCalFactor(180);
  can5.setCalFactor(180);
  can1.tare();
  can2.tare();
  can3.tare();
  can4.tare();
  can5.tare();
  lcd.init();
  lcd.backlight();

  Serial.println("d");
  lcd.print("dang cap nhap gia.."); //
  delay(3000);
  lcd.clear();
  String so = "";
  st = Serial.readString();
  Serial.println(st);
  int p = 0;
  for (int i = 0; i < st.length(); i++)
  {

    if (st[i] == ' ')
    {
      p++;
      gia[p] = so.toInt();

      // Serial.println(gia[p]);
      so = "";
    }
    else
      so = so + String(st[i]);
  }
}

void loop()
{

  bool ktkey1 = false, ktkey2 = false, ktkey3 = false, ktkey4, ktkey5, buoc1 = false, buoc2 = false;
  char hienthi1[12] = "", hienthi2[12] = "", hienthi3[12] = "", hienthi4[12] = "", hienthi5[12] = "";
  int kl1 = 0, kl2 = 0, kl3 = 0, kl4 = 0, kl5 = 0;
  int ktkl1, ktkl2, ktkl3, ktkl4, ktkl5;
  int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0;
  int xh[6];
  int kll[6];
  for (int i = 0; i < 5; i++)
  {
    xh[i] = 0;
    kll[i] = 0;
  }
  const String rt = "            ";
  String keystring = "";
  while (1 != 2)
  {

    // reset moi lan?//

    // cap nhap can//
    can1.update();
    can2.update();
    can3.update();
    can4.update();
    can5.update();
    // bien can
    int kcan1 = 0, kcan2 = 0, kcan3 = 0, kcan4 = 0, kcan5 = 0;
    kcan1 = can1.getData();
    kcan2 = can2.getData();
    kcan3 = can3.getData();
    kcan4 = can4.getData();
    kcan5 = can5.getData();

    if ((kl1 == 0) && (kcan1 > 20))
    {
      if (ktkl1 == kcan1)
      {
        d1++;
      }
      else
      {
        d1 = 0;
        ktkl1 = kcan1;
      }
      if (d1 >= 20)
      {
        kl1 = kcan1;
        kll[1] = kl1;
      }
    }

    if ((kl2 == 0) && (kcan2 > 20))
    {
      if (ktkl2 == kcan2)
      {
        d2++;
      }
      else
      {
        d2 = 0;
        ktkl2 = kcan2;
      }
      if (d2 >= 20)
      {
        kl2 = kcan2;
        kll[2] = kl2;
      }
    }
    if ((kl3 == 0) && (kcan3 > 20))
    {
      if (ktkl3 == kcan3)
      {
        d3++;
      }
      else
      {
        d3 = 0;
        ktkl3 = kcan3;
      }
      if (d3 >= 20)
      {
        kl3 = kcan3;
        kll[3] = kl3;
      }
    }
    if ((kl4 == 0) && (kcan4 > 20))
    {
      if (ktkl4 == kcan4)
      {
        d4++;
      }
      else
      {
        d4 = 0;
        ktkl4 = kcan4;
      }
      if (d4 >= 20)
      {
        kl4 = kcan4;
        kll[4] = kl4;
      }
    }
    if ((kl5 == 0) && (kcan5 > 20))
    {
      if (ktkl5 == kcan5)
      {
        d5++;
      }
      else
      {
        d5 = 0;
        ktkl5 = kcan5;
      }
      if (d5 >= 20)
      {
        kl5 = kcan5;
        kll[5] = kl5;
      }
    }
    u8g.firstPage();
    do
    {
      char see1[20] = "", see2[20] = "", see3[20] = "", see4[20] = "", see5[20] = "";
      char key1 = phim1.getKey(), key2 = phim2.getKey(), key3 = phim3.getKey(), key4 = phim4.getKey(), key5 = phim5.getKey();
      // hien thi can
      sprintf(see1, "%d", kcan1);
      sprintf(see2, "%d", kcan2);
      sprintf(see3, "%d", kcan3);
      sprintf(see4, "%d", kcan4);
      sprintf(see5, "%d", kcan5);

      u8g.setFont(u8g_font_6x12);

      if (ktkey1 == false)
      {
        if (key1)
        {
          xemten(key1).toCharArray(hienthi1, 12);
          ktkey1 = true;
          xh[1] = key1 - 48;
        }
      }
      if (ktkey2 == false)
      {
        if (key2)
        {
          xemten(key2).toCharArray(hienthi2, 12);
          ktkey2 = true;
          xh[2] = key2 - 48;
        }
      }
      if (ktkey3 == false)
      {
        if (key3)
        {
          xemten(key3).toCharArray(hienthi3, 12);
          ktkey3 = true;
          xh[3] = key3 - 48;
        }
      }
      if (ktkey4 == false)
      {
        if (key4)
        {
          xemten(key4).toCharArray(hienthi4, 12);
          ktkey4 = true;
          xh[4] = key4 - 48;
        }
      }
      if (ktkey5 == false)
      {
        if (key5)
        {
          xemten(key5).toCharArray(hienthi5, 12);
          ktkey5 = true;
          xh[5] = key5 - 48;
        }
      }
      const char *unit = "g";
      strcat(see1, unit);
      strcat(see2, unit);
      strcat(see3, unit);
      strcat(see4, unit);
      strcat(see5, unit);
      u8g.drawStr(0, 12, "Can1: ");
      u8g.drawStr(29, 12, hienthi1);
      u8g.drawStr(87, 12, see1);
      u8g.drawStr(0, 24, "Can2: ");
      u8g.drawStr(29, 24, hienthi2);
      u8g.drawStr(87, 24, see2);
      u8g.drawStr(0, 36, "Can3: ");
      u8g.drawStr(29, 36, hienthi3);
      u8g.drawStr(87, 36, see3);
      u8g.drawStr(0, 48, "Can4: ");
      u8g.drawStr(29, 48, hienthi4);
      u8g.drawStr(87, 48, see4);
      u8g.drawStr(0, 60, "Can5: ");
      u8g.drawStr(29, 60, hienthi5);
      u8g.drawStr(87, 60, see5);
    } while (u8g.nextPage());
    lcd.clear();

    if (buoc2 == false)
    {
      if (buoc1 == true)
      {
        char keychar = phim4x4.getKey();
        if (keychar)
        {
          if ((keychar == '#') || (keychar == '1') || (keychar == '2') || (keychar == '3') || (keychar == '4') || (keychar == '5') || (keychar == 'C') || (keychar == '*'))
          {
            if (keychar == 'C')
              keystring.remove(keystring.length() - 1);
            else
              keystring = keystring + keychar;
            if (keychar == '#')
            {
              buoc2 = true;
              delay(500);
            }
          }
        }
        lcd.print(keystring);
      }
      else
      {

        char key4x4 = phim4x4.getKey();

        if (key4x4 == 'C')
        {
          // Serial.println("dong");

          int mon = 1;
          String xaugia = "";
          while (mon != 5)
          {
            lcd.clear();
            String s = "";
            char nhan = "";
            while (nhan != '#')
            {

              if (mon == 1)
                lcd.print("gia carot: ");

              if (mon == 2)
                lcd.print("gia khoai tay: ");

              if (mon == 3)
                lcd.print("gia bi: ");

              if (mon == 4)

                lcd.print("gia bap cai: ");
              lcd.setCursor(0, 1);

              lcd.print(s);
              nhan = phim4x4.waitForKey();
              if (nhan != 'D' && nhan != 'A' && nhan != 'B' && nhan != '*')
              {
                if (nhan == 'C')
                  s.remove(s.length() - 1);
                else if (nhan != '#')
                  s = s + nhan;
              }
              lcd.clear();
            }

            int num = s.toInt();
            gia[mon] = num;
            mon++;
            if (s == "")
              s = "0";
            xaugia = xaugia + s + " ";
          }

          Serial.println("g" + xaugia);

          // key4x4 = phim4x4.waitForKey() ;
        }
        lcd.print("Start D :");
        // key4x4=phim4x4.getKey();
        if (key4x4 == 'D')
          buoc1 = true;
      }
    }
    else
    {
      char showdonkl1[20] = "", showdonkl2[20] = "", showdonkl3[20] = "", showdonkl4[20] = "";
      char tien1[20] = "", tien2[20] = "", tien3[20] = "", tien4[20] = "";
      int tonghoadon[9][5];
      for (int i = 1; i <= 6; i++)
      {
        for (int j = 1; j <= 5; j++)
        {
          tonghoadon[i][j] = 0;
        }
      }
      int dem = 1;
      for (int i = 0; i < keystring.length(); i++)
      {
        if (keystring[i] == '*')
          dem++;
        tonghoadon[dem][xh[keystring[i] - 48]] = 0;
        tonghoadon[dem][xh[keystring[i] - 48]] = kll[keystring[i] - 48];
        // Serial.println(tonghoadon[dem][xh[keystring[i]-48]]);
      }
      sgui = "u";
      for (int i = 1; i <= 5; i++)
      {
        for (int j = 1; j <= 4; j++)
        {
          sgui = sgui + String(tonghoadon[i][j]) + " ";
        }
      }
      Serial.println(sgui);
      for (int i = 1; i <= dem; i++)
      {

        char hoadon[12];
        String hoadoncc = "Hoa don 1";
        if (i == 2)
          hoadoncc = "Hoa don 2";
        if (i == 3)
          hoadoncc = "Hoa don 3";
        if (i == 4)
          hoadoncc = "Hoa don 4";
        if (i == 5)
          hoadoncc = "Hoa don 5";
        hoadoncc.toCharArray(hoadon, 12);
        // Serial.println(hoadon[1]);

        u8g.firstPage();
        do
        {

          const char *unit = "k";
          const char *unit1 = "g";
          float nguyen, du = tonghoadon[i][1];
          nguyen = du / 1000;
          sprintf(tien1, "%d", ((gia[1] * tonghoadon[i][1]) / 1000));
          dtostrf(nguyen, 3, 2, showdonkl1);
          strcat(showdonkl1, unit);
          strcat(showdonkl1, unit1);

          du = tonghoadon[i][2];
          nguyen = du / 1000;
          sprintf(tien2, "%d", ((gia[2] * tonghoadon[i][2]) / 1000));
          dtostrf(nguyen, 3, 2, showdonkl2);
          strcat(showdonkl2, unit);
          strcat(showdonkl2, unit1);
          du = tonghoadon[i][3];
          nguyen = du / 1000;
          sprintf(tien3, "%d", ((gia[3] * tonghoadon[i][3]) / 1000));
          dtostrf(nguyen, 3, 2, showdonkl3);
          strcat(showdonkl3, unit);
          strcat(showdonkl3, unit1);
          du = tonghoadon[i][4];
          nguyen = du / 1000;
          sprintf(tien4, "%d", ((gia[4] * tonghoadon[i][4]) / 1000));
          dtostrf(nguyen, 3, 2, showdonkl4);
          strcat(showdonkl4, unit);
          strcat(showdonkl4, unit1);
          char tongtien[20] = "";
          sprintf(tongtien, "%d", ((gia[1] * tonghoadon[i][1]) / 1000) + ((gia[2] * tonghoadon[i][2]) / 1000) + ((gia[3] * tonghoadon[i][3]) / 1000) + ((gia[4] * tonghoadon[i][4]) / 1000));
          u8g.drawStr(0, 8, hoadon);
          u8g.drawStr(0, 19, "Carot    ");
          u8g.drawStr(51, 19, showdonkl1);
          u8g.drawStr(90, 19, tien1);
          u8g.drawStr(0, 30, "Khoaitay");
          u8g.drawStr(51, 30, showdonkl2);
          u8g.drawStr(90, 30, tien2);
          u8g.drawStr(0, 41, "Bi       ");
          u8g.drawStr(51, 41, showdonkl3);
          u8g.drawStr(90, 41, tien3);
          u8g.drawStr(0, 52, "Bapcai");
          u8g.drawStr(51, 52, showdonkl4);
          u8g.drawStr(90, 52, tien4);
          u8g.drawStr(51, 63, "TONG: ");
          u8g.drawStr(90, 63, tongtien);

        } while (u8g.nextPage());
        delay(5000);
      }

      ktkey1 = false;
      ktkey2 = false;
      ktkey3 = false;
      ktkey4 = false;
      ktkey5 = false;
      buoc1 = false;
      buoc2 = false;
      rt.toCharArray(hienthi1, 12);
      rt.toCharArray(hienthi2, 12);
      rt.toCharArray(hienthi3, 12);
      rt.toCharArray(hienthi4, 12);
      rt.toCharArray(hienthi5, 12);
      kl1 = 0;
      kl2 = 0;
      kl3 = 0;
      kl4 = 0;
      kl5 = 0;
      ktkl1;
      ktkl2;
      ktkl3;
      ktkl4;
      ktkl5;
      d1 = 0;
      d2 = 0;
      d3 = 0;
      d4 = 0;
      d5 = 0;
      for (int i = 0; i <= 5; i++)
      {
        xh[i] = 0;
        kll[i] = 0;
      }
      keystring = "";
    }
  }
}

String xemten(char x)
{
  if (x == '1')
    return "Carot";
  if (x == '2')
    return "Khoai tay";
  if (x == '3')
    return "Bi";
  if (x == '4')
    return "Bap cai";
  return "";
}
