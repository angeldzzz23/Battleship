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
#include "Prompt.h"
#include "Battleship.h"


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
    
    // Coordinates for the user1
   // boat 1
    Coordinate *cord01 = new Coordinate(0,0);
    Coordinate *cord02 = new Coordinate(0,1);
//    
//    // boat 2
    Coordinate *cord03 = new Coordinate(1,0);
    Coordinate *cord04 = new Coordinate(1,1);
    Coordinate *cord05 = new Coordinate(1,2);
    
    // boat 3
    Coordinate *cord06 = new Coordinate(2,0);
    Coordinate *cord07 = new Coordinate(2,1); // 
    Coordinate *cord08 = new Coordinate(2,2); //
    
    // boat 4
    Coordinate *cord09 = new Coordinate(3,0); //
    Coordinate *cord10 = new Coordinate(3,1); //
    Coordinate *cord11 = new Coordinate(3,2); //
    Coordinate *cord12 = new Coordinate(3,3); //
   
    // boat 5
    Coordinate *cord13 = new Coordinate(4,0); //
    Coordinate *cord14 = new Coordinate(4,1); //
    Coordinate *cord15 = new Coordinate(4,2); //
    Coordinate *cord16 = new Coordinate(4,3); //
    Coordinate *cord17 = new Coordinate(4,4); //
       
    Destroyer *depp = new Destroyer(); 
    depp->addCord(cord01);
    depp->addCord(cord02);
    
    
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
    
    
     // Coordinates for the user2
   // boat 1
    Coordinate *cord0123 = new Coordinate(5,0);
    Coordinate *cord0223 = new Coordinate(5,1);
//    
//    // boat 2
    Coordinate *cord0323 = new Coordinate(6,0);
    Coordinate *cord0423 = new Coordinate(6,1);
    Coordinate *cord0523 = new Coordinate(6,2);
    
    // boat 3
    Coordinate *cord0623 = new Coordinate(7,0);
    Coordinate *cord0723 = new Coordinate(7,1); // 
    Coordinate *cord0823 = new Coordinate(7,2); //
    
    // boat 4
    Coordinate *cord0923 = new Coordinate(8,0); //
    Coordinate *cord1023 = new Coordinate(8,1); //
    Coordinate *cord1123 = new Coordinate(8,2); //
    Coordinate *cord1223 = new Coordinate(8,3); //
   
    // boat 5
    Coordinate *cord1323 = new Coordinate(9,0); //
    Coordinate *cord1423 = new Coordinate(9,2); //
    Coordinate *cord1523 = new Coordinate(9,3); //
    Coordinate *cord1623 = new Coordinate(9,4); //
    Coordinate *cord1723 = new Coordinate(9,5); //
      
           // boats for the Destroyer 
     Destroyer *depp2 = new Destroyer(); 
     depp2->addCord(cord0123);
     depp2->addCord(cord0223);
     
     
      Submarine *sub2 = new Submarine();
      sub2->addCord(cord0323);
      sub2->addCord(cord0423);
      sub2->addCord(cord0523);
      
      Cruiser *cuucu2 = new  Cruiser();
      cuucu2->addCord(cord0623);
      cuucu2->addCord(cord0723);
      cuucu2->addCord(cord0823);
           
      Battleshp *battle2 = new Battleshp();
      battle2->addCord(cord0923);
      battle2->addCord(cord1023);
      battle2->addCord(cord1123);
      battle2->addCord(cord1223);
    
      Carrier *carr2 = new Carrier();
      carr2->addCord(cord1323);
      carr2->addCord(cord1423);
      carr2->addCord(cord1523);
      carr2->addCord(cord1623);
      carr2->addCord(cord1723);
      
       Board *brd1 = new Board;
       User *user1 = new User;
       user1->adBoat(depp);
       user1->adBoat(sub);
       user1->adBoat(cuucu);
       user1->adBoat(battle);
       user1->adBoat(carr);
       // update the board of the user 
       brd1->adBoat(depp);
       brd1->adBoat(sub);
       brd1->adBoat(cuucu);
       brd1->adBoat(battle);
       brd1->adBoat(carr);
       
      Board *brd2 = new Board;
      User *user2 = new User;
      user2->adBoat(depp2);
      user2->adBoat(sub2);
      user2->adBoat(cuucu2);
      user2->adBoat(battle2);
      user2->adBoat(carr2);
      
      brd2->adBoat(depp2);
      brd2->adBoat(sub2);
      brd2->adBoat(cuucu2);
      brd2->adBoat(battle2);
      brd2->adBoat(carr2);
      
    // both of the users have their things 
      
      
     Display test;
     
     test.displayboard(brd1);
     cout << endl;
     test.displayboard(brd2);
     
     GameType gmo = twoPlyr;
     // create battleship game 
     Battleship *game = new Battleship(gmo);
    
     game->setPlayerOne(user1);
     game->setPlayerTwo(user2);
     
     // do the game logic 
     
     // choose a cordinate for user take a shot 
     Coordinate *shot111 = new Coordinate(2,0);
     game->takeShot(user2, shot111);
     
     
     
     
     
     
//     test.displayboard(brd1);
     
//     cout << endl;
//     cout << user1->getId() << endl;
//     cout << user2->getId() << endl;
//     cout << endl;
    // get the boats from the user 
    
//        delete brd1; 
//        delete user1;
        //delete user2;
//    delete 
    


    
    

    return 0;
}

// Prompt class
// Display class


/* How to add boats
 * you can add an array of boats using: 
 * 
 
 */

//    Game game;
//    game.startGame();

//     User *user = new User();

//
//         Coordinate *cord0222 = new Coordinate(5,3);
//         Coordinate *cord3333 = new Coordinate(6,1);
//         Coordinate *cord02224 = new Coordinate(7,5);
//         Coordinate *cord33334 = new Coordinate(8,1);
//     
//       int misz = 4;
//      Coordinate **misses = new Coordinate*[21];
//      misses[0] = cord0222;
//      misses[1] = cord3333;
//      misses[2] = cord02224;
//      misses[3] = cord33334;
//      
//      // how to update the board
//      Board *brd = new Board();
//      
//      // update misses at once 
//      brd->upms(cord0222);
//      brd->upms(cord3333);
//      brd->upms(cord02224);
//      brd->upms(cord33334);
//      
//      // the boaats
//     Boat **boatss = new Boat*[6]; // the array 
//     boatss[0] = depp;
//     boatss[1] = sub;
//     boatss[2] = cuucu;
//     boatss[3] = battle;
//     boatss[4] = carr;
//      // update the boats 
//      brd->update(boatss, 5);
//
//
//    // displaying the row and cols size 
    /*for (int i = 0; i <  brd->getrowsize(); i++) {
        for (int j = 0; j < brd->getcolsize(); j++) {
            cout << brd->getElement(i,j) << " ";
        }
        cout << endl;
    }*/
//     
//      //testing display and prompt

//     
//      Prompt tester;
//      tester.hello();
//      tester.mainmenu();
//      tester.waitturn();
//      tester.getturn();
//      tester.winner();
     