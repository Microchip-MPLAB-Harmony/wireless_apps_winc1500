---
parent: Harmony 3 Wireless Package
title: WiFi Applications in Socket Mode and Bypass Mode
has_toc: true
has_children: false
has_toc: false
nav_order: 1

family: SAME54
family: SAMD21
function: WiFi Applications in Socket Mode and Bypass Mode
---

# WINC1500 Example Applications

This example project demonstrates the WINC1500 applications of WiFi in Socket mode and Bypass Mode.

## Description

This project has WiFi example applications of WINC1500 . The user can configure the WiFi parameters and select the required example application through command. 

## Downloading and building the application

To download or clone this application from Github, go to the [top level of the repository](https://github.com/Microchip-MPLAB-Harmony/wireless)


Path of the application within the repository is ,<br>Socket Mode: **wireless_apps_winc1500/apps/wifi_socket_demos/firmware** 
<br>Bypass Mode: **wireless_apps_winc1500/apps/wifi_bypass_demos/firmware**.

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------| -----------------------------------------------------  |
| sam_e54_xpro_winc1500.X | MPLABX project for SAME54 and WINC1500 Xplained pro|
| sam_d21_xpro_winc1500.X | MPLABX project for SAMD21 and WINC1500 Xplained pro|
|||


## Setting up SAMXXX Xplained Pro board

- Connect the Debug USB port on the SAMXXX Xplained Pro board to the computer using a micro USB cable




## Running the Application

1. Build and program the application project using its respective IDE.

2. Open the Terminal application (Ex.:Tera term) on the computer

3. Connect to the "USB to UART" COM port and configure the serial settings as follows:

    * Baud : 115200
    * Data : 8 Bits
    * Parity : None
    * Stop : 1 Bit
    * Flow Control : None

4. Use WiFi commands to configure WiFi parameters and use application commands to select the example application.

WiFi Commands Details

| Command         | Details        |               Example                |
| ----------------| ---------------|-------------------------------       |
| wifi help    	  | Wi-Fi Service help command| wifi help                 |
| wifi set \<bootmode\> \<ssid_name\> \<auth_type\> \<pwd\> \<username/index\>     | Set Wi-Fi Configuration for Station(STA) mode or Access Point (AP) mode | wifi set 2 DEMO_AP 2 12345678 |
| wifi get        | Get Wi-Fi Configuration   | wifi get   |
|||

Wi-Fi command parameters information

| Parameter       | Sub Parameter                                          |
| ----------------| -----------------------------------------------------  |
| bootmode        | 1- Access point(AP) mode.<br>2- Station(STA) mode.     |
| ssid_name       | SSID name                                			   |
|authtype(Security type) | 1 - OPEN Mode.<br> 2 - WPAPSK mode.<br> 3 - WEP mode.<br>  5 -  802.1x authentication MSCHAPV2 mode.  |
|pwd(password)| Password/passphrase  |
|username/index| Username if authtype is 802.1x authentication MSCHAPV2  or Key Index if the authtype is WEP.  |
|||

Application command parameters information

| Command         | Details        |               Example                |
| ----------------| ---------------|-------------------------------       |
| appdemo help    | Application Service help command| appdemo help        |
| appdemo start \<demo_id\>  | Select and start an application demo | appdemo start 1 |
| appdemo get     | Get the ID of currently running application demo  | appdemo get   |
| appdemo stop     | Stop the currently running application demo  | appdemo stop   |
|||

Application command parameters information

| Parameter       | Sub Parameter                                          |
| ----------------| -----------------------------------------------------  |
| demo_ID         | 1 - WiFi station mode/Access point mode demo.<br> 7 - OTA Demo. <br> 8 - SSL Demo. <br> 9 - Ping Demo. <br> 10 - Iperf demo. <br> 11 - SNTP demo. <br> 18 - MQTT Demo.|
|||

**List of Applications**

| Application         | Socket Mode        |               Bypass Mode                
| ----------------| ---------------| -------------------------------       |
| [WiFi station mode/Access point mode demo](docs/readme_sta_ap_mode_application.md)    	  | Available| Available                 | Available |Available| 
| [OTA Demo](docs/readme_ota_application.md)        | Available   | Not Available   |
| [SSL Demo](docs/readme_ssl_application.md)        | Available   | Available   |
| [Ping Demo](docs/readme_ping_application.md)        | Available   | Available   |
| [Iperf Demo](docs/readme_iperf_application.md)       | Available   | Available   |
| [SNTP Demo](docs/readme_sntp_application.md)       | Available   | Available   |
| [MQTT Demo](docs/readme_mqtt_application.md)       | Available   | Available   |
| [WiFi Provisioning Demo](docs/readme_wifi_provision_application.md)       | Available   | Available   |
|||


**Note:** <br> 

1. User has to make sure the project path does not exceed windows path limit.

2. User should reset the device before switching the application.

