#include <HX711_ADC.h>

// Khai báo module HX711 với chân DT và SCK
const int HX711_dout = 4;  // Chân DT của HX711
const int HX711_sck = 5;   // Chân SCK của HX711

HX711_ADC LoadCell(HX711_dout, HX711_sck);

void setup() {
  Serial.begin(9600);  // Thiết lập giao tiếp Serial
  LoadCell.begin();  // Khởi động cảm biến
  delay(1000);  // Chờ 1 giây để cảm biến ổn định
  LoadCell.start(2000);  // Khởi tạo và hiệu chỉnh cảm biến trong 2 giây
  LoadCell.setCalFactor(696.0);  // Đặt hệ số hiệu chỉnh (calibration factor)
  Serial.println("HX711 setup complete");
}

void loop() {
  // Cập nhật dữ liệu từ cảm biến
  LoadCell.update();

  // Kiểm tra xem dữ liệu mới đã sẵn sàng chưa
  if (LoadCell.getData() > 0) {
    float weight = LoadCell.getData();
    Serial.print("Trọng lượng: ");
    Serial.print(weight);
    Serial.println(" kg");
  } else {
    Serial.println("Cảm biến không phản hồi.");
  }
  delay(1000);
}
