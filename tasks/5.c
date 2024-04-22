#include <stdio.h>

#define MAX_MAP_ROWS 100
#define MAX_MAP_COLS 100

// Structure to represent the game map
typedef struct {
    char tiles[MAX_MAP_ROWS][MAX_MAP_COLS]; // 2D array to store the map tiles
    int rows;
    int cols;
} Map;

// Function to parse the map file and populate the Map structure
int parseMap(const char *filename, Map *map) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return 0; // Error opening file
    }

    int row = 0;
    int col = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            map->rows = row; // Set the number of rows in the map
            col = 0; // Reset column index for next row
            row++; // Move to the next row
        } else {
            if (row < MAX_MAP_ROWS && col < MAX_MAP_COLS) {
                map->tiles[row][col] = (char)c; // Store the tile character in the map
                col++; // Move to the next column
            } else {
                printf("Error: Map size exceeds maximum limit\n");
                fclose(file);
                return 0; // Map size exceeds maximum limit
            }
        }
    }
    map->cols = col; // Set the number of columns in the map

    fclose(file);
    return 1; // Parsing successful
}

// Function to print the parsed map
void printMap(Map *map) {
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            printf("%c", map->tiles[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Map map;

    // Parse the map file
    if (!parseMap("map.txt", &map)) {
        return 1; // Error parsing map file
    }

    // Print the parsed map
    printMap(&map);

    return 0;
}
