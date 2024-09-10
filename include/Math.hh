#pragma once
#include <cmath>
#include <iostream>
#include <SDL2/SDL.h>


struct Vector2D
{
    float x;
    float y;
    Vector2D() : x(0), y(0) {}
    Vector2D(float x, float y) : x(x), y(y) {}
    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }
    Vector2D& operator+(const Vector2D& v2)
    {
        x += v2.x;
        y += v2.y;
        return *this;
    }
    Vector2D& operator-(const Vector2D& v2)
    {
        x -= v2.x;
        y -= v2.y;
        return *this;
    }
    Vector2D& operator*(const float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    Vector2D& operator/(const float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }
    float length()
    {
        return sqrt(x * x + y * y);
    }
    Vector2D& normalize()
    {
        float l = length();
        if (l > 0)
        {
            (*this) * (1 / l);
        }
        return *this;
    }
};


struct Transform {
    float x, y;

    Transform(float _x, float _y) : x(_x), y(_y) {}

    void print(std::string msg = ""){
        std::cout << msg << " ( x: " << x << ", y: " << y << " )" << std::endl;
    }


    inline void TranslateX(float dx) { x += dx; }
    inline void TranslateY(float dy) { y += dy; }
    inline void Translate(Vector2D v) { x += v.x; y += v.y; }
};
