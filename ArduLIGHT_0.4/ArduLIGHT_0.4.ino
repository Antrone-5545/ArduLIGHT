char buffer[19];
int led;
int r;
int g;
int b;
int Bright;
String com;
void(* reset) (void) = 0;
#include <FastLED.h>
#include <EEPROM.h>

//EDIT THIS:
#define LEDS 21
#define NUM_LEDS 21
#define PIN 5
//---------


CRGB leds[LEDS];
void setup() {
  FastLED.addLeds<WS2812, PIN, GRB>(leds, LEDS);
  Serial.begin(115200);
   EEPROM.get(10, Bright);
  FastLED.setBrightness(Bright);
  Serial.println("Start");
  Serial.setTimeout(3);
  int i = 0;
  do {
    leds[i] = CRGB::Black;
    i++;
    FastLED.show();
  } while (i < NUM_LEDS);

}

void loop()
{
  
  check();
  com = "";
  com = Serial.readString();
  if (com == "")
  {
       
    EEPROM.get(0, led);
    EEPROM.get(2, r);
    EEPROM.get(4, g);
    EEPROM.get(6, b);
    
   
    
  }
  if (com != ""|| led != 0) {

    Serial.println("loop");
    com.toCharArray(buffer, 16);

if (com != "")
    {
    led = atoi(strtok(buffer, " "));
    r = atoi(strtok(NULL, " "));
    g = atoi(strtok(NULL, " "));
    b = atoi(strtok(NULL, " "));
    }
   if(led <0 && led > -51)
   {
    EEPROM.put(0, led);
    EEPROM.put(2, r);
    EEPROM.put(4, g);
    EEPROM.put(6, b);
    Serial.println("W");
   }

    
  
    if (led == -1)
    {
      Serial.setTimeout(3);
      if (r == 1) bounce(g, 255, 0, 0);
      if (r == 2) bounce(g, 255, 120, 0);
      if (r == 3) bounce(g, 255, 255, 0);
      if (r == 4) bounce(g, 0, 255, 0);
      if (r == 5) bounce(g, 0, 120, 255);
      if (r == 6) bounce(g, 0, 0, 255);
      if (r == 7) bounce(g, 255, 0, 255);
    }

    if (led == -2) {
      Serial.setTimeout(3); 
        colour_cycle(r);
      }
      if (led == -3)
      {
        Serial.setTimeout(3);
        rainbow(r*2,g);
      }

      if (led == -4) {
        Serial.setTimeout(3);
        twink(r*5);
      }

      if (led == -5)
      {
        Serial.setTimeout(3);
        if (r == 1) ping_pong(g, 255, 0, 0);
        if (r == 2) ping_pong(g, 255, 120, 0);
        if (r == 3) ping_pong(g, 255, 255, 0);
        if (r == 4) ping_pong(g, 0, 255, 0);
        if (r == 5) ping_pong(g, 0, 120, 255);
        if (r == 6) ping_pong(g, 0, 0, 255);
        if (r == 7) ping_pong(g, 255, 0, 255);
      }

      if (led == -6) static_color();

      if (led == -7) tetris(r);
      
      if(r+g+b > 0){
      leds[led].r = r;
      leds[led].g = g;
      leds[led].b = b;
      }
       checkWR();
      FastLED.show();







    
    }
  }
