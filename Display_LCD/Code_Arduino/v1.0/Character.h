// GitHub Account:  GitHub.com/AliRezaJoodi

#ifdef _LCD_INCLUDED_

byte degree[8]={
  0b10001000,
  0b10010100,
  0b10001000,
  0b10000011,
  0b10000100,
  0b10000100,
  0b10000011,
  0b10000000
};

//******************************************
void Config_Chr(void){
  lcd.createChar(0, degree); 
}

#endif  