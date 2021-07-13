

## MQTT Demo<a name="mqttdemo"></a>
This application demonstrates how a user run a MQTT Client using third party Paho software on WINC1500 device. The user would need to use "MQTT.fx" third party Mqtt Client application to receive message posted by MQTT Client running on WINC1500 device once it connects to the MQTT server.

### Socket Mode MQTT Demo

1. Download the MQTT.fx Third Party Mqtt Client Application and open it on Laptop.

2. Connect the MQTT.fx Application to the MQTT Server - test.mosquitto.org with port 1883.

	![Mqtt App Connect](images/mqtt_fx1.png)

3. Make the MQTT.fx Application susbcribe to Topic MCHP/Sample/a.

	![Mqtt App Connect](images/mqtt_fx2.png)

4. Configure the wifi parameters using "wifi set" command.

	![](images/ping_demo_config.png)

5. Enter the command "mqtt start". 

	![](images/mqtt_start_cmd.png)

6. Enter the command "appdemo start 1". The device will connect to the network and IP address will be displayed on the terminal window.

	![](images/mqtt_app_start.png)

7. Enter the command "appdemo start 18" to start the MQTT application. The MQTT Client on the WINC1500 device shall connect to the MQTT Server - test.mosquitto.org.

	![](images/mqtt_connected.png)

8. After connecting to MQTT Server, the MQTT Client on the WINC1500 device shall subscribe to Topic MCHP/Sample/b.

	![](images/mqtt_subscribe_1.png)

9. The MQTT Client on the WINC1500 device shall publish the message "Hello" to Topic MCHP/Sample/a.

	![](images/mqtt_subscribe.png)

10. MQTT.fx Application receives the message "Hello" on the Topic MCHP/Sample/a sent by the MQTT Client running on the WINC1500.

	![Mqtt App Receive](images/mqtt_fx3.png)

11. Publish message from MQTT.fx Application on the Topic MCHP/Sample/b.

	![Mqtt App Publish](images/mqtt_fx4.png)

12. The MQTT Client on the WINC1500 device receives the message on the Topic MCHP/Sample/b sent by the MQTT.fx Application running on the laptop.

	![Mqtt App Publish](images/mqtt_publish_terminal.png)

**Note:**<br> If the user wants to create a MQTT application project in Socket Mode, and wants to use the Paho for MQTT Protocol, One needs to follow the below mentioned steps
1. From the "paho.mqtt.embedded-c" repo, copy the folder "paho.mqtt.embedded-c\MQTTPacket" to "app_demos\firmware\src\third_party\paho.mqtt.embedded-c\MQTTPacket" of the new project directory.<br>
2. From the "paho.mqtt.embedded-c" repo, copy the folder "paho.mqtt.embedded-c\MQTTClient-C" to "app_demos\firmware\src\third_party\paho.mqtt.embedded-c\MQTTClient-C" of the new project directory.<br>
3. It is important to have the porting files "MCHP_winc.c" and "MCHP_winc.h" in the project. These porting files are available only in "wifi_socket_demo" project. Copy the folder from "wifi_socket_demos\firmware\src\third_party\paho.mqtt.embedded-c\MQTTClient-C\Platforms" to "app_demos\firmware\src\third_party\paho.mqtt.embedded-c\MQTTClient-C\Platforms" of the new project directory. Please make sure that the folder structure of the new project is same as mentioned above.

* Enable MQTT<br>
	User should enable the macro "WINC_MQTT" to enable the MQTT application. For this follow the steps:
	* Open project properties

		![](images/mqtt_properties_1.png)

	* Select xc32-gcc

		![](images/mqtt_properties_2.png)

	* Select "preprocessing and messages" from the "Option Categories".

		![](images/mqtt_properties_3.png)

	* Select the "add" button of "Preprocessor Macros"

		![](images/mqtt_properties_4.png)

	* Add the macro "WINC_MQTT" and press OK.

		![](images/mqtt_properties_6.png)

### Bypass Mode MQTT Demo

1. Download the MQTT.fx Third Party Mqtt Client Application and open it on Laptop.

2. Connect the MQTT.fx Application to the MQTT Server - mqtt.eclipseprojects.io with port 1883.

	![Mqtt App Connect](images/mqtt_bypass_fx1.png)

3. Make the MQTT.fx Application susbcribe to Topic "MQTT_NET_Client topic".

	![Mqtt App Connect](images/mqtt_bypass_fx2.png)

4. Configure the wifi parameters using "wifi set" command.

	![](images/mqtt_bypass_wifi_set.png)

5. Enter the command "mqtt start". 

	![](images/mqtt_bypass_start.png)

6. Enter the command "appdemo start 1 18". The device will connect to the network and IP address will be displayed on the terminal window.

	![](images/mqtt_bypass_ap_connected.png)

7.  The MQTT Client on the WINC1500 device shall connect to the MQTT Server - mqtt.eclipseprojects.io.

	![](images/mqtt_bypass_client_connected.png)

8. After connecting to MQTT Server, the MQTT Client on the WINC1500 device shall subscribe to Topic "MQTT_NET_Client topic".

	![](images/mqtt_bypass_subscribed.png)

9. The MQTT Client on the WINC1500 device shall publish the message "MQTT NET Demo Test Message" to Topic "MQTT_NET_Client topic".

	![](images/mqtt_bypass_published.png)

10. MQTT.fx Application receives the message "MQTT NET Demo Test Message" on the Topic "MQTT_NET_Client topic" sent by the MQTT Client running on the WINC1500.

	![Mqtt App Receive](images/mqtt_bypass_fx3.png)

11. The message "MQTT NET Demo Test Message" will be published from MQTT.fx Application. Since it is subcribing to the same topic "MQTT_NET_Client topic". The MQTT demo will exit after publishing the message.

	![Mqtt App Publish](images/mqtt_bypass_completed.png)
   
   

<a href="#top">Back to top</a>