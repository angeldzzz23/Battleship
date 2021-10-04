/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "User.h"
#include <iostream>

// constructor 
User::User() {
    
    int brdsz = 100; // the size of the board 
    int boatsz = 5; // the total number of boats a user can add 
    int totHit = 5 + 4 + 3 + 3 + 2; // sz of Cruiser,battleship,sz of cruiser, sz sub, sz of dest
    int totMis = brdsz - totHit; // gets the tot misses the user can have 
    
    // initialize the sizes to zero
    boatsz = 0; // set the size of the boat to zeroo
    hitsz = 0; // the size of the hits to zero
    missSz = 0; // set the missSz to zero
    
    
    // dynamically allocate memory for boat 
    boats = new Boat[boatsz];
    // dynamically allocate memory for hits 
//    hits = new Coordinate[totHit];
    // dynamically allocate memory for miss 
//    misses = new Coordinate[totMis];

}

// takes in a string, and the size of the string 
void User::updNam(char *name, int sz) {
    // TODO
}


void User::adBoat(Boat boat) {
    
}

// adds a hit into the hit array
void User::adHit(Coordinate hit) {
    
}

void User::adMiss(Coordinate mis) {
    
}






        
