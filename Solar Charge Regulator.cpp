// Include libraries
#include <LiquidCrystal.h>

// Global constants
const int solarVoltagePin = A4;
const int batteryVoltagePin = A5;
const int pwmOutputPin = 3;
const int voltageSensorPin = A3;

// Voltage Calibration
const float VOLTAGE_CAP = 14.4; 
const int UpdateInterval = 17;

// Global variables 
LiquidCrystal myLCD(12, 11, 10, 9, 8, 7);
bool isLCDReset = true;
unsigned long lastDisplayUpdate = 0;  
float batteryVoltage;
double measuredVoltageDrop;

// Function declarations
void initializeSystem();
void DisplayWelcomeMessage();
void updateLCD(float batteryVoltage, char* message);
void updateSystem();
void initiateCharging(float batteryVoltage);
void haltCharging();

void setup() {
  initializeSystem(); 
}
 
void loop() {
  updateSystem();
}

// Function definitions
void initializeSystem() {
  Serial.begin(9600);
  
  pinMode(pwmOutputPin, OUTPUT);
  analogWrite(pwmOutputPin, 0);
  // LCD 
  myLCD.begin(16, 2); 
  DisplayWelcomeMessage();
  
  delay(2770);
}
  //  LCD display/set up
void DisplayWelcomeMessage() {
  myLCD.print("Solar Charger");
  myLCD.setCursor(0, 1);
  myLCD.print("Mukadi 220492174"); 
}
   // LCD display
void updateLCD(float batteryVoltage, char* message) {
  if (isLCDReset) {
    myLCD.clear();
    isLCDReset = false; 
  } else {
    myLCD.setCursor(0, 0);
    myLCD.print(message);
    myLCD.setCursor(0, 1);  
    myLCD.print("Batt Volts: ");
    myLCD.print(batteryVoltage, 1);
    myLCD.print("V");
    
    Serial.print("Battery Voltage = "); 
    Serial.println(batteryVoltage);
  }
}

void updateSystem() {
  
  // Reading sensor values
  batteryVoltage = analogRead(batteryVoltagePin) * 0.015616;

  float sensorVoltageOutput = analogRead(voltageSensorPin) * 0.015616;
  
  float solarVoltage = analogRead(solarVoltagePin) * 0.023912;
  
  measuredVoltageDrop = sensorVoltageOutput - batteryVoltage;

  // Control charging
  if (batteryVoltage < VOLTAGE_CAP) {
    initiateCharging(batteryVoltage);
  } else {
    
    // Stop Charging
    haltCharging();
  }

  // Update LCD
  if (millis() - lastDisplayUpdate >= UpdateInterval) {
    updateLCD(batteryVoltage, "Charging...");
    lastDisplayUpdate = millis();
  }

}

void initiateCharging(float batteryVoltage) {
  
  float chargingDutyCycle = 2.8;
  analogWrite(pwmOutputPin, chargingDutyCycle);
  
  updateLCD(batteryVoltage, "Charging...");
}

void haltCharging() {
  analogWrite(pwmOutputPin, 0);
}
