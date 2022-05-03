#include <stdio.h>
#include <stdlib.h>
#include "readFile.h"

int main(int argc, char **argv) {
    FILE *fPtr;
    journal *journalArray;
    char *message = NULL;
    int size, day, month, year, index, i;

    if (argc < 2) {
        printf("USAGE: ./readFile <journalIndex>\n");
    } else {
        if ((fPtr = fopen("journal.txt", "r")) == NULL) {
            printf("Failed to open file/n");
        } else {
            fscanf(fPtr, "%d", &size);
            journalArray = (journal*)malloc(size * sizeof(journal));
            
            for (i = 0; i < size; i++) {
                fscanf(fPtr, "%d/%d/%d", &day, &month, &year);
                fgets(message, 100, fPtr);
                journalArray[i].date.day = day;
                journalArray[i].date.month = month;
                journalArray[i].date.year = year;
                journalArray[i].message = message;
            }

            index = atoi(argv[1]);

            year = journalArray[index].date.year;
            month = journalArray[index].date.month;
            day = journalArray[index].date.day;
            message = journalArray[index].message;

            printf("%d-%d-%d: %s", year, month, day, message);
            free(journalArray);
        }
    }
}
