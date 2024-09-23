#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "window.h"
#include "upng.h"
#include "config_ubuntu.h"
#include "config.h"
/* Constants */

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64

#define MINIMAP_SCALE_FACTOR 0.25

#define SCREEN_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS SCREEN_WIDTH

#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

#define NUM_TEXTURES 8
#define TEXTURE_PATH(name) ASSETS_PATH "/" name

typedef uint32_t color_t;
void handleInput(void);
/* Setup game */
void setupPlayer(void);
void updateFrame(void);
void renderGame(SDL_instance *instance);

/**
* Player - player components
 * @x: x coordinate
 * @y: y coordinate
 * @width: width of player
 * @height: height of player
 * @turnDirection: turn direction
 * @walkDirection: walk direction
 * @rotationAngle: rotation angle
 * @walkSpeed: walk speed
 * @turnSpeed: turn speed
*/
typedef struct player_s {
    int x;
    int y;
    int width;
    int height;
    int turnDirection;
    int walkDirection;
    float rotationAngle;
    float walkSpeed;
    float turnSpeed;
} Player;

extern Player player;

void movePlayer(float deltaTime);
void renderPlayer(void);

/* Functions-variables-structs for map */
bool DetectCollision(float x, float y);
bool isInsideMap(float x, float y);
void renderMap(void);
int getMapValue(int row, int col);

/**
 * Ray - ray components
 * @rayAngle: ray angle
 * @wallHitX: wall hit x coordinate
 * @wallHitY: wall hit y coordinate
 * @distance: distance
 * @wasHitVertical: was hit vertical
 * @wallHitContent: wall hit content
 */

typedef  struct ray_s{
    float rayAngle;
    float wallHitX;
    float wallHitY;
    float distance;
    bool wasHitVertical;
    int wallHitContent;
} Ray;

extern Ray rays[NUM_RAYS];

float distanceBetweenPoints(float x1, float y1, float x2, float y2);
bool isRayFacingUp(float angle);
bool isRayFacingDown(float angle);
bool isRayFacingLeft(float angle);
bool isRayFacingRight(float angle);
void castAllRays(void);
void castRay(float rayAngle, int stripId);
void renderRays(void);
void horzIntersection(float rayAngle);
void vertIntersection(float rayAngle);

/* Functions-variables-structs for textures */

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

texture_t wallTextures[NUM_TEXTURES];

void WallTexturesready(void);
void freeWallTextures(void);

/* Functions-variables-structs for walls */

void renderWall(void);

#endif /* GAME_H */
