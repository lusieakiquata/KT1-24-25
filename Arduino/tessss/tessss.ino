#include <HX711_ADC.h>

// Khai báo các chân kết nối
const int HX711_DOUT_PIN = 2; // Chân DOUT của HX711
const int HX711_SCK_PIN = 3;  // Chân SCK của HX711

HX711_ADC adc(HX711_DOUT_PIN, HX711_SCK_PIN);

void setup() {
  Serial.begin(9600);           // Khởi động giao tiếp Serial
  adc.begin();                  // Khởi tạo HX711
  adc.start(1000);              // Chờ HX711 ổn định
  adc.setCalFactor(69000.0);     // Đặt hệ số hiệu chuẩn (tùy chỉnh)
  adc.tare();                   // Tính trọng lượng ban đầu (zero)
  Serial.println("HX711 initialized.");
}

void loop() {
  adc.update(); // Cập nhật giá trị từ HX711
  bool kt=false;
  int i,kl;
  int a[21];
  a[1]=0;
while (kt != true ){
      i++;
      a[i]=0;
    float p;
    p = adc.getData();
    a[i]= p *100;
 adc.update();
if (i>20) i=0;

    if (a[1]==a[20] && a[2]==a[15]&& a[3]==a[10]&& a[1]>10) {kt= true;kl=a[1];Serial.print ("done ");}
    
  

  delay (50);
  }
Serial.println (kl);
  delay(2000); // Đợi 500 ms giữa các lần đọc
}
