#include <stdio.h>
#include "order.h"
#include "user_input.h"

int main() {
    /* Initialise the pointers and variables. */
    int *ptr1, *ptr2, *ptr3;
    char *chPtr;
    int v1, v2, v3;
    char c1;

    /* Assign the pointers to store the memory addresses of the variables. */ 
    ptr1 = &v1;
    ptr2 = &v2;
    ptr3 = &v3;
    chPtr = &c1;
    
    /* Call the readInt function to provide values to the pointers. */
    readInts(ptr1, ptr2, ptr3, chPtr);

    /* Call ascending(3) with unsorted integers. */
    printf("\nPre-Ascending(3) sort: %d , %d, %d\n", *ptr1, *ptr2, *ptr3);
    ascending3(ptr1, ptr2, ptr3);
    printf("Post-Ascending(3) sort: %d , %d , %d\n", *ptr1, *ptr2, *ptr3);

    /* Call descending(3) with already ascending integers (reverse order). */
    printf("\nPre-Descending(3) sort: %d , %d, %d\n", *ptr1, *ptr2, *ptr3);
    descending3(ptr1, ptr2, ptr3);
    printf("Post-Descending(3) sort: %d , %d , %d\n", *ptr1, *ptr2, *ptr3);
    return 0;
}
