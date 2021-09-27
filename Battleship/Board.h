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
#include "Boat.h"

class Board{
private:
    char **board; // the board 
public:
    void update(*Boat);
    void upHts(*Coordinate);
    
    void update(*Coordinate);
};


#endif /* BOARD_H */

