/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// this is an example of how we would create a a ship


#include "AbsBoat.h"
#include "Boat.h"
#include <iostream>


// initializerr
// The initializer should probably take in the 
Boat::Boat() {
    name = "Boat"; 
    
    
}

// destructor
Boat::~Boat() {
    
}

 bool Boat::cordHshit(Coordinate) { // Checks if that specific cordinate has been hit
     return true;
 }
   
 
 void Boat::setHit(Coordinate *hit) { // initializez the hit with a a cord
       
   }  