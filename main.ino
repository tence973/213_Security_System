#include "sms.h"
int trigger = 0; // True if alarm triggered, false if not triggered
int armed = 1; // True if armed, false if not armed
// Main file for alarm system
void setup() {
 wifiSetup();
 sensorSetup();
}
void loop() {
 // int scan() = armed;
 while (armed == 1){
 int trigger = motionTrigger();
 if (trigger == 1){
  sendSMS();
  //alarm();
 }
 else
  return;
 }
}
