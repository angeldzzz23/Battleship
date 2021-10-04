/* 
 * Author: Team #23232323
 * Created on Sept 28, 2021, 11:40 AM
 * Purpose: 
 *    
 */

#ifndef ABSBOAT_H
#define ABSBOAT_H

#include "Coordinate.h"

// We might want to create all the boats using this abstract class
class AbsBoat {
protected: 
    int csize; // the current size of the boat
    int hsize; // the current size of hits
    int size; // the current size of the boat 
    Coordinate **cordinate;  // the positions of the boat 
    Coordinate **hits; // cordinates that have been hit 
    char *name; 
public: 
    virtual int reqsz() const = 0; // the requirement of  boat size. When we initialize a boat we want to make sure that reqsz is the same as the size of *cordinate
    virtual int getSize() const = 0; // the current size of the boat 
    virtual bool cordHshit(Coordinate) {return false;} // check if the cordinate has been hit
    virtual void setHit(Coordinate *hit) {};  // initializez the hit with a a cord 
                                              // we might need a a function to set the name
    
};

// TODO 
// Abstract boat ->  boat -> DifferentBoats
// Use an array of boats to include differentboats

#endif /* ABSBOAT_H */

