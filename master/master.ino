#include "WiFi.h"
#include "ESPAsyncWebServer.h"

#include <Wire.h>


// Set your access point network credentials
const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

AsyncWebServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("Setting up AP...");

  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP adress: ");
  Serial.println(IP);

  server.on("/wonderfulnessie", HTTP_POST, [](AsyncWebServerRequest* request) {
    String msg;
    if (request->hasParam("message")){
      msg = request->getParam("message")->value();
    }
    else {
      msg = "NONE";
    }
    Serial.println(msg);
    request->send(200, "text/plain", "Hello, GET: " + msg);
  });

  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}
