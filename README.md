# RFID-Based Automatic Milk Dispensing System

## 📌 Project Overview
This project is an *RFID-based milk dispensing system* using an Arduino microcontroller.  
It automates milk dispensing by recognizing pre-registered RFID cards, each corresponding to a specific milk quantity.  
The system ensures controlled dispensing, user authentication, and accurate measurement.

---

## 🛠 Components Used
- Arduino Uno
- RFID Module (MFRC522)
- I2C LCD Display (16x2)
- IR Sensor
- Motor (for dispensing)
- LEDs (Red & Green)
- Buzzer
- Jumper wires
- Breadboard
- Power Supply

---

## ⚙ How It Works (Working Process)
1. *Startup*  
   - The LCD displays a welcome message.  
   - The system waits for an RFID card to be scanned.

2. *Card Detection*  
   - When a card is scanned, the system reads its UID (Unique ID).  
   - If the UID matches a pre-stored value, the system identifies the corresponding milk quantity.

3. *Container Check*  
   - The IR sensor checks whether a container is placed under the dispenser.  
   - If *no container* is detected, the buzzer alerts the user and asks to place a container.  

4. *Milk Dispensing*  
   - Once the container is detected, the motor starts running for a pre-set time depending on the card:
     - Card A → 100ml (8 seconds)
     - Card B → 200ml (16 seconds)
     - Card C → 500ml (40 seconds)
     - Card D → 1L (80 seconds)
   - The green LED indicates dispensing in progress.
     ---
     ## Flowchart
        ``mermaid
flowchart TD
    A([Start]) --> B([Initialize])
    B --> C([Scan RFID])
    C --> D{Card?}
    D -->|Yes| E([Dispense])
    D -->|No| C
