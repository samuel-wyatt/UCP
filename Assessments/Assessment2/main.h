#ifndef MAIN_H
#define MAIN_H

void freeList(void *data);

typedef struct snakeBody {
    int row;
    int col;
    char body;
} snakeBody;

#endif
