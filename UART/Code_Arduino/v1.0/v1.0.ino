// GitHub Account:  GitHub.com/AliRezaJoodi
              
void setup(){   
  Serial.begin(9600);
  Serial.print("Config USART"); Serial.println(); 
}

int value_int=100; 
 
void loop(){
  Serial.print("Number:"); Serial.print(value_int,1); Serial.println();  
  delay(250); 
  ++value_int;
}
