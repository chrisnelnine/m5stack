/**
 * @file myCounter.ino
 * @author MDS 
 * @brief CoreS3 Display Test
 * @version 0.1
 * @date 2024-09-29
 *
 *
 * @Hardwares: CoreS3
 * @Platform Version: Arduino M5Stack Board Manager v2.0.7
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */

#include "M5CoreS3.h"
//#include "M5GFX.h"

M5Canvas canvas(&CoreS3.Display);
String data = "> ";

int xValue = 1;  // Initialize xValue to 1

void setup() {
  auto cfg = M5.config();
  CoreS3.begin(cfg);
  CoreS3.Display.setRotation(1);
  CoreS3.Display.setTextSize(8);
  CoreS3.Display.fillScreen(TFT_BLACK);  // Clear the display with a black screen
  CoreS3.Display.setTextColor(TFT_YELLOW, TFT_BLACK);  // Set text color to white on black background
  CoreS3.Display.setTextDatum(MC_DATUM);  // Align the text to the center
  Serial.begin(9600);  // Start the Serial Monitor for debugging
}

void loop() {
  // Print the current xValue on the display
  CoreS3.Display.drawString(String(xValue, DEC),
                                 CoreS3.Display.width() / 2,
                                 CoreS3.Display.height() / 2);

  Serial.print("xValue: ");
  Serial.println(xValue);  // Optionally print the value to the Serial Monitor as well

  xValue++;  // Increment xValue by 1

  delay(1000);  // Wait for 1 second (1000 milliseconds)

  // Optionally clear the screen for the next value to avoid overlapping numbers
  CoreS3.Display.fillScreen(TFT_BLACK);
}
