#include <M5Unified.h>   // For general M5CoreS3 functionalities
#include <M5UnitENV.h>   // For ENV sensor (SHT30 & BMP280)
#include <Wire.h>        // For I2C communication

// Create sensor objects
SHT3X sht3x;
BMP280 bmp;

void setup() {
  // Initialize M5CoreS3
  auto cfg = M5.config();
  M5.begin(cfg);

  // Display setup
  M5.Display.setRotation(1);
  M5.Display.setTextColor(YELLOW);
  M5.Display.setTextDatum(middle_center);
  M5.Display.setFont(&fonts::Orbitron_Light_32);
  M5.Display.setTextSize(2); //larger font since just two lines used on screen
  M5.Display.fillScreen(TFT_BLACK);
  M5.Display.drawString("Initializing...", M5.Display.width() / 2, M5.Display.height() / 2);

  // Initialize I2C for SHT30 and BMP280
  Wire.begin(2, 1);  // Use SDA = 2, SCL = 1 for Port A

  // Initialize the SHT30 sensor
  if (!sht3x.begin(&Wire, 0x44, 2, 1, 100000U)) { // SDA = 2, SCL = 1
    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.drawString("SHT30 Error", M5.Display.width() / 2, M5.Display.height() / 2);
    while (1);  // Halt if initialization fails
  }

  // Initialize the BMP280 sensor
  if (!bmp.begin(&Wire, 0x76, 2, 1, 100000U)) {  // SDA = 2, SCL = 1
    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.drawString("BMP280 Error", M5.Display.width() / 2, M5.Display.height() / 2);
    while (1);  // Halt if initialization fails
  }
}

void loop() {
  // Update the SHT3X sensor readings
  if (sht3x.update()) {
    float temperatureSHT = sht3x.cTemp;
    float humidity = sht3x.humidity;

    // Update the BMP280 sensor readings
    float pressure = bmp.readPressure();  // in Pa
    float altitude = bmp.readAltitude(1011);  // in meters; in parenthesis is pressure at sea level at location
    float temperatureBMP = bmp.readTemperature();
    // Clear the display for updated values
    M5.Display.fillScreen(TFT_BLACK);

    
    String tempStr = String(temperatureSHT, 1) + " C";
    String humidityStr = String(humidity, 1) + " %";


    M5.Display.drawString(tempStr, M5.Display.width() / 2, M5.Display.height() / 2 - 45);
    M5.Display.drawString(humidityStr, M5.Display.width() / 2, M5.Display.height() / 2 + 45);


  } else {
    M5.Display.fillScreen(TFT_BLACK);
    M5.Display.drawString("Error", M5.Display.width() / 2, M5.Display.height() / 2);
  }

  delay(2000);  // Wait for 2 seconds before the next reading
}