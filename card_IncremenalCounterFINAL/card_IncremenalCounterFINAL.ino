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
  M5Cardputer.Display.setRotation(1);
  M5Cardputer.Display.setTextSize(8);
  M5Cardputer.Display.fillScreen(TFT_BLACK);  // Clear the display with a black screen
  M5Cardputer.Display.setTextColor(TFT_YELLOW, TFT_BLACK);  // Set text color to white on black background
  M5Cardputer.Display.setTextDatum(MC_DATUM);  // Align the text to the center
  Serial.begin(9600);  // Start the Serial Monitor for debugging
}

void loop() {
  // Print the current xValue on the display
  M5Cardputer.Display.drawString(String(xValue, DEC),
                                 M5Cardputer.Display.width() / 2,
                                 M5Cardputer.Display.height() / 2);

  Serial.print("xValue: ");
  Serial.println(xValue);  // Optionally print the value to the Serial Monitor as well

  xValue++;  // Increment xValue by 1

  delay(1000);  // Wait for 1 second (1000 milliseconds)

  // Optionally clear the screen for the next value to avoid overlapping numbers
  M5Cardputer.Display.fillScreen(TFT_BLACK);
}
