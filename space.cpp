#include "space.h"
#include "card.h"

Space::Space() : 
    flipped(NULL) {
    this->card = new Card();
}

Space::Space(const Space& s) :
    flipped(s.flipped) {
    this->card = new Card(*s.card);
}

Space::~Space() { };

Space& Space::operator=(Space rhs) { 
    this->swap(rhs);
    return *this;
}

void Space::swap(Space& s) {
    if(this != &s) {
        std::swap(this->flipped, s.flipped);
        std::swap(this->card, s.card);
    }
}

void Space::flip() {
    flipped = !flipped;
}

bool Space::isFlipped() {
    return flipped;
}

void Space::setCard(Card& newCard) {
    card = &newCard;
}

Card* Space::getCard() {
    return card;
}