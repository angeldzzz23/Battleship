/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AIPlayer.h
 * Author: rianc
 *
 * Created on October 10, 2021, 6:41 PM
 */

#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Coordinate.h"
#include "Boat.h"
#include "User.h"
#include "Battleship.h"
#include "Board.h"

//enum Direction {north, east, south, west};

class AIPlayer : public User {
    private:
        bool checkPrevMoves(Coordinate*);
    public:
        void RNGCoords(Boat*);
        Coordinate makeAMove();
        AIPlayer();
        ~AIPlayer();
};

#endif /* AIPLAYER_H */

