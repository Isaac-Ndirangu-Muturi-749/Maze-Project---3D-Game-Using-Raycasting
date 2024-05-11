#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>

#include "window.h"
#include "rain.h"
#include "walls.h"
#include "ceiling.h"
#include "floor.h"
#include "weapon.h"
#include "color_buffer.h"
#include "input.h"
#include "player.h"


// Constants
#define FPS 60
#define FRAME_TIME_LENGTH (1000 / FPS)


/**
 * struct texture_s - struct for the textures
 * @width: texture width
 * @height: texture height
 * @texture_buffer: pointer to texture buffer
 * @upngTexture: pointer to upng buffer
 *
 */
typedef struct texture_s
{
	int width;
	int height;
	color_t *texture_buffer;
	upng_t *upngTexture;
} texture_t;

// Function prototypes
void setupGame(void);
void updateGame(void);
void renderGame(void);
void destroyGame(void);

// Global variables
extern bool GameRunning;
extern int TicksLastFrame;

#endif /* MAIN_H */
