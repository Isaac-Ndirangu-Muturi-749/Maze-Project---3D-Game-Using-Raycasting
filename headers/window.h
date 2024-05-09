#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "map.h"

#include <stdint.h>
typedef uint32_t color_t;

#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)


// Function prototypes
bool initializeWindow(void);
void destroyWindow(void);


// Declare external variables
extern SDL_Renderer *renderer;
extern color_t *colorBuffer;
extern SDL_Texture *colorBufferTexture;
extern SDL_Window *window;

#endif /* WINDOW_H */
