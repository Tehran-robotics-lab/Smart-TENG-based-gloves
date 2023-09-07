/*
#include<Arduino.h>
#include <WiFi.h>
#include "ESPAsyncWebServer.h"
const char* ssid = "ESP32 WiFI AP"; 
const char* password = "123456789";

AsyncWebServer server(80);

IPAddress Ip(192, 168, 1, 1);
IPAddress NMask(255, 255, 255, 0);

String request;
int input1;
int input2;
int input3;
int sensor = 14;
unsigned long previousMillis = 0;
const long interval = 250; 
unsigned long currentMillis;
void setup(){
  Serial.begin(115200);
  Serial.println("ESP32 Access Point Mode");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  delay(100);
  WiFi.softAPConfig(Ip, Ip, NMask);
  Serial.print("Connect to IP address: ");
  Serial.println(WiFi.softAPIP());
  server.begin();
      server.on("/sensor", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", String(input1));
    });
}
void loop(){
     currentMillis = millis();
       
  if(currentMillis - previousMillis >= interval) {
      input1 = currentMillis;
      // save the last HTTP GET Request
      previousMillis = currentMillis;

  }
}
*/
