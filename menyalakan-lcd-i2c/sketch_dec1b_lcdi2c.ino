#include <LiquidCrystal_I2C.h>

// Sesuaikan alamat I2C dan ukuran LCD sesuai dengan perangkat Anda
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.begin(16, 2); // Ukuran LCD disertakan di sini, bisa jadi berbeda tergantung pada LCD yang Anda gunakan
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Test LCD I2C");
  lcd.setCursor(0, 1);
  lcd.print("Firda Rosela Sundari");
}
