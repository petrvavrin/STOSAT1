# STOSAT1
### !!The project is under development!!

**STO**-Storage **SAT**-Satellite **1**

The STOSAT1 project is a scaled down version of the CubeSat satellite, containing most of what the real cubesat does.
Solar battery charging, ESP-07 module, SDHC storage.

Once the firmware is uploaded, STOSAT1 functions as an FTP server, granting access to the SDHC storage.
![STOSAT1 under construction](STOSAT1_under_construction.jpg)

## Wiring diagram
The project includes a detailed wiring schematic, created using EAGLE. The complete EAGLE project is accessible [here](STOSAT1_EAGLE_2.1).

This diagram offers insights into the wiring configuration of STOSAT1.
![STOSAT1 wiring diagram](STOSAT1_wiring_diagram.png)

## Compilation
The firmware is crafted using PlatformIO. When working with PlatformIO, we recommend configuring the ESP with specific parameters as defined in the [platformio.ini](STOSAT1_FIRMWARE/platformio.ini) file.

## Future plans
My future goals for STOSAT1 include:

- **Battery Voltage Measurement:** a circuit used to measure battery voltage to monitor charging.

- **Miniature Display:** to show important information.
