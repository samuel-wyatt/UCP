#ifndef FOOD
#define FOOD '@'
#endif

#ifndef WALL
#define WALL '*'
#endif

void createBorder(int row, int col, char **map);
void placeFood(int nRow, int nCol, char** map);
