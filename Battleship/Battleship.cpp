/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// thethe actual battleship game 

#include "Battleship.h"
#include <iostream>

using namespace std;


 // if user user wants to quit, we ask they if they want to save the current game. 

// TODO
// my constructor 
Battleship::Battleship(int gameType) {
    // figure out the game type 
    

}

 // we set the user one
// takes user pointer as paramater
 void Battleship::setUserOne(User* user) {
    // point userOne to user
     userOne = user;
     
     
 }
 
 // we set the user two
 // takes user pointer as paramater
  void Battleship::setUserTwo(User* user) {
      // pointer userTwo to user
      userTwo = user;
  }
  
  // returns the winner of the game
  User* Battleship::getWin() {
      
      if (userTwo->alBrDead()) {
          return userTwo; // returns the userTwo that one
      }
    
      if (userOne->alBrDead()) {
          return userOne; // returns the userOne that one
      }
      
      
      return userTwo;
  }
  
  // TODO: fix the bug for when the user enters a hit twice 
  // a failed shot attempt happens when a user enters the same 
  void Battleship::shotAttempt(User* usr, Coordinate * cord) {
      
      cout << "a shot has been attempted" << endl;
      
      if(*usr == *userOne) {
       
          if (userTwo->isHitb(cord)) {
              // add a hit in userTwo
              userTwo->adHit(cord);
              cout << "it is a hit" << endl;
              
          } else if (userOne->isMisB(cord)) {
            
              userOne->adMiss(cord);
              // you add a miss in userOne
              cout << "it is not a hit" << endl;
          } else if (!(userOne->isMisB(cord))) {
              cout << "it is repeated because it is repeated" << endl;
          } 
          
      } else if (*usr == *userTwo) {
        
          if (userOne->isHitb(cord)) { // add a hit in userOne
              cout << "a hit" << endl;
              userOne->adHit(cord);
          } else if (userTwo->isMisB(cord)) { // add a hit userTwo
              cout << "a miss" << endl;
              userTwo->adMiss(cord);
          } else if (!(userTwo->isMisB(cord))){
              cout << "it is repeated!!!!!" << endl;
          }
      }
  }
  
  // returns true if either userone or usertwo has all boats dead
  bool Battleship::gameIsOver() {
      // loop thoru
      // return true if all boats are dead
      if (userTwo->alBrDead()) {
          return true;
      }
    
      if (userOne->alBrDead()) {
          return true;
      }
      
      return false; 
   }
  
  // deletes the user 
  Battleship::~Battleship() {
      delete userTwo; 
      delete userOne;
      
      userTwo = NULL;
      userOne = NULL;
      
  }


