/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/
 
 // DOM-IGNORE-BEGIN
 /*******************************************************************************
* Copyright (C) 2020-21 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdlib.h>
#include "app.h"
#include "wdrv_winc_client_api.h"
#include "stdarg.h"

#include "app_wifi.h"
#include "app_sntp.h"
#include "app_ping.h"
#include "app_ota.h"
#include "app_iperf.h"
#include "app_mqtt.h"
#include "app_ssl.h"
#include "app_cert_download_ota.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
DRV_HANDLE wdrvHandle;
static APP_DEMOS appDemoId;

#define APP_PRINT_BUFFER_SIZ    2048

static OSAL_MUTEX_HANDLE_TYPE consoleMutex;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
void APP_Callback(APP_CALLBACK_NOTIFY value,void *data);

static inline void APP_DEMOTASKS(DRV_HANDLE handle) 
{
#ifdef APP_STA_AP
    if((APP_STA_AP_DEMO & appDemoId) == APP_STA_AP_DEMO) 
    {
        appData.state = APP_STATE_WDRV_OPEN;
    }
#endif
    
#ifdef APP_PING   
    if((APP_PING_DEMO & appDemoId) == APP_PING_DEMO) 
        APP_PingTasks(handle);
#endif 

#ifdef APP_SNTP 
    if((APP_SNTP_DEMO & appDemoId) == APP_SNTP_DEMO) 
    { 
        APP_SntpTasks(handle); 
    } 
#endif
    
#ifdef APP_OTA  
if((APP_OTA_DEMO & appDemoId) == APP_OTA_DEMO) 
    APP_OtaTasks(handle);
#endif 
    
#ifdef APP_IPERF
    if((APP_IPERF_DEMO & appDemoId) == APP_IPERF_DEMO) 
    { 
       APP_iperfTasks(handle); 
    } 
#endif
    
#ifdef APP_MQTT
    if((APP_MQTT_DEMO & appDemoId) == APP_MQTT_DEMO) 
    { 
       APP_MQTT_Tasks(handle); 
    } 
#endif
    
#ifdef APP_SSL
    if((APP_SSL_DEMO & appDemoId) == APP_SSL_DEMO) 
    { 
       APP_SSL_Tasks(handle); 
    } 
#endif
    
#ifdef APP_CERT_DOWNLOAD_OTA
    if((APP_CERT_DOWNLOAD_OTA_DEMO & appDemoId) == APP_CERT_DOWNLOAD_OTA_DEMO) 
    { 
       APP_CertDownloadOtaTasks(handle); 
    } 
#endif
}


static inline void APP_INITIALIZE(APP_CALLBACK APPWiFiCallback)
{
    
#ifdef APP_STA_AP    
    APP_WiFiInitialize(APPWiFiCallback);    
#endif
   
#ifdef APP_PING  
    APP_PingInitialize(APPWiFiCallback); 
#endif
    
#ifdef APP_SNTP  
    APP_SntpInitialize(APPWiFiCallback); 
#endif

#ifdef APP_OTA 
    APP_OtaInitialize(APPWiFiCallback); 
#endif

#ifdef APP_IPERF
    APP_IperfInitialize(APPWiFiCallback);
#endif 
    
#ifdef APP_MQTT
    APP_MQTT_Initialize(APPWiFiCallback);
#endif
    
#ifdef APP_SSL
    APP_SSL_Initialize(APPWiFiCallback);
#endif
    
#ifdef APP_CERT_DOWNLOAD_OTA

   APP_CertDownloadOtaInitialize(APPWiFiCallback);

#endif
}

static int App_demo_CMDProcess
(
    SYS_CMD_DEVICE_NODE* pCmdIO, 
    int argc, 
    char** argv
) 
{
    if ((argc >= 1) && (!strcmp(argv[1], "set")))
    {
       
    }
    if ((argc >= 1) && (!strcmp(argv[1], "start")))
    {
        for (int i = 2; i < argc; i++)
        {
            appDemoId |= 1 << (strtol(argv[i], NULL, 0) - 1);
        }
    }
    else if(!strcmp(argv[1], "get"))
    {
        SYS_CONSOLE_Print(appData.consoleHandle, "Demo_ID:0x%x\r\n",appDemoId);
    }
    else if(!strcmp(argv[1], "help"))
    {
        SYS_CONSOLE_PRINT("appdemo start <demo_id>\r\n");
        SYS_CONSOLE_PRINT("demo_id : \r\n1 - WiFi station mode/Access point mode demo\r\n6 - WiFi Provisioning via BLE");
        SYS_CONSOLE_PRINT("\r\n7 - OTA Demo\r\n8 - SSL Demo\r\n9 - Ping Demo\r\n10 - Iperf demo");
        SYS_CONSOLE_PRINT("\r\n11 - SNTP demo\r\n12 - Serial Chat\r\n13 - Heart rate profile\r\n14 - Battery Service");
        SYS_CONSOLE_PRINT("\r\n15 - Proximity Reporter\r\n16 - Transparent Service\r\n18 - MQTT Demo\r\n");
    }
    else if ((argc >= 1) && (!strcmp(argv[1], "stop")))
    {
        appDemoId = 0;
        WDRV_WINC_Close(wdrvHandle);
        APP_INITIALIZE(&APP_Callback);
    }
    
    return 0;
}


static const SYS_CMD_DESCRIPTOR AppDemoCmdTbl[] =
{
    {"appdemo", (SYS_CMD_FNC) App_demo_CMDProcess, ": APP commands processing"},
};

void APP_Callback(APP_CALLBACK_NOTIFY value,void *data)
{
    switch (value)
    {
        case APP_WIFI_CONNECT:
        {
            appDemoId &= ~(APP_STA_AP_DEMO);
            appData.state = APP_STATE_WDRV_APP_LOOP;
            break;
        }
        case APP_WIFI_DISCONNECT:
        {
            appDemoId |= APP_STA_AP_DEMO;
            appData.state = APP_STATE_WDRV_OPEN;
            break;
        }
        case APP_WIFI_PROVISION:
        {
            appDemoId |= APP_STA_AP_DEMO; /*Enable STA mode connection*/
            appData.state = APP_STATE_WDRV_OPEN;
            break;
        }
        default:
        {
            break;
        }
    }
}

// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize(void)
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    OSAL_MUTEX_Create(&consoleMutex);    
    SYS_CMD_ADDGRP(AppDemoCmdTbl, sizeof (AppDemoCmdTbl) / sizeof (*AppDemoCmdTbl), "appdemo", ": Appdemo commands");  
    APP_INITIALIZE(&APP_Callback);
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks(void)
{
    switch(appData.state)
    {
        case APP_STATE_INIT:
        {
            /* Get handles to both the USB console instances */
            appData.consoleHandle = SYS_CONSOLE_HandleGet(SYS_CONSOLE_INDEX_0);
            if (SYS_STATUS_READY == WDRV_WINC_Status(sysObj.drvWifiWinc))
            {
                SYS_CONSOLE_PRINT("\r\n");
                SYS_CONSOLE_PRINT("======================================\r\n");
                SYS_CONSOLE_PRINT("WIFI WINC Example Demos\r\n");
                SYS_CONSOLE_PRINT("======================================\r\n");
                appData.state = APP_STATE_WDRV_INIT_READY;
            }

            break;
        }

        case APP_STATE_WDRV_INIT_READY:
        {
            wdrvHandle = WDRV_WINC_Open(0, 0);

            if (DRV_HANDLE_INVALID != wdrvHandle)
            {   
                appData.state = APP_STATE_WDRV_OPEN;
            }
            break;
        }
        case APP_STATE_WDRV_OPEN:   
        {
#ifdef APP_STA_AP
            if((APP_STA_AP_DEMO & appDemoId) == APP_STA_AP_DEMO) 
            {
                APP_WiFiTasks(wdrvHandle);
            }
#endif
            break;
        }
        case APP_STATE_WDRV_APP_LOOP:  
        {
            APP_DEMOTASKS(wdrvHandle);
            break;
        }
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

/*******************************************************************************
 End of File
 */
