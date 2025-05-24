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
