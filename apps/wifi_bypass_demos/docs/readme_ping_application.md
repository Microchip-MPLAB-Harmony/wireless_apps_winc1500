
## Ping Demo<a name="pingdemo"></a>
This application demonstrates how a user can run a ping test on WINC1500 device. The steps to be followed to run the demo in socket mode and bypass mode are different. Refer the respective sections for details.

### Socket Mode Ping Demo

1. Configure the wifi parameters using "wifi set" command.

	![](images/ping_demo_config.png)

2. Enter the command "sping <ip_address> <no_of_ping>". 

	![](images/sping_cmd.png)

3. Then enter the command "appdemo start 1 9" to run the Ping demo.
First the device will connect to the network. After the IP address has displayed on the terminal window, the ping command will start.

	![](images/ping_response.png)

### Bypass Mode Ping Demo

1. Configure the wifi parameters using "wifi set" command.

	![](images/ping_bypass_start.png)

2. Enter the Then enter the command "appdemo start 1". Then the device will connected to the AP and the IP address will be displayed on the terminal.

	![](images/ping_bypass_ip.png)

3. Enter the command "ping <ip_address>". It will start pinging the corresponding IP address.
	
	![](images/ping_bypass_response.png)



