/*
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

AsyncWebServer server(80);
IPAddress local_IP(192, 168, 1, 184);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);
String degree() {
  return String("done!");
}


void setup(){
  // Serial port for debugging purposes
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  Serial.println();
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid,password);
  WiFi.softAPConfig(local_IP,gateway,subnet);
    server.begin();
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    server.on("/degree", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "Hello, world");
    });

}
 
void loop(){
}
*/