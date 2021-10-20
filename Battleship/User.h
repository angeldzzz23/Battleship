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
  protected:
    int id; // the identifier of a user
    char *name; // the name of the user
    int boatsz; // the size of the boats
    Boat **boats;  // the boats that the user contains
    int missSz; // the size of the misses array
    Coordinate **misses;  // constains
    int hitsz;
//    Coordinate **hits;
public:
    User(); //initializes a user with a name
    void updNam(char *n, int sz); // updates the name of the user
    void adBoat(Boat *boat); // adds a boat into the boat array and int myBoard
    void adHit(Coordinate *hit); // adds user hits into enemyBoard
    void adMiss(Coordinate *mis); // adds user misses into enemyBoard
    char *gtName() {return name;} // returns the name of the user
    bool isHitb(Coordinate*); // returns true if the cordinate exist but it is not contained in the hits array
    // for printing a user board use the these two functions
    Boat* getBoat(int i); // returns a boat at a specific index
    Boat** gtboats() {return boats;} // returns an array of all the boats
    int gtTotBtsz() { return boatsz;} // get the total boat size
    int gtTotmiSz() {return missSz; } // returns the total missSz
    Coordinate* gtMiCrd(int i); // get the miss coordinate
    int getId() const {return id;} // returns the id of the user
    bool operator==(const User &); // operator overload
    bool isMisB(Coordinate *cord); // checks if a coordinate is a miss
    bool bIsNotTaken(Coordinate* cord); // returns true if coordinate cord DNE in boats
    bool CrdsNotTaken(Coordinate** cord, int size); // returns true if all of the coordinates DNE exist in boats
    bool hboat(Boat*); // returns true if the user contains the boat
    bool alBrDead();   // return true if all the boats are dead
    Coordinate** gtmiss() {return misses;} // gets the misses of the boat
    int gthtSz() {return hitsz;} // gets the size of the boat
    int reqBSz() {return 5;} // the amount of boats a user can have


    ~User(); // destructor
};

#endif /* USER_H */
