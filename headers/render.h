#ifndef RENDER_H
#define RENDER_H

#include "player.h"
#include "raycast.h"
#include "map.h"
#include "raycast.h"
#include "draw.h"
#include "upng.h"
#include <SDL2/SDL_image.h>

#include "main.h"
#include "rain.h"


#include <stdint.h>
typedef uint32_t color_t;

#define MINIMAP_SCALE_FACTOR 0.25

// Function prototypes
void render_game(void);
void renderMap(void);
void renderRays(void);
void renderPlayer(void);
void renderWall(void);
void renderFloor(int wallBottomPixel, color_t *texelColor, int x);
void renderCeil(int wallTopPixel, color_t *texelColor, int x);
void clearColorBuffer(color_t color);
void renderColorBuffer(void);
void renderWeapon(void);


#endif /* RENDER_H */
