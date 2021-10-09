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
    static int identifier = 0;
    identifier +=1;
    id = identifier;
    
    int brdsz = 100; // the size of the board 
    int boatszs = 5; // the total number of boats a user can add 
    int totHit = 5 + 4 + 3 + 3 + 2; // sz of Cruiser,battleship,sz of cruiser, sz sub, sz of dest
    int totMis = brdsz - totHit; // gets the tot misses the user can have 
    
    // initialize the sizes to zero
    boatsz = 0; // the number of boats the user currently has 
    hitsz = 0; // the size of the hits to zero
    missSz = 0; // set the missSz to zero
    
    
    // dynamically allocate memory for boat 
    boats = new Boat*[boatszs];
    // dynamically allocate memory for miss 
    misses = new Coordinate*[totMis];
    
    name = new char[81]; // dynamically allocate memory for the name 
    
 
}

// takes in a string, and the size of the string 
// dynamically allocate memory for this. 
void User::updNam(char *n, int sz) {
    // TODO
   // Angel - Comment for Lehr: I have experienced with C. 
    strcpy(name,n);
    
}

Coordinate* User::gtMiCrd(int i) {
    if (i >= missSz) {
        cout << "you are out of bounds" << endl;
        exit(1);
    }
    return misses[i];
}

 bool User::operator==(const User &usr) {
     if (this->id == usr.getId() ) {
         return true;
     }
     else {
         return false;
     }
     
 }

// The adding of boats 
// parameter: is a reference to a boat
// TODO: check if the function works for other boats 
void User::adBoat(Boat *boat) {
    if (boatsz < 5) {
        boats[boatsz] = boat;
        boatsz++;
    } else {
        std::cout << "YOU ARE ADDING MORE THAN FIVE BOATS" << std::endl;
        exit(0);
    }  
}


// updates the enemy board with the hit
// update the boat that
// adds the hit into the hits array 
// update: add hits into the boat 
void User::adHit(Coordinate *hit) {
  
   
   // loop through the boats and add the hit to that boat 
    for(int i = 0; i < boatsz; i++)  {
        Boat *cboat = boats[i]; // the current boat at index i  
        
        // check if the boat contains the cordinate 
        if (cboat->cordHsadd(hit)) {
            //  set the hit to the boats
            cboat->setHit(hit); 
        }         
    }
    
    hitsz += 1; // increment the number of hits the user has
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
}

Boat* User::getBoat(int i) {
    return boats[i];
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
    
    
    // loop thorugh misses and delete each instance of boat
     for(int i = 0; i <totMis;i++ ) {
        delete misses[i]; 
        misses[i] = NULL; 
    }
    
    // deleting the arrays 
    delete [] boats;
    delete [] misses;
    delete [] name; 
    
}





        
