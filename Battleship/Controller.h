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
   // deconstructor: TODO
private:

};


#endif /* CONTROLLER_H */
