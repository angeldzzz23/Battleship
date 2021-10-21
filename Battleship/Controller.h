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
   int cnvrtLet(char letter);
   int cnvrt(char digit);
   void clearScreen(); // clears the screen
   void gtUsrBts(User *user, Board* brd);
  Coordinate** strTCo( string strC, int btsz);
  Coordinate *strToSC(string sC);
  void updUsrViews(Board*Sbrd, Board *Ebrd, User* us1, User *us2);
  void gameController();
  void mnMnCntrl(); // the main menu control 
  string gtuser1() {return "user1";}
  string gtuser2() {return "user2";}
  
   // deconstructor: TODO
private:
    Display distt; // the display of the controller 
    Prompt prompt; // the prompt of the controller.. prompts the user for input 
    InptVal inptval; // displays input validation errors
};


#endif /* CONTROLLER_H */
