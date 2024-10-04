#include "M5CoreS3.h"
#include <Adafruit_NeoPixel.h>

#define LED_PIN 2        // GPIO Pin 2 for the RGB LEDs CORES3 PORT A
// #define LED_PIN 9        // GPIO Pin 9 for the RGB LEDs CORES3 PORT B
// #define LED_PIN 17       // GPIO Pin 17 for the RGB LEDs CORES3 PORT C

#define NUMPIXELS 37      // Number of LEDs in your RGB LED setup

// Create a NeoPixel object
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initialize the configuration and enable 5V output power
  auto cfg = M5.config();
  cfg.output_power = true;  // Enable 5V output power -- IMPORTANT
  CoreS3.begin(cfg);

  // Display setup as requested
  CoreS3.Display.setRotation(1);
  CoreS3.Display.setTextColor(GREEN);
  CoreS3.Display.setTextDatum(middle_center);
  CoreS3.Display.setTextFont(&fonts::Orbitron_Light_32);
  CoreS3.Display.setTextSize(1);
  CoreS3.Display.drawString("Traffic Light", CoreS3.Display.width() / 2, CoreS3.Display.height() / 2);

  // Initialize the RGB LED strip
  pixels.begin();
}

void loop() {

/*
  Turn the bottom LED (index 2) green for 5 seconds
  pixels.setPixelColor(2, pixels.Color(0, 255, 0));  // Green LED (bottom)
  pixels.show();  // Update the LEDs
  delay(5000);    // Wait for 5 seconds

  // Turn the middle LED (index 1) amber for 1 second
  pixels.clear();  // Turn off all LEDs before switching
  pixels.setPixelColor(1, pixels.Color(255, 191, 0));  // Amber LED (middle)
  pixels.show();
  delay(1000);     // Wait for 1 second

  // Turn the top LED (index 0) red for 5 seconds
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));  // Red LED (top)
  pixels.show();
  delay(5000);     // Wait for 5 seconds
*/

  for (int i = 0; i <= 14; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));  // Set each pixel from 0 to 12 to green
  }
  pixels.show();
  delay(5000);
  pixels.clear();

  for (int i = 15; i <= 21; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 191, 0));  // Set each pixel from 0 to 12 to green
  }
  pixels.show();
  delay(1500);
  pixels.clear();

  for (int i = 22; i <= 37; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));  // Set each pixel from 0 to 12 to green
  }
  pixels.show();
  delay(5000);
  pixels.clear();

  // Clear the LEDs before repeating the cycle
  pixels.clear();
  pixels.show();
}
