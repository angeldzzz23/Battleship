/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Destroyer.h
 * Author: AZ
 *
 * Created on September 27, 2021, 2:03 PM
 */

#ifndef DESTROYER_H
#define DESTROYER_H

#include "AbsBoat.h"

// destoyers have a size int 
class Destroyer: public AbsBoat {
    public: 
        Destroyer(); // We might want to add cordinates on our constructor 
        virtual ~Destroyer();
       int reqsz() const  {return 2; }; // the requirement of every boat size. 
       int getSize() const {return size;}; // the current size of the boat 
        bool cordHshit(Coordinate); // check if the cordinate has been hit
         void setHit(Coordinate *hit);  // initializez the hit with a a cord
};


#endif /* DESTROYER_H */

