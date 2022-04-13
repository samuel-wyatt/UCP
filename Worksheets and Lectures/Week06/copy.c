#include <stdio.h>

int main(int args, char **argv) {

    char ch;
    FILE *readPtr;
    FILE *writePtr;

    if (args < 3) {
        printf("USAGE : ./program <fileToRead> <fileToWrite>\n");
        return 1;
    }
    if ((readPtr = fopen(argv[1], "r")) == NULL) {
        printf("File \"%s\" could not be found or opened. Aborting\n", argv[1]);
        return 1;
    }
    if ((writePtr = fopen(argv[2], "w")) == NULL) {
        printf("USAGE : ./program <fileToRead> <fileToWrite>\n");
        return 1;
    }
    while ((ch = fgetc(readPtr)) != EOF) {
        fputc(ch, writePtr);   
    }
    
    fclose(readPtr);
    fclose(writePtr);
    return 0;
}
