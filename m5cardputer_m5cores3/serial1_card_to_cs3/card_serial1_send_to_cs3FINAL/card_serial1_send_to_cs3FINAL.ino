/**
 * @file CardputerSerialTerminalWDK.ino
 * @author Skinwill (https://reddit.com/u/skinwill)
 * @brief Very basic Serial1 terminal for the M5Cardputer.
 * @version 0.1
 * @date 2023-11-28
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
const int textBufferSize = 50;
char textBuffer[textBufferSize];
int textIndex = 0;
constexpr uint8_t PORT_RX_PIN = 1;       //The Rx PIN for the only Port is 1
constexpr uint8_t PORT_TX_PIN = 2;       //The Tx PIN for the only Port is 2

void setup() {
    Serial1.begin(115200, SERIAL_8N1, PORT_RX_PIN, PORT_TX_PIN);
    auto cfg = M5.config();
    M5Cardputer.begin(cfg, true);
    M5Cardputer.Display.setRotation(1);
    M5Cardputer.Display.setTextSize(0.5);
    M5Cardputer.Display.drawRect(0, 0, M5Cardputer.Display.width(),
                                 M5Cardputer.Display.height() - 28, GREEN);
    M5Cardputer.Display.setTextFont(&fonts::FreeSansBold18pt7b);

    M5Cardputer.Display.fillRect(0, M5Cardputer.Display.height() - 4,
                                 M5Cardputer.Display.width(), 4, GREEN);

    canvas.setTextFont(&fonts::FreeSansBold18pt7b);
    canvas.setTextSize(0.5);
    canvas.createSprite(M5Cardputer.Display.width() - 8,
                        M5Cardputer.Display.height() - 36);
    canvas.setTextScroll(true);
    canvas.println("Press Key and Enter to Input Text");
    canvas.pushSprite(4, 4);
    M5Cardputer.Display.drawString(data, 4, M5Cardputer.Display.height() - 24);
}

void loop() {
    M5Cardputer.update();
    if (M5Cardputer.Keyboard.isChange()) {
        if (M5Cardputer.Keyboard.isPressed()) {
            Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();

            for (auto i : status.word) {
                data += i;
            }

            if (status.del) {
                data.remove(data.length() - 1);
            }

            if (status.enter) {
                data.remove(0, 2);
                canvas.println(data);
                Serial1.println(data);
                canvas.pushSprite(4, 4);
                data = "> ";
            }

            M5Cardputer.Display.fillRect(0, M5Cardputer.Display.height() - 28,
                                         M5Cardputer.Display.width(), 25,
                                         BLACK);

            M5Cardputer.Display.drawString(data, 4,
                                           M5Cardputer.Display.height() - 24);
        }
    }
        while (Serial1.available() > 0) {
        char incomingChar = Serial1.read();

        // Check for carriage return to end the string
        if (incomingChar == '\r') {
            // Display the received string on the screen
            canvas.println(textBuffer);
            canvas.pushSprite(4, 4);

            // Clear the text buffer
            memset(textBuffer, 0, textBufferSize);
            textIndex = 0;
        } else {
            // Add the received character to the text buffer
            if (textIndex < textBufferSize - 1) {
                textBuffer[textIndex++] = incomingChar;
                textBuffer[textIndex] = '\0'; // Ensure null-termination
            }
        }
      }   
}