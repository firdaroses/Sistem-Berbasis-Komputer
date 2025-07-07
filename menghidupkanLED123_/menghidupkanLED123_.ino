#include <Servo.h>

const int trigPin = 4;
const int echoPin = 3;
const int servoPin = 2;
const int speakerPin = 12;

Servo myservo;
int pos = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance < 30) {
    myservo.write(180);
    delay(1000);
    digitalWrite(speakerPin, HIGH);
    delay(500);
    digitalWrite(speakerPin, LOW);
    delay(500);
    digitalWrite(speakerPin, HIGH);
    delay(500);
    digitalWrite(speakerPin, LOW);
    delay(500);
    myservo.write(0);
    delay(1000);
  }
}