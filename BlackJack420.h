#ifndef BLACKJACK420_H
#define BLACKJACK420_H

#include <iostream>
#include <array>
#include <random>
#include <string>
#include <vector>

using namespace std;

//Trianna
class Card{
    public:
        enum RANK{
            ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
            EIGHT, NINE, TEN, JACK, QUEEN, KING
        };
        enum SUIT{
            HEARTS, SPADES, DIAMONDS, CLUBS
        };

        Card(RANK rank = ACE, SUIT suit = SPADES, bool isUp = true);
        int getValue() const;
        void flip();

        friend ostream& operator<<(ostream& out, const Card& card);

    protected:
        RANK rank;
        SUIT suit;

    private:
        bool isFaceUp;

};

//Trianna
class Hand{
    public:
        Hand();
        virtual ~Hand();

        void add(Card* cardPtr);
        void clearHand();
        int getTotal() const;

    protected:
        vector<Card*> cardVector;
   
};

class GenericPlayer;

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
class GenericPlayer : public Hand{
    public:
        GenericPlayer();
        virtual ~GenericPlayer();

        string getName() const;
        void setName(const string& playerName);
        bool isBusted() const;
        bool bust() const;
        virtual bool isHitting() const = 0;

        friend ostream& operator<<(ostream& out, const GenericPlayer& player);

    private:
        string name;
};

//Nakana
class Player : public GenericPlayer{
    public:
        Player(const string& playerName = "");
        virtual ~Player();

        virtual bool isHitting() const;
        bool win() const;
        bool lose() const;
        bool push() const;
};

//Nakana
class House : public GenericPlayer{
    public:
        House(const string& houseName = "Dealer");
        virtual ~House();

        virtual bool isHitting() const;
        void flipFirstCard();

};

//Trianna
class Game{
    public:
        Game(const string& name);
        ~Game();
        void play();

    private:
        Deck deck;
        House house;
        Player player;

};

ostream& operator<<(ostream& out, const Card& card);
ostream& operator<<(ostream& out, const GenericPlayer& player);

#endif