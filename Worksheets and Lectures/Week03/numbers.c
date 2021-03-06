#include <stdio.h>
#include "order.h"
#include "user_input.h"

int main() {
    /* Initialise the pointers and variables. */
    int *ptr1, *ptr2, *ptr3;
    char *chPtr;
    int v1, v2, v3;
    char c1;
    void (*ptr4)(int*, int*, int*);

    /* Assign the pointers to store the memory addresses of the variables. */ 
    ptr1 = &v1;
    ptr2 = &v2;
    ptr3 = &v3;
    chPtr = &c1;
    
    /* Call the readInt function to provide values to the pointers. */
    readInts(ptr1, ptr2, ptr3, chPtr);

    /* Call ascending(3) with unsorted integers. */
    printf("\nPre-sort: %d , %d, %d\n", *ptr1, *ptr2, *ptr3);
    ptr4 = order(c1);
    ptr4(ptr1, ptr2, ptr3);
    printf("Post-sort: %d , %d , %d\n", *ptr1, *ptr2, *ptr3);

    return 0;
}
