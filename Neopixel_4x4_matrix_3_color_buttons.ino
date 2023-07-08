// Enciende LED Neopixel uno a uno y cambia al color (RGB) del botón pulsado (3 botones, uno para color RGB).
// Written by PLÉYADES IT

#include <Adafruit_NeoPixel.h>

const int RED_button = 12;
const int GREEN_button = 11;
const int BLUE_button = 10;
int Color_R;
int Color_G;
int Color_B;
int R = 128;
int G = 128;
int B = 128;

#define PIN 6           // Pin digital del Arduino --> pin DIN matriz LED.

#define NUMPIXELS 16    // Número de píxeles de la matriz 4x4

#define BRIGHTNESS 1    // Set BRIGHTNESS (min = 0, max = 255)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 165    // ms de retardo

void setup()
{
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
  
  pinMode(RED_button, INPUT_PULLUP);    // Activa resistencia Pull-up interna en este pin
  pinMode(GREEN_button, INPUT_PULLUP);
  pinMode(BLUE_button, INPUT_PULLUP);
  delay(2000);
}

void loop()
{
  pixels.clear();     // Apaga todos los LEDs

  for(int i=0; i<NUMPIXELS; i++)
  {
    Color_R = digitalRead(RED_button);
    if (Color_R == LOW)
    {
      R = 128; G = 0; B = 0;
    }
    Color_G = digitalRead(GREEN_button);
    if (Color_G == LOW)
    {
      R = 0; G = 128; B = 0;
    }
    Color_B = digitalRead(BLUE_button);
    if (Color_B == LOW)
    {
      R = 0; G = 0; B = 128;
    }
    if (Color_R == LOW && Color_G == LOW && Color_B == LOW)
    {
      R = 128; G = 128; B = 128;
    }
    pixels.setPixelColor(i, pixels.Color(R, G, B));
    pixels.show();
    delay(DELAYVAL);
  }
}
