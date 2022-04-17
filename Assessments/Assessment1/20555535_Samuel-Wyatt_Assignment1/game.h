#ifndef GAME_H
#define GAME_H

void logic(char **map, int **snake, int row, int col, int snakeLength);
char input();
int move(char **map, int **snake, int tailIdx, char direction, int *msg, int row, int col);
void printMap(char **map, int row, int col);
void resetChar(int **snake, char direction, int tailIdx);

#endif
