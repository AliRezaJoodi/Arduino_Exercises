// GitHub Account:  GitHub.com/AliRezaJoodi

#include "LCD.h"
#include "Character.h"
#include "ADC.h"
#include "LM35.h"
              
void setup(){  
  Config_LCD();
  Config_Chr();
  Config_ADC(); 
}

//******************************************
void loop(){
  float mv=0;  
  float temp=0;
  mv=GetInputVoltage_ADC(CH_LM35); 
  temp=mVtoTemp_LM35(mv);
  Display_Value(temp);
  delay(500);
}

//******************************************
void Display_Value(float value){
  lcd.clear(); 
  lcd.setCursor(0,0); lcd.print("Temp:"); lcd.print(value); lcd.write(byte(0));
  lcd.setCursor(0,1); lcd.print("LM35 Sensor");    
}
