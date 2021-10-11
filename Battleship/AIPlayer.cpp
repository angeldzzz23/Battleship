/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AIPlayer.h"


Coordinate* AIPlayer::RNGCoords(Boat* boat) {
    int randRow, randCol; //Holds rand gen coord for row/col
    bool noBoats; //whether there are boats nearby the first coord
    int direction;
    
    Coordinate *coord = new Coordinate(1, 1); //Create new coord
    
    do {
        //1) Rand gen a unique coord
        randRow = rand() % 10 + 1;
        randCol = rand() % 10 + 1;
        coord->setRow(randRow);
        coord->setCol(randCol);
        
        //2) Rand gen a direction
        do {
            direction = rand() % 4 + 1;
            for (int i = 0; i < boat->reqsz(); i++)
                noBoats = bIsNotTaken(coord);
        } while (!noBoats);
    } while (boat->cordHsadd(coord)); //if the boat does not have that row
    
    //Choose a direction to finish the coords
    return NULL;
}

AIPlayer::AIPlayer() {
    
    //Initialize all boat types
    Destroyer *aiDes = new Destroyer();
    Submarine *aiSub = new Submarine();
    Cruiser *aiCruise = new Cruiser();
    Battleshp *aiBattle = new Battleshp();
    Carrier *aiCarr = new Carrier();
    
    //Assign boat types to Boat array
    boats[0] = aiDes;
    boats[1] = aiSub;
    boats[2] = aiCruise;
    boats[3] = aiBattle;
    boats[4] = aiCarr;
    
    /* For Destroyer */
    Coordinate *aiCoord01 = RNGCoords(aiDes); //Rand gen first coord
}