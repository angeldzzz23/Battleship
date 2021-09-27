/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Game.h"
#include <iostream>
using namespace std;




Game::Game() {
    
}

bool Game::gameIsNotOver() {
    
    return true;
}

// displays the user menu

void Game::startGame() {
    
    int userSze = 81; 
    
    char *userInput = new char [userSze];
    
    cout << "WELCOME TO battleship" << endl;
    
    do {
     
    
    cout << "Press 1 to play a 2 player game" << endl;
    cout << "Press 2 to play against a computer" << endl; 
    cout << "press 3 to quit" << endl;
    cin.getline(userInput, userSze-1); // read lines 
    makeAdecision(userInput[0]);
    
    } while(userInput[0] != '3');
    
   // present the menu 
   
}

// c++
void Game::makeAdecision(char p) {
    
    switch(p) {
        case '1':
            // call a play 2 player game
        case '2':
            // call a game against an AI
        case '3':
            // quit the program 
        default:
            break;
    }
}
