/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Battleship.h"
#include <iostream>

using namespace std;



Battleship::Battleship(GameType gmetype) {
    myBoardOne = new Board();
    enemyBoardOne = new Board();
    
    myBoardTwo = new Board();
    enemyBoardTwo = new Board();
    
    
// if (gmetype == twoPlyr)  {
//     cout << "a two player game" << endl;
//     // create two new users
//     
//     
// } 
// else if (gmetype == AIGme) {
//    
// }
    
}

void Battleship::takeShot(User* n, Coordinate* cor) {
    
    // if userOne took the shot 

    if (*n == *userOne ) {
          // we check if it is the userTwo contains that hit 
        if (userTwo->isHitb(cor)) {
           // we hit the boat that has that specific coordinate
           // we dont 
            userTwo->adHit(cor);
        } 
        // we dont do anything if it is not a hit 
        
    } 
    else if (*n == *userTwo) {
        cout << "userTwo" << endl;
        
        if (userOne->isHitb(cor)) {
           // we hit the boat that has that specific coordinate
           // we dont 
            userOne->adHit(cor);
        } 
        
    }
    
//    if (n->isHitb(cor)) {
//        std::cout << "it is a hit" << std::endl;
//    } else {
//     std::cout << "Not a hit" << std::endl;
//    }
//    
}

// might want to loop through playerOne and get all of its things
  void Battleship::setPlayerOne(User* u) {
      // loop through 
      userOne = u;
        
  }
  
  
  // might want to loop through playerTwo and get all of its things 
  void Battleship::setPlayerTwo(User* u) {
      userTwo = u;// make them both point to the same things
  }