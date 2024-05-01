#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include "upng.h"
#include <SDL2/SDL_image.h>


#include <stdbool.h>
#include "input.h"
#include "player.h"
#include "render.h"
#include "raycast.h"
#include "textures.h"
#include "window.h"
#include "rain.h"



// Constants
#define PI 3.14159265
#define SCREEN_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)


// Function prototypes
void setup_game(void);
void update_game(void);
void destroy_game(void);


// Global variables
extern bool GameRunning;
extern int TicksLastFrame;


#endif /* MAIN_H */
