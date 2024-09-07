#pragma once
#include <SDL2/SDL.h>

namespace Utils {
    inline float hireTimeInSeconds()
    {
        return SDL_GetTicks() / 1000.0f;
    }
}
