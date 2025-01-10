#include <U8glib.h>

// Khởi tạo màn hình LCD ST7920
U8GLIB_ST7920_128X64 u8g(5, 4, 3, 2);  // SCK, MOSI, CS

void setup() {}
void drawHouse() {
  // Vẽ tường ngôi nhà (hình chữ nhật)
  u8g.drawBox(30, 30, 60, 40);  // X, Y, width, height

  // Vẽ mái ngói (hình tam giác)
  u8g.drawTriangle(30, 30, 60, 10, 90, 30);  // 3 điểm của tam giác

  // Vẽ cửa sổ (hình vuông)
  u8g.drawBox(40, 40, 15, 15);  // Vị trí và kích thước cửa sổ

  // Vẽ cửa chính (hình chữ nhật)
  u8g.drawBox(60, 50, 20, 20);  // Vị trí và kích thước cửa chính
}

void loop() {
  // Bắt đầu vẽ nội dung lên màn hình
  u8g.firstPage();
  do {
    drawHouse();
  } while (u8g.nextPage());
  
  delay(1000);  // Chờ 1 giây trước khi lặp lại
}

