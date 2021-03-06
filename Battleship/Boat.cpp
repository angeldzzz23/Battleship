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

// the constructor 
Boat::Boat() {
    
//     strcpy(name,"boat"); 
    csize=0;  // set the coordinate size to zero 
    hsize=0; // set the hit size to zero
    dead=0; // sets the boolean to zero 
    
}




// destructor
// This works with destroying other boats
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

    csize=0;  // set the coordinate size to zero 
    hsize=0; // set the hit size to zero
    dead=0; // sets the boolean to zero 

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
 // TODO: figure out why this fails in the ai 
 Coordinate* Boat::hcordAt(int i) {
     if (i >= hsize) {
         cout << "class boat-hcordaT: your index is out of bounds" << endl;
         exit(1);
     }
     return hits[i];
 }
 
 // retuns a cordAt
 // TODO: figure out why this fails in the ai 
 Coordinate* Boat::cordAt(int i) {
//     if (i >= csize) {
//         cout << "class boat-cordAt: Your index is out of bounds." << endl;
//         exit(1);
//     }
     
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
 
 // checks if the coordinates entered are a good match 
 // use this when you have the reqsz of a boat 
 // TODO: make it so that it exits when a child reqsz() != size
  bool Boat::alCords(Coordinate** cord, int size) {
      // if there is only one element in the array, then it is a match 
      if (size == 1) {
          return true;
      }
       
      // if the size is less than or equal 0 
      if (size <=  0 ) {
          cout << "array not big enough" << endl;
          return false;
      }
      
      // you get the row and the col
      int row = cord[0]->getRow();
      int col = cord[0]->getCol();
      
      bool rrow = true;
      bool rcol = true;
     
     
      // check if they all have the same row 
      // sets if rrow to false if at least one element doest not have the same row 
      for (int i = 0; i < size; i++) {
          // comparing the row element to the entire 
          if (row != cord[i]->getRow()) {
             rrow = false; //sets rrow to false 
          }
      }
      
     
     // checks if they all have the same col 
     // make sure they all have the same col 
      for (int i = 0; i < size; i++) {
          if (col != cord[i]->getCol()) {
              rcol = false;
          }
      }
       
      // all of them have the same row and same col
      if (rcol && rrow) {
          return false; 
      }
      
      // check if there are any duplicates 
        for (int i = 0; i < size; i++) {
     
          for (int j = i+1; j < size; j++) {
              cout << endl;
              if (*cord[i] == *cord[j]) {
                   return false; // returns false 
              }
          }
      }
      
      // do the row case
     
      if (rrow) { 
         // we sort the cordinate by their row element (smallest to largest)
         // we subtract cord[i + 1] - cord[i] to check they all have a col distance of one
        rSort(cord, size);  // 
        for (int i = 0; i < size-1; i++) {
           if (cord[i+1]->getCol() - cord[i]->getCol() != 1) {
              rrow = false;
          }           
        }
      
        return rrow;
      } else if (rcol) {   // do the col case
         
         // we sort the cordinate by their row element (smallest to largest)
         // we subtract cord[i + 1] - cord[i] to check they all have a row distance of one
        sort(cord,size); // sort by col 
       // check if they all have a difference of one 
      for (int i = 0; i < size-1; i++) {
          if (cord[i+1]->getRow() - cord[i]->getRow() != 1) {
              cout << "no distance of one" << endl;
              rcol = false;
          }
        }
        
        return rcol; 
      }
      // still need to check this 
      return false;
      
  }
 
 
 // Sorting based on rows 
 void Boat::rSort(Coordinate** cords, int size) {  // sorts based on the
     int row; // used for swapping
     int col; // used for swapping
     for (int i =0; i < size-1; i++) {
         for (int j = 0; j < size-i-1; j++) { 
             if (cords[j]->getRow() > cords[j + 1]->getRow()) {
                 // swapping - 
                 row = cords[j]->getRow();
                 col = cords[j]->getCol();
       
                 cords[j]->setCol(cords[j + 1]->getCol());
                 cords[j]->setRow(cords[j + 1]->getRow());
             
                cords[j + 1]->setCol(col);
                cords[j + 1]->setRow(row);
             }
         }
     }  
 }

 // adds a cordinate into our boat cordinate 
 // make this cleaner later
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
 
 // TODO: 
  void Boat::addCords(Coordinate **n, int size) {
  
 }
 
 // TODO
 void Destroyer::addCords(Coordinate **n, int size) {
     
     if (size != reqsz()) {
         cout << "size is not required size" << endl;
         exit(1);
     }
     
     if (csize == reqsz()) {
         cout << "you cannot add more elements. Coordinate is full" << endl;
         exit(1);
     }
     
     // setting the pointers equal to each other 
     for (int i = 0; i < size; i++) {
         cordinate[i] = n[i];
     }
     
        csize = size; // the coordinate 
        
 }
 
 void Submarine::addCords(Coordinate **n, int size) {
 
     if (size != reqsz()) {
         cout << "size is not required size" << endl;
         exit(1);
     }
     
     if (csize == reqsz()) {
         cout << "you cannot add more elements. Coordinate is full" << endl;
         exit(1);
     }
     
     // setting the pointers equal to each other 
     for (int i = 0; i < size; i++) {
         cordinate[i] = n[i];
     }
     
        csize = size; // the coordinate 
 }
 
 void Cruiser::addCords(Coordinate **n, int size) {
   
     if (size != reqsz()) {
         cout << "size is not required size" << endl;
         exit(1);
     }
     
     if (csize == reqsz()) {
         cout << "you cannot add more elements. Coordinate is full" << endl;
         exit(1);
     }
     
     // setting the pointers equal to each other 
     for (int i = 0; i < size; i++) {
         cordinate[i] = n[i];
     }
     
        csize = size; // the coordinate 
       
 }
 
 void Battleshp::addCords(Coordinate **n, int size) {
    
     if (size != reqsz()) {
         cout << "size is not required size" << endl;
         exit(1);
     }
     
     if (csize == reqsz()) {
         cout << "you cannot add more elements. Coordinate is full" << endl;
         exit(1);
     }
     
     // setting the pointers equal to each other 
     for (int i = 0; i < size; i++) {
         cordinate[i] = n[i];
     }
     
        csize = size; // the coordinate 
 }
 
 void Carrier::addCords(Coordinate **n, int size) {
   
     if (size != reqsz()) {
         cout << "size is not required size" << endl;
         exit(1);
     }
     
     if (csize == reqsz()) {
         cout << "you cannot add more elements. Coordinate is full" << endl;
         exit(1);
     }
     
     // setting the pointers equal to each other 
     for (int i = 0; i < size; i++) {
         cordinate[i] = n[i];
     }
     
        csize = size; // the coordinate 
 }
  
  
  
 
 // sorts coordings - rows 
 void Boat::sort(Coordinate** cords, int size) {
     int row; // used for swapping
     int col; // used for swapping
     for (int i =0; i < size-1; i++) {
         for (int j = 0; j < size-i-1; j++) {
             
             if (cords[j]->getCol() > cords[j + 1]->getCol()) {
                 // swapping 
                 row = cords[j]->getRow();
                 col = cords[j]->getCol();
       
                 cords[j]->setCol(cords[j + 1]->getCol());
                 cords[j]->setRow(cords[j + 1]->getRow());
             
                cords[j + 1]->setCol(col);
                cords[j + 1]->setRow(row);
             }
         }
     }
 }
 
 