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

  //if (adc.getData()) {
    float weight;
    weight = adc.getData(); // Lấy giá trị trọng lượng (kg)
    Serial.print("Weight: ");
    Serial.print(weight, 2);
    Serial.println(" kg");
    //adc.setData(0);
  //}

  delay(50); // Đợi 500 ms giữa các lần đọc
}
