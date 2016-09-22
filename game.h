#include <vector>

class Player;
class Board;
class Card;

class Game {
    public:
        Game();
        Game(const Game& game);
        ~Game();
        Game& operator=(Game rhs);
        void swap(Game& g);

        void loadPlayers();
        void loadPlayer();
        void loadCardsFromFile(std::string filename);

        void PlayTheGame();
    private:
        bool hasAnyoneWon(); 
        Card* makeACard(std::string title, std::string desc, int noSpaces, int noTurns, bool rollAgain);
        void parseLine(std::string line, std::string& title, std::string& desc,
                int& noSpaces, int& noTurns, bool& rollAgain);

        std::vector<Player*> players;
        std::vector<Card*> cards;
        Board* board;
};