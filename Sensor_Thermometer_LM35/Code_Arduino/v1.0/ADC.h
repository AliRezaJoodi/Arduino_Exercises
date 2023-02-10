// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _ADC_INCLUDED_
  #define _ADC_INCLUDED_


#ifndef _ADC_PORTS_
  #define _ADC_PORTS_
  #define GAIN_ADC      5000/1023
  #define CH0           A0  
#endif

//******************************************
void Config_ADC(void){
  analogReference(DEFAULT);
}

//******************************************
float GetInputVoltage_ADC(char ch){
  int buffer_int=analogRead(ch);    
  float milivolt=buffer_int;
  return milivolt*GAIN_ADC;  
}

#endif