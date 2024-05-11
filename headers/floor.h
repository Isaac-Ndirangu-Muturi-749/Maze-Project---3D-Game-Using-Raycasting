#ifndef FLOOR_H
#define FLOOR_H


#include "main.h"
#include "upng.h"
#include "window.h"

#define NUM_FLOOR_TEXTURES 1

// Function to load floor textures
void loadFloorTextures(void);
void freeFloorTextures(void);
void renderFloor(int wallBottomPixel, color_t *texelColor, int x);

#endif /* FLOOR_H */
