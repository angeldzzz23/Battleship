/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boat.h
 * Author: AZ
 *
 * Created on September 26, 2021, 4:31 PM
 */

#ifndef BOAT_H
#define BOAT_H


// vertical 
// horizonal


class Boat {
    
private: 
    int size; 
    Coordinate *cordinate;  // the positions of the boat
    Coordinate *hit; // cordinates that have been hit 
public: 
    int reqsz(); // the requirement of every boat size. 
     int getSize() const; // the current size of the boat 
     bool cordHshit(Coordinate); // check if the cordinate has been hit
     void setHit(Coordinate *hit); 

};



#endif /* BOAT_H */

