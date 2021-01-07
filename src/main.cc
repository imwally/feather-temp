#include <LiquidCrystal.h>

// initialize LCD pins
LiquidCrystal lcd(6, 5, 9, 10, 11, 12);

int sensorPin = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temperature");
}

void loop() {
  int reading = analogRead(sensorPin);
  
  float voltage = reading * 3.3;
  voltage /= 1024.0;

  float tempC = (voltage - 0.5) * 100;
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  lcd.setCursor(0, 1);
  lcd.print(int(tempC)); lcd.print("c"); lcd.print(" / ");
  lcd.print(int(tempF)); lcd.print("f");
    
  delay(2000);
}
