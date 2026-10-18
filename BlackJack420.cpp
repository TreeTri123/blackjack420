#include <iostream>
#include <BlackJack420.h>
#include <array>
#include <random>
#include <string>

using namespace std;

//Card class functions

//Constructor
Card::Card(RANK rank, RANK suit, bool isUp)
    : rank(rank), suit(suit), isFaceUp(isUp){

}

int Card::getValue() const{
    if (!isFaceUp){
        return 0;
    }

    if (rank == KING || rank == QUEEN || rank == JACK){
        return 10;
    }

    return rank;
}

void Card::flip(){
    isFaceUp = !isFaceUp;
}

//Hand class functions

//Constructor 
Hand::Hand(){
    cardVector.reserve(7);
}

//Destructor 
Hand::~Hand(){
    clearHand();
}

void Hand::add (Card* cardPtr){
    cardVector.pushback(cardPtr);
}

void Hand::clearHand(){
    vector<Card*>::iterator iter;

    for (iter = cardVector.begin(); iter != cardVector.end(); ++iter){
        delete *iter;
        *iter = NULL;
    }

    cardVector.clear();
}

int Hand::getTotal() const{
    int total = 0;
    vector<Card*>::const_iterator iter;

    //empty hand total of 0
    if (cardVector.empty()){
        return 0;
    }

    //hide total if first card is faced down
    if (cardVector[0]->getValue() == 0){
        return 0;
    }

    //add each card value, aces = 1
    for (iter = cardVector.begin(); iter != cardVector.end(); ++iter){
        total += (*iter)->getValue();
    }

    //ace that counts as 11, not exceeding 21
    for (iter = cardVector.begin(); iter != cardVector.end(); ++iter){
        if ((*iter)->getValue() == Card::ACE){
            if (total <= 11){
                total += 10;
                return total;
            }
        }
    }

    return totall;
}