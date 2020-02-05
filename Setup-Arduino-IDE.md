## Setup the Arduino IDE for ESP8266 Boards
I made this summary following this link [simple-circuit.com](https://simple-circuit.com/arduino-esp-01-esp8266-programming/)   
   
   
It’s easy to start ESP8266 programming, all what we’ve to do is adding it to the Arduino IDE software.   
First, open Arduino IDE and go to File —> Preferences   
Add the link below to Additional Boards Manager URLs and click on OK:   
   
http://arduino.esp8266.com/stable/package_esp8266com_index.json   
   
   
![preferences](https://raw.githubusercontent.com/rsamanez/arduino-ESP8266/master/images/arduino-ide-esp8266-esp-01-board.png)   
   
Now go to Tools —> Board —> Boards Manager …   
   
![Boards Manager](https://raw.githubusercontent.com/rsamanez/arduino-ESP8266/master/images/esp-01-arduino-ide.png)   
   
In the search box write esp8266 and click on Install and the installation of the board should start (the installation may take some time depending on the connection speed):   
   
![Install ESP8266 Boards](https://raw.githubusercontent.com/rsamanez/arduino-ESP8266/master/images/arduino-ide-esp8266-boards.png)    
   
After the installation select the ESP-01 board by going to: Tools —> Board: —> Generic ESP8266 Module  
   
![Use Generic Board](https://github.com/rsamanez/arduino-ESP8266/blob/master/images/esp8266-generic-board-arduino-ide.png)   
   
   
Now every thing is finished and we can start our ESP8266 programming.   
