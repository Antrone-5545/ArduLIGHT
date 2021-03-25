void wipe()
{
   ch = 0;
  EEPROM.put(1, ch);
  led = 0;
  r = 0;
  g = 0;
  b = 0;
    EEPROM.put(50, led);
    EEPROM.put(52, r);
    EEPROM.put(54, g);
    EEPROM.put(56, b);
    Serial.println("Wipe0");

  led1 = 0;
  r1 = 0;
  g1 = 0;
  b1 = 0;
    EEPROM.put(10, led1);
    EEPROM.put(12, r1);
    EEPROM.put(14, g1);
    EEPROM.put(16, b1);
    Serial.println("Wipe1");

      led2 = 0;
  r2 = 0;
  g2 = 0;
  b2 = 0;
    EEPROM.put(20, led2);
    EEPROM.put(22, r2);
    EEPROM.put(24, g2);
    EEPROM.put(26, b2);
    Serial.println("Wipe2");


      led3 = 0;
  r3 = 0;
  g3 = 0;
  b3 = 0;
    EEPROM.put(30, led3);
    EEPROM.put(32, r3);
    EEPROM.put(34, g3);
    EEPROM.put(36, b3);
    Serial.println("Wipe3");

      led4 = 0;
  r4 = 0;
  g4 = 0;
  b4 = 0;
    EEPROM.put(40, led4);
    EEPROM.put(42, r4);
    EEPROM.put(44, g4);
    EEPROM.put(46, b4);
    Serial.println("Wipe4");
}

void check()
{
 led = Serial.parseInt();
  if(led == -900) {EEPROM.put(1, 0); EEPROM.put(50, 0); reset();}
  if (led == -999 ) { wipe(); reset();}
  if (led >0)
  {
    Bright = led;
     FastLED.setBrightness(Bright);
       EEPROM.put(100, Bright);

  }
}
void checkWR()
{
  if(led == -900) {EEPROM.put(1, 0); EEPROM.put(50, 0); reset();}
  if (led == -999 ) { wipe(); reset();}
  if (led >0 && r+g+b == 0)
  {
    Bright = led;
     FastLED.setBrightness(Bright);
       EEPROM.put(100, Bright);
  }
}
   
