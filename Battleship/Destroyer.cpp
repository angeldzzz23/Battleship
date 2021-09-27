/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
// this is an example of how we would create a a ship


#include "AbsBoat.h"
#include "Destroyer.h"
#include <iostream>

// initializerr
// The initializer should probably take in the 
Destroyer::Destroyer() {
    name = "Destroyer"; 
    
    
}

// destructor
Destroyer::~Destroyer() {
    
}

 bool Destroyer::cordHshit(Coordinate) { // Checks if that specific cordinate has been hit
     return true;
 }
   
 
 void Destroyer::setHit(Coordinate *hit) { // initializez the hit with a a cord
       
   }  