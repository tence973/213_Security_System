#include "alarm.h"
//#include "lcd.h"
#include "sms.h"
#include "pir.h"
#include "rfid.h"
int trigger = 0; // True if alarm triggered, false if not triggered
int armed = 0; // True if armed, false if not armed
int disarmed = 0;
// Main file for alarm system
void setup() {
 //lcd();
 wifiSetup();
 sensorSetup();
 rfidSetup();
 alarmSetup();
// lcdSetup();
// lcdDisarmed();
}
void loop() {
// int scan() = armed;
 while (armed == 1){
 //lcdArmed();
 int trigger = motionTrigger();
 if (trigger == 1){
  sendSMS();
  alarm();
//  int scan() = disarmed;
  if (disarmed == 1){
    armed = 0;
  //  lcdDisarmed();
    alarm();
    break;
  }
 }
 else
  return;
 }
}
