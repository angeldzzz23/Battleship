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
    
    // allocates memory for hits array 
//    hits =  new Coordinate*[totHit];

}

// returns false if the boat passed in the parameter does not exist in user
// returns true if they do have boat
bool User::hboat(Boat* boat) {
    if (boatsz == 0) {
        return false;
    }
        
    return true;
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

bool User::CrdsNotTaken(Coordinate** cord, int size) { // returns true if all of the coordinates DNE exist in boats
     
    for (int i = 0; i < size; i++) {
        // if it is taken 
        if (!bIsNotTaken(cord[i])) {
            return false;
        }
    }
    
    return true; // returns true 
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
    // if the boat has at least another coordinate of another boat 
  
      // debugging 
    if (boatsz == 5) {
        cout << "we got five boats" << endl;
        exit(0);
        
    }
   
    if (boatsz > 0) {
        for(int i = 0; i < boat->reqsz(); i++) {
            Coordinate *cord = boat->cordAt(i);
            if (!(bIsNotTaken(cord))) {                    
                    cout << "you cannot initialize boats with the same coordinate " << endl;
                    cout  <<cord->getRow() <<" " <<cord->getCol() <<endl;
                exit(1);
            }
        }
    }
    
    
    if (boatsz < 5) {
        boats[boatsz] = boat;
        boatsz++;
    } else {
        std::cout << "YOU ARE ADDING MORE THAN FIVE BOATS" << std::endl;
        exit(0);
    }  
    
}

// returns true if all of the boats in user are dead
 bool User::alBrDead() {
     if (boatsz != 5) {
         cout << "all boats cannot be dead. Please initialize all your boats" << endl;
         exit(1);
     }
     
     for (int i = 0; i < boatsz; i++) { // loop through all of the boats 
         Boat *cboat = boats[i]; // boat that specific index
         if (!cboat->isDead()) {
             return false;
         }
     }
     
     return true; 
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
//            hits[hitsz] = hit; // holds a reference to hit 
            hitsz += 1; // increment the number of hits the user has
        }         
    }
    
}


// loops through the boats 
// takes in a coordinate called cord
// returns true if a boat contains the cord and if the cord hasnt been hit yet. 
// returns false if the coordinate is a hit 
bool User::isHitb(Coordinate* cord) {
    // find the boat that contains that cordinate
    for (int i =0; i < boatsz; i++) {
        Boat *cboat = boats[i];
        // check if the boat contains the cordinate
        if (cboat->cordHsadd(cord)) {
            if (cboat->cordHshit(cord)) {
                return false;     
            } 
//            // returns true if the coordinate has been added and has not been hit 
            return true;
        }
    }
    // return false
    return false; 
}
bool User::bIsNotTaken(Coordinate* cord) {
    for (int i = 0; i < boatsz;i++) {
        Boat *cboat = boats[i];  // the boat at a specific index
        // checks if the coordinate has been added before 
        if (cboat->cordHsadd(cord)) { 
            return false;
        }

    }
    
    return true; // the coordinate does not exist 
}

// returns true if the coordinate is a miss
bool User::isMisB(Coordinate *cord) {
 
        
    // loop through our boats array and see if that coordinate exists 
    for (int i =0; i < boatsz; i++) {
         Boat *cboat = boats[i];
         // check if the boat contains the coordinate 
         if (cboat->cordHsadd(cord)) {
             return false;
         }
         
         if (cboat->cordHshit(cord)) {
             return false;
         }
         
         // check the misses array 
         
    }
    
    // loop thorugh your misses 
    for (int i = 0; i < missSz;i++) {
        if (*misses[i] == *cord) {
            return false;
        }
    }
     
    
    
    return true;
}


// updates the enemyboard with the miss
void User::adMiss(Coordinate *mis) {
    // check if the coordinate that has been hit
    // loop through you boars 
    // find the boat that contains that cordinate
    for (int i =0; i < boatsz; i++) {
        Boat *cboat = boats[i];
        // check if the boat contains the cordinate
        if (cboat->cordHsadd(mis) ) {
            cout << "here we are" << endl;
            // you know that is a duplicate 
            if (cboat->cordHshit(mis)) {
                cout << "You have already hit this coordinate. It cannot be missed" << endl;
                exit(1);
            } 
           
        }
    }
    
    
    misses[missSz] = mis;  // add the cordinate to our misses
    missSz += 1; // increment misses by one 
    cout << missSz<<endl;
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





        
