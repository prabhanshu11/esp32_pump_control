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

## Ubuntu Setup for Serial Port Access

On Ubuntu, you might encounter permissions errors when trying to upload code to the ESP32 board, as the default user often doesn't have access to serial ports like `/dev/ttyUSB0`. Follow these steps to resolve this:

1.  **Download the udev rules file:**
    ```bash
    sudo curl -L https://raw.githubusercontent.com/platformio/platformio-core/develop/platformio/assets/system/99-platformio-udev.rules -o /etc/udev/rules.d/99-platformio-udev.rules
    ```
    This downloads the necessary udev rules that allow access to USB devices used by PlatformIO. You will be prompted for your password.

2.  **Reload udev rules:**
    ```bash
    sudo udevadm control --reload-rules
    ```
    This command tells the udev system to load the new rules you just added.

3.  **Trigger udev:**
    ```bash
    sudo udevadm trigger
    ```
    This command reapplies the udev rules to the currently connected devices.

4.  **Add your user to the `dialout` group:**
    ```bash
    sudo usermod -a -G dialout $USER
    ```
    Grant your user permissions to access serial ports by adding them to the `dialout` group.

5.  **Log out and Log In:** For the group membership change to take effect, you must log out of your Ubuntu session and log back in (or restart your computer).

After following these steps, you should have the necessary permissions to upload code to your ESP32 board without encountering the "Could not open /dev/ttyUSB0" error.
