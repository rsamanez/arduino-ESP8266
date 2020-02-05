## LED Blink with ESP8266 (ESP-01):   
   
This is a simple example which we should start with, it’s the LED blinking example. In this example I’m going to connect one LED to ESP-01 board GPIO2 pin, and make this LED blinks. Circuit diagram is shown below:   
   
![Project schema](https://raw.githubusercontent.com/rsamanez/arduino-ESP8266/master/images/esp-01-module-pinout.png)   
   
The LED is connected to pin GPIO2 of the ESP-01 module through a 330 ohm resistor.   
The ESP-01 module needs a 3.3V supply.   
   
   
Arduino code for ESP8266 module:   
```
// LED Blink example for ESP8266 (ESP-01) module
 
#define LED        2               // LED is connected to GPIO2
 
void setup() {
 
  pinMode(LED, OUTPUT);            // Configure LED pin as output
 
}
 
void loop() {
 
  digitalWrite(LED, HIGH);          // Turn the LED on
  delay(500);                       // wait 1/2 second
  digitalWrite(LED, LOW);           // turn the LED off
  delay(500);                       // wait 1/2 second
 
}
```
