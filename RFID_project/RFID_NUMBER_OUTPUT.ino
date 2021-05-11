#include <SPI.h>
#include <MFRC522.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define SS_PIN 10
#define RST_PIN 9

int segmentLED[]={2,3,4,5};
int digitnum[10][4] = {
  {0,0,0,0},//0
  {1,0,0,0},//1
  {0,1,0,0},//2
  {1,1,0,0},//3
  {0,0,1,0},//4
  {1,0,1,0},//5
  {0,1,1,0},//6
  {1,1,1,0},//7
  {0,0,0,1},//8
  {1,0,0,1} //9
};

MFRC522 rfid(SS_PIN, RST_PIN);

int zero_tagID[4] = {195, 5, 234, 12};
int one_tagID[4] = {51, 96, 125, 12};
int two_tagID[4] = {35, 175, 126, 12};
int three_tagID[4] = {44, 135, 184, 23};
int four_tagID[4] = {220, 156, 169, 23};
int five_tagID[4] = {19, 198, 144, 12};
int six_tagID[4] = {57, 235, 189, 178};
int seven_tagID[4] = {201, 244, 191, 178};
int eight_tagID[4] = {60, 173, 156, 23};
int nine_tagID[4] = {220, 115, 84, 24};

void setup() {
 Serial.begin(9600);
 SPI.begin();
 
 rfid.PCD_Init();
 
 for(int i=0 ; i<4; i++){
  pinMode(segmentLED[i], OUTPUT);}

 lcd.init();
 lcd.backlight();
}

void loop() {
  if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()){
    delay(300);
    return;
  }

 int zero = 0;
 int one = 0;
 int two = 0;
 int three = 0;
 int four = 0;
 int five = 0;
 int six = 0;
 int seven = 0;
 int eight = 0;
 int nine = 0;
 
 Serial.print("Card Tag ID: ");
 for(byte i=0; i<4; i++){
  Serial.print(rfid.uid.uidByte[i]);
  Serial.print(" ");

  if(rfid.uid.uidByte[i] == zero_tagID[i]){
    zero++;
    }
  if(rfid.uid.uidByte[i] == one_tagID[i]){
    one++;
    }
  if(rfid.uid.uidByte[i] == two_tagID[i]){
    two++;
    }
   if(rfid.uid.uidByte[i] == three_tagID[i]){
    three++;
    }
    if(rfid.uid.uidByte[i] == four_tagID[i]){
    four++;
    }
    if(rfid.uid.uidByte[i] == five_tagID[i]){
    five++;
    }
    if(rfid.uid.uidByte[i] == six_tagID[i]){
    six++;
    }
    if(rfid.uid.uidByte[i] == seven_tagID[i]){
    seven++;
    }
    if(rfid.uid.uidByte[i] == eight_tagID[i]){
    eight++;
    }
    if(rfid.uid.uidByte[i] == nine_tagID[i]){
    nine++;
    }    
  }
  
 Serial.println();
 
 if(zero == 4){
  Serial.println("Number 0 detected");
  for(int j=0; j<4; j++){
    digitalWrite(segmentLED[j], digitnum[0][j]);
    }
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("Hello LAON");
   lcd.setCursor(0,1);
   lcd.print("This is Number 0");
    
  }
  if(one == 4){
  Serial.println("Number 1 detected");
  for(int j=0; j<4; j++){
    digitalWrite(segmentLED[j], digitnum[1][j]);
    }
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("Hello LAON");
   lcd.setCursor(0,1);
   lcd.print("This is Number 1");
    
  }
   if(two == 4){
  Serial.println("Number 2 detected");
  for(int j=0; j<4; j++){
    digitalWrite(segmentLED[j], digitnum[2][j]);
    }
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("Hello LAON");
   lcd.setCursor(0,1);
   lcd.print("This is Number 2");
    
  }
  if(three == 4){
  Serial.println("Number 3 detected");
  for(int j=0; j<4; j++){
    digitalWrite(segmentLED[j], digitnum[3][j]);
    }
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("Hello LAON");
   lcd.setCursor(0,1);
   lcd.print("This is Number 3");
    
  }
  if(four == 4){
  Serial.println("Number 4 detected");
  for(int j=0; j<4; j++){
    digitalWrite(segmentLED[j], digitnum[4][j]);
    }
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("Hello LAON");
   lcd.setCursor(0,1);
   lcd.print("This is Number 4");    
  }
  if(five == 4){
  Serial.println("Number 5 detected");
  for(int j=0; j<4; j++){
    digitalWrite(segmentLED[j], digitnum[5][j]);
    }
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("Hello LAON");
   lcd.setCursor(0,1);
   lcd.print("This is Number 5");    
  }
   if(six == 4){
  Serial.println("Number 6 detected");
  for(int j=0; j<4; j++){
    digitalWrite(segmentLED[j], digitnum[6][j]);
    }
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("Hello LAON");
   lcd.setCursor(0,1);
   lcd.print("This is Number 6");    
  }                        
  if(seven == 4){
  Serial.println("Number 7 detected");
  for(int j=0; j<4; j++){
    digitalWrite(segmentLED[j], digitnum[7][j]);
    }
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("Hello LAON");
   lcd.setCursor(0,1);
   lcd.print("This is Number 7");    
  }                           
   if(eight == 4){
  Serial.println("Number 8 detected");
  for(int j=0; j<4; j++){
    digitalWrite(segmentLED[j], digitnum[8][j]);
    }
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("Hello LAON");
   lcd.setCursor(0,1);
   lcd.print("This is Number 8");    
  }                           
  if(nine == 4){
  Serial.println("Number 9 detected");
  for(int j=0; j<4; j++){
    digitalWrite(segmentLED[j], digitnum[9][j]);
    }
   delay(1000);
   lcd.setCursor(0,0);
   lcd.print("Hello LAON");
   lcd.setCursor(0,1);
   lcd.print("This is Number 9");    
  }                                             
}
