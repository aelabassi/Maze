#include "game.hh"
#include "SDL_image.h"

Game::Game(){
    cnt = 0;
}
Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems Initialized..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }

}

SDL_Texture *Game::loadTexture(const char* filepath){
    SDL_Texture *texture = nullptr;
    texture = IMG_LoadTexture(renderer, filepath);
    if(texture == nullptr){
        std::cout << "Failed to load texture" << SDL_GetError()  << std::endl;
    }

    return texture;

}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update(){
    cnt++;
    std::cout << cnt << std::endl;
}

void Game::clear(){
    SDL_RenderClear(renderer);
}
void Game::render_texture(Entity& entity){
    SDL_Rect src_dims;
    src_dims.x = entity.getCurrentFrame().x;
    src_dims.y = entity.getCurrentFrame().y;
    src_dims.w = entity.getCurrentFrame().w;
    src_dims.h = entity.getCurrentFrame().h;
    SDL_Rect dst_dims;
    dst_dims.x = entity.getPosition().x*4;
    dst_dims.y = entity.getPosition().y*4;
    dst_dims.w = entity.getCurrentFrame().w * 4;
    dst_dims.h = entity.getCurrentFrame().h * 4;
    SDL_RenderCopy(renderer, entity.getTexture(), &src_dims, &dst_dims);
}
void Game::display(){
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned..." << std::endl;
}

bool Game::running() const{
    return isRunning;
}
