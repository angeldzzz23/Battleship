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
 * V3 add two users as parameters for the readingame function, and hooked up saved boat data to read into the users
 * V4 - Due to not being to save boat data directly, need to create own boat structures that can hold all the necessary information, and hook them up (WIP)
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
struct coordin{
    int row;
    int col;
};

struct destroye{
    coordin position[2];
    coordin hits[2];
    bool dead;
};

struct cruise{
    coordin position[3];
    coordin hits[3];
    bool dead;    
};

struct submarin{
    coordin position[3];
    coordin hits[3];
    bool dead;    
};

struct battleshi{
    coordin position[4];
    coordin hits[4];
    bool dead;    
};

struct carrie{
    coordin position[5];
    coordin hits[5];
    bool dead;    
};

struct usersave{ //this one will hold individual users
    bool isturn;//for saving who's turn it is
    
    //copy pasted from user class
    int id; // the identifier of a user
    //char *name; // the name of the user 
    int missSz; // the size of the misses array  
    int hitsz; //size of the hits array
    //Coordinate **misses; //the miss array 
    
    //all of the boat structures for hold their information
    destroye destroy;
    cruise cruisee;
    submarin sub;
    battleshi battle;
    carrie carr;

    //fill in with the necessary data fields from user, boat, etc.
};

struct gamesave{ //this one will hold both users who are playing together - thus all the information can be extracted from one super structure
    int index; //index for the game
    usersave player1; //holds the stats of player one
    usersave player2;    //holds stats of player 
    
};


class NSFile {
private:
    gamesave gamesaver; //temp gamesave struct for saving to a file
    gamesave gameloader;//temp gamesave struct for loading from a file
    Coordinate **transferdes; //transfering information back into the game
    Coordinate **transfersub;
    Coordinate **transfercruise;
    Coordinate **transferbattle;
    Coordinate **transfercarr;
public:
    NSFile();
    void savethegame(User*, User*);//for saving a game - takes in two user as the parameters
    void readingame(User*, User*);//for recalling a game
};

#endif /* NSFILE_H */

