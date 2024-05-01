#ifndef WALL_TEXTURES_H
#define WALL_TEXTURES_H

#include "main.h"
#include "upng.h"
#include "window.h"
#include "rays.h"
#include "draw.h"

#define NUM_WALL_TEXTURES 6

// Function to load wall textures
void loadWallTextures(void);
void freeWallTextures(void);
void renderWall(void);
void changeColorIntensity(color_t *color, float factor);


#endif /* WALL_TEXTURES_H */
