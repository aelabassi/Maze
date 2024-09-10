#pragma once
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "Math.hh"
#include <iostream>
#include <string>
#include "game.hh"


class Character: public Game{
    protected:
    std::string name;

    public:
    Character(std::string name, Properties props) : name(name) {}

    virtual void Draw() = 0;
    virtual void Clean() = 0;
    virtual void Update() = 0;
};
