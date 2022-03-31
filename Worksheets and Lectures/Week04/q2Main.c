#include <stdio.h>
#include "question2.h"

int main(void) {
    /* Initialise variables and array. */
    int i, sumArr, maxIdx;
    static int LENGTH = 5;
    int array[] = {3, 5, 10, 46, 8};
    
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
    /* Print the reversed array, should be [8, 46, 10, 5, 3]. */
    for (i = 0; i < LENGTH; i++) {
        printf("%d , ", array[i]);
    }
    printf("\n");
    return 0;
}