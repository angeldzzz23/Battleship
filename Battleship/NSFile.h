/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NSFile.h
 * Author: AZ
 *
 * V1 create basic structures for storing data - do a couple test ones to ensure it works
 * V2 add two users as parameters for savethegame function, and have their data read into the gamesave structs
 * V3 - add two users as parameters for the readingame function, and have the data stored read into them
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

struct usersave{ //this one will hold individual users
    bool isturn;//for saving who's turn it is
    
    //copy pasted from user class
    int id; // the identifier of a user
    //char *name; // the name of the user 
    int boatsz; // the size of the boats 
    Boat* boats[5];  // the boats that the user contains - sidenote:Also contains the hit arrays and if they're dead
    int missSz; // the size of the misses array  
    int hitsz; //size of the hits array
    //Coordinate **misses; //the miss array 
    //fill in with the necessary data fields from user, boat, etc.
};

struct gamesave{ //this one will hold both users who are playing together - thus all the information can be extracted from one super structure
    int index; //index for the game
    usersave player1; //holds the stats of player one
    usersave player2;    //holds stats of player two
};


class NSFile {
private:
    gamesave gamesaver; //temp gamesave struct for saving to a file
    gamesave gameloader;//temp gamesave struct for loading from a file

public:
    void savethegame(User*, User*);//for saving a game - takes in two user as the parameters
    void readingame();//for recalling a game
};

#endif /* NSFILE_H */

