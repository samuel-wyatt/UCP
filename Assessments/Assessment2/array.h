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
void allocateMap(char **map, int row, int col);
void freeMap(char **map, int row);
void placeFood(int row, int col, char **map);
void createBorder(int row, int col, char **map);

#endif
