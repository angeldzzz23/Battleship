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
#include "Board.h"


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
 
    
    char n0[] = "glee";
    //char* n1 = new char[4];
    //n1 = "a1";
    //Coordinate *cord1 = new Coordinate(n1); // 0 1
    //cout << cord1->getCol() << " " << cord1->getRow() << endl;
    
    
    // boat 1
    Coordinate *cord01 = new Coordinate(0,0);
    Coordinate *cord02 = new Coordinate(0,1);
    
    // boat 2
    Coordinate *cord03 = new Coordinate(2,1);
    Coordinate *cord04 = new Coordinate(2,2);
    
    // boat 3
    Coordinate *cord05 = new Coordinate(5,5);
    Coordinate *cord06 = new Coordinate(5,6);
    
    // boat 4
    Coordinate *cord07 = new Coordinate(7,8); // 
    Coordinate *cord08 = new Coordinate(7,9); //
    
    // boat 5
    Coordinate *cord09 = new Coordinate(9,1); // 
    Coordinate *cord10 = new Coordinate(9,2); //
    
    
//    n2 = "a1";
//    
//    Coordinate *cord2 = new Coordinate(n2);// 0 1
//    cout << cord2->getCol() << " " << cord2->getRow() << endl;
//    

        
    // Fix  == overoading opera

//    if (*cord1 == *cord2) {
//        cout << "dwdwdwfefefefef" << endl;
//    } else {
//        cout << "not true" << endl;
//    }
    
    
    Boat *boat1 = new Boat();
    boat1->addCord(cord01);
    boat1->addCord(cord02);
//    
    Boat *boat2 = new Boat();
    boat2->addCord(cord03);
    boat2->addCord(cord04);
//    
    Boat *boat3 = new Boat();
    boat3->addCord(cord05);
    boat3->addCord(cord06);
//
    Boat *boat4 = new Boat();
    boat4->addCord(cord07);
    boat4->addCord(cord08);
    
    Boat *boat5 = new Boat();
    boat5->addCord(cord09);
    boat5->addCord(cord10);
    
    
    User *user = new User();
  
    user->adBoat(boat1);
    user->adBoat(boat2);
    user->adBoat(boat3);
    user->adBoat(boat4);
    user->adBoat(boat5);
    
    
    // enemy hits 
    Coordinate *cord101 = new Coordinate(0,3); // should be a missed
    
    // check if your ship has been hit or missed
    // it has not been hit 
    if (user->isHit(cord101)) {
        user->adEnemyHt(cord101);
    } else {
        user->adEnemyMs(cord101); // adds enemy miss 
    }
    
    
    //adEnemyHt
    //adEnemyMs
//    if (user->isHit(cord101)) {
//        cout << "you are good fam" << endl;
//    }
            
    
    
//    Board *board = new Board();
//    
//    board->update(boats, 2);
//    board->upHts(cord8);
//    board->upHts(cord88);
//    
//    board->upms(cord9);
//    board->upms(cord99);
    
    
    
    
//    cout << "printing your current board" << endl;
//    cout << "your boats and enemy hits and misses"  << endl;
//    // printing the board of the user
    
    
    
    // displaying the 
    for (int i = 0; i <  user->brdRow(); i++) {
        for (int j = 0; j < user->brdCol(); j++) {
            cout << user->gtMBrdElmnt(i,j) << " ";
        }
        cout << endl;
    }
     
    return 0;
}

// Prompt class
// Display class