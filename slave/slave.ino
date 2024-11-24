#include <WiFi.h>
#include <HTTPClient.h>

#include <Wire.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";
String message = "YAEBALVROTETOTVASHREST";
String serverPath = "http://192.168.4.1/wonderfulnessie?message=" + message;

unsigned long lastTime = 0;

unsigned long timerDelay = 500;

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
  if ((millis() - lastTime) > timerDelay){
    if (WiFi.status() == WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;

      http.begin(client, serverPath);

      String httpRequestData = "";
      int httpResponseCode = http.POST(httpRequestData);
      Serial.println(httpResponseCode);
      http.end();
    }
  }
  lastTime = millis();
}
