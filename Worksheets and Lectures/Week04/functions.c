#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int array[], int length) {
    int i, answer = 0;
    for (i = 0; i < length; i++) {
        answer += array[i];
    }
    return answer;
}

int max(int array[], int length) {
    int i, index = 0, highest = 0;
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

void lowerUpper(char *array) {

    /*Change type to equal: 1. Using strlen().
                            2. Not using strlen().
                            3. Not using array indexing. */
    int type = 3;
    int length;
    int i;
    int lower;

    switch(type) {
        case 1:
            length = strlen(array);

            for (i = 0; i < length; i++) {

                if ((array[i] > 96) && (array[i] < 123)) {

                    array[i] = array[i] - 32;
                }
            }
        break;
        case 2:
            i = 0;
            while (array[i + 1] != '\0') {

                if ((array[i] > 96) && (array[i] < 123)) {

                    array[i] = array[i] - 32;
                }
                i += 1;
            }

        break;
        case 3:
            i = 0;
            while (*(array + i) != '\0') {
                
                if (*(array + i) > 96 && *(array + i) < 123) {
                    lower = *(array + i) - 32;
                    *(array + i) = lower;
                }
                i += 1;
            }
        break;
    }
}
