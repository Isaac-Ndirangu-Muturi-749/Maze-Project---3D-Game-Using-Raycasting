#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>

// Function prototypes
void initRenderer(SDL_Renderer **renderer, int screenWidth, int screenHeight);
void renderFrame(SDL_Renderer *renderer, int playerX, int playerY, double playerAngle);

#endif /* RENDER_H */
