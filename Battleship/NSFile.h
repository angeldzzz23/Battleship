/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NSFile.h
 * Author: AZ
 *
 * Created on September 28, 2021, 11:03 AM
 */

#ifndef NSFILE_H
#define NSFILE_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include "AbsBoat.h"
#include "Boat.h"
#include "Coordinate.h"
#include "Board.h"
#include "User.h"

// TODO #1 come up with properties
// TODo #2 come up with definitions 
struct usersave{ //this one will hold individual users
    bool isturn;//for saving who's turn it is
    
    //copy pasted from user class
    int id; // the identifier of a user
    //char *name; // the name of the user 
    //int boatsz; // the size of the boats 
    //Boat **boats;  // the boats that the user contains 
    //int missSz; // the size of the misses array  
    //int hitsz;
    //Coordinate **misses; 
    //fill in with the necessary data fields from user, boat, etc.
};

struct gamesave{ //this one will hold both users who are playing together
    int index;
    usersave player1;
    usersave player2;    
};


class NSFile {
private:
    gamesave gamesaver; //for saving
    gamesave gameloader;//for loading

public:
    void savethegame();//for saving a game
    void readingame();//for recalling a game
};

#endif /* NSFILE_H */

