#include "M5CoreS3.h"

void drawArrows() {
  // Get the screen dimensions
  int screenWidth = CoreS3.Display.width();
  int screenHeight = CoreS3.Display.height();

  // Draw the first arrow along the top edge pointing to the left (whole width of the screen)
  CoreS3.Display.drawLine(screenWidth - 10, 10, 10, 10, TFT_YELLOW);  // Horizontal line (arrow body full length)
  CoreS3.Display.drawLine(10, 10, 20, 0, TFT_YELLOW);   // Arrow tip upper part
  CoreS3.Display.drawLine(10, 10, 20, 20, TFT_YELLOW);  // Arrow tip lower part

  // Label the first arrow "higher frequency" with larger font
  CoreS3.Display.setTextSize(2);  // Set text size larger
  CoreS3.Display.setTextDatum(TL_DATUM);
  CoreS3.Display.setTextColor(TFT_YELLOW);
  CoreS3.Display.drawString("higher frequency", screenWidth - 250, 20);  // Label for frequency arrow

  // Draw the second arrow along the right edge pointing down (whole height of the screen)
  CoreS3.Display.drawLine(screenWidth - 10, 10, screenWidth - 10, screenHeight - 10, TFT_YELLOW);  // Vertical line (arrow body full length)
  CoreS3.Display.drawLine(screenWidth - 10, screenHeight - 10, screenWidth - 20, screenHeight - 20, TFT_YELLOW);  // Arrow tip left part
  CoreS3.Display.drawLine(screenWidth - 10, screenHeight - 10, screenWidth, screenHeight - 20, TFT_YELLOW);       // Arrow tip right part

  // Label the second arrow "higher intensity" with larger font
  CoreS3.Display.setTextSize(2);  // Keep the text size large
  CoreS3.Display.setTextDatum(TR_DATUM);
  CoreS3.Display.drawString("higher intensity", screenWidth - 20, screenHeight - 50);  // Label for intensity arrow
}

void setup() {
  auto cfg = M5.config();
  CoreS3.begin(cfg);
  Serial.begin(9600);  // For debugging output
  CoreS3.Display.setRotation(1);  // Set screen orientation
  CoreS3.Display.fillScreen(TFT_BLACK);  // Clear the screen

  // Draw the arrows on the screen
  drawArrows();
}

void loop() {
  // Update M5CoreS3 touch status
  CoreS3.update();

  // Get touch details
  auto t = CoreS3.Touch.getDetail();

  // If the screen is touched
  if (t.state != 0) {
    // Map the x-coordinate to frequency (left is higher frequency, right is lower)
    int frequency = map(t.x, 0, CoreS3.Display.width(), 4000, 500);

    // Map the y-coordinate to intensity (lower is higher intensity, upper is lower intensity)
    int duration = map(t.y, 0, CoreS3.Display.height(), 100, 1000);

    // Output the frequency and duration to the Serial Monitor for debugging
    Serial.print("X: ");
    Serial.print(t.x);
    Serial.print(" Y: ");
    Serial.print(t.y);
    Serial.print(" Frequency: ");
    Serial.print(frequency);
    Serial.print(" Duration: ");
    Serial.println(duration);

    // Make a buzzing sound (frequency, duration)
    CoreS3.Speaker.tone(frequency, duration);

    // Delay to avoid immediate repeated buzzing
    delay(200);
  }
}
