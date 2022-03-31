#include <stdio.h>
#include "macros.h"
int powers(void)
{
     
     static int answer = 1;
     answer = answer * 2;
     #ifdef DEBUG
          printf("%d\n", answer);
     #endif
     return answer;
}
