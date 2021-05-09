#include<SPI.h>
#include<MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
 
void setup() {
  Serial.begin(9600);
  SPI.begin();

  rfid.PCD_Init();

}

void loop() {
 if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()){
  delay(300);
  return;
  }

Serial.print("Card Tag Id: ");
for(byte i=0; i<4; i++){
  Serial.print(rfid.uid.uidByte[i]);
  Serial.print(" ");
  }  
  Serial.println();

}
