#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include "player.h"


extern bool GameRunning;


// Function prototypes
void handleInput(void);
void SDL_KEYDOWN_FUNC(SDL_Event event);
void SDL_KEYUP_FUNC(SDL_Event event);

#endif /* INPUT_H */
