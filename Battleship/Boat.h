/* 
 * Author: Team #23232323
 * Created on Sept 28, 2021, 11:40 AM
 * Purpose: 
 *    
 */

#ifndef DESTROYER_H
#define DESTROYER_H

#include "AbsBoat.h"

// we are subclassing the Absboat
// we will subclass all of our votes from general boat class
// This is a destroyer ship that should be initialized with cordinates 

class Boat: public AbsBoat {
        
    public: 
        Boat(); // We might want to add cordinates on our constructor 
                     // we might want to create another constructor thae has an array of constructor 
       virtual ~Boat();
       int reqsz() const  {return 2; }; // the requirement of every boat size. 
       int getSize() const {return size;}; // the current size of the boat 
       bool cordHshit(Coordinate); // check if the cordinate has been hit
       void setHit(Coordinate *hit);  // initializez the hit with a a cord
       void addCord(Coordinate*);    // Adds a cordinate
       bool cordHsadd(Coordinate c);
       char* nameOfBoat() {return name;}
       Coordinate **getcordinates() {return cordinate;}
};


#endif /* DESTROYER_H */



