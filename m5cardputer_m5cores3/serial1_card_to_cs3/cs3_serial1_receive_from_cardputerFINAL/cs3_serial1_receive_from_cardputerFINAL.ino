/**
 * @file CardputerSerial1Receiver.ino
 * @brief This sketch sets the M5CoreS3 in a mode ready to receive text via Serial1 at Port C and display it on the screen.
 * @author Skinwill (https://reddit.com/u/skinwill)
 * @version 0.1
 * @date 2024-10-03
 *
 * @Hardware: M5Cardputer
 * @Platform Version: Arduino M5Stack Board Manager v2.0.7
 * @Dependent Libraries:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */

#include <M5Unified.h>   // For general M5Cardputer functionalities
#include "M5GFX.h"

// Set up the canvas for drawing text
M5Canvas canvas(&M5.Display);
String data = "> ";
const int textBufferSize = 50;
char textBuffer[textBufferSize];
int textIndex = 0;
constexpr uint8_t PORTC_TX_PIN = 17;       //The Tx PIN for Port C is 17
constexpr uint8_t PORTC_RX_PIN = 18;       //The Rx PIN for Port C is 18

void setup() {
    Serial1.begin(115200, SERIAL_8N1, PORTC_TX_PIN, PORTC_RX_PIN);   // Start the Serial1 monitor; 
    auto cfg = M5.config();
    M5.begin(cfg);          // Initialize the M5Cardputer
    M5.Display.setRotation(1);
    M5.Display.setTextSize(0.5);
    
    // Create a display frame
    M5.Display.drawRect(0, 0, M5.Display.width(),
                                 M5.Display.height() - 28, GREEN);
    M5.Display.setTextFont(&fonts::FreeSansBold18pt7b);

    // Create a visual divider at the bottom of the screen
    M5.Display.fillRect(0, M5.Display.height() - 4,
                                 M5.Display.width(), 4, GREEN);

    // Configure canvas for text
    canvas.setTextFont(&fonts::FreeSansBold18pt7b);
    canvas.setTextSize(0.5);
    canvas.createSprite(M5.Display.width() - 8,
                        M5.Display.height() - 36);
    canvas.setTextScroll(true);
    canvas.println("Waiting for Serial1 input...");
    canvas.pushSprite(4, 4);  // Display initial message

    // Display input prompt
    M5.Display.drawString(data, 4, M5.Display.height() - 24);
}

void loop() {
    // Continuously check if there's Serial1 data available
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
