#include <stdio.h>
#include "question2.h"
int main(void) {
    /* Initialise variables and array. */
    int sumArr, maxIdx;
    static int LENGTH = 5;
    int array[] = {2, 8, 6, 4};
    int intArray[5];
    char *charArray[] = {"5", "10", "15", "20", "25"};
    
    /* Call sum to find the sum of the array elements. */
    sumArr = sum(array, LENGTH);
    /* Print sumArr, should be equal to 72. */
    printf("sum() = %d", sumArr);

    /* Call max to find the index of the largest element of the array. */
    maxIdx = max(array, LENGTH);
    /* Print maxIdx, should be equal to 3. */
    printf("\nmax() = %d\n", maxIdx);

    /* Call reverse to reverse the array. */
    reverse(array, LENGTH);

    /* Display the reversed array. */
    printArr(array, LENGTH);

    /* Call strToInt to turn array of strings into ints. */
    strToInt(charArray, intArray, LENGTH);

    /* Call printArr to display the intArray. */
    printArr(intArray, LENGTH);

    return 0;
}
