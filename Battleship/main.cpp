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
#include <string>

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


// method to translate the prompt to coordinates
Coordinate** strTCo(string, int btsz); // takes in a coordinate A1 A2 A3 and returns coordinates (0,1), (0,1), (0,2)
//int Coordinate::cnvrtLet(char letter); // converts a character number to an integer 
                                       // convrting a character letter to a
//int  Coordinate::cnvrt(char digit);
 
   int cnvrtLet(char letter);
   int cnvrt(char digit);
   
int main(int argc, char** argv) {
    
    
    
//    Game game;
//    game.startGame();
// 
   
       
      string des = "a1 a2";
      Coordinate **dest2 = strTCo(des, 2); // reads two pos 
      Destroyer *de = new Destroyer();
      de->addCords(dest2); // testing adding a coordinate
      
      string sub = "b1 b2";
      Coordinate **sub1 = strTCo(sub, 3); // reads two pos 
      
      Submarine *subb = new Submarine();
      subb->addCords(sub1); // testing adding a coordinate
      
//      string crui = "c1 c2 c3";
//      Coordinate **crui1 = strTCo(crui, 3); 
//       de->addCords(crui1); // testing adding a coordinate
//      
//      string battl = "d1 d2 d3 d4";
//     Coordinate **battl1 = strTCo(battl, 4); 
//     
//       string carry = "e1 e2 e3 e4 e5";
//     Coordinate **carr = strTCo(carry, 5); 
      
      
      
//      for (int i = 0; i < 5; i++) {
//          cout << "row " << carr[i]->getRow() << " col " << carr[i]->getCol() << endl;
//      }
//      
   
      
         
    return 0;
}


Coordinate** strTCo( string strC, int btsz) {
    string inSCrd[10]; // individual string coordinates
    int totInx = 0;
    string str; // adding elements here and then adding them into inSCrd
    
    for (int i = 0; i < strC.length(); i++) {
        
        if (isdigit(strC[i]) && !isdigit(strC[i + 1])) { // checks if it is a digit
          str += strC[i]; // this completes the entire  letter
          inSCrd[totInx] = str; 
  
          totInx++; // incrementing sz of this 
          str.clear(); // clears the string 
          
          continue;
        } 
        
        if (strC[i] == ' ') { // we read an empty space
            continue;
        }
          str += strC[i];     
    }
      
    // get the sze of the boats 
    Coordinate **cords = new Coordinate*[btsz];
    int s = 0; // size of the coordinate 
    
     int row;
     int col;
     
     for (int i = 0; i < totInx; i++) {
         // length > 3
         if (inSCrd[i].length() == 3) { // there is a letter and a 10 
             string cop = inSCrd[i]; // the copy of the 
             row =  cnvrtLet(cop[0]); // convert the letter into a digit 
             col = 9; // converts the col to 9
             cout << " " << row << " " << col << endl;
             Coordinate *cord = new Coordinate(row, col);
             cords[s] = cord;
             s += 1;
         } else { // a letter and a digit that is 1 through 10
             string cop = inSCrd[i];
             row = cnvrtLet(cop[0]); // get the first letter 
             col = cnvrt(cop[1]); // converts the col 
             
             Coordinate *cord = new Coordinate(row, col);
             cords[s] = cord;
             s += 1;
         }
      
     }
      
      
        
    return cords;
}

   int cnvrt(char digit) {
     if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
      }
     
      //compensate if 0 is input
     if(digit=='0'){
         return digit-'0'; 
     }
      
    return digit-'0'-1;  
   }

// convert string to integer 
   int cnvrtLet(char letter) {
    
       switch(letter) {
           case 'a':
               return 0; 
           case 'b':
               return 1; 
           case 'c':
               return 2; 
           case 'd':
               return 3; 
           case 'e':
               return 4; 
           case 'f':
               return 5; 
           case 'g':
               return 6; 
           case 'h':
               return 7; 
           case 'i':
               return 8; 
          case 'j':
               return 9;
                           
       }

       return -1;
   }
