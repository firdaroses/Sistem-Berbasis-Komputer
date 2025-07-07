void setup()
{
  pinmode (led1, output);
  pinmode (led2, output);
  pinmode (led3, output);
}

void loop()
{
  digitalwrite (led1, high);
  delay (3000);
  digitalwrite (led1, low);
  delay (1000);

  digitalwrite (led2, high);
  delay (3000);
  digitalwrite (led2, low);
  delay (1000);

  digitalwrite (led3, high);
  delay (3000);
  digitalwrite (led3, low);
  delay (1000);
}  
