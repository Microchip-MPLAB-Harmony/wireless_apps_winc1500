######################  wireless_apps_winc1500  ######################
def loadModule():
    print('Load Module: wireless_apps_winc1500')

    ## Serial Bridge Application
    ##appSerBridge = Module.CreateComponent('appWincSerialBridge', 'Serial Bridge Application', '/Wireless/SerialBridge/', 'apps/serial_bridge/config/app_winc_serial_bridge.py')

    ## Example Applications
    appWincExampleConfComponent = Module.CreateComponent('appWincExampleConf', 'WINC Example Application Configuration', '/wireless_apps_winc1500/', 'config/winc_example_app_conf.py')
