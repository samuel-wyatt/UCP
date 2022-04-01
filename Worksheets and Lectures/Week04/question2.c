#include <stdio.h>
#include <stdlib.h>

int sum(int array[], int length) {
    int i, answer = 0;
    for (i = 0; i < length; i++) {
        answer = answer + array[i];
    }
    return answer;
}

int max(int array[], int length) {
    int i, index, highest = 0;
    for (i = 0; i < length; i++) {
        if (array[i] > highest) {
            highest = array[i];
            index = i;
        }
    }
    return index;
}

void reverse(int array[], int length) {
    int i, tmp = 0;
    for (i = 0; i < length/2; i++) {
        tmp = array[i];
        array[i] = array[length - 1 - i];
        array[length - 1 - i] = tmp;
    }
}

void strToInt(char *charArray[], int intArray[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        intArray[i] = atoi(charArray[i]);
    }
}

void printArr(int array[], int length) {
    int i;
    printf("{");
    for (i = 0; i < length - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d}\n", array[length - 1]);
}
