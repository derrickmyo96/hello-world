#include <FastLED.h>
#define NUM_LED 60
#define LED_PIN 6

CRGB leds[NUM_LED];
long duration, cm;
const int buttonPin = 2;
int buttonState = HIGH;
int lastButtonState = HIGH;
int ledState = HIGH;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 500;
int startTime = millis();

void setup()
{
  FastLED.addLeds<WS2812B, LED_PIN>(leds, NUM_LED);
  pinMode(buttonPin, INPUT);
  pinMode(LED_PIN, OUTPUT);

  for(int i = 0; i<NUM_LED; i++) {
          leds[i] = CRGB::Black;
        }
        FastLED.show();
}

void loop()
{
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
    buttonState = reading;
  }

  if((millis() - lastDebounceTime) > debounceDelay) 
  {
    if (reading != buttonState)
    {
      //buttonState = reading;

      if (buttonState == LOW)
      {
        //ledState = !ledState;
        for(int i = 0; i<NUM_LED; i++) {
          leds[i] = CRGB::Black;
        }
        FastLED.show();
      }
    }
  }

//  digitalWrite(LED_PIN, ledState);
  lastButtonState = reading;

  
  if(buttonState == HIGH)
  {
  
  
  for (int i=0; i<NUM_LED; i++)
  {
    for (int j=60; j>i; j--)
    {
      leds[i+2] = CRGB:: Red;
      FastLED.show();
      delayMicroseconds(0);
      leds[i] = CRGB::Blue;
      leds[j-2] = CRGB::Green;
      FastLED.show();
      delayMicroseconds(0);
      leds[j] = CRGB::Blue;
    }
  }

//  for (int a=0; a<NUM_LED; a++)
//  {
//    for (int b=60; b>a; b--)
//    {
//      leds[a+3] = CRGB:: Green;
//      FastLED.show();
//      delayMicroseconds(0);
//      leds[a] = CRGB::Blue;
//      leds[b-3] = CRGB::Red;
//      FastLED.show();
//      delayMicroseconds(0);
//      leds[b] = CRGB::Blue;
//    }
//  }
  for(int i = 0; i<NUM_LED; i++) {
          leds[i] = CRGB::Black;
        }
        FastLED.show();
  }  
}



  
  
