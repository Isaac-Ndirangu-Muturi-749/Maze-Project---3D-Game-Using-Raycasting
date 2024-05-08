#include "../headers/draw.h"

/**
 * drawPixel - Assign a color to each pixel
 * @x: X pixel coordinate
 * @y: Y pixel coordinate
 * @color: Pixel color
 */
void drawPixel(int x, int y, color_t color) {
	colorBuffer[(WINDOW_WIDTH * y) + x] = color;
}

/**
 * drawLine - Draw a line
 * @x0: X coordinate init
 * @y0: Y coordinate init
 * @x1: X coordinate end
 * @y1: Y coordinate end
 * @color: Pixel color
 */
void drawLine(int x0, int y0, int x1, int y1, color_t color) {
	float xIncrement, yIncrement, currentX, currentY;
	int i, longestSideLength, deltaX, deltaY;

	deltaX = (x1 - x0);
	deltaY = (y1 - y0);

	longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

	xIncrement = deltaX / (float)longestSideLength;
	yIncrement = deltaY / (float)longestSideLength;

	currentX = x0;
	currentY = y0;

	for (i = 0; i < longestSideLength; i++) {
		drawPixel(round(currentX), round(currentY), color);
		currentX += xIncrement;
		currentY += yIncrement;
	}
}

/**
 * drawRect - Draw a rectangle
 * @x: X coordinate
 * @y: Y coordinate
 * @width: Rectangle width
 * @height: Rectangle height
 * @color: Pixel color
 */
void drawRect(int x, int y, int width, int height, color_t color) {
	int i, j;

	for (i = x; i <= (x + width); i++) {
		for (j = y; j <= (y + height); j++) {
			drawPixel(i, j, color);
		}
	}
}
