/**
 * @file myCounter.ino
 * @author MDS 
 * @brief M5Cardputer Display Test
 * @version 0.1
 * @date 2024-09-29
 *
 *
 * @Hardwares: M5Cardputer
 * @Platform Version: Arduino M5Stack Board Manager v2.0.7
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */

#include "M5Cardputer.h"
#include "M5GFX.h"

M5Canvas canvas(&M5Cardputer.Display);
String data = "> ";

int xValue = 1;  // Initialize xValue to 1

void setup() {
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);
  M5Cardputer.Display.setRotation(1);  // Set screen orientation
  M5Cardputer.Display.setTextSize(8);  // Set text size to large
  M5Cardputer.Display.fillScreen(TFT_BLACK);  // Clear the display with a black screen
  M5Cardputer.Display.setTextColor(TFT_YELLOW, TFT_BLACK);  // Set text color to yellow on black background
  M5Cardputer.Display.setTextDatum(MC_DATUM);  // Align the text to the center
  Serial.begin(9600);  // Start the Serial Monitor for debugging
  randomSeed(analogRead(0));  // Seed the random number generator
}

void loop() {
  int randomValue = random(1, 7);  // Generate a random integer between 1 and 100 (inclusive)

  // Print the random value on the display
  M5Cardputer.Display.fillScreen(TFT_BLACK);  // Clear the screen before drawing the new number
  M5Cardputer.Display.drawString(String(randomValue), 
                                 M5Cardputer.Display.width() / 2, 
                                 M5Cardputer.Display.height() / 2);

  Serial.print("Random Value: ");
  Serial.println(randomValue);  // Print the value to the Serial Monitor as well

  delay(2000);  // Wait for 2 seconds before generating a new random value
}
