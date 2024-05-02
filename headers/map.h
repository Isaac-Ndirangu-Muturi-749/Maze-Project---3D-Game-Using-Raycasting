#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

#include "draw.h"

// Constants
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20
#define TILE_SIZE 50

#define MINIMAP_SCALE_FACTOR 0.25

extern const int map[MAP_NUM_ROWS][MAP_NUM_COLS];

// Function prototypes
bool isInsideMap(float x, float y);
int getMapValue(int row, int col);
void renderMap(void);

#endif /* MAP_H */

