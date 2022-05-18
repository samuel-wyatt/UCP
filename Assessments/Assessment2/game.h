#ifndef GAME_H
#define GAME_H

#include "LinkedList.h"

void logic(char **map, LinkedList *snake, int row, int col, int foodNum);
char input();
void move(char **map, LinkedList *snake, char direction, int *msg, int *foodCountPtr);
void printMap(char **map, int row, int col);
void resetChar(LinkedList *snake, char direction);

#endif
