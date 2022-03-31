#include <stdio.h>
static void ascending2(int *ptr1, int *ptr2) {
    int tmp;
    if (*ptr1 > *ptr2)
    {
	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
    }
}

void ascending3(int *ptr1, int *ptr2, int *ptr3) {
    ascending2(ptr1, ptr2);
    ascending2(ptr2, ptr3);
    ascending2(ptr1, ptr2);
}

void descending3(int *ptr1, int *ptr2, int *ptr3) {
    int tmp;
    ascending2(ptr1, ptr2);
    ascending2(ptr2, ptr3);
    tmp = *ptr1;
    *ptr1 = *ptr3;
    *ptr3 = tmp;
}
