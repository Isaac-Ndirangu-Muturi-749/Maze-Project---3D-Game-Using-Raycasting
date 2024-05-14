#include "../headers/draw.h"

/**
 * drawPixel - Assign a color to each pixel
 * @pixelX: X pixel coordinate
 * @pixelY: Y pixel coordinate
 * @pixelColor: Pixel color
 */
void drawPixel(int pixelX, int pixelY, color_t pixelColor) {
	colorBuffer[(WINDOW_WIDTH * pixelY) + pixelX] = pixelColor;
}


/**
 * drawLine - Draw a line
 * @startX: X coordinate of the starting point
 * @startY: Y coordinate of the starting point
 * @endX: X coordinate of the ending point
 * @endY: Y coordinate of the ending point
 * @lineColor: Color of the line
 */
void drawLine(int startX, int startY, int endX, int endY, color_t lineColor) {
    float xIncrement, yIncrement, currentX, currentY;
    int i, longestSideLength, deltaX, deltaY;

    deltaX = (endX - startX);
    deltaY = (endY - startY);

    // Determine the longest side length
    longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

    // Calculate the increments for each step along the line
    xIncrement = deltaX / (float)longestSideLength;
    yIncrement = deltaY / (float)longestSideLength;

    // Initialize the starting point
    currentX = startX;
    currentY = startY;

    // Draw the line by stepping along it and drawing pixels
    for (i = 0; i < longestSideLength; i++) {
        drawPixel(round(currentX), round(currentY), lineColor);
        currentX += xIncrement;
        currentY += yIncrement;
    }
}


/**
 * drawRect - Draw a rectangle
 * @topLeftX: X coordinate of the top-left corner
 * @topLeftY: Y coordinate of the top-left corner
 * @rectWidth: Width of the rectangle
 * @rectHeight: Height of the rectangle
 * @rectColor: Color of the rectangle
 */
void drawRect(int topLeftX, int topLeftY, int rectWidth, int rectHeight, color_t rectColor) {
	int i, j;

	for (i = topLeftX; i <= (topLeftX + rectWidth); i++) {
		for (j = topLeftY; j <= (topLeftY + rectHeight); j++) {
			drawPixel(i, j, rectColor);
		}
	}
}
