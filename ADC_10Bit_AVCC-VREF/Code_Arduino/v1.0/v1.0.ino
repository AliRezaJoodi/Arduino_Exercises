// GitHub Account:  GitHub.com/AliRezaJoodi

#include "LCD.h"
#include "ADC.h"
              
void setup(){  
  Config_LCD();
  Config_ADC();
}

void loop(){    
  float value=0;
  value=GetInputVoltage_ADC(CH0);
  Display_Value(value);
  delay(500);
}

//******************************************
void Display_Value(float value){
  lcd.clear(); 
  lcd.setCursor(0,0); lcd.print("In:"); lcd.print(value); lcd.print("mV");
  lcd.setCursor(0,1); lcd.print("ADC Config");    
}
