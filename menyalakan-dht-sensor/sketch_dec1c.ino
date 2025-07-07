

#include <DHT.h>

DHT dht (2, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float kelembaban = dht.readHumidity();
  float suhu = dht.readTemperature();

  if (isnan(kelembaban) || isnan (suhu)){
    Serial.println (F("gagal membaca data dht sensor"));
    return;
  }
  Serial.print ("kelembaban : ");
  Serial.println (kelembaban);
  Serial.print ("suhu: ");
  Serial.println (suhu);
}
