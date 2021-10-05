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
    int missSz; // the size of the misses array  
    Coordinate **misses;  // constains 
  
    // enemy board
    Board *enemyBoard; // contains your misses and hits.
                      // contains your misses.
                      // contains your hits.   
     
       // user board
    Board *myBoard; // contains the location of your boats
                   // and the hits and misses of the enemy
public: 
    
    
    User(); //initializes a user with a name
    void updNam(char *n, int sz); // updates the name of the user 
    void adBoat(Boat *boat); // adds a boat into the boat array 
    void adHit(Coordinate *hit); // adds user hits into enemyBoard
    void adMiss(Coordinate *mis); // adds user misses into enemyBoard
    void adEnemyHt(Coordinate *hit); // adds the hits the enemy has made on myBoard. 
    void adEnemyMs(Coordinate *mis); // adds the misses the enemy has made on myBoard.
    char *gtName() {return name;}
    bool isHit(Coordinate*); // return true if cordinate is a hit 
    // for printing a user board use the these two functions 
    char gtMBrdElmnt(int row, int col) { return myBoard->getElement(row, col); } // get my board element 
    char gtEnBrdElmnt(int row, int col) {return enemyBoard->getElement(row, col);} // get enemy board element
    int brdRow() {return myBoard->getrowsize();} // return a boards row  
    int brdCol() {return myBoard->getcolsize();} // returns a board's col
     
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
