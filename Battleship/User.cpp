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
    // dynamically allocate memory for hits 
    hits = new Coordinate*[totHit];
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


// The adding of boats 
// parameter: is a reference to a boat
// TODO: check if the function works for other boats 
void User::adBoat(Boat *boat) {
    if (boatsz < 5) {
        boats[boatsz] = boat;
        boatsz++;
        myBoard.adBoat(boat);
    } else {
        std::cout << "YOU ARE ADDING MORE THAN FIVE BOATS" << std::endl;
        exit(0);
    }
    
    std::cout << "size of boat: " << boatsz << std::endl;
    for (int i = 0; i < boatsz; i++) {
        std::cout <<boats[i]->nameOfBoat() << std::endl;
    }

    // update the user board class 
    
    
}

// adds a hit into the hit array
void User::adHit(Coordinate *hit) {
  
   hits[hitsz] = hit;  // 
   hitsz += 1; // increment the number of hits the user has
   // myBoard.upHts(hit);
   enemyBoard.upHts(hit); // updates the htz of the enemy 
 
}

// returns true if the cordinate is a hit. 
bool User::isHit(Coordinate* cord) {
    cout << "is hit function is called" << endl; 
    // loop through all boats
    for(int i = 0; i < boatsz; i++)  {
        Boat *cboat = boats[i]; // the current boat at index i  
        Coordinate **cords = cboat->getcordinates(); // the current cords 
        
        // loop through all the cordinates of the current boat 
        // TODO: == is still not working for some odd reason
        for (int j = 0; j < cboat->reqsz(); j++) {
//            cout << cords[j]->getCol             
            if (cords[j]->getCol() == cord->getCol() && cords[j]->getRow() == cord->getRow()) {
                cout << "here" << endl;
                return true;
            }
        }
    }
    
    
    //boatsz; // the size of the boat 
     //**boats;  // the boats that the user contains 
    
    return false; 
}


void User::adMiss(Coordinate *mis) {
    misses[missSz] = mis;  // add the cordinate to our misses
    missSz += 1; // increment misses by one 
    //myBoard.upms(mis); // updates the misse
    enemyBoard.upms(mis); // 
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
}





        
