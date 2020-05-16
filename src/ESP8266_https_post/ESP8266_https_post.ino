/*
 * HTTPS Secured Client POST Request
 * Copyright (c) 2019, circuits4you.com
 * All rights reserved.
 * https://circuits4you.com 
 * Connects to WiFi HotSpot. */

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h> 
#include <ESP8266HTTPClient.h>

/* Set these to your desired credentials. */
const char *ssid = "XXXXXX";  //ENTER YOUR WIFI SETTINGS
const char *password = "MY-PASSWORD";

//Link to read data from https://jsonplaceholder.typicode.com/comments?postId=7
//Web/Server address to read/write from 


//SHA1 finger print of certificate use web browser to view and copy                                 
const char *host = "jsonplaceholder.typicode.com";
const int httpsPort = 443;  //HTTPS= 443 and HTTP = 80
const char fingerprint[] PROGMEM = "06 68 CF CF 1D 2C E8 30 5F DF 33 C9 33 C3 10 01 22 13 15 1E";
//=======================================================================
//                    Power on setup
//=======================================================================

void setup() {
  
  delay(2000);
  Serial.begin(115200);
  Serial.println("");
  Serial.println("");
  Serial.println("SetUp Wifi step1");
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  Serial.println("SetUp Wifi step2");
  delay(2000);
  WiFi.mode(WIFI_STA);        //Only Station No AP, This line hides the viewing of ESP as wifi hotspot
  Serial.println("Wifi try to connect to SSID");
  WiFi.persistent(false);
  WiFi.disconnect(true);
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  WiFiClientSecure httpsClient;    //Declare object of class WiFiClient

  Serial.println(host);

  Serial.printf("Using fingerprint '%s'\n", fingerprint);
  httpsClient.setFingerprint(fingerprint);
  httpsClient.setTimeout(15000); // 15 Seconds
  delay(1000);
  
  Serial.print("HTTPS Connecting");
  int r=0; //retry counter
  while((!httpsClient.connect(host, httpsPort)) && (r < 30)){
      delay(100);
      Serial.print(".");
      r++;
  }
  if(r==30) {
    Serial.println("Connection failed");
  }
  else {
    Serial.println("Connected to web");
  }
  
  String getData, Link;
  
  //POST Data
  Link = "/posts";

  Serial.print("requesting URL: ");
  Serial.println(host);
  /*
   POST /post HTTP/1.1
   Host: postman-echo.com
   Content-Type: application/x-www-form-urlencoded
   Content-Length: 13
  
   say=Hi&to=Mom

     "Content-Length: 13" + "\r\n\r\n" +
      "say=Hi&to=Mom" + "\r\n" +
      "Connection: close\r\n\r\n");
   */

  httpsClient.print(String("POST ") + Link + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Cache-control: no-cache"+ "\r\n\r\n" +
               "{\"title\":\"foo\",\"body\":\"bar\",\"userId\":1}" + "\r\n"+
               "Connection: close\r\n\r\n");
               

  Serial.println("request sent");
                  
  while (httpsClient.connected()) {
    String line = httpsClient.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }

  Serial.println("reply was:");
  Serial.println("==========");
  String line;
  while(httpsClient.available()){        
    line = httpsClient.readStringUntil('\n');  //Read Line by Line
    Serial.println(line); //Print response
  }
  Serial.println("==========");
  Serial.println("closing connection\n\n\n");
    
  delay(10000);  //POST Data at every 2 seconds
}
//=======================================================================
