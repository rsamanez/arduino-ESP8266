## EPS-01 Module
![ESP-01Module](https://raw.githubusercontent.com/rsamanez/arduino-ESP8266/master/images/ESP-01-8266.jpg)
## PinOut Diagram
TX: UART data transmit pin which is also GPIO1 pin   
GND: ground pin (0 V)   
CH_PD: chip power down pin, used to turn off the ESP8266EX chip, when high the chip is enabled and when low the chip is off, also named as CH_PU (chip power up) and CHIP_EN (chip enable)   
GPIO2: general purpose input/output pin 2   
RESET: external reset pin (active low), when low the chip is in reset mode   
GPIO0: general purpose input/output pin 0   
VCC: power supply pin. ESP8266EX chip Operating voltage: 2.5V ~ 3.6V   
RX: UART data receive pin which is also GPIO3 pin   
![ESP-01-pinout](https://raw.githubusercontent.com/rsamanez/arduino-ESP8266/master/images/esp-01-module-pinout.png)
## Flashing Firmware
This step is used to be sure that the ESP-01 Module is running ok. To start flashing, ground GPIO0 pin and reset the Module.   
Use this firmware file:   [AI-v0.9.5 AT Firmware.bin](https://github.com/rsamanez/arduino-ESP8266/blob/master/firmware/AI-v0.9.5.0%20AT%20Firmware.bin?raw=true)   
Flasher Application: [ESP8266Flasher.exe](https://github.com/rsamanez/arduino-ESP8266/blob/master/tools/ESP8266Flasher.exe?raw=true)   
   
Check the flasher advance parameters   
![config](https://raw.githubusercontent.com/rsamanez/arduino-ESP8266/master/images/flasher_img03.jpg)   
   
Check the flasher firmware file to be flashed   
![firmware](https://raw.githubusercontent.com/rsamanez/arduino-ESP8266/master/images/flasher_img02.jpg)   
   
Start flashing process   
![start](https://raw.githubusercontent.com/rsamanez/arduino-ESP8266/master/images/flasher_img01.jpg)   
   
Release the GPIO0 pin and restart the Module.   
By default the serial speed is set to 9600 baud   
   
Use a serial console to check the AT commands
```
# Check the current serial speed
AT+CIOBAUD?
# Change the serial speed to 115200 baud
AT+CIOBAUD=115200
```
