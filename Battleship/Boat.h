/* 
 * Author: Team #23232323
 * Created on Sept 28, 2021, 11:40 AM
 * Purpose: 
 *    
 */

#ifndef DESTROYER_H
#define DESTROYER_H

#include "AbsBoat.h"
#include <iostream>
// we are subclassing the Absboat
// we will subclass all of our votes from general boat class
// This is a destroyer ship that should be initialized with cordinates 

class Boat: public AbsBoat {
    private: 
        void sort(Coordinate**, int ); // col sorts the coordinates 
        void rSort(Coordinate**, int ); // sorts based on the
    public: 
         Boat(); // We might want to add cordinates on our constructor 
                // we might want to create another constructor thae has an array of constructor 
        ~Boat();
       virtual int reqsz() const  {return 2; }; // the requirement of every boat size 
       virtual bool cordHshit(Coordinate*); // check if the cordinate has been hit
       virtual bool cordHsadd(Coordinate *c); 
       virtual void setHit(Coordinate *hit);  // initializez the hit with a a cord
       virtual void addCord(Coordinate*);    // Adds a cordinates
       virtual Type getType() {return type;}
       char* nameOfBoat() {return name;}
       // Check if cordinates added are
       bool alCords(Coordinate**, int size); // returns true if the coordinates of the boat fit our board. todo: Test more 
       bool isDead() {return dead;}
       Coordinate* cordAt(int i);
       Coordinate* hcordAt(int i); // returns a coordinate at index i  
       
};

class Destroyer: public Boat {
    public: 
        Destroyer() {
              type=dest;
            hits = new Coordinate*[reqsz()]; 
             // creates cordinate
            cordinate = new Coordinate*[reqsz()];
        }
     
        Type getType() {return type;}
        int reqsz() const  {return 2; }      
};

// TODO: find a better way to initialize an inherited constructor 

//boat=1,dest=2, sub=3, crui=3, battl=4, carr=5
class Submarine:public Boat {
    public:
        // constructor
        Submarine() {
            
            type=sub;
            // initialize 
        
             hits = new Coordinate*[reqsz()]; 
             // creates cordinate
            cordinate = new Coordinate*[reqsz()];
        }
         
        Type getType() {return type;}
        int reqsz() const {return 3;}
};


class Cruiser:public Boat {
    public:
        Cruiser() {
            type=crui;
            hits = new Coordinate*[reqsz()]; 
             // creates cordinate
            cordinate = new Coordinate*[reqsz()];
        }
        Type getType() {return type;}
        int reqsz() const {return 3;}
};


// the the battleship boat
class Battleshp:public Boat {
    public:
        Battleshp() {
            type=battl;
            hits = new Coordinate*[reqsz()]; 
             // creates cordinate
            cordinate = new Coordinate*[reqsz()];
        }
        Type getType() {return type;}
        int reqsz() const {return 4;}
};

// the the battleship boat
class Carrier:public Boat {
    public:
        Carrier() {
            type=carr;
            hits = new Coordinate*[reqsz()]; 
             // creates cordinate
            cordinate = new Coordinate*[reqsz()];
        }
        Type getType() {return type;}
        int reqsz() const {return 5;}
};

#endif /* DESTROYER_H */



