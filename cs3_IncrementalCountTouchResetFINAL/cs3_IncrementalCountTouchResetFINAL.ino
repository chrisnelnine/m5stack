#include "M5CoreS3.h"

M5Canvas canvas(&CoreS3.Display);  // Optional, not used in this example
String data = "> ";

int xValue = 1;  // Initialize xValue to 1

void setup() {
  auto cfg = M5.config();
  CoreS3.begin(cfg);
  CoreS3.Display.setRotation(1);
  CoreS3.Display.setTextSize(8);  // Set text size to large
  CoreS3.Display.fillScreen(TFT_BLACK);  // Clear the display with a black screen
  CoreS3.Display.setTextColor(TFT_YELLOW, TFT_BLACK);  // Set text color to yellow on black background
  CoreS3.Display.setTextDatum(MC_DATUM);  // Align the text to the center
  Serial.begin(9600);  // Start the Serial Monitor for debugging
}

void loop() {
  // Check for touch input
  CoreS3.update();
  auto t = CoreS3.Touch.getDetail();  // Get touch details

  // If touch is detected, reset xValue to 0
  if (t.state != 0) {  // Check if any touch event has occurred
    xValue = 0;  // Reset the counter when the screen is touched
    Serial.println("Screen touched: Counter reset to 0");
  }

  // Print the current xValue on the display
  CoreS3.Display.fillScreen(TFT_BLACK);  // Clear the screen before drawing the new number
  CoreS3.Display.drawString(String(xValue, DEC),
                            CoreS3.Display.width() / 2,
                            CoreS3.Display.height() / 2);

  Serial.print("xValue: ");
  Serial.println(xValue);  // Optionally print the value to the Serial Monitor as well

  xValue++;  // Increment xValue by 1

  delay(1000);  // Wait for 1 second (1000 milliseconds)
}
