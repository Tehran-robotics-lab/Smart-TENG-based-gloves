/*
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const char* ssid = "ESP32-Soft-accessPoint";
const char* password = "123456789";

AsyncWebServer server(80);
IPAddress local_IP(192, 168, 1, 184);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);
// String savi() {
//   return String(bme.readTemperature());
// }
void setup(){
  Serial.begin(115200);
  if (WiFi.config(local_IP, gateway, subnet) == false) {
    Serial.println("Configuration failed.");
  }

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting...\n\n");
  }

  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "hello world");
  });

  server.begin();
}
 
void loop(){
  
}
*/