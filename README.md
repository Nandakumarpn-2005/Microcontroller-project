RFID-Based Milk Dispensing System

This project is an *Arduino-based automated milk dispensing system* that uses *RFID cards* to dispense pre-set quantities of milk.  
It includes an *IR sensor, **LCD display, **LED indicators, and a **buzzer* for user feedback.

---

## 📌 Features
- *RFID Authentication* – Only registered RFID cards can trigger dispensing.
- *Predefined Milk Quantities* – Different cards dispense different amounts:
  - Card A → 100 ml  
  - Card B → 200 ml  
  - Card C → 500 ml  
  - Card D → 1 liter  
- *IR Sensor Safety* – Ensures a container is placed before dispensing.
- *LCD Display* – Shows instructions and dispensing status.
- *LED & Buzzer Alerts* – Indicate errors, readiness, and completion.

---

## 🛠 Components Used
- Arduino (UNO/Nano/compatible)
- RFID Module (*MFRC522*)
- IR Sensor
- LCD Display (*16x2*, I2C)
- LEDs (Red & Green)
- Buzzer
- Relay/Motor Driver & Motor Pump
- Wires, Breadboard, Power Supply

---

## 📋 Circuit Connections
| Component | Arduino Pin |
|-----------|-------------|
| RFID SDA  | 10          |
| RFID RST  | 9           |
| IR Sensor | 8           |
| Red LED   | 3           |
| Green LED | 7           |
| Buzzer    | 4           |
| Motor (Pump) | 6        |
| LCD I2C   | SDA → A4, SCL → A5 |

---

## 💻 Code

```cpp
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define IR_SENSOR 8
#define RED_LED 3
#define GREEN_LED 7
#define BUZZER 4
#define MOTOR 6

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte cardA[4] = {0x2F, 0x91, 0xA3, 0xD2}; // Example UID for 100 ml
byte cardB[4] = {0xF3, 0x59, 0xA7, 0xC5}; // Example UID for 200 ml
byte cardC[4] = {0xB7, 0x12, 0xE5, 0xA9}; // Example UID for 500 ml
byte cardD[4] = {0x90, 0xA4, 0xC2, 0xB1}; // Example UID for 1 liter

void setup() {
  pinMode(IR_SENSOR, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(MOTOR, OUTPUT);

  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Milk Dispenser");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  if (compareUID(mfrc522.uid.uidByte, cardA)) dispenseMilk(100);
  else if (compareUID(mfrc522.uid.uidByte, cardB)) dispenseMilk(200);
  else if (compareUID(mfrc522.uid.uidByte, cardC)) dispenseMilk(500);
  else if (compareUID(mfrc522.uid.uidByte, cardD)) dispenseMilk(1000);
  else {
    lcd.clear();
    lcd.print("Access Denied");
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER, 1000);
    delay(1000);
    noTone(BUZZER);
    digitalWrite(RED_LED, LOW);
  }
}

bool compareUID(byte *uid, byte *card) {
  for (byte i = 0; i < 4; i++) {
    if (uid[i] != card[i]) return false;
  }
  return true;
}

void dispenseMilk(int quantity) {
  lcd.clear();
  lcd.print("Place Container");

  unsigned long dispenseTime;
  if (quantity == 100) dispenseTime = 8000; // Adjust according to
