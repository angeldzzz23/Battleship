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
//     strcpy(name,"boat\0"); gave me a 
//    name = "boat";
    csize=0; 
    hsize=0; 
    
    // create hits 
    hits = new Coordinate*[reqsz()]; 
    // creates cordinate
    cordinate = new Coordinate*[reqsz()];
    
}

// destructor
Boat::~Boat() {
 
    // loop through hits
    for (int i =0; i < csize; i++) {
        delete hits[i]; // deletes reference
        hits[i] = NULL; // 
    }
    
    // loop through cordinates and delete things
    for (int i =0; i < csize; i++) {
        delete cordinate[i];
        cordinate[i] = NULL;
    }
    
    // deletes the hits 
    delete [] hits;
    // deletes the cordinates
    delete[] cordinate; 
}

// checks of a specific cordinate has been hit 
// you might need to specify a new parameter
 bool Boat::cordHshit(Coordinate c) { // Checks if that specific cordinate has been hit
    // TODO: FIX ME
    return false;
    
 }
   
 // FIX: 
 // make that you cannot add more than the ship size
 void Boat::setHit(Coordinate *hit) { // initializez the hit with a a cord
     // if cordinate has not been hit
        // we add we a cordinate into our cordinate array 
      hits[csize]= hit;
      hsize++;
      
      std::cout << "set hit called: " << std::endl;
      for(int i = 0; i < hsize; i++) {
          std::cout << hits[i]->getRow() << " " << hits[i]->getCol() << std::endl;
      }

 }  
 
 // checks if the boat has already been added
 // FIX ME: 
 // test that it works. 
 bool Boat::cordHsadd(Coordinate c) {
     // TODO: 
     // return false if it is not in the corddinate array
     return false;
 
 
 
 }
 

 // adds a cordinate into our boat cordinate 
 // make this cleaner later 
 // FIX: 
    // make sure that you dont add more than required size cordinates.
    // fix the cordhadded function
 // make that you cannot add more than the ship size
 
 void Boat::addCord(Coordinate *cord) {   
     
      cordinate[csize]= cord;
      csize++;
      
 }
 
 