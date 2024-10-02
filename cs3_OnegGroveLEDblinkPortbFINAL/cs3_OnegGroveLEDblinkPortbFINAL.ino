#include "M5CoreS3.h"  // Include the CoreS3 library

#define LED_PIN 8  // G1 (SCL) corresponds to Pin 32 on CoreS3 (Grove Port A)

void setup() {
  auto cfg = M5.config();
  CoreS3.begin(cfg);

  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);

  // Turn the LED off at the beginning
  digitalWrite(LED_PIN, LOW);

  CoreS3.Display.setRotation(1);
    CoreS3.Display.setTextColor(GREEN);
    CoreS3.Display.setTextDatum(middle_center);
    CoreS3.Display.setTextFont(&fonts::Orbitron_Light_32);
    CoreS3.Display.setTextSize(1);
    CoreS3.Display.drawString("Test",
                                   CoreS3.Display.width() / 2,
                                   CoreS3.Display.height() / 2);

}

void loop() {
  // Blink the LED
  digitalWrite(LED_PIN, HIGH);  // Turn LED on
  CoreS3.Speaker.tone(10000, 100);
  delay(1000);                  // Wait 1 second
  digitalWrite(LED_PIN, LOW);   // Turn LED off
  delay(1000);                  // Wait 1 second
}
