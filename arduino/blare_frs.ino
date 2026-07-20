#include <Keypad.h>
#include <Time.h>
#include "weather.h"
#include "cat.h"

#define LCD_SCL 16
#define LCD_SDA 15
#define LCD_CS 11
#define LCD_DC 13
#define LCD_RST 12
#define LCD_BLK 7
const int buzzerPin = 14;

const byte ROWS = 2; 
const byte COLS = 3; 
double alarm = 12.00
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
};

byte rowPins[ROWS] = {2, 6}; 
byte colPins[COLS] = {5, 4, 3}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  setTime(12:00:00); 
  time_t t = now();
  pinMode(buzzerPin, OUTPUT); 
}

void loop(){
  lcd.print(timeStatus());
  if (timeStatus() = timeSet) {
    lcd.println("Click 1 for setting time")
    lcd.println("Click 2 for setting alarm")
    lcd.println("Click 3 for changing text color")
    lcd.println("Click 4 for date and weather")
    lcd.println("Click 5 for kittyyyyy")
    lcd.println("Click 6 for musica")
  }
  else {
    lcd.println("time not set!!")
  }
  char customKey = customKeypad.getKey();
  
  if (customKey = 1){
    lcd.println("click 1 for hour")
    lcd.println("click 2 for minute")
    lcd.println("click 3 for second")
    delay(20000)
    lcd.println(now());
      if (customKey = 1){
        /*smth to change hour*/
      }
      if (customKey = 2){
        /*smth to change min*/
      }
      if (customKey = 3){
        /*smth to change sec*/
      }
  }
  if (customKey = 2){
    lcd.println("click 1 for hour")
    lcd.println("click 2 for minute")
    delay(20000)
    lcd.println(alarm);
      if (customKey = 1){
        /*smth to change hour*/
      }
      if (customKey = 2){
        /*smth to change min*/
      }
  }
  if (customKey = 3){
    lcd.println("click 1 to change color randomly")
      if (customKey = 1){
        lcd.setTextColor(ST77XX_Random);
      }
      else {
        lcd.println ("wrong button silly")
      }
  }
  if (customKey = 4) {
    weather.h
  }
  if (customKey=5) {
      tft.drawRGBBitmap(0, 0, cat_array, CAT_WIDTH, CAT_HEIGHT);
  }
  if (customKey = 6) {
      digitalWrite(buzzerPin, HIGH); 
      delay(1000);                  
      digitalWrite(buzzerPin, LOW);  
      delay(1000);                  
  }
}
