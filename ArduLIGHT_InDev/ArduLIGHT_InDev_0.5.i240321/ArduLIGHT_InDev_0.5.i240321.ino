char buffer[24];
int ch;
int j;
bool counter;

bool counter1 = 0;
bool counter2;
bool counter3;
bool counter4;



int chCount;
//All
int led;
int r;
int g;
int b;

//Ch1
int led1;
int r1;
int g1;
int b1;
int dot1;

//Ch2
int led2;
int r2;
int g2;
int b2;
int dot2;

//Ch3
int led3;
int r3;
int g3;
int b3;
int dot3;

//Ch4
int led4;
int r4;
int g4;
int b4;
int dot4;


int Bright;
String com;
void(* reset) (void) = 0;
#include <FastLED.h>
#include <EEPROM.h>

//EDIT THIS:

#define LEDS 21 //MAX OF LEDS 

#define LEDS1 21 // CHANNEL 1 LEDS
#define LEDS2 21 // CHANNEL 2 LEDS
#define LEDS3 16 // CHANNEL 3 LEDS
#define LEDS4 8  // CHANNEL 4 LEDS

#define PIN1 5  // CHANNEL 1 PIN
#define PIN2 6  // CHANNEL 2 PIN
#define PIN3 7  // CHANNEL 3 PIN
#define PIN4 8  // CHANNEL 4 PIN
//---------


#define NUM_LEDS LEDS
#define NUM_LEDS1 LEDS1
#define NUM_LEDS2 LEDS2

#define NUM_LEDS3 LEDS3
#define NUM_LEDS4 LEDS4


int count1 = NUM_LEDS1;

CRGB leds[LEDS];
CRGB leds1[LEDS1];
CRGB leds2[LEDS2];
CRGB leds3[LEDS3];
CRGB leds4[LEDS4];
void setup() {
chCount = 4; //HOW MANY CHANNELS YOU HAVE        <-------------------------
  
  if(chCount > 0)
  {
     FastLED.addLeds<WS2812, PIN1, GRB>(leds1, LEDS1);
  }

    if(chCount > 1)
  {
     FastLED.addLeds<WS2812, PIN2, GRB>(leds2, LEDS2);
  }

    if(chCount > 2)
  {
     FastLED.addLeds<WS2812, PIN3, GRB>(leds3, LEDS3);
  }

    if(chCount > 3)
  {
     FastLED.addLeds<WS2812, PIN4, GRB>(leds4, LEDS4);
  }




  Serial.begin(115200);
   EEPROM.get(100, Bright);
  FastLED.setBrightness(Bright);
  Serial.println("Start");
  int i = 0;
  do {
    leds[i] = CRGB::Black;
    i++;
    FastLED.show();
  } while (i <= NUM_LEDS);

}

void loop()
{
  Serial.setTimeout(50);
  com = Serial.readString();
  checkWR();
  if (com == "")
  {
    EEPROM.get(1, ch);
    //All
    EEPROM.get(50, led);
    EEPROM.get(52, r);
    EEPROM.get(54, g);
    EEPROM.get(56, b);
    //Ch1
    EEPROM.get(10, led1);
    EEPROM.get(12, r1);
    EEPROM.get(14, g1);
    EEPROM.get(16, b1);    
    //Ch2
    EEPROM.get(20, led2);
    EEPROM.get(22, r2);
    EEPROM.get(24, g2);
    EEPROM.get(26, b2);   
    //Ch3
    EEPROM.get(30, led3);
    EEPROM.get(32, r3);
    EEPROM.get(34, g3);
    EEPROM.get(36, b3);
    //Ch4
    EEPROM.get(40, led4);
    EEPROM.get(42, r4);
    EEPROM.get(44, g4);
    EEPROM.get(46, b4);        
  }
  if (com != ""|| led != 0) {

    Serial.println("loop");
    com.toCharArray(buffer, 24);

if (com != "")
    {
      ch = atoi(strtok(buffer, " "));
      EEPROM.put(1, ch);

        if(ch == 1)
      {
         led1 = atoi(strtok(NULL, " "));
         r1 = atoi(strtok(NULL, " "));
         g1 = atoi(strtok(NULL, " "));
         b1 = atoi(strtok(NULL, " "));  

              if(led1 <0 && led1 > -51)
         {
         EEPROM.put(ch*10 + 0, led1);
         EEPROM.put(ch*10 + 2, r1);
         EEPROM.put(ch*10 + 4, g1);
         EEPROM.put(ch*10 + 6, b1);
         Serial.println("W");      
         }
      }
        if(ch == 2)
      {
         led2 = atoi(strtok(NULL, " "));
         r2 = atoi(strtok(NULL, " "));
         g2 = atoi(strtok(NULL, " "));
         b2 = atoi(strtok(NULL, " "));   

               if(led2 <0 && led2 > -51)
         {
         EEPROM.put(ch*10 + 0, led2);
         EEPROM.put(ch*10 + 2, r2);
         EEPROM.put(ch*10 + 4, g2);
         EEPROM.put(ch*10 + 6, b2);
         Serial.println("W");      
         }
      }
        if(ch == 3)
      {
         led3 = atoi(strtok(NULL, " "));
         r3 = atoi(strtok(NULL, " "));
         g3 = atoi(strtok(NULL, " "));
         b3 = atoi(strtok(NULL, " "));

         if(led3 <0 && led3> -51)
         {
         EEPROM.put(ch*10 + 0, led3);
         EEPROM.put(ch*10 + 2, r3);
         EEPROM.put(ch*10 + 4, g3);
         EEPROM.put(ch*10 + 6, b3);
         Serial.println("W");      
         }
      }
        if(ch == 4)
      {
         led4 = atoi(strtok(NULL, " "));
         r4 = atoi(strtok(NULL, " "));
         g4 = atoi(strtok(NULL, " "));
         b4= atoi(strtok(NULL, " "));

          if(led4 <0 && led4 > -51)
         {
         EEPROM.put(ch*10 + 0, led4);
         EEPROM.put(ch*10 + 2, r4);
         EEPROM.put(ch*10 + 4, g4);
         EEPROM.put(ch*10 + 6, b4);
         Serial.println("W");      
         }
      }
        if(ch == 5)
      {
         led = atoi(strtok(NULL, " "));
         r = atoi(strtok(NULL, " "));
         g = atoi(strtok(NULL, " "));
         b = atoi(strtok(NULL, " "));

          if(led <0 && led > -556)
         {
         EEPROM.put(ch*10 + 0, led);
         EEPROM.put(ch*10 + 2, r);
         EEPROM.put(ch*10 + 4, g);
         EEPROM.put(ch*10 + 6, b);
         Serial.println("W");      
         }
      }
       
     
    }
   
if(led == -555)
{ Serial.setTimeout(3);
   while (true){
    
  if (chCount > 0)
  {
   Serial.println("1"); 
    
      if (led1 == -1) bounce(r1, g1, 1);

      if (led1 == -2) colour_cycle(r1, 1);
      
      if (led1 == -3) rainbow(r1*2,g1, 1);

      if (led1 == -4) twink(r1*5, 1);

      if (led1 == -5) ping_pong(r1, g1, 1);

      if (led1 == -6) static_color();

      if (led1 == -7) tetris(r, 1);
  }

  if (chCount > 1)
  {
    Serial.println("2"); 
      if (led2 == -1) bounce(r2, g2, 2);

      if (led2 == -2) colour_cycle(r2, 2);
      
      if (led2 == -3) rainbow(r2*2,g2, 2);

      if (led2 == -4) twink(r2*5, 2);

      if (led2 == -5) ping_pong(r2, g2, 2);

      if (led2 == -6) static_color();

      if (led2 == -7) tetris(r, 2);
  }

    if (chCount > 2)
  {
    Serial.println("3"); 
      if (led3 == -1) bounce(r3, g3, 3);

      if (led3 == -2) colour_cycle(r3, 3);
      
      if (led3 == -3) rainbow(r3*2,g3, 3);

      if (led3 == -4) twink(r3*5, 3);

      if (led3 == -5) ping_pong(r3, g3, 3);

      if (led3 == -6) static_color();

      if (led3 == -7) tetris(r, 3);
  }

    if (chCount > 3)
  {
    Serial.println("4"); 
      if (led4 == -1) bounce(r4, g4, 4);

      if (led4 == -2) colour_cycle(r4, 4);
      
      if (led4 == -3) rainbow(r4*2,g4, 4);

      if (led4 == -4) twink(r4*5 ,4);

      if (led4 == -5) ping_pong(r4, g4, 4);

      if (led4== -6) static_color();

      if (led4 == -7) tetris(r, 4);
  }
  
  if (led1 == -1 || led1 == -7) leds1[dot1 -1] = CRGB::Black;
  if (led2 == -1) leds2[dot2 -1] = CRGB::Black;
  if (led3 == -1) leds3[dot3 -1] = CRGB::Black;
  if (led4 == -1) leds4[dot4 -1] = CRGB::Black;

  if (led1 == -5 && counter1 == 0) leds1[dot1 -1] = CRGB::Black;
  else if(led1 == -5) leds1[dot1 +1] = CRGB::Black;
  
    if (led2 == -5 && counter2 == 0) leds2[dot2 -1] = CRGB::Black;
  else if(led2 == -5) leds2[dot2 +1] = CRGB::Black;
  
    if (led3 == -5 && counter3 == 0) leds3[dot3 -1] = CRGB::Black;
  else if(led3 == -5) leds3[dot3 +1] = CRGB::Black;
  
    if (led4 == -5 && counter4 == 0) leds4[dot4 -1] = CRGB::Black;
  else if(led4 == -5) leds4[dot4 +1] = CRGB::Black;

   FastLED.show();
  
   check();
   }
}     



      
      if(r1+g1+b1+r2+g2+b2+r3+g3+b3+r4+g4+b4 != 0)
      {
        if(ch == 1)
        {
          leds1[led1].r = r1;
          leds1[led1].g = g1;
          leds1[led1].b = b1;
        }
        
        if(ch == 2)
        {
          leds2[led2].r = r2;
          leds2[led2].g = g2;
          leds2[led2].b = b2;
        }
        
        if(ch == 3)
        {
          leds3[led3].r = r3;
          leds3[led3].g = g3;
          leds3[led3].b = b3;
        }

        if(ch == 4)
        {
          leds4[led4].r = r4;
          leds4[led4].g = g4;
          leds4[led4].b = b4;
        }
                        
      }
       checkWR();
      FastLED.show();







    
    }
  }
  
