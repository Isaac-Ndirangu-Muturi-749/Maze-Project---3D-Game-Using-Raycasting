#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>

// Function prototypes
void initRenderer(SDL_Renderer **renderer, int screenWidth, int screenHeight);
void renderFrame(SDL_Renderer *renderer, int playerX, int playerY, double playerAngle);

#endif /* RENDER_H */


void render_game(void);

void renderMap(void);
void renderColorBuffer(void);
void renderPlayer(void);
void renderWall(void);
void clearColorBuffer(color_t color);
