# Microchip MPLAB® Harmony 3 Release Notes

## Harmony 3 Wireless application examples for WINC1500 v3.5.0

### Development kit and demo application support

Following table provides number of Wireless examples available for different development kits.

|Development Kits|MPLABx applications|
|----------------|-------------------|
|SAMD21 with WINC1500 Xpro|7|
|SAME54 with WINC1500 Xpro|9|

### New Features

-   New MQTT, SSL, SNTP and OTA demos added for Bypass mode.

-   New MQTT, SSL, SNTP, OTA Certificate download and OTA demos added for Socket mode.


### Bug fixes

-   "wireless\_wifi\_apps\_winc1500" applications are upgraded with Countermeasures for ‘Fragattack’ vulnerabilities.


### Known Issues

-   Due to an issue in the underlying `net` repo, you need to turn off `-Werror` for the `icmp.c` file in your projects.

-   User may face connectivity issue with the SSL demo of bypass mode with FreeRTOS. Please use SSL demo of bypass mode without FreeRTOS.

-   "wireless\_wifi" Serial bridge application needs to be regenerated before using it for firmware update.

-   Additional known issues can be found at [WINC15x0-known-issues](https://github.com/MicrochipTech/WINC15x0-known-issues)


### Development Tools

-   [MPLAB® X IDE v5.50](https://www.microchip.com/mplab/mplab-x-ide)

-   MPLAB® X IDE plug-ins:

    -   MPLAB® Harmony Configurator \(MHC\) v3.8.2

-   [MPLAB® XC32 C/C++ Compiler v3.01](https://www.microchip.com/mplab/compilers)

