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
      usOnBrd = new Board(); // contains user one boats, and contains UserTwo hits and misses     
      usOnHS = new Board(); // contains hits and misses of user 
        
                
       
        usTwBrd = new Board(); // contains user two boats, and contains UserTwo hits and misses     
        usTwHS = new Board; // contains hits and misses of user 
   
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
  
  // 
  void Battleship::shotAttempt(User* usr, Coordinate * cord) {
      
      cout << "a shot has been attempted" << endl;
      
      if(*usr == *userOne) {
       
         
          if (userTwo->isHitb(cord)) {
              // add a hit in userTwo
              userTwo->adHit(cord);
              cout << "it is a hit" << endl;
          } else {
              userOne->adMiss(cord);
              // you add a miss in userOne
              cout << "it is not a hit" << endl;
          }
          
      } else if (*usr == *userTwo) {
        
          if (userOne->isHitb(cord)) { // add a hit in userOne
              cout << "a hit" << endl;
              userOne->adHit(cord);
          } else { // add a hit userTwo
              cout << "a miss" << endl;
              userTwo->adMiss(cord);
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


