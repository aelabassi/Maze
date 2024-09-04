#include "game.h"

/**
* init_maze - Initialize the maze
 * @maze: The maze to initialize
 */
void init_maze(Maze *maze)
{
    int x, y;

    for (y = 0; y < MAP_HEIGHT; y++)
    {
        for (x = 0; x < MAP_WIDTH; x++)
        {
            maze->map[y][x].type = CELL_WALL;
        }
    }
}

/**
* generate_maze - Generate the maze
 * @x: The x coordinate
 * @y: The y coordinate
 */
void generate_maze(int x, int y)
{
    Maze *maze;
    int direction[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    maze->map[y][x].type = CELL_PATH;
    for (int i = 0; i < 4; i++)
    {
        int r = rand() % 4;
        int tmp = direction[i][0];
        direction[i][0] = direction[r][0];
        direction[r][0] = tmp;
        tmp = direction[i][1];
        direction[i][1] = direction[r][1];
        direction[r][1] = tmp;
    }
    for (int i = 0; i < 4; i++)
    {
        int dx = x + direction[i][0] * 2;
        int dy = y + direction[i][1] * 2;
        if (dx < 0 || dy < 0 || dx >= MAP_WIDTH || dy >= MAP_HEIGHT)
            continue;
        if (maze->map[dy][dx].type == CELL_WALL)
        {
            maze->map[y + direction[i][1]][x + direction[i][0]].type = CELL_PATH;
            generate_maze(dx, dy);
        }
    }
}

/**
* render_maze - Render the maze
 * @instance: The instance to render
 */
void render_maze(SDL_instance *instance)
{
    int x, y;
    Maze maze;
    SDL_Rect rect = {0, 0, TILE_SIZE, TILE_SIZE};

    for (y = 0; y < MAP_HEIGHT; y++)
    {
        for (x = 0; x < MAP_WIDTH; x++)
        {
            if (maze.map[y][x].type == CELL_WALL)
            {
                SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 255);
            }
            else
            {
                SDL_SetRenderDrawColor(instance->renderer, 255, 255, 255, 255);
            }
            rect.x = x * TILE_SIZE;
            rect.y = y * TILE_SIZE;
            SDL_RenderFillRect(instance->renderer, &rect);
        }
    }
}