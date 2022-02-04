#include<esp_wifi.h>
#include <ArduinoHttpClient.h>
#include<WiFi.h>

const char* HOST = "maker.ifttt.com";

String PATH_NAME   = "/trigger/motion_detected/with/key/E9XwTRnSndghQxBALMPt0";

const char* WIFI_SSID = "kelly";
const char* WIFI_PASS = "kelly123";

void setup() {
Serial.begin(115200);
WiFi.begin(WIFI_SSID,WIFI_PASS);

Serial.print("Connecting to WiFi");
while (WiFi.status() != WL_CONNECTED){
  Serial.print(".");
  delay(500);
}
//Wifi connected
Serial.println("Wifi Connected!");
Serial.println(WiFi.localIP());
  

delay(200);
WiFiClient client;
Serial.print("Connecting to host...");
if (client.connect(HOST, 80)){
  Serial.println("Host connected");
} else {
         Serial.println("Host connection failed");
}
}

void loop() {
WiFiClient w;
HttpClient http = HttpClient(w, HOST, 80);
Serial.println("Making POST request");
http.post("/trigger/motion_detected/with/key/E9XwTRnSndghQxBALMPt0");
delay(1000000);
}
