#pragma once


class Object {
public:
    virtual void Draw() = 0;
    virtual void Clean() = 0;
    virtual void Update() = 0;

};
