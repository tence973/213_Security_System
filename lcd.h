#include <LiquidCrystal_I2C.h>
// set the LCD number of columns and rows
const int lcdColumns = 16;
const int lcdRows = 2;

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void lcdSetup();
void lcd();
void lcdArmed();
void lcdDisarmed();
