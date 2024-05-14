#ifndef DRAW_H
#define DRAW_H

#include "window.h"

#include <stdint.h>
typedef uint32_t color_t;

// Function prototypes
void drawPixel(int pixelX, int pixelY, color_t pixelColor);
void drawLine(int startX, int startY, int endX, int endY, color_t lineColor);
void drawRect(int topLeftX, int topLeftY, int rectWidth, int rectHeight, color_t rectColor);

#endif /* DRAW_H */
