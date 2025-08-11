RFID-Based Automatic Milk Dispensing System

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

 
