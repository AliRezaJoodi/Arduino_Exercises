// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _LCD_INCLUDED_
  #define _LCD_INCLUDED_

#include <LiquidCrystal.h>

#ifndef _LCD_PORTS_
  #define _LCD_PORTS_
  /*
  initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(rs, enable, d4, d5, d6, d7) 
  LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7) 
  LiquidCrystal lcd(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) 
  LiquidCrystal lcd(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)
  */
  LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
#endif  

//******************************************
void Config_LCD(void){
  lcd.begin(16, 2);   
  lcd.setCursor(0,0); 
  lcd.print("Loading ...");  

  lcd.autoscroll(); //set the display to automatically scroll:
  lcd.noAutoscroll(); //turn off automatic scrolling
  lcd.blink();  //Turn on the blinking cursor    
  lcd.noBlink();  //Turn off the blinking cursor
  lcd.cursor(); //Turn on the cursor 
  lcd.noCursor(); //Turn off the cursor}
  lcd.noDisplay();  //Turn off the display  
  lcd.display();  //Turn on the display

  lcd.clear();
}  
  
#endif  