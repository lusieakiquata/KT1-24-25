#include <HX711_ADC.h>
HX711_ADC can1(7, 6); // dt,sck
HX711_ADC can2(9, 8);
HX711_ADC can3(11, 10);
HX711_ADC can4(13, 12);
HX711_ADC can5(5, 4);
void setup() {
Serial.begin(9600);
  can1.begin();
  can2.begin();
  can3.begin();
  can4.begin();
  can5.begin();
  can1.setCalFactor(95.7);
  can2.setCalFactor(95.7);
  can3.setCalFactor(95.7);
  can4.setCalFactor(95.7);
  can5.setCalFactor(95.7);
  can1.tare();
  can2.tare();
  can3.tare();
  can4.tare();
  can5.tare();
}

void loop() {
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
    Serial.print(kcan1);Serial.print("g ");
    Serial.print(kcan2);Serial.print("g ");
    Serial.print(kcan3);Serial.print("g ");
    Serial.print(kcan4);Serial.print("g ");
    Serial.print(kcan5);Serial.println("g ");
  // put your main code here, to run repeatedly:

}
