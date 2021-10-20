/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BattleshipAI.h
 * Author: rianc
 *
 * Created on October 14, 2021, 11:00 PM
 */

#ifndef BATTLESHIPAI_H
#define BATTLESHIPAI_H

#include "Battleship.h"

class BattleshipAI : public Battleship {
    public:
        BattleshipAI();
        ~BattleshipAI();
        void AIBSshotAttempt(); //shotAttempt, but made to include AI
};

#endif /* BATTLESHIPAI_H */

