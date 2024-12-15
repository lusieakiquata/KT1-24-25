
#include<Keypad.h>
#include <HX711_ADC.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
byte rowPins[4] = {45, 43, 41, 39};
byte colPins[4] = {53, 51, 49, 47};
char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
HX711_ADC can1(1, 2);
HX711_ADC can2(3, 4);
HX711_ADC can3(5, 6);
HX711_ADC can4(7, 8);
HX711_ADC can5(9, 10);
Keypad key4x4 = Keypad(makeKeymap(keys), rowPins, colPins,4, 4);
char nut4[4][1]={
      {'1','2','3','4'}
}
    r1={1}
Keypad phim1 = Keypad(makeKeymap(nut4), rowPins, colPins,4, 4);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
