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
<<<<<<< Updated upstream
=======
#include <cstring>
#include "User.h"
#include "Boat.h"
#include "Board.h"
#include "Prompt.h"
>>>>>>> Stashed changes


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
    Coordinate cord = Coordinate("a2");
    cout << cord.getRow() << endl;
    cout << cord.getCol() << endl;
    
    //testing board display function
    Board testboard; //creating a test board object
    
<<<<<<< Updated upstream
    Display test; //created the display object test
    test.displayboard(testboard); //displaying the board
//    cout << "\u24E7" << endl;
    // Hello
=======
    
    Submarine *sub = new Submarine();
      sub->addCord(cord03);
      sub->addCord(cord04);
      sub->addCord(cord05);
   
    Cruiser *cuucu = new  Cruiser();
      cuucu->addCord(cord06);
      cuucu->addCord(cord07);
      cuucu->addCord(cord08);
   
   Battleshp *battle = new Battleshp();
      battle->addCord(cord09);
      battle->addCord(cord10);
      battle->addCord(cord11);
      battle->addCord(cord12);
    
    Carrier *carr = new Carrier();
      carr->addCord(cord13);
      carr->addCord(cord14);
      carr->addCord(cord15);
      carr->addCord(cord16);
      carr->addCord(cord17);
      
     User *user = new User();
     user->adBoat(depp);
     user->adBoat(sub);
     user->adBoat(cuucu);
     user->adBoat(battle);
     user->adBoat(carr);
//
         Coordinate *cord0222 = new Coordinate(5,3);
         Coordinate *cord3333 = new Coordinate(6,1);
         Coordinate *cord02224 = new Coordinate(7,5);
         Coordinate *cord33334 = new Coordinate(8,1);
     
       int misz = 4;
      Coordinate **misses = new Coordinate*[21];
      misses[0] = cord0222;
      misses[1] = cord3333;
      misses[2] = cord02224;
      misses[3] = cord33334;
      
      // how to update the board
      Board *brd = new Board();
      
      // update misses at once 
      brd->upms(cord0222);
      brd->upms(cord3333);
      brd->upms(cord02224);
      brd->upms(cord33334);
      
      // the boaats
     Boat **boatss = new Boat*[6]; // the array 
     boatss[0] = depp;
     boatss[1] = sub;
     boatss[2] = cuucu;
     boatss[3] = battle;
     boatss[4] = carr;
      // update the boats 
      brd->update(boatss, 5);
      
      Display test;
      test.displayboard(brd);
      
      Prompt tester;
      tester.mainmenu();
      tester.hello();
      tester.getturn();
      tester.waitturn();
      tester.winner();
     
>>>>>>> Stashed changes
    return 0;
}

// Prompt class
// Display class