#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>


const int m2=6;
const int irSensorPin = 8;
 const int RST_PIN =9;       
const int SS_PIN=10;       
const int redLedPin = 3;
const int greenLedPin = 7;
const int buzzerPin = 4;
const String cardA="627C3B51";
const String cardB="62DD5451";
const String cardC="2197864C";
const String cardD="11A31E4C";
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);
void setup() {
 SPI.begin();  
   Serial.begin(9600);                
   rfid.PCD_Init();              
   Serial.println("Scan an RFID card");
   
   lcd.init();
   lcd.setCursor(0,0);
   lcd.backlight();
   lcd.print("welcome!");
   pinMode(irSensorPin, INPUT);
   pinMode(redLedPin, OUTPUT);
   pinMode(greenLedPin, OUTPUT);
   pinMode(buzzerPin, OUTPUT);
  
   pinMode(m2, OUTPUT);
   digitalWrite(redLedPin, LOW);
   digitalWrite(greenLedPin, LOW);
   digitalWrite(buzzerPin, LOW);
 
}

void loop() {
   
     if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }
  String t="";
   
  for (byte i = 0; i < rfid.uid.size; i++) {
    if(rfid.uid.uidByte[i] < 16){
    t+="0";}
    t+=String(rfid.uid.uidByte[i], HEX);
  }
  t.toUpperCase();
    Serial.print("UID: "+t);
    delay(500);
    lcd.print("welcome!");
    if(t==cardA){
      if(digitalRead(irSensorPin) ==HIGH){
    
   lcd.clear();
   lcd.print("Place Container");
   digitalWrite(redLedPin,LOW); 
   digitalWrite(buzzerPin, HIGH);
    }
    else{

    
      digitalWrite(greenLedPin,HIGH);
        digitalWrite(redLedPin,LOW);

    lcd.clear();
    lcd.print("100ml");
    lcd.setCursor(0,1);
   lcd.print("Milk dispensing");
    digitalWrite(m2,HIGH);
    delay(8000);
    digitalWrite(m2,LOW);
     lcd.clear();
    }}
  
 if(t==cardB){
      if(digitalRead(irSensorPin) ==HIGH){
    
   lcd.clear();
   lcd.print("Place Container");
   digitalWrite(redLedPin,LOW); 
   digitalWrite(buzzerPin, HIGH);
    }
    else{

    
      digitalWrite(greenLedPin,HIGH);
        digitalWrite(redLedPin,LOW);

    lcd.clear();
    lcd.print("200ml");
    lcd.setCursor(0,1);
   lcd.print("Milk dispensing");
    digitalWrite(m2,HIGH);
    delay(16000);
    digitalWrite(m2,LOW);
     lcd.clear();
    }}if(t==cardC){
      if(digitalRead(irSensorPin) ==HIGH){
    
   lcd.clear();
   lcd.print("Place Container");
    
   digitalWrite(redLedPin,LOW); 
   digitalWrite(buzzerPin, HIGH);
    }
    else{

    
      digitalWrite(greenLedPin,HIGH);
        digitalWrite(redLedPin,LOW);

    lcd.clear();
    lcd.print("500ml");
    lcd.setCursor(0,1);
   lcd.print("Milk dispensing");
    digitalWrite(m2,HIGH);
    delay(40000);
    digitalWrite(m2,LOW);
     lcd.clear();
    }}if(t==cardD){
      if(digitalRead(irSensorPin) ==HIGH){
    
   lcd.clear();
   lcd.print("Place Container");
   digitalWrite(redLedPin,LOW); 
   digitalWrite(buzzerPin, HIGH);
    }
    else{

    
      digitalWrite(greenLedPin,HIGH);
        digitalWrite(redLedPin,LOW);

    lcd.clear();
    lcd.print("1ltr");
    lcd.setCursor(0,1);
   lcd.print("Milk dispensing");
    digitalWrite(m2,HIGH);
    delay(80000);
    digitalWrite(m2,LOW);
     lcd.clear();
    }}
digitalWrite(greenLedPin,LOW);
  lcd.print("THANK YOU");
  digitalWrite(redLedPin,LOW);
  digitalWrite(buzzerPin,LOW);
  
}
