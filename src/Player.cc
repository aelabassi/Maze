#include "Player.hh"



Player::~Player() {}


void Player::Draw() {
    std::cout << "Drawing player: " << name << std::endl;
}

void Player::Clean() {
    std::cout << "Cleaning player: " << name << std::endl;
}
