	
## WiFi Provisioning<a name="provdemo"></a>
The WiFi Provisioning application is used for receiving Wi-Fi provisioning data via the microchip android application "WiFi-Provisioing" and then triggering a Wi-Fi connection. 

1. Download the android application "WiFi Provisioning" of Microchip Technologies from App store.

2. Start the DUT as Access Point. Use "wifi set" command to configure Access Point. In the configuration, set the bootmode as Access point mode, keep the authentication type as "OPEN" and give an SSID name for the Access point.

	![](images/wifi_prov_app_set.png)

3. Enter the command "appdemo start 1" to run the application.

	![](images/wifi_prov_app_start.png)

4. Connect the mobile phone to this Access point. The IP address of connected device will be displayed on the console.

	![](images/wifi_prov_app_connected.png)

5. Open the WiFi Provisioning application in mobile phone. Set the Server IP Address as "192.168.1.1" and Server Port Number
 as **"80" for Socket mode** and **"6666" for Bypass Mode**. Then press connect.

	![](images/wif_prov_app_1.png)

6. The list of available networks will be displayed in the next window.

	![](images/wif_prov_app_2.png)

7. Select the network and enter the password. Then press, "SEND".

	![](images/wifi_prov_app_3.png)

8. The DUT will connect to the selected network and the IP address will be displayed on the terminal.

	![](images/wifi_prov_app.png)

	

