/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "User.h"
#include <iostream>
#include <string.h>

using namespace std;

// constructor 
User::User() {
    static int q = 0;
    int brdsz = 100; // the size of the board 
    int boatszs = 5; // the total number of boats a user can add 
    int totHit = 5 + 4 + 3 + 3 + 2; // sz of Cruiser,battleship,sz of cruiser, sz sub, sz of dest
    int totMis = brdsz - totHit; // gets the tot misses the user can have 
    
    // initialize the sizes to zero
    boatsz = 0; // the number of boats the user currently has 
    hitsz = 0; // the size of the hits to zero
    missSz = 0; // set the missSz to zero
    
    q+=1;
    // create identifier 
    id = q;
    // dynamically allocate memory for boat 
    boats = new Boat*[boatszs];
    // dynamically allocate memory for hits 
    hits = new Coordinate*[totHit];
    // dynamically allocate memory for miss 
    misses = new Coordinate*[totMis];
    
    name = new char[81]; // dynamically allocate memory for the name 
    
    // create a new board 
    myBoard = new Board();
    enemyBoard = new Board();
}

// takes in a string, and the size of the string 
// dynamically allocate memory for this. 
void User::updNam(char *n, int sz) {
    // TODO
   // Angel - Comment for Lehr: I have experienced with C. 
    strcpy(name,n);
    
}


// The adding of boats 
// parameter: is a reference to a boat
// TODO: check if the function works for other boats 
void User::adBoat(Boat *boat) {
    if (boatsz < 5) {
        boats[boatsz] = boat;
        boatsz++;
        myBoard->adBoat(boat); // updates the user board with the boat
    } else {
        std::cout << "YOU ARE ADDING MORE THAN FIVE BOATS" << std::endl;
        exit(0);
    }  
}

// checks if two users are the same 
  bool User::operator==(const User &c){
      
      if (this->id == c.getId() ) {
          return true; 
      }
      
      return false;
  }


// updates the enemy board with the hit
// update the boat that contains that cordinate 
// adds the hit into the hits array 
// update: add hits into the boat 
void User::adHit(Coordinate *hit) {
   hits[hitsz] = hit;  // 
   hitsz += 1; // increment the number of hits the user has
   enemyBoard->upHts(hit); // updates the htz of the enemy 
   
   // loop through the boats and add the hit to that boat 
    for(int i = 0; i < boatsz; i++)  {
        Boat *cboat = boats[i]; // the current boat at index i  
//        Coordinate **cords = cboat->getcordinates(); // the current cords 
        
        // check if the boat contains the cordinate 
        if (cboat->cordHsadd(hit)) {
          
            //  set the hit to the boats
            cboat->setHit(hit); 
        }
        
}
   
}


// adds the hits the enemy has made on your boats. 
 void User::adEnemyHt(Coordinate *hit)  {
     myBoard->upHts(hit); 
     
 }
 
 // adds the misses the enemy has made on your board.
 void User::adEnemyMs(Coordinate *mis) {
     // TODO: 
     myBoard->upms(mis);
 }
 

// returns true if the cordinate is a hit. 
// A
// this returns true of the user contains that cordinate 
// and if does not exist in the user hit array
bool User::isHit(Coordinate* cord) {  
    cout << hitsz<< endl;
     // loop through the hits array and make sure it hasnt been added yet.
    if (hitsz > 0) {
      
        for(int i = 0; i < hitsz; i++) {
            
         if (*hits[i] == *cord) {
                return false;
            }
       }
    }
    
    
    // loop through all boats
    // and check if it exists 
    for(int i = 0; i < boatsz; i++)  {
        Boat *cboat = boats[i]; // the current boat at index i  
        Coordinate **cords = cboat->getcordinates(); // the current cords 
        
        // loop through all the cordinates of the current boat 
        for (int j = 0; j < cboat->reqsz(); j++) {
            if (cords[j]->getCol() == cord->getCol() && cords[j]->getRow() == cord->getRow()) {
                cout << "here" << endl;
                return true;
            }
        }
    }
    
    return false; 
}


// loops through the boats 
// takes in a coordinate called cord
// returns true if a boat contains the cord and if the cord hasnt been hit yet. 
bool User::isHitb(Coordinate* cord) {
    // find the boat that contains that cordinate
    for (int i =0; i < boatsz; i++) {
        Boat *cboat = boats[i];
        // check if the boat contains the cordinate
        if (cboat->cordHsadd(cord)) {
            cout << "we are here" << endl;
            if (cboat->cordHshit(cord)) {
                return false;     
            } 
//            // returns true if
            return true;
        }
    }
    
    return false; 
}



// updates the enemyboard with the miss
void User::adMiss(Coordinate *mis) {
    misses[missSz] = mis;  // add the cordinate to our misses
    missSz += 1; // increment misses by one 
    enemyBoard->upms(mis); // 
}


// delete the instances allocated in the 
 User::~User() {
    int brdsz = 100; // the size of the board 
    int boatsz = 5; // the total number of boats a user can add 
    int totHit = 5 + 4 + 3 + 3 + 2; // sz of Cruiser,battleship,sz of cruiser, sz sub, sz of dest
    int totMis = brdsz - totHit; // gets the tot misses the user can have 
    
    // loop through boat and delete each instance of boat 
    for(int i = 0; i <boatsz;i++ ) {
        delete boats[i]; 
        boats[i] = NULL; 
    }
    
    // loop thorugh hits and delete each isntance hits 
     for(int i = 0; i <totHit;i++ ) {
        delete hits[i]; 
        hits[i] = NULL; 
    }
    
    // loop thorugh misses and delete each instance of boat
     for(int i = 0; i <totMis;i++ ) {
        delete misses[i]; 
        misses[i] = NULL; 
    }
    
    // deleting the arrays 
    delete [] boats;
    delete [] hits;
    delete [] misses;
    delete [] name; 
    
    // delete boards
    delete myBoard;
    delete enemyBoard;
}





        
