#include "lcd.h"
void lcdSetup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void lcdDisplay(){
  lcd.setCursor(0,0);
  lcd.print("Team 7");
  lcd.setCursor(0,1);
  lcd.print("Alarm System");
  delay(1000);
}

void lcdArmed(){
  lcd.setCursor(0,0);
  lcd.print("Alarm System");
  lcd.setCursor(0,1);
  lcd.print("ARMED");
}

void lcdDisarmed(){
  lcd.setCursor(0,0);
  lcd.print("Alarm System");
  lcd.setCursor(0,1);
  lcd.print("DISARMED");
}
