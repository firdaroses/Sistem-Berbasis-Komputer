// deklarasi library 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
// untuk membaca data dari sensor


// inisailisasi
LiquidCrystal_I2C lcd (0x27, 16, 2); // lcd digunakan untuk mengendalikan tampilan lcd
DHT dht (4, DHT11);

// dht digunakan untuk membaca data dari sensor dht11

//deklarasi pin
#define kipas 9
// kipas digunakan untuk mengontrol kipas

void setup() 
{
  Serial.begin (9600); // baudrate yg digunakan antara laptop dengan arduino secara serial
  pinMode (kipas, OUTPUT); // untuk memfungsikan si kipas sebagai output, arduino akan mengeluarkan sinyal atau data

  dht.begin();

  lcd.begin (16, 2); // lcd yg digunakan 16x2
  lcd.backlight(); // untuk menyalakan lcdnya
  
  lcd.setCursor (1, 0); // untuk mengatur posisi teksnya
  lcd.print ("KIPAS OTOMATIS");

}

void loop() 
{
  delay (3000);
  
  float suhu = dht.readTemperature(); // mendeklarasikan suhu
  float kelembaban = dht.readHumidity(); // mendeklarasikan kelembaban

  if (isnan (suhu) || isnan (kelembaban)){
    
    lcd.setCursor (1, 0);
    lcd.print ("Gagal Membaca"); // gagal membaca sensor
    lcd.setCursor (5, 1);
    lcd.print ("Sensor");
    return;
  }

// untuk menampilkan suhu dan kelembaban di lcd
   lcd.clear();
   lcd.setCursor (0, 0);
   lcd.print ("Suhu : ");
   lcd.print (suhu, 0);
   lcd.print ("C ");

// kondisi untuk menyalakan kipas
  if (suhu > 28){
    digitalWrite (kipas, HIGH);
    lcd.setCursor(9, 1);
    lcd.print ("K: on");
  }
  else {
    lcd.setCursor(9, 1);
    digitalWrite (kipas, LOW);
    lcd.print ("K: off");
  }

  lcd.setCursor(0, 1);
  lcd.print("LB :");
  lcd.print(kelembaban, 0); // Print one decimal place
  lcd.print("%");
  delay (1000);

  lcd.clear();
  lcd.print ("KIPAS FIRDA");

}
