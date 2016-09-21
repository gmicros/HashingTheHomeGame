#include "player.h"

Player::Player() : 
    name(""), position(0) { }

Player::Player(const Player& p) :
    name(p.name), position(p.position) { };

Player::~Player() { };

Player& Player::operator=(Player rhs) {
    this->swap(rhs);
    return *this;
}

void Player::swap(Player& p) {
    if(this != &p) {
        std::swap(this->name, p.name);
        std::swap(this->position, p.position);        
    }
}