#include <stdio.h>
#include <stdlib.h>
void readInts(int *ptr1, int *ptr2, int *ptr3, char *ptr4) {
    int v1, v2, v3;
    char v4;

    printf("Integer 1: " );
    scanf("%d", &v1);
    *ptr1 = v1;

    printf("Integer 2: ");
    scanf("%d", &v2);
    *ptr2 = v2;

    printf("integer 3: ");
    scanf("%d", &v3);
    *ptr3 = v3;

    printf("Enter A or D: ");
    scanf(" %c", &v4);
    if (v4 == 'A' || v4 == 'D') {
        *ptr4 = v4;
    } else {
        printf("Invalid\n");
        exit(0);  
    }
}
