void wipe()
{
  led = 0;
  r = 0;
  g = 0;
  b = 0;
    EEPROM.put(0, led);
    EEPROM.put(2, r);
    EEPROM.put(4, g);
    EEPROM.put(6, b);
    Serial.println("Wipe");
}

void check()
{
 led = Serial.parseInt();
  if (led == -999 ) { wipe(); reset();}
  if (led >0)
  {
    Bright = led;
     FastLED.setBrightness(Bright);
       EEPROM.put(10, Bright);

  }
}
void checkWR()
{
  if (led == -999 ) { wipe(); reset();}
  if (led >0 && r+g+b == 0)
  {
    Bright = led;
     FastLED.setBrightness(Bright);
       EEPROM.put(10, Bright);
  }
}
   
