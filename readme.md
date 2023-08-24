# Harmony 3 Wireless application examples for WINC1500

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating embedded firmware solutions for Microchip 32-bit SAM and PIC® microcontroller and microprocessor devices. Refer to the following links for more information.

-   [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)

-   [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)

-   [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)

-   [Microchip MPLAB® Harmony](https://www.microchip.com/mplab/mplab-harmony)

-   [Microchip MPLAB® Harmony Pages](https://microchip-mplab-harmony.github.io/)


This repository contains the MPLAB® Harmony 3 Wireless application examples for WINC1500

-   [Release Notes](release_notes.md)

-   [MPLAB® Harmony License](mplab_harmony_license.md)


To clone or download these applications from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/wireless_apps_winc1500) and then click **Clone** button to clone this repository or download as zip file.<br />This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

-   **[WINC STA Bypass](apps/wifi_winc_sta_bypass/readme.md)**  

-   **[TCP Server in SoftAP](apps/wifi_tcp_server_in_softap/readme.md)**  

-   **[Wifi Provisioning via WPS](apps/wifi_provisioning_via_wps/readme.md)**  

-   **[Wifi Provisioning via SoftAP](apps/wifi_provisioning_via_softap/readme.md)**  

-   **[TCP Client](apps/tcp_client/readme.md)**  

-   **[Power Save Mode](apps/power_save_mode_example/readme.md)**  

-   **[AP Scan](apps/ap_scan/readme.md)**  

-   **[WINC1500 Socket Mode Demo Applications](apps/wifi_socket_demos/readme.md)**  

-   **[Example project creation - WINC Socket mode project with SAMD21](apps/wifi_socket_demos/docs/GUID-7C51815B-F559-46A3-A8B7-3F48A517B4A4.md)**  

-   **[Example project creation - WINC Socket mode project with SAME54](apps/wifi_socket_demos/docs/GUID-BB3E45B9-E26C-4E97-8325-FBF9B81BBF81.md)**  

-   **[WINC1500 Bypass Mode Demo Applications](apps/wifi_bypass_demos/docs/GUID-40C3ABB9-0449-4A53-94DF-0DFB4CE5540E.md)**  

-   **[Create your first WINC1500 Bypass mode example using Harmony TCP/IP stack](apps/wifi_bypass_demos/docs/GUID-34243CDA-B156-4D2B-B9C1-7ED5BE2586A6.md)**  

-   **[Supported Network Modes in WINC](apps/getting_started/GUID-74562C24-BC96-4BBA-8346-836D98E39F8C.md)**  

-   **[WINC Devices – Integrated Serial Flash Memory Download Procedure](apps/getting_started/GUID-AE48AE71-0F91-444B-8AC3-C5C1939A37FB.md)**  

-   **[Create WINC Project - Getting Started](apps/getting_started/GUID-8C38797E-1BBB-4ACF-A496-EEC03A6075AC.md)**  


## Contents Summary

|Folder|Description|
|------|-----------|
|apps|Contains Wireless service example applications.|
|docs|Contains documentation in html format for offline viewing \(to be used only after cloning this repository onto a local machine\). Use [github pages](https://microchip-mplab-harmony.github.io/wireless_apps_winc1500/) of this repository for viewing it online.|

## Code Examples

The following applications are provided to demonstrate the typical or interesting usage models of one or more wireless usecases.

|Name|Description|
|----|-----------|
|[AP Scan \(Socket mode\)](apps/ap_scan/readme.md)|Demonstrates scan of near by HomeAP’s and connects to configured HomeAP|
|[TCP Client \(Socket mode\)](apps/tcp_client/readme.md)|Demonstrates WINC1500 TCP Client example application|
|[TCP Server \(Socket mode\)](apps/wifi_tcp_server_in_softap/readme.md)|Demonstrates WINC1500 TCP Server example application|
|[Wi-Fi Provisioning using SoftAP \(Socket mode\)](apps/wifi_provisioning_via_softap/readme.md)|Demonstrates WINC1500 HomeAP Provisioning using SoftAP|
|[Wi-Fi Provisioning using WPS \(Socket mode\)](apps/wifi_provisioning_via_wps/readme.md)|Demonstrates WINC1500 HomeAP Provisioning using WPS|
|[Wi-Fi STA \(Bypass/Ethernet mode\)](apps/wifi_winc_sta_bypass/readme.md))|Demonstrates WINC1500 STA Bypass\\Ethenet mode application|
|[Power Save Mode](apps/power_save_mode_example/readme.md)|Demonstrates WINC1500 low power modes|
|[Wi-Fi Socket Mode Demos](apps/wifi_socket_demos/readme.md)|Demonstrates the below WINC1500 applications in Socket Mode. WiFi station mode/Access point mode demo,OTA Demo, SSL Demo, Ping Demo, Iperf Demo, SNTP Demo, MQTT Demo, WiFi Provisioning Demo, Certificate Download OTA|
|[Wi-Fi Bypass Mode Demos](apps/wifi_bypass_demos/docs/GUID-40C3ABB9-0449-4A53-94DF-0DFB4CE5540E.md)|Demonstrates the below WINC1500 applications in Bypass Mode. WiFi station mode/Access point mode demo, SSL Demo, Ping Demo, Iperf Demo, SNTP Demo, MQTT Demo, WiFi Provisioning Demo|

## Documentation

|Mode|Document|Description|
|----|--------|-----------|
||[Create WINC Project - Getting Started](apps/getting_started/GUID-8C38797E-1BBB-4ACF-A496-EEC03A6075AC.md)|This is a getting-started guide for MPLABX IDE|
||[Firmware Upgrade of WINC Devices](apps/getting_started/GUID-AE48AE71-0F91-444B-8AC3-C5C1939A37FB.md)|This document explains in detail downloading procedure of firmware, certificate, and gain values into WINC serial flash through different supported serial interfaces like UART/I2C.|
||[Supported Modes In WINC devices](apps/getting_started/GUID-74562C24-BC96-4BBA-8346-836D98E39F8C.md)|Describes the supported modes in WINC devices|
|Socket Mode|[WINC1500+SAMD21](apps/wifi_socket_demos/docs/GUID-7C51815B-F559-46A3-A8B7-3F48A517B4A4.md)|This document explains a step by step approach to create a WINC1500 Socket mode project with SAMD21 host.|
|Socket Mode|[WINC1500+SAME54](apps/wifi_socket_demos/docs/GUID-BB3E45B9-E26C-4E97-8325-FBF9B81BBF81.md)|This document explains a step by step approach to create a WINC1500 Socket mode project with SAME54 host.|
|Bypass Mode|[WINC1500+SAME54](apps/wifi_bypass_demos/docs/GUID-34243CDA-B156-4D2B-B9C1-7ED5BE2586A6.md)|This document explains a step by step approach to create a WINC1500 Bypass mode project with SAME54 host.|
| |

