# Microchip MPLAB® Harmony 3 Release Notes

## Harmony 3 Wireless application examples for WINC1500 v3.6.1

### Development kit and demo application support

Following table provides number of Wireless examples available for different development kits.

|Development Kits|MPLABx applications|
|----------------|-------------------|
|SAMD21 with WINC1500 Xpro|7|
|SAME54 with WINC1500 Xpro|9|
|SAMA5D27-SOM1-EK1 with WINC1500 Wifi 7 Click board|1|

### New Features

-   All applications have been migrated from MHC to MCC.

-   "wifi\_socket\_demos" is available for SAMA5D27-SOM1-EK1 with WINC1500 Wifi 7 Click board with latest "wireless\_wifi" driver v3.7.1


**Note**

Only "wifi\_socket\_demos" of SAMA5D27-SOM1-EK1 with WINC1500 Wifi 7 Click board is upgraded with the latest "wireless\_wifi" driver v3.7.1. All Other applcations are having "wireless\_wifi" driver v3.7.0

### Bug fixes

-   "wireless\_wifi\_apps\_winc1500" applications are upgraded with latest "wireless\_wifi" driver v3.7.0.


### Known Issues

-   WolfMQTT\(STA bypass mode\) demo application need to build "third\_party/wolfMQTT/mqtt\_socket.c" without xc32 option 'Make warnings into errors' as it uses the obsolete \#include <sys/errno.h\> file in WolfMQTT repo.

-   Additional known issues can be found at [WINC15x0-known-issues](https://github.com/MicrochipTech/WINC15x0-known-issues)


### Development Tools

-   [MPLAB® X IDE v6.00](https://www.microchip.com/mplab/mplab-x-ide)

-   MPLAB® X IDE plug-ins:

    -   MPLAB® Code Configurator \(MCC\) v5.1.17

-   [MPLAB® XC32 C/C++ Compiler v4.10](https://www.microchip.com/mplab/compilers)


