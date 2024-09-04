#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "window.h"
// gloab variables
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_TITLE "Maze Game"
#define SCREEN_FPS 60
#define SCREEN_TICKS_PER_FRAME 1000 / SCREEN_FPS
#define MAP_WIDTH 100
#define MAP_HEIGHT 100
#define TILE_SIZE 32

/**
 * CellType - type of cell
 * @CELL_WALL: wall cell
 * @CELL_PATH: path cell
 */
typedef enum {
    CELL_WALL,
    CELL_PATH
} CellType;

/**
 * Cell - cell components
 * @type: type of cell
 */
typedef struct {
    CellType type;
} Cell;

/**
* Manifold - entire maze components
*/
typedef struct manifold_s {
    Cell map[MAP_HEIGHT][MAP_WIDTH];
    SDL_instance *instance;
    void (*draw)(struct manifold_s *self, SDL_instance *instance);
    void (*handle_events)(struct manifold_s *self, SDL_instance *instance);
    void (*update)(struct manifold_s *self, SDL_instance *instance);
    void (*free)(struct manifold_s *self);
    void (*render)(struct manifold_s *self);

} Maze;

/**
* Player - player components
*/
typedef struct player_s {
    int x;
    int y;
    int width;
    int height;
} Player;


void init_maze(Maze *maze);
void generate_maze(int x, int y);
void render_maze(SDL_instance *instance);

#endif /* GAME_H */
