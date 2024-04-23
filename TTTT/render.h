#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>

// Function prototypes
void initRenderer(SDL_Renderer **renderer, int screenWidth, int screenHeight);
void renderFrame(SDL_Renderer *renderer, int playerX, int playerY, double playerAngle);

#endif /* RENDER_H */



#ifndef RENDER_H
#define RENDER_H

#include "graphics.h"
#include "player.h"
#include "raycast.h"
#include "map.h"

// Function prototypes
void render_game(void);
void clearColorBuffer(color_t color);
void renderColorBuffer(void);
void renderMap(void);
void renderRays(void);
void renderPlayer(void);
void renderWall(void);
void renderFloor(int wallBottomPixel, color_t *texelColor, int x);
void renderCeil(int wallTopPixel, color_t *texelColor, int x);

#endif /* RENDER_H */
