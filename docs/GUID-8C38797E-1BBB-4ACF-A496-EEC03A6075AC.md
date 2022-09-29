# Create WINC Project - Getting Started

**Parent topic:**[Harmony 3 Wireless application examples for WINC1500](GUID-D41DC58E-4197-40C3-B2E5-298EE2491305.md)

## Download wireless repository from Github

After the installation, open the MPLAB IDE and launch H3 content manager from the IDE

![](GUID-0351C42C-43DD-4841-A743-ACCA0A7C1ABD-low.png)

Please provide the framework path with the local system path.

![](GUID-F7E34FF5-A016-4F16-99D4-1FD46EFA610A-low.png)

This displays a new window as shown below.

![](GUID-F18344BC-FDC0-411B-9930-EDDA8EA5D900-low.png)

Using this window, user can download either all the packages or only the wireless packages with its required dependencies.

To download the wireless packages and its dependencies:

-   Scroll down and select **wireless\_wifi, wireless\_apps\_winc1500 and wireless\_apps\_winc3400**.

-   Click **Download Selected**


![](GUID-C7714015-2A3A-400B-A04C-8AE9DB772EA6-low.png)

It requests permission to download its dependencies. Click **OK**

![](GUID-7EB80D17-AA7C-4ED6-975C-C29B67FE44D7-low.png)

In the License Window

-   Select **Accept All License**

-   Click **Close**


Go to the local system path and check if the following packages are downloaded correctly

![](GUID-77BCA461-E9F3-4532-94CE-E908C8D874E3-low.png)

## Pin mapping between host and WINC

This section explains how to map pins between WINC1500/WINC3400 device and host to establish connection and exchange data. Totally 7/11 pins are involved in pin mapping \(except VCC and GND\) and they are.

-   SPI \(SS, CLOCK, MOSI and MISO\)

-   Reset

-   Chip Enable

-   Interrupt

-   UART only applicable for WINC3400 BLE \(Tx, Rx, CTS and RTS\)


![](GUID-C9A39DB8-7D3B-4A56-A625-CF580B6E5A6B-low.png)

SAME54 and SAMD21 is used as example host throughout this document for both WINC1500 and WINC3400. SAME54 / SAMD21 XPRO board is used as the host development board and WINC1500 XPRO / WINC3400 XPRO is used as development board. Host and the WINC device are connected through extension headers. In this document, Extension 1 of SAME54 / SAMD21 host is used to connect with WINC device.

The one to one pin mapping can be performed between SAME54 / SAMD21 XPRO extension header and WINC XPRO extension header by referring the following sections of the document. Table 4-1 section under 4.1.1 of **[WINC1500 Xplained Pro User's Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/50002616A.pdf)**. Table 4-1 section under 4.1.1 of **[WINC3400 Xplained Pro User's Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/50002702A.pdf)** Table 5-1 section under 5.2.1 of **[SAM E54 Xplained Pro User's Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/70005321A.pdf)** Table 4-1 section under 4.1.1 of **[SAM D21 Xplained Pro User's Guide](http://ww1.microchip.com/downloads/en/devicedoc/atmel-42220-samd21-xplained-pro_user-guide.pdf)** In the same way if the user is using a different host, then he can perform one to one pin mapping by referring that host’s user guide.

### SPI interface

Communication between SAME54 / SAMD21 and WINC happens through SPI interface. Here, WINC acts as a slave and SAME54 / SAMD21 acts as master. The below table lists the SPI pins of WINC extension and its corresponding pins of SAME54 and SAMD21.

![](GUID-8A934DFF-5C6A-4EF9-9AAA-EDF7E47A1FE0-low.png)

### Power up pins

Reset and Chip Enable pins are used to perform power up sequence in WINC from host. The below table lists the power up pins of WINC extension and its corresponding pins of SAME54 / SAMD21.

#### WINC1500 Power up pins

![](GUID-2840D2CD-109E-4B06-9C63-1FFD7B5DAD59-low.png)

#### WINC3400 Power up pins

![](GUID-FFC324AC-3805-44DE-AC5A-0456224C3EC3-low.png)

#### Interrupt pin

Interrupt pin is used to send signal to host from WINC device.

![](GUID-FFC324AC-3805-44DE-AC5A-0456224C3EC3-low.png)

