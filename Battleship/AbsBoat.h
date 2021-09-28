/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbsBoat.h
 * Author: AZ
 *
 * Created on September 26, 2021, 4:43 PM
 */

#ifndef ABSBOAT_H
#define ABSBOAT_H

#include "Coordinate.h"

// We might want to create all the boats using this abstract class

class AbsBoat {
protected: 
    int size; // the current size of the boat 
    Coordinate *cordinate;  // the positions of the boat
    Coordinate *hit; // cordinates that have been hit 
    char *name; 
public: 
    virtual int reqsz() const = 0; // the requirement of every boat size. 
    virtual int getSize() const = 0; // the current size of the boat 
    virtual bool cordHshit(Coordinate) {return false;}; // check if the cordinate has been hit
    virtual void setHit(Coordinate *hit) {};  // initializez the hit with a a cord 
       
};


#endif /* ABSBOAT_H */

