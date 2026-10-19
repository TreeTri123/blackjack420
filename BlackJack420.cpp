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

    return total;
}

//GenericPlayer class functions

//Constructor
GenericPlayer::GenericPlayer() 
    : name("") {

}

//Destructor
GenericPlayer::~GenericPlayer() {
}

string GenericPlayer::getName() const {
    return name;
}

void GenericPlayer::setName(const string& playerName) {
    name = playerName;
}

bool GenericPlayer::isBusted() const {
    if (getTotal() > 21) {
        return true;
    }
    else {
        return false;
    }
}

bool GenericPlayer::bust() const {
    cout << name << " has busted" << endl;
    return true;
}

//Player class functions

//Constructor
Player::Player(const string& playerName)
    : GenericPlayer() {
    setName(playerName);
}

//Destructor
Player::~Player() {
}

bool Player::isHitting() const {
    char input;

    while (true) {
        cout << getName() << ", would you like to hit? y for Yes, n for No: ";
        cin >> input;

        if (input == 'y') {
            return true;
        }
        else if (input == 'n') {
            return false;
        }
        //if user inputs letter other than y or n
        else {
            cout << "Not a valid answer" << endl;
        }
    }
}

bool Player::win() const {
    cout << getName() << " has won!" << endl;
    return true;
}

bool Player::lose() const {
    cout << getName() << " has lost!" << endl;
    return true;
}

bool Player::push() const {
    cout << getName() << " has pushed" << endl;
    return true;
}

//House class functions

//Constructor
House::House(const string& houseName)
    : GenericPlayer() {
    setName(houseName);
}

//Destructor
House::~House() {
}

bool House::isHitting() const {
    //Hit if dealer's total is less than or equal to 16
    if (getTotal() <= 16) {
        return true;
    }
    else {
        return false;
    }
}

void House::flipFirstCard() {
    //If cardVector is not empty, then flip first element
    if (!cardVector.empty()) {
        cardVector[0]->flip();
    }
    else {
        cout << "There are no cards to flip" << endl;
    }
}