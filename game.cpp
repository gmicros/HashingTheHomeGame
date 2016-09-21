#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "game.h"
#include "player.h"
#include "board.h"
#include "card.h"


Game::Game() {
    this->players = std::vector<Player*>();
    this->cards = std::vector<Card*>();
    board = new Board();
}

Game::Game(const Game& g) {
    players = std::vector<Player*>();
    std::vector<Player*>::const_iterator pIter = g.players.begin();
    for(; pIter != g.players.end(); pIter++) {
        this->players.push_back(new Player(**pIter));
    }

    cards = std::vector<Card*>();
    std::vector<Card*>::const_iterator cIter = g.cards.begin();
    for(; cIter != g.cards.end(); cIter++) {
        this->cards.push_back(new Card(**cIter));
    }
    
    board = new Board(*g.board);
}

Game::~Game() {
    std::vector<Player*>::iterator pIter = this->players.begin();
    for(; pIter != this->players.end(); pIter++) {
        delete *pIter;        
    }
    players.clear();

    std::vector<Card*>::iterator cIter = this->cards.begin();
    for(; cIter != this->cards.end(); cIter++) {
        delete *cIter;
    }
    cards.clear();

    delete this->board;
}

Game& Game::operator=(Game rhs) {
    this->swap(rhs);
    return *this;
}

void Game::swap(Game& g) {
    if(this != &g) {
        std::swap(this->board, g.board);
        std::swap(this->players, g.players);
        std::swap(this->cards, g.cards);
    }
}

void Game::loadPlayer() { }

void Game::parseLine(std::string line, std::string& title, std::string& desc,
                int& noSpaces, int& noTurns, bool& rollAgain) {
    std::string token;
    std::istringstream iss(line);

    remove_if(line.begin(), line.end(), isspace);

    std::getline(iss, title, ',');
    std::getline(iss, desc, ',');
    std::getline(iss, token, ',');
    noSpaces = std::atoi(token.c_str());
    std::getline(iss, token, ',');
    noTurns = std::atoi(token.c_str());
    std::getline(iss, token, ',');
    std::istringstream(token) >> rollAgain;         
}

Card* Game::makeACard(std::string title, std::string desc, int noSpaces, int noTurns, bool rollAgain) {
    Card* c = new Card();
    c->setTitle(title);
    c->setDesc(desc);
    c->setNoSpacesToMove(noSpaces);
    c->setNoTurnsToSkip(noTurns);
    c->setRollAgain(rollAgain);
    return c;
}

void Game::loadCardsFromFile(std::string filename) {
    std::ifstream inFile(filename.c_str());
    std::string line, title, desc;
    int noSpaces, noTurns;
    bool rollAgain;
    
    while(std::getline(inFile, line)) {
        parseLine(line, title, desc, noSpaces, noTurns, rollAgain);
        std::cout << title << " " << desc << " " 
            << noSpaces << " " << noTurns << " " << rollAgain << std::endl;
        cards.push_back(makeACard(title, desc, noSpaces, noTurns, rollAgain));            
    }
    std::cout << "Num cards = " << cards.size() << std::endl;

}