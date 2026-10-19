#include <iostream>
#include "BlackJack420.h"

int main {

    cout << "Welcome to BlackJack!" << endl;

    char again = 'y';
    string name;

    cout << "Please enter your name: " << endl;
    cin >> name;

    while (again == 'y') {
        Game game(name);
        game.play();

        cout << "Would you like to play again to stay in the game?
                y for Yes, n for No" << endl;
        cin >> again;
    }

    cout << "Thank you for playing!" << endl;

    return 0;
}