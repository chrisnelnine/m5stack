#include "M5CoreS3.h"
#include <Adafruit_NeoPixel.h>

#define LED_PIN 9       // GPIO Pin 8 for the RGB LEDs
#define NUMPIXELS 3    // Number of LEDs in your hex RGB LED setup

// Create a NeoPixel object
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  auto cfg = M5.config();
  cfg.output_power = true; //elusive - this gives 5V power
  CoreS3.begin(cfg);
  //M5.Axp.powerModeSet(POWER_MODE_USB_IN_BUS_OUT);

  //CoreS3.Axp.powerModeSet(POWER_MODE_USB_IN_BUS_OUT);
 
  

  // Display setup as requested
  CoreS3.Display.setRotation(1);
  CoreS3.Display.setTextColor(GREEN);
  CoreS3.Display.setTextDatum(middle_center);
  CoreS3.Display.setTextFont(&fonts::Orbitron_Light_32);
  CoreS3.Display.setTextSize(1);
  CoreS3.Display.drawString("Test", CoreS3.Display.width() / 2, CoreS3.Display.height() / 2);

  // Initialize the RGB LED strip
  pixels.begin();
}

void loop() {
  // Turn all LEDs on (set to Red)
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));  // Set LED to red
  }
  pixels.show();  // Update the LED strip
  delay(1000);    // Wait for 1 second

  // Turn all LEDs off
  pixels.clear();  // Turn off all LEDs
  pixels.show();   // Update the LED strip
  delay(1000);     // Wait for 1 second
}
