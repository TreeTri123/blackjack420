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

//getting value of each card
int Card::getValue() const{
    if (!isFaceUp){
        return 0;
    }

    if (rank == KING || rank == QUEEN || rank == JACK){
        return 10;
    }

    return rank;
}

//flipping the card over
void Card::flip(){
    isFaceUp = !isFaceUp;
}

//Hand class functions

//Constructor 
Hand::Hand(){
    cardVector.reserve(7);
}

//Destructor + deleting the remaining hand
Hand::~Hand(){
    clearHand();
}

//adding cards to the deck
void Hand::add (Card* cardPtr){
    cardVector.pushback(cardPtr);
}

//Clearing the hand
void Hand::clearHand(){
    vector<Card*>::iterator iter;

    for (iter = cardVector.begin(); iter != cardVector.end(); ++iter){
        delete *iter;
        *iter = NULL;
    }

    cardVector.clear();
}

//adding up the total to 21
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

// Deck class functions

//reserve space and create the deck
Deck::Deck(){
    cardVector.reserve(52);
    populate();
}

//Deleting remaining cards
Deck::~Deck(){
}

//Create one card for each combo of suit and rank
void Deck::populate(){
    clearHand();

    for (int s = Card::CLUBS; s <= Card:: SPADES; ++s){
        for (int r = Card::ACE; r <= Card::KING; ++r){
            add(new Card(<Card::RANK>(r),<Card::SUIT>(s)));
        }
    }
}

//Randomize the order of the cards
void Deck::shuffle(){
    random_shuffle(cardVector.begin(), cardVector.end());
}

//Transfer the last card from the deck to hand
void Deck::deal(Hand& aHand){
    if (!cardVector.empty()){
        aHand.add(cardVector.back());
        cardVector.pop_back();
    } else {
        cout << "You are out of cards and are unable to deal" << endl;
    }
}

//Keep dealing while player is not busted and wants to hit
void Deck::additionalCards(GenericPlayer& a GenericPlayer){
    while (!aGenericPlay.isBusted() && aGenericPlayer.isHitting()){
        if (cardVector.emplty()){
            cout << "No cards remaining, unable to deal " << endl;
            break;
        }
    }

    deal(aGenericPlayer);
    cout << aGenericPlayer << endl;

    if (aGenericPlayer.isBusted()){
        aGenericPlayer.bust();
    }
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