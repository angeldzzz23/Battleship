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
    
//    
    char* n1 = new char[4];
    n1 = "a1";
    Coordinate *cord1 = new Coordinate(n1); // 0 1
    cout << cord1->getCol() << " " << cord1->getRow() << endl;
    
    char* n2 = new char[4];
    n2 = "a1";
    
    Coordinate *cord2 = new Coordinate(n2);// 0 1
    cout << cord2->getCol() << " " << cord2->getRow() << endl;
    

//    Coordinate *cord3 = new Coordinate("c2");
//    Coordinate *cord4 = new Coordinate("c3");
//    
//    Coordinate *cord5 = new Coordinate("b6");
//    Coordinate *cord6 = new Coordinate("b7");
//   
//    Coordinate *cord7 = new Coordinate("f7");
//    Coordinate *cord8 = new Coordinate("f8");
//    
//    Coordinate *cord9 = new Coordinate("d1");
//    Coordinate *cord10 = new Coordinate("d2");
//    
//    Coordinate *cord101 = new Coordinate("f8");
//    Coordinate *cord102 = new Coordinate("f7");
//    
//   Coordinate *cord103 =  new Coordinate("a5");
//    Coordinate *cord104 = new  Coordinate("a7");
        
    // Fix  == overoading opera
    if (*cord1 == *cord2) {
        cout << "dwdwdwfefefefef" << endl;
    } else {
        cout << "not true" << endl;
    }
    
    
//    Boat *boat1 = new Boat();
//   
//    boat1->addCord(cord1);
//    boat1->addCord(cord2);
//    
//    Boat *boat2 = new Boat();
//    boat2->addCord(cord3);
//    boat2->addCord(cord4);
//    
//    Boat *boat3 = new Boat();
//    boat3->addCord(cord5);
//    boat3->addCord(cord6);
//
//    Boat *boat4 = new Boat();
//    boat4->addCord(cord7);
//    boat4->addCord(cord8);
//    
//    Boat *boat5 = new Boat();
//    boat5->addCord(cord9);
//    boat5->addCord(cord10);
//    
//    
//    Boat **boats = new Boat*[4];
//    boats[0] = boat1;
//    boats[1] = boat2; 
//    boats[2] = boat3;
//    boats[3] = boat4;
//    boats[4] = boat5;
// 
//    User *user = new User();
//    
//    user->adBoat(boat1);
//    user->adBoat(boat2);
//    user->adBoat(boat3);
//    user->adBoat(boat4);
//    user->adBoat(boat5);
//    
//    user->adEnemyHt(cord101);
//    user->adEnemyHt(cord102);
//    
//    user->adEnemyMs(cord103);
//    user->adEnemyMs(cord104);
    
               
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
    
    
//    f int getrowsize(); //get size of row variable for other functions Ethan/Yanis
//    int getcolsize(); //get size of colomn variable for other functions Ethan/Yanis
//    char getElement(
    
    
//    cout << "printing your current board" << endl;
//    cout << "your boats and enemy hits and misses"  << endl;
//    // printing the board of the user
//    for (int i = 0; i <  user->brdRow(); i++) {
//        for (int j = 0; j < user->brdCol(); j++) {
//            cout << user->gtMBrdElmnt(i,j) << " ";
//        }
//        cout << endl;
//    }
    
    
    
    
    
    
    
    
//    char *name = new char[81];
//    cin.getline(name, 81-1);
    
//    User *user = new User();
//    user->updNam(name, 81); 
//    user->adMiss(cord1);
//    user->adMiss(cord2);
//    user->adMiss(cord3);
    
    
    
    
//    delete [] name;
      

    
    
    return 0;
}

// Prompt class
// Display class