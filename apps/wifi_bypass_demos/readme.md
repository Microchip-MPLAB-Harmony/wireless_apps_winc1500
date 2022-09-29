# WINC1500 Bypass Mode Demo Applications

This example project demonstrates the WINC1500 applications of WiFi in Bypass Mode.

-   **[WiFi Provisioning](docs/GUID-C129E413-3D92-4428-8646-BC9190FC7308.md)**  

-   **[WiFi Station Mode / Access Point Mode Demo](docs/GUID-456F0E35-F354-495B-990A-4260F78B7E1B.md)**  

-   **[SSL Demo](docs/GUID-45DFB9CF-9D14-4229-8684-879C5FE9ED4E.md)**  

-   **[SNTP Demo](docs/GUID-5947E22A-1032-43CF-A6AB-AC31EBAAE0F1.md)**  

-   **[Iperf Demo](docs/GUID-9E01D5E1-824A-4A25-AA2C-D6AC57E7FB37.md)**  

-   **[Ping Demo](docs/GUID-705D1F84-1489-4A43-9406-404760FD0167.md)**  

-   **[MQTT Demo](docs/GUID-F541358A-9210-4065-B206-8CA48009BF68.md)**  


## Description

This project has WiFi example applications of WINC1500 . The user can configure the WiFi parameters and select the required example application through command.

## Downloading and building the application

To download or clone this application from Github, go to the [top level of the repository](https://github.com/Microchip-MPLAB-Harmony/wireless_apps_winc1500)

Path of the application within the repository is , **wireless\_apps\_winc1500/apps/wifi\_bypass\_demos/firmware**.

To build the application, refer to the following table and open the project using its IDE.

|Project Name|Description|
|------------|-----------|
|sam\_e54\_xpro\_winc1500.X|MPLABX project for SAME54 and WINC1500 Xplained pro|
|sam\_e54\_xpro\_winc1500\_freertos.X|MPLABX project for SAME54 and WINC1500 Xplained pro using FreeRTOS|
| | |

## Setting up SAMXXX Xplained Pro board

-   Connect the Debug USB port on the SAMXXX Xplained Pro board to the computer using a micro USB cable


## Running the Application

1.  Build and program the application project using its respective IDE.

2.  Open the Terminal application \(Ex.:Tera term\) on the computer

3.  Connect to the "USB to UART" COM port and configure the serial settings as follows:

    -   Baud : 115200

    -   Data : 8 Bits

    -   Parity : None

    -   Stop : 1 Bit

    -   Flow Control : None

4.  Use WiFi commands to configure WiFi parameters and use application commands to select the example application.


WiFi Commands Details

|Command|Details|Example|
|-------|-------|-------|
|wifi help|Wi-Fi Service help command|wifi help|
|wifi set <bootmode\> <ssid\_name\> <auth\_type\> <pwd\> <username/index\>|Set Wi-Fi Configuration for Station\(STA\) mode or Access Point \(AP\) mode|wifi set 2 DEMO\_AP 2 12345678|
|wifi get|Get Wi-Fi Configuration|wifi get|
| | | |

Wi-Fi command parameters information

|Parameter|Sub Parameter|
|---------|-------------|
|bootmode|1- Access point\(AP\) mode.2- Station\(STA\) mode.|
|ssid\_name|SSID name|
|authtype\(Security type\)|1 - OPEN Mode. 2 - WPAPSK mode. 3 - WEP mode. 5 - 802.1x authentication MSCHAPV2 mode.|
|pwd\(password\)|Password/passphrase|
|username/index|Username if authtype is 802.1x authentication MSCHAPV2 or Key Index if the authtype is WEP.|
| | |

Application command parameters information

|Command|Details|Example|
|-------|-------|-------|
|appdemo help|Application Service help command|appdemo help|
|appdemo start <demo\_id\>|Select and start an application demo|appdemo start 1|
|appdemo get|Get the ID of currently running application demo|appdemo get|
|appdemo stop|Stop the currently running application demo|appdemo stop|
| | | |

Application command parameters information

|Parameter|Sub Parameter|
|---------|-------------|
|demo\_ID|1 - WiFi station mode/Access point mode demo. 8 - SSL Demo. 9 - Ping Demo. 10 - Iperf demo. 11 - SNTP demo. 18 - MQTT Demo.|
| | |

**List of Applications**

|Application|Description|
|-----------|-----------|
|[WiFi station mode/Access point mode demo](docs/GUID-456F0E35-F354-495B-990A-4260F78B7E1B.md)|Demonstartes the Station Mode or Access Point\(AP\) mode of WINC1500|
|[SSL Demo](docs/GUID-45DFB9CF-9D14-4229-8684-879C5FE9ED4E.md)|Demonstrates TCP SSL Client application|
|[Ping Demo](docs/GUID-705D1F84-1489-4A43-9406-404760FD0167.md)|Demonstrates the Ping test|
|[Iperf Demo](docs/GUID-9E01D5E1-824A-4A25-AA2C-D6AC57E7FB37.md)|Demonstrates the iperf application|
|[SNTP Demo](docs/GUID-5947E22A-1032-43CF-A6AB-AC31EBAAE0F1.md)|Demonstrates how to retrieve time information from the time server|
|[MQTT Demo](docs/GUID-F541358A-9210-4065-B206-8CA48009BF68.md)|Demonstrates MQTT Application|
|[WiFi Provisioning Demo](docs/GUID-C129E413-3D92-4428-8646-BC9190FC7308.md)|Demonstartes the WiFi provisioning application|
| | |

### Steps to isolate/copy individual application\(s\) from the demo

If the user wants to isolate an application, follow the below mentioned steps

For example, the user wants to isolate SNTP demo,

1.  The SNTP demo uses the WiFi functionalities to get connected with the network. So copy the files "*app\_wifi.c*" and "*app\_wifi.h*" from the path "*wireless\_apps\_winc1500/apps/wifi\_bypass\_demos/firmware/src*" or "*wireless\_apps\_winc1500/apps/wifi\_socket\_demos/firmware/src*" to "src" folder of the new demo project. Then add these files to the project.

2.  Now user should copy and add the SNTP application files "*app\_sntp.c*" and "*app\_sntp.h*" from the path "*wireless\_apps\_winc1500/apps/wifi\_bypass\_demos/firmware/src*" or "*wireless\_apps\_winc1500/apps/wifi\_socket\_demos/firmware/src*" to the "*src* folder of the new demo project.

3.  The "*app.c*" and "*app.h*" files need to be copied by the user. These files integrate the SNTP application and WiFi functionalities. Copy and add these two files from the same "src" path to the "src" folder of the new demo project.

4.  In "app.c", within "*APP\_Initialize\(\)*" function, initialize the sntp application by calling "*APP\_SntpInitialize\(APPWiFiCallback\)*".

5.  In "app.c" file, make sure that, "*APP\_WiFiTasks\(wdrvHandle\)*" is getting called from the "*APP\_STATE\_WDRV\_OPEN*" state of "*APP\_Tasks\(\)*" state machine.

6.  In the same state machine "*APP\_Tasks\(\)*", within the state "*APP\_STATE\_WDRV\_APP\_LOOP*" , call the sntp application state machine "*APP\_SntpTasks\(handle\)*".

7.  Now follow the steps mentioned in the SNTP demo document to run the SNTP demo using "wifi", "sntp" and "appdemo" commands.


Similarly, for any application demo, take the required application files along with WiFi files and "app" files to create the demo.

**Note:**

1.  User has to make sure the project path does not exceed windows path limit.

2.  User should reset the device before switching the application.


