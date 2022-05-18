#ifndef FOOD
#define FOOD '@'
#endif

#ifndef WALL
#define WALL '*'
#endif

#ifndef ARRAY_H
#define ARRAY_H

#include "LinkedList.h"

void createGame(int row, int col, char **map, LinkedList *snake);
void freeMap(char **map, int row);
void placeFood(int row, int col, char **map, LinkedList *snake);
void createBorder(int row, int col, char **map);
void freeList(void *data);

#endif
