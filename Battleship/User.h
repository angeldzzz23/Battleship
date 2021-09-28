/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.h
 * Author: AZ
 *
 * Created on September 26, 2021, 3:16 PM
 */

#ifndef USER_H
#define USER_H


#include "AbsBoat.h"
#include "Board.h"
#include "Coordinate.h"


class User {
  private:
    char *name; // the name of the user 
    AbsBoat *boats;  // the boats that the user contains 
    Coordinate *hits;  
    Coordinate *misses; 
   
    
    // user board
    Board myBoard; // contains the location of your boats
                   // and the hits and misses of the enemy
        
    // enemy board
    Board enemyBoard; // contains your misses and hits.
                      // contains your misses.
                      // contains your hits.   
public: 
    
    
};

#endif /* USER_H */

