#include <string>

class Player {
    public:
        Player();
        Player(const Player& p);
        ~Player();
        Player& operator=(Player rhs);
        void swap(Player& p);

    private:
        std::string name;
        int position;
};