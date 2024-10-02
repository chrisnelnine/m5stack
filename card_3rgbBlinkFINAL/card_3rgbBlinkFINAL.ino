#include "M5Cardputer.h"
#include <Adafruit_NeoPixel.h>

constexpr uint8_t LED_PIN = 2;       // GPIO Pin 8 for the RGB LEDs
constexpr uint16_t NUM_PIXELS = 3;  // Number of LEDs in your hex RGB LED setup

M5Canvas canvas(&M5Cardputer.Display);
String data = "> ";

// Create a NeoPixel object
Adafruit_NeoPixel pixels(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  auto cfg = M5.config();
  cfg.output_power = true; // Enable 5V power

  M5Cardputer.begin(cfg, true);
  M5Cardputer.Display.setRotation(1);  // Set screen orientation
  M5Cardputer.Display.setTextSize(8);  // Set text size to large
  M5Cardputer.Display.fillScreen(TFT_BLACK);  // Clear the display with a black screen
  M5Cardputer.Display.setTextColor(TFT_YELLOW, TFT_BLACK);  // Set text color to yellow on black background
  M5Cardputer.Display.setTextDatum(MC_DATUM);  // Align the text to the center
  Serial.begin(9600);  // Start the Serial Monitor for debugging
  randomSeed(analogRead(0));  // Seed the random number generator

  // Initial screen instructions
  canvas.setTextFont(&fonts::FreeSerifBoldItalic18pt7b);
  canvas.setTextSize(0.5);
  canvas.createSprite(M5Cardputer.Display.width() - 8, M5Cardputer.Display.height() - 36);
  canvas.setTextScroll(true);
  canvas.println("Press Key for first Digit");
  canvas.pushSprite(4, 4);
}

void loop() {
  // Turn all LEDs on (set to Red)
  for (int i = 0; i < NUM_PIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));  // Set LED to red
  }
  pixels.show();  // Update the LED strip
  delay(1000);    // Wait for 1 second

  // Turn all LEDs off
  pixels.clear();  // Turn off all LEDs
  pixels.show();   // Update the LED strip
  delay(1000);     // Wait for 1 second
}
