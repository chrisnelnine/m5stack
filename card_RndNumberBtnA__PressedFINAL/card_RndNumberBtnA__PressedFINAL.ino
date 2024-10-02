/**
 * @file myRndNumberKeyPressed.ino
 * On any key press, a random number from 1 to 6 is displayed

 * @author chrisnel
 * @brief M5Cardputer input text test
 * @version 0.1
 * @date 2024-09-29
 *
 *
 * @Hardware: M5Cardputer
 * @Platform Version: Arduino M5Stack Board Manager v2.0.7
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */

#include "M5Cardputer.h"
#include "M5GFX.h"

M5Canvas canvas(&M5Cardputer.Display);
String data = "> ";


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

//initial screen instructions
  canvas.setTextFont(&fonts::FreeSerifBoldItalic18pt7b);
  canvas.setTextSize(0.5);
  canvas.createSprite(M5Cardputer.Display.width() - 8,
                      M5Cardputer.Display.height() - 36);
  canvas.setTextScroll(true);
  canvas.println("Press GO for first Digit");
  canvas.pushSprite(4, 4);
}

void loop() {
  // Update the M5Cardputer system to check for key presses
  M5Cardputer.update();

  // Check if a key has been pressed

    if (M5Cardputer.BtnA.wasPressed()) {
      // A key has been pressed, generate and display a new random number
      int randomValue = random(1, 7);  // Generate a random integer between 1 and 100

      // Clear the screen before drawing the new number
      M5Cardputer.Display.fillScreen(TFT_BLACK);
      M5Cardputer.Display.drawString(String(randomValue),
                                     M5Cardputer.Display.width() / 2,
                                     M5Cardputer.Display.height() / 2);

      // Print the random value to the Serial Monitor
      Serial.print("Random Value: ");
      Serial.println(randomValue);
    }
  
}

