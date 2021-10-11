/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AIPlayer.h
 * Author: rianc
 *
 * Created on October 9, 2021, 6:44 PM
 */
#include "User.h"
#include "Boat.h"
#include "Coordinate.h"

#ifndef AIPLAYER_H
#define AIPLAYER_H

class AIPlayer: public User {
    private:
        Coordinate RNGCoords(Boat*); //RNG coords for each boat
    public:
        AIPlayer(); //Creates an AI player + 5 boats + RNG coords per boat
        ~AIPlayer(); // Deletes all boat/coord arrays and AI player
        
};

#endif /* AIPLAYER_H */

