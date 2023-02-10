// GitHub Account:  GitHub.com/AliRezaJoodi

#ifndef _LM35_INCLUDED_
  #define _LM35_INCLUDED_

#ifndef _LM35_PORTS_
  #define _LM35_PORTS_ 
  #define CH_LM35       A0
  #define GAIN_LM35     1/10
#endif

//****************************************
float mVtoTemp_LM35(float mv){
  return mv*GAIN_LM35;  
}

#endif