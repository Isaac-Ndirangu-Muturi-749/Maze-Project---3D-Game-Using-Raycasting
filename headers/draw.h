#ifndef DRAW_H
#define DRAW_H

#include "main.h"
#include "window.h"

#include <stdint.h>
typedef uint32_t color_t;

// Function prototypes
void drawPixel(int x, int y, color_t color);
void drawLine(int x0, int y0, int x1, int y1, color_t color);
void drawRect(int x, int y, int width, int height, color_t color);

#endif /* DRAW_H */
