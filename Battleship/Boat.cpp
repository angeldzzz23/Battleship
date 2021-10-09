/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// this is an example of how we would create a a ship


#include "AbsBoat.h"
#include "Boat.h"
#include <iostream>

using namespace std;
// initializerr
// The initializer should probably take in the 
// TODO: might want to create another intiializer that takes in a size so that we can use in our other boat classes
// 
Boat::Boat() {
    
//     strcpy(name,"boat"); 
//    name = "boat"; FIX THIS
    csize=0; 
    hsize=0;
    dead=0;
    
    // create hits 
   // hits = new Coordinate*[reqsz()]; 
    // creates cordinate
   // cordinate = new Coordinate*[reqsz()];
    
}




// destructor
// This works with destroying other boats
Boat::~Boat() {
    
    cout << "dess" << csize << endl;
    
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
// returns true if the cordinate has been hit before 
 bool Boat::cordHshit(Coordinate *c) { // Checks if that specific cordinate has been hit
    // TODO:

     
     for(int i = 0; i <hsize; i++) {
//         cout << "hdhdhddh" << endl;
         if (hits[i]->getRow() == c->getRow() && hits[i]->getCol() == c->getCol()) {
             return true;
         }
        
     }
    return false;
    
 }
 // returns a hit coordinate 
 Coordinate* Boat::hcordAt(int i) {
     if (i >= hsize) {
         cout << "class boat-hcordaT: your index is out of bounds" << endl;
         exit(1);
     }
     return hits[i];
 }
 
 // retuns a cordAt
 Coordinate* Boat::cordAt(int i) {
     if (i >= csize) {
         cout << "class boat-cordAt: Your index is out of bounds." << endl;
         exit(1);
     }
     
     return cordinate[i];
 }
   
 // FIX: 
 // make that you cannot add more than the ship size
 void Boat::setHit(Coordinate *hit) { // initializez the hit with a a cord
     
     // if coordinate is not in the boat
     if (!cordHsadd(hit)) {
         cout << "the coordinate is not in the boat. what is wrong with you." << endl;
         exit(1);
     }
     
     if (cordHshit(hit)) {
         cout << "cordinate has been hit before, exiting the game " <<endl;
           for (int i = 0; i < hsize;i++) {
             cout <<"cord row " << hits[i]->getRow() <<" col " << hits[i]->getCol() << endl;
         }
         exit(1);
     }
     
     // cannot add more hits if the boat is already dead 
     if (hsize == reqsz()) {
         std::cout<<"you cant add more hits, boat is dead" << std::endl;
       
         exit(1);
     }
     // if cordinate has not been hit
        // we add we a cordinate into our cordinate array 
      hits[hsize]= hit;
      hsize++;
      
      
      if (hsize == reqsz()) {
         dead = true;  
         cout << "you boat is dead" << endl;
      }
 }  
 
 // checks if the boat has already been added
 // FIX ME: 
 // test that it works. 
 bool Boat::cordHsadd(Coordinate *c) {
     // TODO: 
     // return false if it is not in the corddinate array
     for(int i=0; i <csize;i++) {
         
         if (*cordinate[i] == *c) {
             return true;
         }
     }
     
     return false;
 }
 

 // adds a cordinate into our boat cordinate 
 // make this cleaner later 
 // FIX: 
    // make sure that you dont add more than required size cordinates.
    // fix the cordhadded function
 // make that you cannot add more than the ship size
 
 void Boat::addCord(Coordinate *cord) {   
    
     if (csize == reqsz()) {
         std::cout << "you have added way too many boats" <<std::endl;
         exit(1);
     }
     
     if (cordHsadd(cord)) {
         cout << "the coordinate has already been added in the boat. Please fix" << endl;
         exit(1);
     }
     
      cordinate[csize]= cord;
      csize++;

      
 }
 
 