# M5Stack Arduino Sketches Repository

## Description
This repository contains working Arduino sketches designed for the **M5Stack CoreS3** and **Cardputer** controllers. It includes compatible modules like the **M5Unit ENVII** (SHT30 & BMP280), and other attachable sensors or units for embedded system projects. The repository offers practical examples to help hobbyists and professionals with their development of IoT applications using M5Stack devices.

## Hardware Supported
- **M5Stack CoreS3**: An ESP32-based controller with various built-in features, including a display and a proximity sensor.
- **M5Stack Cardputer**: A handheld modular device with attachable Grove modules.
- **M5Unit ENVII (SHT30 & BMP280)**: A combined temperature, humidity, and pressure sensor that connects via I2C.

## What You’ll Find
1. **Arduino sketches**: Ready-to-upload sketches covering the use of the M5Stack hardware and attached modules.
2. **Documentation**: Each sketch comes with explanations on how it interacts with the hardware.
3. **Examples**: Examples of real-time sensor readings displayed on CoreS3 or other controllers' screens.

## How to Use
1. Clone the repository to your local machine.
2. Upload the sketches to your M5Stack controller via the Arduino IDE.
3. Ensure you have the correct libraries installed:
   - `M5Unified.h`
   - `M5UnitENV.h`
   - `Wire.h`

## Libraries Used
Make sure to install the following libraries through the Arduino Library Manager:
- [M5Unified](https://github.com/m5stack/M5Unified)
- [M5UnitENV](https://github.com/m5stack/M5Unit-ENV)

## Future Goals
- Add more sketches for different M5Stack units and sensors.
- Expand compatibility with other M5Stack controllers.

## Author
GitHub: [chrisnelnine](https://github.com/chrisnelnine)

Feel free to contribute by submitting pull requests or creating issues to help improve this repository!


