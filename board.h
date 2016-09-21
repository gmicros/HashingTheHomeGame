#include <vector>

class Card;
class Space;

class Board {
    public:
        Board();
        
        Board(const Board& b);
        
        ~Board();

        Board& operator=(Board rhs);

        void swap(Board& b);

        Card* openCardFromSpaceIndex(int index);

        void addCardToBoard(Card* c);
        
    private:
        std::vector<Space*> spaces;
};