#include "sms.h"
#include "pir.h"
#include "rfid.h"
int trigger = 0; // True if alarm triggered, false if not triggered
int arm = 0; // True if armed, false if not armed
int disarm = 0;
// Main file for alarm system
void setup() {
 lcd();
 wifiSetup();
 sensorSetup();
 rfidSetup();
 alarmSetup();
 lcdSetup();
 lcdDisarmed();
}
void loop() {
 int scan() = arm;
 while (armed == 1){
 lcdArmed();
 int trigger = motionTrigger();
 if (trigger == 1){
  sendSMS();
  alarm(1);
  int scan() = disarm;
  if (disarm == 1){
    arm = 0;
    lcdDisarmed();
    alarm(0);
    break;
  }
 }
 else
  return;
 }
}
