#include <WiFi.h>
#include <HTTPClient.h>

#include <Wire.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

const char* serverPath = "http://192.168.4.1/wonderfulnessie";

unsigned long lastTime = 0;

unsigned long timerDelay = 5000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
