// modified sketch
// by Nico N
// 03/22/2022

#include <Joystick.h>
#include <FastLED.h>


Joystick_ Joystick;

// Die pins neu bennen für die richtige zahlen
#define PIN_01 0
#define PIN_02 1
#define PIN_03 2
#define PIN_04 3
#define PIN_05 4
#define PIN_06 5
#define PIN_07 6
#define PIN_08 7
#define PIN_09 8
#define PIN_10 9
#define PIN_11 10
#define PIN_12 11
#define PIN_13 12
#define PIN_14 13
#define PIN_15 A0
#define NUM_LEDS 10
#define DATA_PIN A1
#define PIN A1

CRGB leds[NUM_LEDS];

void setup() {
  // Initialize Button Pins
  pinMode(PIN_01, INPUT_PULLUP);
  pinMode(PIN_02, INPUT_PULLUP);
  pinMode(PIN_03, INPUT_PULLUP);
  pinMode(PIN_04, INPUT_PULLUP);
  pinMode(PIN_05, INPUT_PULLUP);
  pinMode(PIN_06, INPUT_PULLUP);
  pinMode(PIN_07, INPUT_PULLUP);
  pinMode(PIN_08, INPUT_PULLUP);
  pinMode(PIN_09, INPUT_PULLUP);
  pinMode(PIN_10, INPUT_PULLUP);
  pinMode(PIN_11, INPUT_PULLUP);
  pinMode(PIN_12, INPUT_PULLUP);
  pinMode(PIN_13, INPUT_PULLUP);
  pinMode(PIN_14, INPUT_PULLUP);
  pinMode(PIN_15, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);

  Serial.begin(57600);
  Serial.println("resetting");
  // Dieser Teil ist für die LEDs. Dieser kann Ingnoriert egal ob man einen hat.
  FastLED.addLeds<WS2812B, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); 
  LEDS.setBrightness(84);
  

    leds[0].b = 0xFF;
    delay(50);
    FastLED.show();
    leds[1].b = 0xFF;
    delay(50);
    FastLED.show();
    leds[2].b = 0xFF;
    delay(50);
    FastLED.show();
    leds[3].b = 0xFF;
    delay(50);
    FastLED.show();
    leds[4].b = 0xFF;
    delay(50);
    FastLED.show();
    leds[5].b = 0xFF;
    delay(50);
    FastLED.show();
    leds[6].b = 0xFF;
    delay(50);
    FastLED.show();
    leds[7].b = 0xFF;
    delay(50);
    FastLED.show();
    leds[8].b = 0xFF;
    delay(50);
    FastLED.show();
    leds[9].b = 0xFF;
    delay(50);
    FastLED.show();
    leds[10].b = 0xFF;
    delay(50);
    FastLED.show();
  
  // Dies ist für die Joystick Library
  Joystick.begin();
}

// Constant die den Start pin angibt (niedrigster) pin#
const int pinToButtonMap = PIN_01;

// Der letzte status der Pins [anzahl der buttons]
int lastButtonState[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void loop() {

  // Liest den Pin wert
  for (int index = 0; index < 17; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(50);

}
