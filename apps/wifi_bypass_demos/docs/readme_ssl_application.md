

## SSL Demo<a name="ssldemo"></a>
This application demonstrates how a user can run a secured TCP Client on WINC1500 device. In this application, we open a secured html page 'https://www.google.com'. Here the TCP SSL Client running on the WINC1500 device shall connect to server google.com over a secured html port 443, and make a reuqtest for getting the html page. 

1. Configure the wifi parameters using "wifi set" command.

	![](images/ping_demo_config.png)

2. Enter the command "ssl https://www.google.com/"

	![](images/ssl_url.png)

3. Enter the command "appdemo start 1". The device will connect to the network and IP address will be displayed on the terminal window.

	![](images/ssl_start.png)

4. Enter the command "appdemo start 8" to run the SSL demo. After connecting to the AP, the TCP SSL Client on the WINC1500 device shall connect to the Server - google.com over the secured html port 443. 

	![](images/ssl_connected.png)

	Note: The user needs to ensure that the server certificate is a part of the WINC FW Image in case a secured connection is needed with the server.

5. After connecting to google Server, the TCP SSL Client on the WINC1500 device shall send a GET HTML request, and the google server shall send in the html page.

	![](images/ssl_response.png)

