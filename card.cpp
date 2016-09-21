#include "card.h"

Card::Card() {
	title = "";
	desc = "";
	noSpacesToMove = 0;
	noTurnsToSkip = 0;
	rollAgain = false;
}

Card::Card(const Card& c) : 
	title(c.title), 
	desc(c.desc),
	noSpacesToMove(c.noSpacesToMove),
	noTurnsToSkip(c.noTurnsToSkip),
	rollAgain(c.rollAgain) { }

Card::~Card() { }

Card& Card::operator=(Card rhs) {
	this->swap(rhs);
	return *this;
}

void Card::swap(Card& c) {
	if(this != &c) {
		std::swap(this->title, c.title);
		std::swap(this->desc, c.desc);
		std::swap(this->noSpacesToMove, c.noSpacesToMove);
		std::swap(this->noTurnsToSkip, c.noTurnsToSkip);
		std::swap(this->rollAgain, c.rollAgain);
	}
}

std::string Card::getTitle() {
	return title;
}

void Card::setTitle(std::string newTitle) {
	title = newTitle;
}

std::string Card::getDesc() {
	return desc;
}

void Card::setDesc(std::string newDesc) {
	desc = newDesc;
}

int Card::getNoSpacesToMove() {
	return noSpacesToMove;
}

void Card::setNoSpacesToMove(int numSpaces) {
	noSpacesToMove = numSpaces;
}

int Card::getNoTurnsToSkip() {
	return noTurnsToSkip;
}

void Card::setNoTurnsToSkip(int numTurns) {
	noTurnsToSkip = numTurns;
}

bool Card::getRollAgain() {
	return rollAgain;
}

void Card::setRollAgain(bool reRoll) {
	rollAgain = reRoll;
} 
