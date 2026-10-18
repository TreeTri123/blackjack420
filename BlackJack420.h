#include <iostream>
#include <BlackJack420.cpp>
#include <array>
#include <random>
#include <string>

using namespace std;

//Trianna
class Card{
    public:
        enum RANK{
            ACE, 2, 3, 4, 5, 6, 7,
            8, 9, 10, JACK, QUEEN, KING
        };
        enum SUIT{
            HEARTS, SPADES, DIAMONDS, CLOVERS
        };

        Card(RANK rank = ACE, RANK suit = SPADES, bool isUp = true);
        int getValue();
        void flip();

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

        void add(Card* = cardPtr);
        void clearHand();
        int getTotal() const;

    protected:
        vector<Card*> cardVector;
   
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
class GenericPlayer : public Hand{
    public:
        GenericPlayer();
        virtual ~GenericPlayer();

        string getName() const;
        void setName(const string& playerName);
        bool isBusted();
        bool bust() const;
        virtual bool isHitting() const = 0;

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

