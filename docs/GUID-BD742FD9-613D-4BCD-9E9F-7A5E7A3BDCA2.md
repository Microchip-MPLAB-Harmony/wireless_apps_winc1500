# Certificate Download OTA Demo

This example demonstrates how to download the TLS certificates into WINC1500 via OTA. It downloads the certificates from an OTA download server, which is a web server.

**Note:**<br />This example will be only available with SAME54 Host

1.  Use any HTTP server or hfs.exe from [http://www.rejetto.com/hfs/](http://www.rejetto.com/hfs/)

2.  Run the hfs.exe

3.  Add the certificates from â€œ\\utilities\\cert\_storeâ€? to the root folder in the hfs.exe tool.

    ![cert_down_ota_1](GUID-25F9CE1D-4222-477D-B45A-D07904C0BB11-low.png)

4.  Configure the wifi parameters using "wifi set" command.

    ![cert_down_ota_3](GUID-42CB90D8-03AB-4614-A227-E6DA380E26AE-low.png)

5.  Copy the URL from hfs tool.

    ![cert_down_ota_2](GUID-D1327EB9-B93B-49FD-83BD-A3458384A49B-low.png)

6.  Enter the command "cert <url\>".

    ![cert_down_ota_4](GUID-239DA03B-8D3E-4621-A256-2AC541EB3351-low.png)

7.  Enter the application command "appdemo start 1 19" to run the Certificate download via OTA demo. First the device will connect to the network.

    ![cert_down_ota_5](GUID-9B6AB3FA-1090-4B5A-802E-E915333DD54C-low.png)

8.  After the IP address has displayed on the terminal window, application will execute the CERT command and starts the certificate download.

    ![cert_down_ota_6](GUID-DB3D84FE-1712-4025-BF35-770F818C6022-low.png)


**Parent topic:**[WINC1500 Socket Mode Demo Applications](GUID-52D24502-1FE3-473D-9DA1-624A4E26166B.md)

