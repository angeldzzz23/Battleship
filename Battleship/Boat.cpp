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
//     strcpy(name,"boat"); gave ne =
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
 bool Boat::cordHshit(Coordinate c) { // Checks if that specific cordinate has been hit
     
     for(int i=0;i<hsize;i++){
        if(hits[i]== &c) {
             return true; 
        }   
    }
    return false;
    
 }
   
 // FIX: 
 // make that you cannot add more than the ship size
 void Boat::setHit(Coordinate hit) { // initializez the hit with a a cord
     // if cordinate has not been hit
        // we add we a cordinate into our cordinate array 
     if (!cordHshit(hit)) {
         if (hsize==0) {
             hits[0]= &hit;
             hsize++;
         } else {
             hits[hsize] = &hit;
             hsize++;
         }
     }
   }  
 
 // checks if the boat has already been added
 bool Boat::cordHsadd(Coordinate c) {
     for(int i = 0; i<csize;i++) {
       // returns true if it is in the codinate array 
//         if (cordinate[i]== &c) {
//           return true;
//       }
     }
     // return false if it is not in the corddinate array
     return false;
 }
 
 // adds a cordinate into our boat cordinate 
 // make this cleaner later 
 // FIX: 
 // make that you cannot add more than the ship size
 void Boat::addCord(Coordinate cord) {   
     std::cout << "here we are" << std::endl;
     
     
     if(!cordHsadd(cord)){
        if(csize==0){
            cordinate[0]=&cord;
            csize++; 
        }else{
            cordinate[csize]=&cord; 
            csize++; 
        }
    }
     
     // 
     std::cout<<"cordinates in the array" << std::endl;
     for (int i = 0; i <csize;i++) {
         std::cout <<"row: " <<cordinate[i]->getRow() << " col " << cordinate[i]->getCol() << std::endl;
     }
 }