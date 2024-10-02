/**
 * @file buzzer.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Cardputer Buzzer Test
 * @version 0.1
 * @date 2023-10-09
 *
 *
 * @Hardwares: M5Cardputer
 * @Platform Version: Arduino M5Stack Board Manager v2.0.7
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */
//#include "M5Cardputer.h"

#include "M5CoreS3.h"

void setup() {
    auto cfg = M5.config();
    CoreS3.begin(cfg);
    CoreS3.Display.setRotation(1);
    CoreS3.Display.setTextColor(GREEN);
    CoreS3.Display.setTextDatum(middle_center);
    CoreS3.Display.setTextFont(&fonts::Orbitron_Light_32);
    CoreS3.Display.setTextSize(1);
    CoreS3.Display.drawString("Buzzer Test",
                                   CoreS3.Display.width() / 2,
                                   CoreS3.Display.height() / 2);
}

void loop() {
    CoreS3.Speaker.tone(10000, 100);
    delay(1000);
    CoreS3.Speaker.tone(4000, 20);
    delay(1000);
}