/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Controller.h
 * Author: Admin
 *
 * Created on October 12, 2021, 11:55 PM
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

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
#include "NSFile.h"
#include "inptVal.h"
#include <map>


// this is in charge of updating the views
// and the game
class Controller {
 public:
  Controller(); // constructor
  int cnvrtLet(char letter); // converts letter to integer
  int cnvrt(char digit); // converts a digit to a letter
  void clearScreen(); // clears the screen DELTE THIS
  void gtUsrBts(User *user, Board* brd); // gets the user boats
  Coordinate** strTCo( string strC, int btsz); // converts a string to multiple coordinatrs
  Coordinate *strToSC(string sC); // converts  a string to a coordinate
  void updUsrViews(Board*Sbrd, Board *Ebrd, User* us1, User *us2);
  void gameController(); // the 2 player game
  void loadGame(); // load the games using NSfile 
  void saveGame(); // saves the game using NSfile
  void updNm(User* user, string usr); // helper to update the name
  void mnMnCntrl(); // the main menu control 
  // these are justt for printing purposes
  string gtuser1() {return "user1";} 
  string gtuser2() {return "user2";}
  
  
   // deconstructor: TODO
private:
    Display distt; // the display of the controller 
    Prompt prompt; // the prompt of the controller.. prompts the user for input 
    InptVal inptval; // displays input validation errors
    // user 1
    User *user1; // user model
    Board *brd;  // View 1 - displays the boats of user 1 and the hits and misses of user 2.
    Board *Sbrd; // view 2 -  containts the hits and misses of the user1
    // user 2 
    User *user2; // user model
    Board *brd2; // view 3 - has the boats of user2 and the hits and misses of user 1
    Board *Sbrd2; // view 4 -  contains the hits and misses of user2
    // creating users and boards
    void crtUsNBrd(); // allocates memory for all of the usr brd
    NSFile saveload; 
    string lfile; // the name of the file you are saving
    string sfile; // the name of the file you are 
    bool lgame; // load the game..initialize is set to false  
    
    void cleanUp(); // deallocates memory before a game has been started
};


#endif /* CONTROLLER_H */
