#include <iostream>
#include <BlackJack420.cpp>
#include <array>
#include <random>
#include <string>

using namespace std;

//Trianna
class Card{
    private:
        bool isFaceUp;

    protected:
        RANK rank;
        SUIT suit;

    public:
        enum RANK{
            ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
            EIGHT, NINE, TEN, JACK, QUEEN, KING
        };
        enum SUIT{
            HEARTS, SPADES, DIAMONDS, CLOVERS
        };

        Card(RANK rank = ACE, RANK suit = SPADES, bool isUp = true);
        int getValue();
        void flip();
};

//Trianna
class Hand{
    protected:
        vector<Card*> cardVector;
    
    public:
        Hand();
        virtual ~Hand();

        void add(Card* = cardPtr);
        void clearHand();
        int getTotal() const;
};

//Trianna
class Deck : public Hand {
    public:
        Deck();
        virtual ~Deck();

        void populate();
        void shuffle();
        void deal(Hand& aHand);
        void additionalCards(GenericPlayer& aGenericPlayer);

};

//Nakana
class GenericPlayer{

};

//Nakana
class Player{

};

//Nakana
class House{

};

//Trianna
class Game{

};

