char buffer[19];
int led;
int r;
int g;
int b;
String com;
void(* reset) (void) = 0;
#include <FastLED.h>

//EDIT THIS:
#define LEDS 120
#define NUM_LEDS 120
#define PIN 5
int Bright = 255 ;
//---------
CRGB leds[LEDS];
void setup() {
  FastLED.addLeds<WS2812, PIN, GRB>(leds, LEDS);
  Serial.begin(115200);
  FastLED.setBrightness(Bright);
  Serial.println("Start");
  Serial.setTimeout(50);
  int i = 0;
  do {
    leds[i] = CRGB::Black;
    i++;
    FastLED.show();
  } while (i < NUM_LEDS);

}

void loop()
{
  com = "";
  com = Serial.readString();
  if (com != "") {

    Serial.println("Start");
    com.toCharArray(buffer, 16);

    led = atoi(strtok(buffer, " "));
    r = atoi(strtok(NULL, " "));
    g = atoi(strtok(NULL, " "));
    b = atoi(strtok(NULL, " "));

    if (led == -999) reset();

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
      Serial.setTimeout(10); 
        colour_cycle(r);
      }
      if (led == -3)
      {
        Serial.setTimeout(3);
        rainbow(r*2);
      }

      if (led == -4) {
        Serial.setTimeout(3);
        twink(g);
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
      leds[led].r = r;
      leds[led].g = g;
      leds[led].b = b;
      FastLED.show();
    }
  }
