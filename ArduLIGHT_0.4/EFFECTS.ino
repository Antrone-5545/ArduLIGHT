void bounce(int del, 
int r, int g, int b)
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
              check();
  }
  }
}


void colour_cycle(int del ) 
{
  while(true){
for (int j = 0; j < 255; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(i - (j * 2), 255, 255); 
    }
    FastLED.show();
    delay(del); 
      check();
  }
    check();
}}


 void rainbow(uint8_t spd, int den)
 {
  while(true){
  check();
uint8_t thisSpeed = spd;
check();
    uint8_t deltaHue=den;
    check();
    uint8_t thisHue = beat8(thisSpeed,255);
    check(); 
    fill_rainbow(leds, NUM_LEDS, thisHue, deltaHue);
    check();            
    FastLED.show();
    check();
  
  }}


void twink(int del)
{
  while(true){
  for (int a = 0; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Blue; FastLED.show();}
  for (int a = 2; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Green; FastLED.show();}
delay(del);
 check();
  for (int a = 0; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Black; FastLED.show();}
  for (int a = 2; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Black; FastLED.show();}
  check();
  for (int a = 1; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Orange; FastLED.show();}
  for (int a = 3; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Red; FastLED.show();}
delay(del);
  check();
  for (int a = 1; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Black; FastLED.show();}
  for (int a = 3; a <= NUM_LEDS; a = a + 4 ) {leds[a] = CRGB::Black; FastLED.show();}
  check();
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
              check();
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
              check();
            dot--;
    } while (dot != 0);
   }     
  }
}

void static_color()
{
  while(true){
  int i = 0;
  Serial.setTimeout(10);
    com = Serial.readString();
    if (com != "") 
    {
     Serial.print("X");
    com.toCharArray(buffer, 16);
    led = atoi(strtok(buffer, " "));
    r = atoi(strtok(NULL, " "));
    g = atoi(strtok(NULL, " "));
    b = atoi(strtok(NULL, " "));
    FastLED.setBrightness(led);
     if (led == -999) { wipe(); reset();}

      do {

    leds[i].r = r;
    leds[i].g = g;
    leds[i].b = b;
    i++;
    
    
    FastLED.show();
  } while (i < NUM_LEDS);
    }
  

}}

void tetris(int del)
{
  int count = NUM_LEDS;
  CRGB Color;
  while (true){
  for(int dot = 0; dot < count; dot++)
  { 
    
  int c = random(0, 9);
  if (c ==0) Color = CRGB::White;
  if (c ==1) Color = CRGB::Red;
  if (c ==2) Color = CRGB::Orange;
  if (c ==3) Color = CRGB::Yellow;
  if (c ==4) Color = CRGB::Green;
  if (c ==5) Color = CRGB::Cyan;
  if (c ==6) Color = CRGB::Blue;
  if (c ==7) {Color.r = 255; Color.g = 0; Color.b = 120;}
  if (c ==8) {Color.r = 255; Color.g = 0; Color.b = 255;}
            leds[dot] = Color;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            delay(del);
              check();
  }
  leds[count] = Color;
  FastLED.show();
  count = count -1;
  if (count < 0)
  {
    count = NUM_LEDS;
    delay(2000);
    int i = 0;
    do {
    leds[i] = CRGB::Black;
    i++;
    delay(100);
    FastLED.show();
  } while (i < NUM_LEDS);
  }
  }
}
