/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: AZ
 *
 * Created on September 26, 2021, 4:48 PM
 */

#ifndef BOARD_H
#define BOARD_H

#include "Coordinate.h"
#include "AbsBoat.h"

class Board {
private:
    char **board; // the board 
public:
    Board();
    void update(AbsBoat*, int size); // adds user boats into board
    void upHts(AbsBoat*, int size); // update the hits 
    void upms(AbsBoat*, int size); // update the misses 
    ~Board();
};

// we probably want something that checks if a full ship has been taken down.


#endif /* BOARD_H */

