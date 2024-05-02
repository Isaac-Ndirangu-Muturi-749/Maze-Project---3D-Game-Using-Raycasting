#ifndef CEILING_H
#define CEILING_H

#include "main.h"
#include "upng.h"
#include "window.h"

#define NUM_CEILING_TEXTURES 1

void loadCeilingTextures(void);
void freeCeilingTextures(void);
void renderCeiling(int wallTopPixel, color_t *texelColor, int x);

#endif /* CEILING_H */
