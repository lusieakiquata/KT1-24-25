#include <Keypad.h>

// Kích thước của ma trận phím bấm
const byte ROWS = 4; // 4 hàng
const byte COLS = 4; // 4 cột

// Ký tự trên các phím của ma trận phím bấm
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Chân kết nối của các hàng và cột
byte rowPins[4] = {45, 43, 41, 39};
byte colPins[4] = {53, 51, 49, 47};

// Khởi tạo đối tượng Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Khởi động giao tiếp Serial
}

void loop() {
  char key = keypad.getKey(); // Đọc phím bấm

  if (key) {
    Serial.print("You pressed: ");
    Serial.println(key); // In ra phím vừa bấm
  }
}
