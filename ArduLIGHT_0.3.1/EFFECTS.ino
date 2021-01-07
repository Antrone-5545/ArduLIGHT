void bounce(int del, int r, int g, int b)
{ 
  while (true){
  for(int dot = 0; dot < NUM_LEDS; dot++)
  { 
            leds[dot].r = r;
            leds[dot].g = g;
            leds[dot].b = b;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            delay(del);
            if (Serial.parseInt() == -999) reset();
  }
  }
}


void colour_cycle(int del ) 
{
  while(true){
for (int j = 0; j < 255; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(i - (j * 2), Bright, 255); 
    }
    FastLED.show();
    delay(del); 
    if (Serial.parseInt() == -999) reset();
  }
   if (Serial.parseInt() == -999) reset();
}}


 void rainbow(uint8_t spd)
 {
  while(true){
  
uint8_t thisSpeed = spd;
    uint8_t deltaHue= 10;
    uint8_t thisHue = beat8(thisSpeed,255); 
    fill_rainbow(leds, NUM_LEDS, thisHue, deltaHue);            
    FastLED.show();
    if (Serial.parseInt() == -999) reset();
  
  }}


void twink(int del)
{
  while(true){
  for (int a = 0; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Blue; FastLED.show();}
  for (int a = 2; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Green; FastLED.show();}
delay(del);
if (Serial.parseInt() == -999) reset();
  for (int a = 0; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Black; FastLED.show();}
  for (int a = 2; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Black; FastLED.show();}
if (Serial.parseInt() == -999) reset();
  for (int a = 1; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Orange; FastLED.show();}
  for (int a = 3; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Red; FastLED.show();}
delay(del);
if (Serial.parseInt() == -999) reset();
  for (int a = 1; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Black; FastLED.show();}
  for (int a = 3; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Black; FastLED.show();}
if (Serial.parseInt() == -999) reset();
  }
}

void ping_pong(int del,int r, int g, int b)
{
  while(true)
  {
  for(int dot = 0; dot < NUM_LEDS; dot++)
  { 
            leds[dot].r = r;
            leds[dot].g = g;
            leds[dot].b = b;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            delay(del);
            if (Serial.parseInt() == -999) reset();
  }

  
int dot = NUM_LEDS;    
   { 
    do
    {
            leds[dot].r = r;
            leds[dot].g = g;
            leds[dot].b = b;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            delay(del);
            if (Serial.parseInt() == -999) reset();
            dot--;
    } while (dot != 0);
   }     
  }
}
