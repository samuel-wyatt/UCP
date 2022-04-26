#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

    FILE *fPtr;
    char month[5], process[20], message[100];
    int day, hour, min, sec, finalTime;

    if (argc > 2) {
        printf("USAGE : ./<programName> <fileName");
    } else if ((fPtr = fopen(argv[1], "r")) == NULL) {
        printf("File \"%s\" could not be found or opened. Aborting\n", argv[1]);
    } else {
        while (fscanf(fPtr, "%s ", month) != EOF) {

            fscanf(fPtr, "%d %d:%d:%d %s: ", &day, &hour, &min, &sec, process);
            fgets(message, 100, fPtr);
            if (strstr(message, "fail") != NULL) {
                finalTime = (hour*3600) + (min*60) + sec;
                printf("\n%d seconds since midnight. Message: %s", finalTime, message);
            }
        }
    }
    fPtr = NULL;
    return 0;
}
