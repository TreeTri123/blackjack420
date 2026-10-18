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
            Ace, Two, Three, Four, Five, Six, Seven,
            Eight, Nine, Ten, Jack, Queen, King
        };
        enum SUIT{
            Hearts, Spades, Diamonds, Clovers
        };

        Card(RANK rank = ACE, RANK suit = SPADES, bool isUp = true);
        int getValue();
        void flip();
}

//Trianna
class Hand{

}

//Trianna
class Deck{

}

//Nakana
class GenericPlayer{

}

//Nakana
class Player{

}

//Nakana
class House{

}

//Trianna
class Game{

}

