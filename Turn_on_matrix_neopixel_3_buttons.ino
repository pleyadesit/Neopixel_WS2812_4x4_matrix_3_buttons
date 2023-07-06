// Enciende LED Neopixel uno a uno y cambia al color (RGB) del botón pulsado (3 botones, uno para color RGB).
// PLÉYADES IT

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

// Pin digital del Arduino al cual conectamos pin DIN la tira o matriz LED.
#define PIN 6 

// Número de píxeles de la tira o matrix
#define NUMPIXELS 16

// Intensidad del brillo de los LED NeoPixel, 0 (min) to 255 (max)
#define BRIGHTNESS 1    // Set BRIGHTNESS to about 1/5 (max = 255)

// Inicializamos objeto "pixeles"
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 165    // Asigna ms a la variable DELAYVAL

void setup()
{
  pixels.begin();       // Inicializamos el objeto "pixeles"
  pixels.setBrightness(BRIGHTNESS);
  
  pinMode(RED_button, INPUT_PULLUP);    // Activa resistencia Pull-up interna en este pin
  pinMode(GREEN_button, INPUT_PULLUP);
  pinMode(BLUE_button, INPUT_PULLUP);
  delay(2000);
}

void loop()
{
  pixels.clear();     // Apaga todos los LEDs

  for(int i=0; i<NUMPIXELS; i++)    // Para cada pixel...
  {
    // Modificamos el LED #i teniendo en cuenta si se ha pulsado uno de los botones selectores de color
    Color_R = digitalRead(RED_button);
    if (Color_R == LOW)
    {
      R = 128; G = 0; B = 0;      // Establece color (R, G, B) --> RED
    }
    Color_G = digitalRead(GREEN_button);
    if (Color_G == LOW)
    {
      R = 0; G = 128; B = 0;      // Establece color (R, G, B) --> GREEN
    }
    Color_B = digitalRead(BLUE_button);
    if (Color_B == LOW)
    {
      R = 0; G = 0; B = 128;      // Establece color (R, G, B) --> BLUE
    }
    if (Color_R == LOW && Color_G == LOW && Color_B == LOW)
    {
      R = 128; G = 128; B = 128;      // Establece color (R, G, B) --> BLUE
    }
    pixels.setPixelColor(i, pixels.Color(R, G, B));     // Establece color (R, G, B)
    pixels.show();        // Mandamos todos los colores con la actualización hecha
    delay(DELAYVAL);      // Pausa antes de iluminar el siguiente LED
  }
}