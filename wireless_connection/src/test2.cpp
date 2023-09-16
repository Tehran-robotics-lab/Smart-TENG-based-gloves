/*
#include <Arduino.h>
#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include <Iir.h>

const char* ssid = "ESP32 WiFI AP";
const char* password = "123456789";

const float cutoffFrequency = 100.0; // Cutoff frequency in Hz
const float samplingFrequency = 1000.0; // Sampling frequency in Hz
const int filterOrder = 4;


Iir::Butterworth::LowPass<filterOrder> filter; // butterworth filter

AsyncWebServer server(80);

IPAddress Ip(192, 168, 1, 1);
IPAddress NMask(255, 255, 255, 0);

String request;
float input1;
float filtered;
int input2;
int input3;
int sensor = 14;
unsigned long previousMillis = 0;
const long interval = 250;
unsigned long currentMillis;

void setup() {
  pinMode(33, INPUT);
  Serial.begin(115200);
  Serial.println("ESP32 Access Point Mode");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  delay(100);
  WiFi.softAPConfig(Ip, Ip, NMask);
  Serial.print("Connect to IP address: ");
  Serial.println(WiFi.softAPIP());
  
  // Calculate the filter coefficients for the Butterworth low-pass filter
  filter.setup(samplingFrequency, cutoffFrequency);
  
  server.begin();
  server.on("/sensor", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", String(input1));
  });
}

void loop() {
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    input1 = analogRead(33);
    
    // Apply the IIR filter to the input signal
    filtered = filter.filter(input1);
    
    //Serial.print("Received Data: ");
    //Serial.print(input1);
    //Serial.println();
    Serial.print(input1);
    Serial.print(" ");
    Serial.println(filtered);
    previousMillis = currentMillis;
  }
}

*/
