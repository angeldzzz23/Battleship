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

void sort1(Coordinate** cords, int size, int typw); 

int main(int argc, char** argv) {
    
//    Game game;
//    game.startGame();

    
    
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
    Coordinate *cord13 = new Coordinate(9,1); //
    Coordinate *cord14 = new Coordinate(9,2); //
    Coordinate *cord15 = new Coordinate(9,3); //
    Coordinate *cord16 = new Coordinate(9,4); //
    Coordinate *cord17 = new Coordinate(9,5); //
    
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

      
       
      
//     Coordinate *hit1 = new Coordinate(1,0);
//     Coordinate *hit2 = new Coordinate(1,1);
//     Coordinate *hit3 = new Coordinate(5,2);
     

//     Boat **boatss = new Boat*[16];
//     boatss[0] = depp;
//     boatss[1] = sub;
//     boatss[2] = cuucu;       
//     boatss[3] = battle;
//     boatss[4] = carr;
     
    
     
     
//     cout << depp->cordAt(1)->getRow() << endl;
//     cout << depp->cordAt(1)->getCol() << endl;
//     
//     
//     Board *brd = new Board;
//     brd->update(boatss, 5);
//     brd->adBoat(depp);
//      
//      Display test;
//      test.displayboard(brd);
////     
     
      
//      delete depp;
//      delete sub;
//      delete cuucu;
//      delete battle;
//      delete carr;
    
      
      Coordinate **co22 = new Coordinate*[7]; // 
      Coordinate *Co1 = new Coordinate(0,1);
      Coordinate *Co2 = new Coordinate(0,2);
      Coordinate *Co3 = new Coordinate(0,7);
      Coordinate *Co4 = new Coordinate(0,4);
      Coordinate *Co5 = new Coordinate(0,5);
      
      // Coordinate 
      co22[0] = Co1;
      co22[1] = Co4;
      co22[2] = Co5;
      co22[3] = Co2;
      co22[4] = Co3;
    
      
      int rtot = 0;  // the total num rows of cols
      int ctot = 0; // the total number cols 
     
      int sz = 5;
//      cout <<   co22[j]->getRow() << " " << co22[j]->getCol() << endl;  
      
      
      // checks duplicates 
      cout << endl;
      for (int i = 0; i < sz; i++) {
          for (int j = i+1; j < sz; j++) {
              if (*co22[i] == *co22[j]) {
                  cout << "dddd" << endl;
                  // return false 
              }

          }
      }
      
      // sort the  coordinates 
      sort1(co22,sz, 3);
      
      for(int i = 0; i < sz;i++) {
       cout <<   co22[i]->getRow() << " " << co22[i]->getCol() << endl;  

      }
      
      // check if they all have a difference of one 
      for (int i = 0; i < sz-1; i++) {
          if (co22[i+1]->getCol() - co22[i]->getCol() != 1) {
              cout << "no distance of one" << endl;
          }
      }
      
      
 
    
    return 0;
}

// Prompt class
// Display class


   
//    
//     user->adHit(hit3);

     
//     if (user->isHitb(hit)) {
//         cout << "it is a hit" << endl;
//     }
     
     
  // Coordinate *cord06 = new Coordinate(2,0);
    //Coordinate *cord07 = new Coordinate(2,1); // 
    //Coordinate *cord08 = new Coordinate(2,2); //
     
     
//     delete user;
     
     
////
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


    // displaying the row and cols size 
    /*for (int i = 0; i <  brd->getrowsize(); i++) {
        for (int j = 0; j < brd->getcolsize(); j++) {
            cout << brd->getElement(i,j) << " ";
        }
        cout << endl;
    }*/
     
      //testing display and prompt
//      Display test;
//      test.displayboard(brd);
//     
//      Prompt tester;
//      tester.hello();
//      tester.mainmenu();
//      tester.waitturn();
//      tester.getturn();
//      tester.winner();
 void sort1(Coordinate** cords, int size, int typw) {
//     Coordinate *inter = new Coordinate(1,3);
     int row; // used for swapping
     int col; // used for swapping
     for (int i =0; i < size-1; i++) {
         for (int j = 0; j < size-i-1; j++) {
             
             if (cords[j]->getCol() > cords[j + 1]->getCol()) {
                 // swapping 
                 row = cords[j]->getRow();
                 col = cords[j]->getCol();
       
                 cords[j]->setCol(cords[j + 1]->getCol());
                 cords[j]->setRow(cords[j + 1]->getRow());
             
                cords[j + 1]->setCol(col);
                cords[j + 1]->setRow(row);
        
             
             }
         }
     }
 }