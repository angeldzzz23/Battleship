/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: AZ
 *sss sjsjsjjs old
 * Created on September 26, 2021, 12:43 PM
 */

#include <cstdlib>
#include "Game.h"
#include <iostream>
#include "Coordinate.h"
#include "Boat.h"
#include "AbsBoat.h"
#include "Display.h"
#include <cstring>
#include "User.h"
#include "Boat.h"


using namespace std;

// We need someone to work on: 
// TODO #1: creating the boats (inheritance of diff boats)
// TODO #2: Cordinates 
// TODO #3 Battleship 2 player game - Angel 
// TODO 3b Battleship playing against a PC - Coder Kai 
// TODO #4 the User 
// TODO #5 The file saving/retrieving - Ethanol/Angel
// TODO #6 Prompt class
// TODO #7 Display class  


int main(int argc, char** argv) {
    
//    Game game;
//    game.startGame();
    
//    
    Coordinate *cord1 = new Coordinate("a2");
    Coordinate *cord2 = new Coordinate("b3");
    Coordinate *cord3 = new Coordinate("a2");

    
    cout << cord1->getRow() << endl;
    cout << cord1->getCol() << endl;
    
//    cout << cord1.getRow() << endl;
//    cout << cord1.getCol() << endl;
    
    //testing board display function
//    Board testboard; //creating a test board object
//    
//    Display test; //created the display object test
//    test.displayboard(testboard); //displaying the board
    
//    User usr = User();
  
//    if (cord1 == cord2) {
//        cout << "same" << endl;
//    }
//    
    
    Boat b = Boat(); // creates a new boat
//    
    b.addCord(cord1);

    
        b.addCord(cord2);
    

    
    
    
    return 0;
}

// Prompt class
// Display class