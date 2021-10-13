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


// method to translate the prompt to coordinates
Coordinate** strTCo(string, int btsz); // takes in a coordinate A1 A2 A3 and returns coordinates (0,1), (0,1), (0,2)
//int Coordinate::cnvrtLet(char letter); // converts a character number to an integer
                                       // convrting a character letter to a
//int  Coordinate::cnvrt(char digit);

   int cnvrtLet(char letter);
   int cnvrt(char digit);
   Coordinate *strToSC(string sC);


int main(int argc, char** argv) {
    Prompt test;
    //test.hello();
    string feedme;
    feedme = test.getboatcoord(3);
    cout <<feedme <<endl;
    string shot;
    shot = test.getshotcoord();
    cout <<shot;
    return 0;
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

   // TODO: a input validation class
