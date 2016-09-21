class Card;

class Space {
    public:
        Space();

        Space(const Space& s);

        ~Space();

        Space& operator=(Space rhs);

        void swap(Space& s);

        bool isFlipped();

        void flip();

        void setCard(Card& newCard);

        Card* getCard();

    private:
        Card* card;
        bool flipped;
};