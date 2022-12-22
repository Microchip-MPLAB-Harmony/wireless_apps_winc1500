
# WINC1500 Socket Mode Demo Applications

This example project demonstrates the WINC1500 applications of WiFi in Socket mode.

## Description

This project has WiFi example applications of WINC1500 . The user can configure the WiFi parameters and select the required example application through command. 

## Downloading and building the application

To download or clone this application from Github, go to the [top level of the repository](https://github.com/Microchip-MPLAB-Harmony/wireless_apps_winc1500)


Path of the application within the repository is , **wireless_apps_winc1500/apps/wifi_socket_demos/firmware** 

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------| -----------------------------------------------------  |
| sam_e54_xpro_winc1500.X | MPLABX project for SAME54 and WINC1500 Xplained pro|
| sam_d21_xpro_winc1500.X | MPLABX project for SAMD21 and WINC1500 Xplained pro|
| sam_e54_xpro_winc1500_freertos.X | MPLABX project for SAME54 and WINC1500 Xplained pro using FreeRTOS|
| sam_a5d27_som1_winc1500.X | MPLABX project for SAMA5D27 and WINC1500 WiFi 7 Click board|
|||


## Setting up SAMXXX Xplained Pro board

- Connect the Debug USB port on the SAMXXX Xplained Pro board to the computer using a micro USB cable

## Setting up SAMA5D27-SOM1-EK1 Evaluation Kit

- Connect the WINC1500 WiFi 7 Click board to the MBus1 connector.

- Connect the USB port (J10) on SOM1-Ek1 board to the computer using micro USB cable.

### Setting up the SD Card

 - Copy the boot loader binary( boot.bin) from "firmware\at91bootstrap_sam_a5d27_som1_ek.X\binaries" onto the SD card

 - Copy the application (harmony.bin) from "firmware/sam_a5d27_som1_winc1500.X/dist/sam_a5d27_som1_winc1500/production" onto the SD card, available after a successful build of the application 

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
| demo_ID         | 1 - WiFi station mode/Access point mode demo.<br> 7 - OTA Demo. <br> 8 - SSL Demo. <br> 9 - Ping Demo. <br> 10 - Iperf demo. <br> 11 - SNTP demo. <br> 18 - MQTT Demo. <br> 19 - Certificate download via OTA Demo.|
|||

**List of Applications**

| Application      | Description                                    |
| ----------------| -----------------------------------------------------  |
| [WiFi station mode/Access point mode demo](GUID-F459DB00-6C0A-4DC0-99F6-C67C5C4A7C52.md)   | Demonstartes the Station Mode or Access Point(AP) mode of WINC1500  | 	  
| [OTA Demo](GUID-6D2D8401-87A9-4600-8700-F113BA941E5D.md)  | Demonstrates OTA firmware upgrade |      
| [SSL Demo](GUID-D776A67C-BE2A-4EC3-A149-32AC22EB4C5A.md) |  Demonstrates TCP SSL Client application |       
| [Ping Demo](GUID-BADEF0EB-B3EA-4EF9-8B9B-8DAC044C7957.md)| Demonstrates the Ping test |        
| [Iperf Demo](GUID-0FD5A351-8B22-466E-90C3-3DCA88C651D3.md) | Demonstrates the iperf application|      
| [SNTP Demo](GUID-EC458E8F-7C6B-4F4A-929B-3DB23A6508CF.md) |Demonstrates how to retrieve time information from the time server|      
| [MQTT Demo](GUID-AE60932A-703A-481E-817A-53DCFD93BA11.md) | Demonstrates  MQTT Application  |      
| [WiFi Provisioning Demo](GUID-DB7F0202-30DD-4848-AE43-CF154294E842.md) | Demonstartes the WiFi provisioning application|
| [Certificate download via OTA Demo](GUID-BD742FD9-613D-4BCD-9E9F-7A5E7A3BDCA2.md) | Demonstartes Certificate download via OTA application|      
|||

### Steps to isolate/copy individual application(s) from the demo

 If the user wants to isolate an application, follow the below mentioned steps <br>

 For example, the user wants to create an SNTP demo in Socket mode.
1. The SNTP demo uses the WiFi functionalities to get connected with the network. So copy the files "<em> app_wifi.c</em>" and "<em> app_wifi.h </em>" from the path "<em>wireless_apps_winc1500/apps/wifi_bypass_demos/firmware/src </em>" or "<em>wireless_apps_winc1500/apps/wifi_socket_demos/firmware/src</em>" to "src" folder of the new demo project. Then add these files to the project.<br>

2. Now user should copy and add the SNTP application files "<em>app_sntp.c</em>" and "<em>app_sntp.h</em>" from the path "<em>wireless_apps_winc1500/apps/wifi_bypass_demos/firmware/src </em>" or "<em>wireless_apps_winc1500/apps/wifi_socket_demos/firmware/src</em>" to the "<em>src</em> folder of the new demo project. <br>

3. The "<em>app.c</em>" and "<em>app.h</em>"  files need to be copied by the user. These files integrate the SNTP application and WiFi functionalities. Copy and add these two files from the same "src" path to the "src" folder of the new demo project. <br>

4. In "app.c", within "<em>APP_Initialize()</em>" function, initialize the sntp application by calling "<em> APP_SntpInitialize(APPWiFiCallback)</em>".

5. In "app.c" file, make sure that, "<em> APP_WiFiTasks(wdrvHandle)</em>" is getting called from the "<em> APP_STATE_WDRV_OPEN </em>" state of "<em> APP_Tasks() </em>" state machine.

6. In the same state machine "<em> APP_Tasks() </em>", within the state "<em> APP_STATE_WDRV_APP_LOOP </em>" , call the sntp application state machine "<em>APP_SntpTasks(handle)</em>".

7. Now follow the steps mentioned in the SNTP demo document to run the SNTP demo using "wifi", "sntp" and "appdemo" commands.

Similarly, for any application demo, take the required application files along with WiFi files and "app" files to create the demo.


**Note:** <br> 

1. User has to make sure the project path does not exceed windows path limit.

2. User should reset the device before switching the application.

