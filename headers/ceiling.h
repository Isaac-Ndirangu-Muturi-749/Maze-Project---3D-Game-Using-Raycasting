#ifndef CEILING_H
#define CEILING_H

#include "main.h"
#include "upng.h"
#include "window.h"

#define NUM_CEILING_TEXTURES 1

void loadCeilingTextures(void);
void freeCeilingTextures(void);

void renderCeiling(int wallTopPixel, color_t *texelColor, int rayIndex);
void getCeilingTextureDimensions(int *textureWidth, int *textureHeight);
float calculateCeilingDistance(int screenHeight, int rayIndex);
void calculateCeilingTextureOffsets(float distance, int rayIndex, int *textureOffsetX, int *textureOffsetY, int textureWidth, int textureHeight);
void fetchCeilingTexelColor(color_t *texelColor, int textureOffsetX, int textureOffsetY, int textureWidth, int textureHeight);

#endif /* CEILING_H */
