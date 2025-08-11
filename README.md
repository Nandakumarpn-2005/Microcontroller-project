# RFID Based Automated Milk Dispensing System

## 📌 Overview
This project is an *RFID-based milk dispensing system* that automatically dispenses different quantities of milk based on the RFID card scanned.  
It is built using *Arduino, **RFID reader, **IR sensor, **LCD display, and **motor pump control*.

## 🎯 Features
- Detects and reads RFID cards to identify the user.
- Dispenses *predefined quantities* of milk (100ml, 200ml, 500ml, 1 litre).
- Displays status and instructions on an *I2C LCD*.
- IR sensor detects the presence of a container before dispensing.
- *LED & buzzer* feedback for user interaction.
- Fully automated process with motor control.

---

## 🛠 Components Used
- *Arduino Uno / Nano*
- *RFID Module (MFRC522)*
- *IR Sensor*
- *LCD Display with I2C module*
- *DC motor / pump*
- *LEDs (Red & Green)*
- *Buzzer*
- *Jumper Wires*
- *Power Supply*

---

## ⚙ Working Process

1. *Initialization*  
   - When powered ON, the LCD displays "Welcome!".
   - All LEDs and buzzer are set to default (OFF).

2. *Card Scanning*  
   - The user scans their *RFID card*.
   - The Arduino reads the *card UID* and matches it to a pre-registered card.

3. *Quantity Selection via RFID Card*  
   - *Card A* → Dispenses *100ml*
   - *Card B* → Dispenses *200ml*
   - *Card C* → Dispenses *500ml*
   - *Card D* → Dispenses *1 litre*

4. *Container Detection*  
   - IR sensor checks for a container.
   - If *no container* is detected → LCD shows "Place Container", buzzer turns ON.
   - If container is detected → proceeds to milk dispensing.

5. *Milk Dispensing*  
   - Green LED turns ON.
   - Motor runs for a specific time depending on quantity.
   - LCD displays "Milk Dispensing" and quantity.

6. *Completion*  
   - Motor stops after required time.
   - LCD shows "Thank You".
   - System resets for the next user.

---
 ## 🔚 Conclusion
   This microcontroller-based vending machine project demonstrates the integration of hardware components (RFID module, IR sensors, LCD display, and DC motor) with embedded programming to create a secure and        automated dispensing system.  
   The system ensures that only authorized users can access items, improving efficiency and reducing manual intervention.  
   The flowchart and working process clearly outline the logical sequence, making the design easy to understand, replicate, and enhance for future applications.
