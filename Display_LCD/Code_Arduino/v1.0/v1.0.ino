// GitHub Account:  GitHub.com/AliRezaJoodi

#include "LCD.h"
#include "Character.h"

void setup(){  
  Config_LCD();
  Config_Chr();

  //Display_Chr(); delay(300);
  Display_Value(12.3456); delay(300);  
  Display1();  
}

void loop(){
  
}

//******************************************
void Display_Value(float value){
  int value_int=4321;
  lcd.clear(); 
  lcd.setCursor(0,0); lcd.print("Temp:"); lcd.print(value); lcd.write(byte(0));
  lcd.setCursor(0,1); lcd.print(value_int); 
}

//***********************************
void Display1(void){
  lcd.clear(); 
  lcd.setCursor(0,0);  lcd.print("Hello World");
  lcd.setCursor(0,1);  lcd.print("Config LCD");   
  delay(100);
   
  for (int i = 0; i < 5; i++) {
    lcd.scrollDisplayRight();   
    delay(100);
  }

  for (int i = 0; i < 5; i++) {
    lcd.scrollDisplayLeft();   
    delay(100);
  }
}
    
//***********************************
void Display_Chr(void){
  lcd.clear(); lcd.setCursor(0,0);
  lcd.write(byte(0));
}
