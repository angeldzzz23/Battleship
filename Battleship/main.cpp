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
    Boat *boat1 = new Boat();
    Boat *boat2 = new Boat();

    char *name = new char[81];
    cin.getline(name, 81-1);
    
    User *user = new User();
    user->updNam(name, 81); 
    user->adMiss(cord1);
    user->adMiss(cord2);
    user->adMiss(cord3);
    
    
    
    
    delete [] name;
      

    
    
    return 0;
}

// Prompt class
// Display class