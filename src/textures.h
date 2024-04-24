#ifndef TEXTURES_H
#define TEXTURES_H

#include "upng.h"
#include "main.h"
#include <stdint.h>

// Constants
#define NUM_TEXTURES 8

typedef uint32_t color_t;


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

// Global array to store textures
extern texture_t wallTextures[NUM_TEXTURES];

extern const char *textureFileNames[NUM_TEXTURES];

// Function prototypes
void WallTexturesready(void);
void freeWallTextures(void);

#endif /* TEXTURES_H */
