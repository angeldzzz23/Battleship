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
 * V5 - Switched from using a dynamic char array using a static one for the purpose of saving the usernames 
 * V6 - Make multi saving possible by allowing user to name their save files
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
struct coordin{//coordinate structure that holds a row and column - name is cut off to prevent confusion with Coordinate class
    int row; //saves the row integer
    int col; //saves the column integer
};

struct destroye{//destroyer structure to hold boat information - name is cut off to prevent confusion with actual destroyer class - same goes for rest of structure names
    coordin position[2]; //holds the coordinate data of positions 
    int hitsz; //how many hits are in the hits array
    coordin hits[2]; //the hits array  -set to the maximum number of hits that are possible on this boat
    bool dead; //if the boat is dead or not
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
    bool curruser;//for saving who's turn it is
    bool isAI;
    int id; // the identifier of a user    
    int missSz; // the size of the misses array  
    int hitsz; //the total size of the hits array
    char name[81]; //the username - 81 is size
    coordin misses[83]; //the miss array - max of 83 misses possible on a board so size is 83
    
    //all of the boat structures to hold their information
    destroye destroy;
    cruise cruisee;
    submarin sub;
    battleshi battle;
    carrie carr;
};

struct gamesave{ //this one will hold both users who are playing together - thus all the information can be extracted from one super structure
    usersave player1; //holds the stats of player one
    usersave player2;    //holds stats of player 
    
};


class NSFile {
private:
    gamesave gamesaver; //a gamesave struct for saving to a file
    gamesave gameloader;//a gamesave struct for loading from a file
    Coordinate **transferdes; //transferring information back into a destroyer class from the saved destroyer structure
    Coordinate **transfersub; //transferring information back into a submarine class from the saved submarine structure - same for the rest of these Coordinate class pointers
    Coordinate **transfercruise;
    Coordinate **transferbattle;
    Coordinate **transfercarr;
public:
    NSFile();
    void savethegame(User*, User*, string);//for saving a game - takes in two user as the parameters - takes in string input as name of the file to save to
    void readingame(User*, User*, string);//for recalling a game - takes in two users and fills them up with information - takes in string input as name of the file to load from
    ~NSFile();
};

#endif /* NSFILE_H */

