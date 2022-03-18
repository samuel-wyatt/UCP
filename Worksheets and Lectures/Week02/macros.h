#ifndef FALSE
#define FALSE 0
#define TRUE !FALSE
#endif 

#define BETWEEN(low, high, val) if(((val) > (low)) && ((val) < (high))) { \
                     return TRUE } else {     \
                     return FALSE}
  
        