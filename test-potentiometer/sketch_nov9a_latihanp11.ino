int led = 8;
int potentiometer = A2;
int button = 7;

void setup() 
{
  Serial.begin(9600);
  pinMode (button, INPUT_PULLUP);
  pinMode (led, OUTPUT);
}

void loop()
{
  int poten = analogRead(potentiometer);
  int buttonState = digitalRead(button);
  if (buttonState == 0)
  {
    digitalWrite(led, LOW);
    Serial.println(poten);
    delay (198);
    
  }
  else if (buttonState == 1)
  {
    digitalWrite (led, HIGH);
   
  }
  
}

