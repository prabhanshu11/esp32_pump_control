# ESP32 PlatformIO Project

A basic template for ESP32 projects using PlatformIO and the Arduino framework. Currently includes a simple example function that adds two integers.

## Getting Started

This is a PlatformIO project. You will need to have PlatformIO Core installed to build and upload this project.

- To build the project: `pio run`
- To upload the project to your ESP32 device: `pio run -t upload`

## Project Structure

- `src/`: Main project source code (e.g., `main.cpp`)
- `lib/`: Project-specific (private) libraries. Each library should be in its own subdirectory.
- `include/`: Project header files (`.h` files).
- `test/`: Project tests for the PlatformIO Test Runner.

## Hardware

- Board: ESP32 Dev Module (esp32dev)

## Framework

- Framework: Arduino

Refer to the `platformio.ini` file for detailed configuration.

## Device Functionality

### LED Indication
The onboard LED (connected to GPIO2) blinks continuously. This serves as a visual indicator that the device is powered on and the main program loop is executing.

### Web Status Interface
The ESP32 hosts a Wi-Fi Access Point (AP) to provide a basic status web page.
- **SSID:** `ESP32-Status-AP`
- **Password:** None (open network)
- **IP Address:** Connect to the AP and then navigate to `http://192.168.4.1` in a web browser.
- **Web Page Content:** The page displays a simple message: "ESP32 Status: Online and Blinking!", confirming the device's operational status.
