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
#include "AIPlayer.h"


using namespace std;
//jOVANNY
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
                                       // convrting a character letter to a
Coordinate *strToSC(string sC);
Coordinate** strTCo( string strC, int btsz);
int cnvrt(char digit);
int cnvrtLet(char letter);
void updUsrViews(Board* Sbrd, Board *Ebrd, User* us1, User *us2);
void clearScreen();

int main(int argc, char** argv) {

//    Game game;
//    game.startGame();
    AIPlayer *AI = new AIPlayer();
    //User *AI = new User();
    
    Board *board = new Board();

    for (int i = 0; i < 5; i++) {
        board->adBoat(AI->getBoat(i));
    }
    
    
    User *user = new User();
    
    
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++)
//            cout << board->getElement(i, j) << " ";
//        cout << endl;
//    }
    /*Boat *testBoat = NULL;

    Coordinate *cord01 = new Coordinate(0,0);
    Coordinate *cord02 = new Coordinate(0,1);

    Coordinate *cord03 = new Coordinate(0,0);
    Coordinate *cord4 = new Coordinate(1,0);
    Coordinate *cord5 = new Coordinate(2,0);

    Coordinate *testCord = NULL;

    Destroyer *depp = new Destroyer();
    Submarine *sub = new Submarine();

    AI->adBoat(depp);
    AI->adBoat(sub);

    cout << "Adding Destroyer\n";
    depp->addCord(cord01);
    depp->addCord(cord02);


    cout << "Adding Submarine\n";
    sub->addCord(cord03);
    sub->addCord(cord4);
    sub->addCord(cord5);
    //for (int i = 0; i < AI->gtTotBtsz(); i++)
        if (!AI->bIsNotTaken(cord01))
            cout << "taken sorry\n";

    cout << "added\n";

    for (int i = 0; i < 2; i++) {
        testBoat = AI->getBoat(i);
        cout << "testBoat " << i << endl;
        cout << AI->getBoat(i)->cordAt(0)->getRow() << " " << AI->getBoat(i)->cordAt(0)->getCol()<< endl;
        board->adBoat(AI->getBoat(i));
        cout << "testBoat added " << i << endl;
    }

    cout << "board\n";*/

    

//    // boat 1
    Coordinate *cord01 = new Coordinate(4,0);
    Coordinate *cord02 = new Coordinate(4,1);

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


    Destroyer *des = new Destroyer();
    des->addCord(cord01);
    des->addCord(cord02);

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
      
      
      user->adBoat(des);
      user->adBoat(sub);
      user->adBoat(cuucu);
      user->adBoat(battle);
      user->adBoat(carr);
      
      //Test hits
      Coordinate *hitCoord1 = new Coordinate(9, 5);
      Coordinate *hitCoord2 = new Coordinate(3, 3);
      Coordinate *hitCoord3 = new Coordinate(2, 0);
      Coordinate *hitCoord4 = new Coordinate(1, 1);
      
      user->adHit(hitCoord1);
      user->adHit(hitCoord2);
      user->adHit(hitCoord3);
      user->adHit(hitCoord4);
      
      //Test misses
      Coordinate *missCoord1 = new Coordinate(4, 3);
      Coordinate *missCoord2 = new Coordinate(1, 3);
      Coordinate *missCoord3 = new Coordinate(2, 3);
      Coordinate *missCoord4 = new Coordinate(3, 4);
      
      AI->adMiss(missCoord1);
      AI->adMiss(missCoord2);
      AI->adMiss(missCoord3);
      AI->adMiss(missCoord4);
      
      Coordinate *reCoord;
      for (int i = 0; i < 2000; i++) {
        reCoord = AI->makeAMove(user);
        if (*reCoord == *missCoord1  || *reCoord == *missCoord2 || *reCoord == *missCoord3 || *reCoord == *missCoord4)
            cout << "Duplicate found\n";
//        if (reCoord->getRow() == 1 && reCoord->getCol() == 1)
//            cout << "Kachow\n";
        cout << "reCoord " << reCoord->getRow() << " " << reCoord->getCol() << endl;
      }


    return 0;
}




// the string should be either of size 3 or size 2
// here I convert one coordinate for making a move
Coordinate *strToSC(string sC) {
    // you prompt class is doing something wrong
    if (sC.length() != 3 && sC.length() != 2) {
        cout << sC.length() << endl;
        cout << "length of string is not 2 or 3" << endl;
        exit(1);
    }

    //this
    Coordinate *cord = NULL; // set it to null

    // here im assuming the string i got is correct forma a1 or A1 or A10

    // it means user inputted a letter + 10
    if (sC.length() == 3) {
        // we know the col is ten since size is 3
        // letter is the first character
        cord = new Coordinate(cnvrtLet(sC[0]), 9);


    } else if (sC.length() == 2) { // ther user inputted a letter and a

        cord = new Coordinate(cnvrtLet(sC[0]),cnvrt(sC[1]));
//        return new Coordinate(cnvrtLet(sC[0]),cnvrt(sC[1]));
    }




    return cord;
}

// TODO:
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


//       switch(digit) {
//           case '1':
//            return 0;
//           case '2':
//                return 1;
//           case '3':
//              return 2;
//           case '4':
//              return 3;
//           case '5':
//             return 4;
//           case '6':
//              return 5;
//           case '7':
//               return 6;
//           case '8':
//               return 7;
//          case '9':
//               return 8;
//
//       }




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

   // update the views of user1
   void updUsrViews(Board* Sbrd, Board *Ebrd, User* us1, User *us2) {
       // you get the misses from user 1 and update it's board
       Sbrd->upmss(us1->gtmiss(), us1->gtTotmiSz());

       // update the user 1 hits into Sbr
       // user 1 hits are located in user2 boats
       Sbrd->upHts(us2->gtboats(), us2->gtTotBtsz());


       Ebrd->upmss(us1->gtmiss(), us1->gtTotmiSz());
       Ebrd->upHts(us2->gtboats(), us2->gtTotBtsz());

   }



   // TODO: a input validation class
   void clearScreen() {
       cout << string(100,'\n');
   }
