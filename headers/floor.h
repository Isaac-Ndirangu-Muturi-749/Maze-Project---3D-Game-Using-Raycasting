#ifndef FLOOR_H
#define FLOOR_H


#include "main.h"
#include "upng.h"
#include "window.h"

#define NUM_FLOOR_TEXTURES 1

// Function to load floor textures
void loadFloorTextures(void);
void freeFloorTextures(void);
void renderFloor(int wallBottomPixel, color_t *texelColor, int rayIndex);

void getFloorTextureDimensions(int *textureWidth, int *textureHeight);
float calculateFloorDistance(int screenHeight, int rayIndex);
void calculateFloorTextureOffsets(float distance, int rayIndex, int *textureOffsetX, int *textureOffsetY, int textureWidth, int textureHeight);
void fetchFloorTexelColor(color_t *texelColor, int textureOffsetX, int textureOffsetY, int textureWidth, int textureHeight);
#endif /* FLOOR_H */
