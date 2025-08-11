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

5. *Completion*  
   - The motor stops after the required time.  
   - The LCD displays "THANK YOU" before returning to the welcome screen.

---
mermaid
flowchart TD
    A[Start] --> B[Power ON System]
    B --> C[Initialize LCD, RFID, Sensors, Motor]
    C --> D[Scan RFID Card]
    D -->|No Card Detected| D
    D -->|Card Detected| E[Read Card UID]
    E --> F[Check Card Type]
    
    F -->|Card A| G[100ml Dispense]
    F -->|Card B| H[200ml Dispense]
    F -->|Card C| I[500ml Dispense]
    F -->|Card D| J[1 Liter Dispense]
    
    G --> K[Check IR Sensor for Container]
    H --> K
    I --> K
    J --> K
    
    K -->|No Container| L[Display "Place Container"]
    L --> D
    
    K -->|Container Present| M[Activate Motor to Dispense Milk]
    M --> N[Stop Motor After Set Time]
    N --> O[Display "Thank You"]
    O --> D
