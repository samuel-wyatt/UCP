#ifndef FALSE
#define FALSE 0
#define TRUE !FALSE
#endif  

#ifndef BETWEEN
#define BETWEEN(low, high, val) ((val <= high) && (val >= low))
#endif
