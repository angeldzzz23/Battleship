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

class AIPlayer : public User {
    private:
        //bool saveSmartHit = false; //AI should not start off with a smart hit
    public:
        //Coordinate* smartMove(Coordinate*);
        //void setSmartHit(bool);
        //bool getSmartHit() {return saveSmartHit;}
        void RNGCoords(Boat*);
        bool checkPrevMoves(Coordinate*, User*);
        Coordinate* makeAMove(User*, Coordinate*);
        AIPlayer();
};

#endif /* AIPLAYER_H */

