#ifndef READFILE_H
#define READFILE_H

typedef struct {
    char *message;
    struct {
        int day;
        int month;
        int year;
    } date;
} journal;

#endif
