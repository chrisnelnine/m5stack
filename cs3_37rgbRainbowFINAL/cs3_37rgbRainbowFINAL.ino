/**
 * @file 37rgbRainbow.ino
 * @author MDS 
 * @brief CoreS3 and 37 Hexagon-shaped RGB LEDS light up one pixel at atime
 * @version 0.1
 * @date 2024-09-29
 *
 *
 * @Hardwares: CoreS3 and 37 Hexagon-shaped RGB LEDS ligh
 * @Platform Version: 
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */

#include "M5CoreS3.h"
#include <Adafruit_NeoPixel.h>

#define LED_PIN 2        // GPIO Pin 2 for the RGB LEDs CORES3 PORT A
// #define LED_PIN 9        // GPIO Pin 9 for the RGB LEDs CORES3 PORT B
// #define LED_PIN 17       // GPIO Pin 17 for the RGB LEDs CORES3 PORT C

#define NUMPIXELS 37      // Number of LEDs in your RGB LED setup

// Create a NeoPixel object
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Function to generate rainbow colors
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);  // Red to Green
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);  // Green to Blue
  } else {
    WheelPos -= 170;
    return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);  // Blue to Red
  }
}

void setup() {
  auto cfg = M5.config();
  cfg.output_power = true;  // Ensure 5V output power is enabled
  CoreS3.begin(cfg);

  // Display setup on CoreS3
  CoreS3.Display.setRotation(1);
  CoreS3.Display.setTextColor(GREEN);
  CoreS3.Display.setTextDatum(middle_center);
  CoreS3.Display.setTextFont(&fonts::Orbitron_Light_32);
  CoreS3.Display.setTextSize(1);
  CoreS3.Display.drawString("Rainbow Effect", CoreS3.Display.width() / 2, CoreS3.Display.height() / 2);

  // Initialize the RGB LED strip
  pixels.begin();
  pixels.clear();  // Start with all LEDs off
}

void loop() {
  // Cycle through colors to create a rainbow effect, lighting up one pixel at a time
  for (int j = 0; j < NUMPIXELS; j++) {  // Iterate over each pixel
    pixels.clear();  // Turn off all LEDs before updating

    // Light up only one LED at a time with a rainbow effect
    pixels.setPixelColor(j, Wheel((j * 256 / NUMPIXELS) & 255));  // Apply rainbow color to current pixel

    pixels.show();  // Update the LEDs with the new color
    delay(1000);  // Control the speed of the transition (200ms per LED)
  }
}
