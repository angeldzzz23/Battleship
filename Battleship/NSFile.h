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
 * V4 - Due to not being to save boat data directly, need to create own boat structures that can hold all the necessary information, and hook them up 
 * V4.5 - Interim version - all the necessary boat information (hit arrays, miss arrays, etc.) are all there and accounted for
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

using namespace std;

//class inheritance does not work with binary files, so created structures to hold the necessary information to restart a game
struct coordin{//coordinate structure that holds a row and column
    int row;
    int col;
};

struct destroye{//destroyer structure to hold boat information - name is cut off to prevent confusion with actual destroyer class - same goes for rest of structure names
    coordin position[2];
    int hitsz;
    coordin hits[2];
    bool dead;
};

struct cruise{//cruiser structure to hold information
    coordin position[3];
    int hitsz;
    coordin hits[3];
    bool dead;    
};

struct submarin{//sub structure
    coordin position[3];
    int hitsz;
    coordin hits[3];
    bool dead;    
};

struct battleshi{//battleship structure
    coordin position[4];
    int hitsz;
    coordin hits[4];
    bool dead;    
};

struct carrie{//carrier structure
    coordin position[5];
    int hitsz;
    coordin hits[5];
    bool dead;    
};

struct usersave{ //this one will hold individual users
    bool isturn;//for saving who's turn it is
    
    //copy pasted from user class
    int id; // the identifier of a user
    char* name; // the name of the user 
    int missSz; // the size of the misses array  
    int hitsz; //size of the hits array
    coordin misses[83]; //the miss array 
    
    //all of the boat structures for hold their information
    destroye destroy;
    cruise cruisee;
    submarin sub;
    battleshi battle;
    carrie carr;
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
    Coordinate **transferdes; //transferring coordinate information back into the game from the destroyer structure
    Coordinate **transfersub;
    Coordinate **transfercruise;
    Coordinate **transferbattle;
    Coordinate **transfercarr;
public:
    NSFile();
    void savethegame(User*, User*);//for saving a game - takes in two user as the parameters
    void readingame(User*, User*);//for recalling a game
    ~NSFile();
};

#endif /* NSFILE_H */

