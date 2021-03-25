void bounce(int del, int c, int chn)
{ 
  Serial.setTimeout(3);
  CRGB Color;
  if (c ==0) Color = CRGB::White;
  if (c ==1) Color = CRGB::Red;
  if (c ==2) Color = CRGB::Orange;
  if (c ==3) Color = CRGB::Yellow;
  if (c ==4) Color = CRGB::Green;
  if (c ==5) Color = CRGB::Cyan;
  if (c ==6) Color = CRGB::Blue;
  if (c ==7) {Color.r = 255; Color.g = 0; Color.b = 120;}
  if (c ==8) {Color.r = 255; Color.g = 0; Color.b = 255;}

  
  if(chn == 1)
  {
  if( dot1 <= NUM_LEDS1)
  { 
            leds1[dot1] = Color;           
            delay(del);
            dot1++;
              check();
              Serial.println("b1"); 
  }
  else dot1 = 0;
  }


  if(chn ==2)
  {
    if( dot2 <= NUM_LEDS2)
  { 
            leds2[dot2] = Color;       
            delay(del);
            dot2++;
              check();
              Serial.println("b2"); 
  }
  else dot2 = 0;
  }

   if(chn ==3)
   { 
    if( dot3 <= NUM_LEDS3)
  { 
            leds3[dot3] = Color;
            delay(del);
            dot3++;
              check();
              Serial.println("b3"); 
  }
  else dot3 = 0;
  }

   if(chn ==4)
   {
    if( dot4 <= NUM_LEDS4)
  { 
            leds4[dot4] = Color;
            delay(del);
            dot4++;
              check();
  }
  else dot4 = 0;
   }
}



void colour_cycle(int del, int chn ) 
{
if(j < 255) {
  j++;
    for (int i = 0; i < NUM_LEDS; i++) {
      if(chn == 1) leds1[i] = CHSV(i - (j * 2), 255, 255);
      if(chn == 2) leds2[i] = CHSV(i - (j * 2), 255, 255); 
      if(chn == 3) leds3[i] = CHSV(i - (j * 2), 255, 255); 
      if(chn == 4) leds4[i] = CHSV(i - (j * 2), 255, 255); 
       
    } 
   
    delay(del); 
      check();
  } else j = 0;
    check();
}


 void rainbow(uint8_t spd, int den, int ch)
 {
  Serial.setTimeout(3);
 
 uint8_t thisSpeed = spd;
    uint8_t deltaHue=den;
    uint8_t thisHue = beat8(thisSpeed,255);
    if (ch == 1) fill_rainbow(leds1, NUM_LEDS1, thisHue, deltaHue);
    if (ch == 2) fill_rainbow(leds2, NUM_LEDS2, thisHue, deltaHue);
    if (ch == 3) fill_rainbow(leds3, NUM_LEDS3, thisHue, deltaHue);
    if (ch == 4) fill_rainbow(leds4, NUM_LEDS4, thisHue, deltaHue);
    check();            
    
   
  
  }


void twink(int del, int chn)
{
 
    if(chn == 1)
  {
  if(counter == 1)
  {
  int i = 0;  
  do { leds1[i] = CRGB::Black; i++; } while (i <= NUM_LEDS1);
  for (int a = 0; a <= NUM_LEDS1; a = a + 4 ) {leds1[a] = CRGB::Blue;}
  for (int a = 2; a <= NUM_LEDS1; a = a + 4 ) {leds1[a] = CRGB::Green;}
  delay(del);
  check();
  counter = 0;
  }
  else
  {
  int i = 0;  
  do { leds1[i] = CRGB::Black; i++; } while (i <= NUM_LEDS1);
  for (int a = 1; a <= NUM_LEDS1; a = a + 4 ) {leds1[a] = CRGB::Orange;}
  for (int a = 3; a <= NUM_LEDS1; a = a + 4 ) {leds1[a] = CRGB::Red;}
  delay(del);
  check();
  counter = 1;
  }
  }


    if(chn == 2)
  {
  if(counter == 1)
  {
  int i = 0;  
  do { leds2[i] = CRGB::Black; i++; } while (i <= NUM_LEDS2);
  for (int a = 0; a <= NUM_LEDS2; a = a + 4 ) {leds2[a] = CRGB::Blue;}
  for (int a = 2; a <= NUM_LEDS2; a = a + 4 ) {leds2[a] = CRGB::Green;}
  delay(del);
  check();
  counter = 0;
  }
  else
  {
  int i = 0;  
  do { leds2[i] = CRGB::Black; i++; } while (i <= NUM_LEDS2);
  for (int a = 1; a <= NUM_LEDS2; a = a + 4 ) {leds2[a] = CRGB::Orange;}
  for (int a = 3; a <= NUM_LEDS2; a = a + 4 ) {leds2[a] = CRGB::Red;}
  delay(del);
  check();
  counter = 1;
  }
  }



    if(chn == 3)
  {
  if(counter == 1)
  {
  int i = 0;  
  do { leds3[i] = CRGB::Black; i++; } while (i <= NUM_LEDS3);
  for (int a = 0; a <= NUM_LEDS3; a = a + 4 ) {leds3[a] = CRGB::Blue;}
  for (int a = 2; a <= NUM_LEDS3; a = a + 4 ) {leds3[a] = CRGB::Green;}
  delay(del);
  check();
  counter = 0;
  }
  else
  {
  int i = 0;  
  do { leds3[i] = CRGB::Black; i++; } while (i <= NUM_LEDS3);
  for (int a = 1; a <= NUM_LEDS3; a = a + 4 ) {leds3[a] = CRGB::Orange;}
  for (int a = 3; a <= NUM_LEDS3; a = a + 4 ) {leds3[a] = CRGB::Red;}
  delay(del);
  check();
  counter = 1;
  }
  }

  
    if(chn == 4)
  {
  if(counter == 1)
  {
  int i = 0;  
  do { leds4[i] = CRGB::Black; i++; } while (i <= NUM_LEDS4);
  for (int a = 0; a <= NUM_LEDS4; a = a + 4 ) {leds4[a] = CRGB::Blue;}
  for (int a = 2; a <= NUM_LEDS4; a = a + 4 ) {leds4[a] = CRGB::Green;}
  delay(del);
  check();
  counter = 0;
  }
  else
  {
  int i = 0;  
  do { leds4[i] = CRGB::Black; i++; } while (i <= NUM_LEDS4);
  for (int a = 1; a <= NUM_LEDS4; a = a + 4 ) {leds4[a] = CRGB::Orange;}
  for (int a = 3; a <= NUM_LEDS4; a = a + 4 ) {leds4[a] = CRGB::Red;}
  delay(del);
  check();
  counter = 1;
  }
  }
  
}

void ping_pong(int del, int c, int chn)
{
Serial.setTimeout(3);
  CRGB Color;
  if (c ==0) Color = CRGB::White;
  if (c ==1) Color = CRGB::Red;
  if (c ==2) Color = CRGB::Orange;
  if (c ==3) Color = CRGB::Yellow;
  if (c ==4) Color = CRGB::Green;
  if (c ==5) Color = CRGB::Cyan;
  if (c ==6) Color = CRGB::Blue;
  if (c ==7) {Color.r = 255; Color.g = 0; Color.b = 120;}
  if (c ==8) {Color.r = 255; Color.g = 0; Color.b = 255;}

  
 if(chn == 1)
  {
  if( dot1 <= NUM_LEDS1 && counter1 == 0)
  { 
            leds1[dot1] = Color;           
            delay(del);
            dot1++;
              check();
              Serial.println(dot1); 
  }
  if (dot1 > NUM_LEDS1 || counter1 == 1 )
  { 
    counter1 = 1;
    delay(del);
    check();
    dot1-- ;  
    leds1[dot1] = Color;
    Serial.println(dot1); 
    if (dot1 == 0) {dot1 = 0; counter1 = 0;}
  }

  }
  


 if(chn == 2)
  {
  if( dot2 <= NUM_LEDS2 && counter2 == 0)
  { 
            leds2[dot2] = Color;           
            delay(del);
            dot2++;
              check();
              Serial.println("b2"); 
  }
  
  else if (dot2 >= 0 )
  { 
    counter2 = 1;
    leds2[dot2] = Color;
    delay(del);
    check();
    dot2--;  
    
  }
  else {dot2 = 0; counter2 = 0;}
  }

  if(chn == 3)
  {
  if( dot3 <= NUM_LEDS3 && counter3 == 0)
  { 
            leds3[dot3] = Color;           
            delay(del);
            dot3++;
              check();
              Serial.println("b3"); 
  }
  
  else if (dot3 >= 0 )
  { 
    counter3 = 1;
    leds3[dot3] = Color;
    delay(del);
    check();
    dot3--;  
    
  }
  else {dot3 = 0; counter3 = 0;}
  }

  if(chn == 4)
  {
  if( dot4 <= NUM_LEDS4 && counter4 == 0)
  { 
            leds4[dot4] = Color;           
            delay(del);
            dot4++;
              check();
              Serial.println("b4"); 
  }
  
  else if (dot4 >= 0 )
  { 
    counter4 = 1;
    leds4[dot4] = Color;
    delay(del);
    check();
    dot4--;  
    
  }
  else {dot4 = 0; counter4 = 0;}
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
    com.toCharArray(buffer, 24);
    ch = atoi(strtok(buffer, " "));
    led = atoi(strtok(NULL, " "));
    r = atoi(strtok(NULL, " "));
    g = atoi(strtok(NULL, " "));
    b = atoi(strtok(NULL, " "));
    FastLED.setBrightness(led);
     if (led == -999) { wipe(); reset();}
     
if(ch == 1)
{
  do {
    leds1[i].r = r;
    leds1[i].g = g;
    leds1[i].b = b;
    i++;
    FastLED.show();
     } while (i < NUM_LEDS1);
}
if(ch == 2)
{
     do {
    leds2[i].r = r;
    leds2[i].g = g;
    leds2[i].b = b;
    i++;
    FastLED.show();
     } while (i < NUM_LEDS2);
}
if(ch == 3)
{
do {
    leds3[i].r = r;
    leds3[i].g = g;
    leds3[i].b = b;
    i++;
    FastLED.show();
     } while (i < NUM_LEDS3);
}
if (ch == 4)
{
     do {
    leds4[i].r = r;
    leds4[i].g = g;
    leds4[i].b = b;
    i++;
    FastLED.show();
     } while (i < NUM_LEDS4);
}
    
    
    
    
    
    }
  

}}

void tetris(int del, int chn)
{
  

 if(chn == 1)
 { 
  CRGB Color;
  if ( dot1 <= count1  &&  counter1 == 0)
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
  leds1[dot1] = Color;
  delay(del);
  check();
  dot1++;
  }
  else if(counter1 == 0)
  {
    leds1[count1] = Color;
    FastLED.show();
    count1 = count1 -1;
  }
  
  if (count1 < 0 || counter1 == 1)
  {
    counter1 = 1;
    count1 = NUM_LEDS1;
    delay(2000);
    int i = 0;
    leds[i] = CRGB::Black;
    i++;
    delay(100);
    FastLED.show();
  }
  else if(counter1 == 1) counter1 == 0;
 }
}
  
