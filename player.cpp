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

std::string Player::getName() {
    return name;
}

void Player::setName(std::string newName) {
    name = newName;
}

int Player::getPosition() {
    return position;
}

void Player::setPosition(int pos) {
    position = pos;
}