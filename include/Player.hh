#pragma once
#include "Character.hh"

class Player: public Character {
    public:
    Player(std::string name, Properties props) : Character(name, props) {}
    ~Player();
    void Draw() override;
    void Clean() override;
    void Update() override;
};
