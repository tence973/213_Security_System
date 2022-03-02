#include <LiquidCrystal_I2C.h>
// set the LCD number of columns and rows
//int lcdColumns = 16;
//const int lcdRows = 2;

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcdSetup();
void lcdDisplay();
void lcdArmed();
void lcdDisarmed();
