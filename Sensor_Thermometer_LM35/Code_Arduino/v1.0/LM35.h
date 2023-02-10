// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _LM35_INCLUDED_
  #define _LM35_INCLUDED_


#ifndef _ADC_PORTS_
  #define _ADC_PORTS_
  #define GAIN_ADC      5000/1023
  
  //******************************************
  void Config_ADC(void){
    analogReference(DEFAULT);
  }
#endif

#ifndef _LM35_PORTS_
  #define _LM35_PORTS_ 
  #define CH_LM35       A0
  #define GAIN_LM35     1/10
#endif

//******************************************
float _InputVoltage_LM35(char ch){
  int buffer_int=analogRead(ch);    
  float milivolt=buffer_int;
  return milivolt*GAIN_ADC;  
}

//******************************************
//Input:    Input Voltage(mV)
//Output:   Temp(^C)
float GetTemp_LM35(char ch){
  float temp=0;
  temp = _InputVoltage_LM35(ch)*GAIN_LM35;
  return temp;
}

#endif