#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"

void game(map, snake) {
    char head = '>';
    do {
        char direction;
        direction = move();


        switch(direction) {
            case 'w':
                if (head != 'v') {
                    head = '^';
                }
                
            break;
            case 'a':
                head = '<';
            break;
            case 's':
                head = 'v';
            break;
            case 'd':
                head = '>';
            break;
        }

    } while (!exit);
}

char move(map, snake) {
    char direction;
    int exit = 0;

    do {
        disableBuffer();
        scanf("%c", &direction);
        enableBuffer();
        if (direction != 'w' || direction != 'a' || direction != 's' || direction != 'd') {
            printf("Invalid Key\n");
            exit = -1;
        }
    } while (exit != 0);
    return direction;
}