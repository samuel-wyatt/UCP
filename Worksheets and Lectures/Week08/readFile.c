#include <stdio.h>
#include <stdlib.h>
#include "readFile.h"

int main(int argc, char **argv) {
    FILE *fPtr;
    journal *journalArray;
    char *message = malloc(100 * sizeof(char));
    int size, day, month, year, index, i;

    if (argc < 2) {
        printf("USAGE: ./readFile <journalIndex>\n");
    } else {
        if ((fPtr = fopen("journal.txt", "r")) == NULL) {
            perror("Failed to open file/n");
        } else {
            fscanf(fPtr, "%d\n", &size);
            journalArray = (journal*)malloc(size * sizeof(journal));
            
            index = atoi(argv[1]);
            if (index >= size) {
                printf("Invalid index\n");
            } else {
                for (i = 0; i < size; i++) {
                    fscanf(fPtr, "%d/%d/%d\n", &day, &month, &year);
                    journalArray[i].date.day = day;
                    journalArray[i].date.month = month;
                    journalArray[i].date.year = year;
                    journalArray[i].message = malloc(100 * sizeof(char));
                    journalArray[i].message = fgets(message, 100, fPtr);
                }

                index = atoi(argv[1]);

                year = journalArray[index].date.year;
                month = journalArray[index].date.month;
                day = journalArray[index].date.day;
                message = journalArray[index].message;

                printf("%d-%d-%d: %s\n", year, month, day, message);
            }
            free(journalArray);
            fclose(fPtr);
        }
    }
    free(message);
    fPtr = NULL;
    message = NULL;
    journalArray = NULL;
    return 0;
}
