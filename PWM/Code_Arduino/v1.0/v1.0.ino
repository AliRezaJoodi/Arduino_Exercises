// GitHub Account:  GitHub.com/AliRezaJoodi

uint8_t CH0_PWM=9; 
uint8_t CH1_PWM=11; 
uint16_t val_chr=125;        
uint16_t val_int=250;   
     
void setup(){
  pinMode(CH0_PWM,OUTPUT);  
  TCCR1A=0b10110011;
  TCCR1B=0b00000011; 
  pinMode(CH1_PWM,OUTPUT);    
}

void loop(){
  analogWrite(CH0_PWM,val_int);  
  analogWrite(CH1_PWM,val_int);  
  delay(500);
}
