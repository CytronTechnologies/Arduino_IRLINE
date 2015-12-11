/*
  Modify from Liquid Crystal example
  For IR Line Sensor
  Using BBFuino from Cytron Technologies with 8x2 character LCD
  If you have inquiry, welcome to discuss in our technical forum: forum.cytron.com.my
  
  The circuit:
 * 8x2 character LCD to BBFuino
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Humidity Sensor module to BBFuino
 *VCC to 5V 
 *GND to GND
 *OUT to D2
 */
  
// include the library code:
#include <LiquidCrystal.h>

#define Digital 2   //Digital Output of IR Line Sensor Module connected to D2 of BBfuino
#define LED     13  //LED at D13 pin

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  //assign the LCD interface pin

//Global variable

void setup() {
  //setup the input or output pin
  pinMode(LED, OUTPUT);
  pinMode(Digital, INPUT); 
  digitalWrite(LED, LOW);  //off LED  
  // set up the LCD's number of columns and rows: 
  lcd.begin(8, 2);
  // Print a message to the LCD.
  lcd.print("IR Line");
  lcd.setCursor(0,1);
  lcd.print("Sensor");
  delay(1000);  //delay for 1 second
  lcd.clear();  
  lcd.print("Di:");
}

void loop() {
   
  //display digital status
  lcd.setCursor(3, 0);
  if(digitalRead(Digital) == 1) // if digital input is high
  {
    lcd.print("HIGH");
    digitalWrite(LED,HIGH);
  }
  else 
  {
    lcd.print("LOW "); 
    digitalWrite(LED,LOW);
  }
  delay(300);
}

