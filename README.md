
# Solar-Charge-Regulator

## Abstract
This project, completed as part of the Embedded Systems subject in my bachelor's degree in computer engineering, aims to create a prototype solar charge controller using an Arduino UNO, voltage dividers, a 16x2 LCD display, a DC power supply to regulate voltage, and capacitors to store energy. The prototype securely charges a lead-acid car battery, simulating conditions where there is no access to 220V AC energy. The controller prevents overcharging and fast charging, ensuring battery safety and longevity while providing real-time charging information on the LCD display.

## Introduction to the Problem
In remote locations without access to 220V AC power, charging a car battery can be challenging. Overcharging and fast charging can harm the battery and pose safety risks, necessitating a reliable and efficient charging solution.

## Why You Want to Fix It
Ensuring the safe and efficient charging of car batteries in remote areas is essential. Overcharging and fast charging can significantly reduce battery life and potentially cause dangerous situations. A charge controller can mitigate these risks by managing the charging process.

## How You’re Going to Fix It
This project involves designing a charge controller that uses an Arduino UNO to monitor and regulate the charging process. Voltage dividers scale down the battery voltage to fit within the Arduino's input range, and a 16x2 LCD display provides real-time information about the charging status. Instead of a solar panel, a DC power supply is used to regulate voltage, and capacitors are used to store energy.

## Technology Used
- **Arduino UNO**: For monitoring and regulating the charging process.
- **Voltage Dividers**: To scale down the battery voltage into the Arduino's input range.
- **16x2 LCD Display**: To display real-time information about the charging process.
- **DC Power Supply**: To provide regulated voltage.
- **Capacitors**: To store energy for the charging process.
- **Lead Acid Car Battery**: The battery being charged by the charge controller.

## Getting Started

### Prerequisites
Before you begin, ensure you have the following:
- **Arduino UNO**: To control the charging process.
- **Voltage Dividers**: To scale the voltage appropriately.
- **16x2 LCD Display**: For displaying charging information.
- **DC Power Supply**: To provide regulated voltage.
- **Capacitors**: To store energy.
- **Lead Acid Car Battery**: To be charged using the charge controller.

### Project Setup
1. **Assemble the Components:**
   - Connect the DC power supply to the input of the charge controller.
   - Use voltage dividers to scale down the battery voltage for the Arduino input.
   - Connect the capacitors to store energy.
   - Connect the Arduino UNO to the voltage dividers and the 16x2 LCD display.

2. **Program the Arduino UNO:**
   - Write code to monitor the battery voltage and control the charging process.
   - Display the charging status and voltage information on the LCD display.

   ```c++
   // Example code snippet
   #include <LiquidCrystal.h>

   const int analogPin = A0;
   LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

   void setup() {
     lcd.begin(16, 2);
     lcd.print("Charge Controller");
   }

   void loop() {
     int sensorValue = analogRead(analogPin);
     float voltage = sensorValue * (5.0 / 1023.0);
     lcd.setCursor(0, 1);
     lcd.print("Voltage: ");
     lcd.print(voltage);
     delay(1000);
   }
## Issues Encountered
- Issue: Ensuring accurate voltage scaling and readings.
- Solution: Carefully calibrating the voltage dividers and testing with different voltage levels to ensure accuracy.
- Issue: Efficiently storing and using energy from capacitors.
- Solution: Optimizing the capacitor configuration to balance energy storage and discharge rates.

## Overall Reflection
Creating this charge controller prototype has provided a reliable and efficient solution for charging car batteries in remote locations using a DC power supply and capacitors. The use of an Arduino UNO and voltage dividers has ensured safe charging practices, while the LCD display offers valuable real-time information. Regular updates and refinements will further improve the system's performance and reliability. This project has also improved my understanding of voltage regulation, energy storage with capacitors, and real-time data display.
