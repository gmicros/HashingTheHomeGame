#include <iostream>

#include "game.h"
#include "board.h"
#include "player.h"


int main() {
	Board* b = new Board();	
	Player* p = new Player();
	Game* g = new Game();
	g->loadCardsFromFile("cardFile");
	std::cout << "Welcome to Hashing The Homegame\n";
	g->loadPlayers();
	g->PlayTheGame();


	
	std::string str;
	return 0;
}
