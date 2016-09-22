#include <string>

class Player {
    public:
        Player();
        Player(const Player& p);
        ~Player();
        Player& operator=(Player rhs);
        void swap(Player& p);

        std::string getName();
        void setName(std::string newName);

        int getPosition();
        void setPosition(int pos);

    private:
        std::string name;
        int position;
};