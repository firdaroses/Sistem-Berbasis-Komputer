#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);
DHT dht (2, DHT11);

#define kipas  5

void setup() {
  
  Serial.begin(9600);
  pinMode(kipas,OUTPUT);

  dht.begin();
  lcd.backlight();
  lcd.begin(16, 2);

  lcd.setCursor(1, 0);
  lcd.print ("KIPAS OTOMATIS");

  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(1000);


}

void loop() 
{
  delay(2000);
  float kelembaban = dht.readHumidity();
  float suhu = dht.readTemperature();

  if (isnan(kelembaban) || isnan (suhu)){
    Serial.println (F("gagal membaca data dht sensor"));
    return;
  }

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Suhu: ");
  lcd.print(suhu, 1); // Print one decimal place
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Kelembaban: ");
  lcd.print(kelembaban, 1); // Print one decimal place
  lcd.print(" %");
  delay(1000);

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" C");

  if (suhu > 25.00){
    lcd.clear();
    digitalWrite (kipas, LOW);
    Serial.println("menyalakan kipas");
    lcd.print ("ON");
  }
  else{
    lcd.clear();
    digitalWrite (kipas, HIGH);
    lcd.print ("OFF");
  }
}

