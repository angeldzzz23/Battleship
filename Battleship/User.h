/* 
 * Author: Team #23232323
 * Created on Sept 28, 2021, 11:40 AM
 * Purpose: 
 *    
 */


#ifndef USER_H
#define USER_H

#include "AbsBoat.h"
#include "Board.h"
#include "Coordinate.h"
#include "Boat.h"


// each user will have a 5 boats 
class User {
  private:
    char *name; // the name of the user 
    int boatsz; // the size of the boat 
    Boat **boats;  // the boats that the user contains 
    int hitsz; // the size of the hits
    Coordinate **hits; // contains the hits you 
    int missSz; // the 
    Coordinate **misses;  
  
    // user board
    Board myBoard; // contains the location of your boats
                   // and the hits and misses of the enemy
        
    // enemy board
    Board enemyBoard; // contains your misses and hits.
                      // contains your misses.
                      // contains your hits.   
public: 
    User(); //initializes a user with a name
    void updNam(char *name, int sz);
    void adBoat(Boat boat); // adds a boat into the boat array 
    void adHit(Coordinate hit); // adds a hit into the boat array 
    void adMiss(Coordinate mis); // adds a cor
    ~User(); // destructor 
};

#endif /* USER_H */

// Helper information 
// for dealing with the abstract boats
// This is how you can create an array with different types of boats
//    Destroyer des1 = Destroyer();
//    Destroyer de2 =  fffefff();
//    Destroyer des3 = Destroyer();
//
//    AbsBoat *ss[10];
//    ss[0] = &des1;
//    
//    cout << ss[0]->reqsz() << endl;
//    
