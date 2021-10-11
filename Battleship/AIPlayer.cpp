/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AIPlayer.h"
#include "Battleship.h"

Coordinate AIPlayer::RNGCoords(Boat* boat) {
    int randRow; //Holds rand gen coord
    
    Coordinate *coord = new Coordinate(); //Create new coord
    do { //1) Gen a row
        coord.
        if (!boat->cordHsadd(coord)) //if the boat does not have that row
    }
}

AIPlayer::AIPlayer() {
    
    int brdsz = 100; // the size of the board 
    int boatszs = 5; // the total number of boats a user can add 
    int totHit = 5 + 4 + 3 + 3 + 2; // sz of Cruiser,battleship,sz of cruiser, sz sub, sz of dest
    int totMis = brdsz - totHit; // gets the tot misses the user can have 
    
    // initialize the sizes to zero
    boatsz = 0; // the number of boats the user currently has 
    hitsz = 0; // the size of the hits to zero
    missSz = 0; // set the missSz to zero
    
    
    // dynamically allocate memory for boat 
    boats = new Boat*[boatszs];
    
    //Initialize all boat types
    Destroyer *aiDes = new Destroyer();
    Submarine *aiSub = new Submarine();
    Cruiser *aiCruise = new Cruiser();
    Battleship *aiBattle = new Battleship();
    Carrier *aiCarr = new Carrier();
    
    //Assign boats to Boat array
    boats[0] = aiDes;
    boats[1] = aiSub;
    boats[2] = aiCruise;
    boats[3] = aiBattle;
    boats[4] = aiCarr;
    
    
    //Rand gen coords for each boats
    int randGen; //holds onto a rand gen coord during validation
    
    //Rand gen coords for Destroyer
    Coordinate *aiCoord01 = RNGCoords(aiDes);
    Coordinate *aiCoord01 = RNGCoords(aiDes);
    
    // dynamically allocate memory for miss 
    misses = new Coordinate*[totMis];
}