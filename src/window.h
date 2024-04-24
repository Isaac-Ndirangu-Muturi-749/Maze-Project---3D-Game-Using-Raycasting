#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "render.h"
#include "main.h"


// Function prototypes
bool initializeWindow(void);
void destroyWindow(void);

// Extern declarations
extern SDL_Renderer *renderer;
extern color_t *colorBuffer;
extern SDL_Texture *colorBufferTexture;
extern SDL_Window *window;

#endif /* WINDOW_H */
