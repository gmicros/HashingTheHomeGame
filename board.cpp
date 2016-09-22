#include <ctime>
#include <cstdlib>
#include "board.h"
#include "space.h"
#include "card.h"
#include <iostream>

Board::Board() {
    this->spaces = std::vector<Space*>();
}

Board::Board(const Board& b) {
    // deep copy collection
    this->spaces = std::vector<Space*>();
    std::vector<Space*>::const_iterator spIter = b.spaces.begin();
    for(; spIter != b.spaces.end(); spIter++) {
        (this->spaces).push_back(new Space(**spIter));
    }
}

Board::~Board() {
    if(!this->spaces.empty()) {
        std::vector<Space*>::iterator spIter = this->spaces.begin();
        for(; spIter != this->spaces.end(); spIter++) {
            delete *spIter;
        }
        this->spaces.clear();
    }
}

Board& Board::operator=(Board rhs) {
    this->swap(rhs);
    return *this;
}

void Board::swap(Board& b) {
    if(this != &b) {
        std::swap(this->spaces, b.spaces);
    }
}

Card* Board::openCardFromSpaceIndex(int index) {
    Space* s = spaces[index];
    Card* c = NULL;
    if (s->isFlipped()) {
        c = NULL;
    } else {
        c = new Card(*(s->getCard()));
        s->flip();
    }    
}

void Board::addCardToBoard(Card* c){
    Space* s = new Space();
    Card* card = new Card(*c);
    s->setCard(*card);
    spaces.push_back(s);
}

void Board::initializeBoard(std::vector<Card*> deck) {
    std::srand((unsigned)time(0));
    while(deck.size() != 0) {
        int i = rand() % deck.size();
        addCardToBoard(deck[i]);
        deck.erase(deck.begin() + i);
        std::cout << "Shuffling cards " << deck.size() << std::endl;
    }
}

int Board::getBoardSize() {
    return spaces.size();
}