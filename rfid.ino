#include "rfid.h"
void rfidSetup() 
{
  Serial.begin(115200);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Setting up RFID scannner...");
  Serial.println();
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  displayColor(COLOR_BLACK);
}

int scan() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "19 DB 2B 2B") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Access granted");
    return 1;
    delay(500);
    displayColor(COLOR_GREEN);
    delay(500);
    displayColor(COLOR_BLUE);
    delay(500);
    displayColor(COLOR_GREEN);
    delay(500);
    displayColor(COLOR_BLUE);
    delay(500);
    displayColor(COLOR_GREEN);
    delay(500);
  }
 
 else   {
    Serial.println("Access denied");
    return 0;
    delay(500);
    displayColor(COLOR_RED);
    delay(500);
    displayColor(COLOR_BLUE);
    delay(500);
    displayColor(COLOR_RED);
    delay(500);
    displayColor(COLOR_BLUE);
    delay(500);
    displayColor(COLOR_RED);
    delay(500);
  }
}

void displayColor(byte color) {
  digitalWrite(PIN_LED_R, !bitRead(color, 2));
  digitalWrite(PIN_LED_G, !bitRead(color, 1));
  digitalWrite(PIN_LED_B, !bitRead(color, 0));
}
