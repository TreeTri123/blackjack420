#include <iostream>
#include <BlackJack420.h>
#include <array>
#include <random>
#include <string>

using namespace std;

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
