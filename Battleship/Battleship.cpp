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
          cout << "user 1" << endl;
         cout << userTwo->gtTotBtsz() <<endl;
         
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
          cout << "user 2 " << endl;
          if (userOne->isHitb(cord)) { // add a hit in userOne
              cout << "it is a hit" << endl;
          } else { // add a hit userTwo
              cout << " it not a hit" << endl;
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


// Game details: 
// Quitting
    // users can quit at any time of the game
    // if users quit, we ask them if they want to save
        // we save and then quit the game
    // the next time the user enters a two player game. We ask them if they want to continue playing the game
// Game details 
    // Each user enters five boats 
    // user 1 gets to choose the coordinates first. 
    // we keep on letting a user choose cordinates until they get a miss 
        // we display both the user's boards (each user has two boards)
        // ask user for correct input. 
        // if the user got a correct, we ask again. 
        // if the user got an incorrect input, we aks the next user 
    // 
        

//void Battleship::startTwoPlayer() {
    
    // we can display a small menu for the user 
        // let them know that they can quit the game at any time and that they can save 
    
    // get the name of user 1
        // create a delay for user 2 to press so that they can pick their name
    // get the name of user 2 
    
    // create a delay for user 1 to press so that they can pick their boats
    
    // get the boats for user one
        // there are around ___ boats
        
    // create a delay for user 2 to press so that they can pick their board
    
    // get the boats for user 2
    
    
    // Here is where we will get input from the user 
    
    
//}


// TODO
// Similar process as the other one 

