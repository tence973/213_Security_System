#ifndef SMS_H
#define SMS_H
#include<esp_wifi.h>
#include <ArduinoHttpClient.h>
#include<WiFi.h>

const char* HOST = "maker.ifttt.com";

const String PATH_NAME   = "/trigger/motion_detected/with/key/E9XwTRnSndghQxBALMPt0"; //make CONSTANT?

const char* WIFI_SSID = "kelly";
const char* WIFI_PASS = "kelly123";

void wifiSetup();
void sendSMS();

#endif
