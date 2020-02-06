#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Put your SSID & Password */
const char* ssid = "ESP8266";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

uint8_t PULSE_COUNT = 0;
uint8_t LED1pin = 2;
bool LED1status = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LED1pin, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("\n\n\nHTTP server started");
}
void loop() {
  server.handleClient();
  if(LED1status)
  {
    digitalWrite(LED1pin, HIGH);
    delay(10);
    digitalWrite(LED1pin, LOW);
    delay(10);
    if(PULSE_COUNT){
      PULSE_COUNT--;
    }else{
      LED1status = LOW;
      Serial.println("GPIO2 Status: OFF");
    }
  }
  else
  {
    digitalWrite(LED1pin, LOW);
  }
}

void handle_OnConnect() {
  LED1status = LOW;
  Serial.println("GPIO2 Status: OFF");
  server.send(200, "text/html", SendHTML()); 
}

void handle_led1on() {
  LED1status = HIGH;
  PULSE_COUNT = 100;
  Serial.println("GPIO2 Status: ON");
  server.send(200, "text/html", SendHTML()); 
}


void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(void){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Carport Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 160px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>10ms Pulse Generator</h1>\n";
  ptr +="<a class=\"button button-on\" href=\"/led1on\">PULSE</a>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
