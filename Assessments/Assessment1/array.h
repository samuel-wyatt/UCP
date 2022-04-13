#ifndef FOOD
#define FOOD '@'
#endif

#ifndef WALL
#define WALL '*'
#endif

void createGame(int row, int col, int snakeLength, char **map);
void placeFood(int nRow, int nCol, int snakeLength, char **map);
