#include <Arduino.h>
#include <Filters.h>
#include <AH/Timing/MillisMicrosTimer.hpp>
#include <Filters/Butterworth.hpp>
#include <Servo.h>
Servo myservo;



const float cutoffFrequency = 10.0; // Cutoff frequency in Hz
const float samplingFrequency = 120.0; // Sampling frequency in Hz
const int filterOrder = 10;
const double f_n = 2 * cutoffFrequency / samplingFrequency;

//Iir::Butterworth::LowPass<filterOrder> filter; // butterworth filter

//AsyncWebServer server(80);

//IPAddress Ip(192, 168, 1, 1);
//IPAddress NMask(255, 255, 255, 0);

String request;
float input1;
float filtered;
int input2;
int input3;
int degree = 90;
int old_degree= 0 ;
int sensor = 14;
unsigned long previousMillis = 0;
const long interval = 10;
unsigned long currentMillis;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  Serial.println("ESP32 Access Point Mode");
  
  //WiFi.mode(WIFI_AP);
  //WiFi.softAP(ssid, password);
  
  //WiFi.softAPConfig(Ip, Ip, NMask);
  Serial.print("Connect to IP address: ");
  //Serial.println(WiFi.softAPIP());
  
  // Calculate the filter coefficients for the Butterworth low-pass filter
  //filter.setup(samplingFrequency, cutoffFrequency);
  
  //server.begin();
  //server.on("/sensor", HTTP_GET, [](AsyncWebServerRequest *request) {
    //request->send(200, "text/plain", String(input1));
  //});
}
auto filter = butter<4>(f_n);

void loop() {
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    
    input1 = analogRead(A0);
    
    
    // Apply the IIR filter to the input signal
    filtered = filter(input1);
    
    
    
    
    
    
    Serial.println(filtered);

    /*if (((filtered >= 727.65) && (filtered <= 733.45)) || ((filtered >= 736.96) && (filtered <= 741.87))){
      degree = 30;
      Serial.println("***********");
    }
    else if (((filtered >= 683.95) && (filtered <= 710.48)) || ((filtered >= 759.75) && (filtered <= 785.99))){
      degree = 60;
      Serial.println("!!!!!!!!!!!!!!!");
    }
    else if(((filtered >= 548.09) && (filtered <= 600.87)) || ((filtered >= 800.67) && (filtered <= 918.19))){
      degree = 90;
      Serial.println("))))))))))))))))))");
    }
    Serial.println(degree);
    Serial.print(" ");
    Serial.println(old_degree);*/

    previousMillis = currentMillis;
    /*if(degree!=old_degree){
      myservo.write(degree);
      Serial.println(degree);
      old_degree = degree;
      
    }
    

    degree = 0;*/
   
  }
}