# Exeption Error connecting Wifi

To fix this issue ADD
```
WiFi.persistent(false);
WiFi.disconnect(true);
WiFi.begin(ssid, password);
```
That code above did the trick.

Example:
```
Serial.println();
Serial.println();
Serial.println(“——————————–“);
Serial.print(“Connecting to “);
Serial.println(ssid);
Serial.println(“Attempt Login…..”);
WiFi.persistent(false);
WiFi.disconnect(true);
WiFi.begin(ssid, password);
```
