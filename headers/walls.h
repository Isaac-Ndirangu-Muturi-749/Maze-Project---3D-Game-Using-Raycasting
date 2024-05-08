#ifndef WALLS_H
#define WALLS_H

#include "main.h"
#include "upng.h"
#include "window.h"
#include "rays.h"
#include "draw.h"
#include "floor.h"
#include "ceiling.h"

#include <stdlib.h>
#include <stdint.h>
typedef uint32_t color_t;

#define NUM_WALL_TEXTURES 8

// Function to load wall textures
void loadWallTextures(void);
void freeWallTextures(void);
void renderWalls(void);
void changeColorIntensity(color_t *color, float factor);

extern int wallTopPixel;
extern int wallBottomPixel;

#endif /* WALLS_H */
