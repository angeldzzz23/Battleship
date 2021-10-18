/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AIPlayer.h"
#include <iostream>

using namespace std;

/* 1 - North
 * 2 - East
 * 3 - South
 * 4 - West
 */

bool AIPlayer::checkPrevMoves(Coordinate *coord, User *user) {
    //check AI miss array
    for (int i = 0; i < this->missSz; i++) {
        if (*this->misses[i] == *coord)
            return false; //if the coord has been shot already
    }
        
    //check enemy user's boat hit coords array
    for (int i = 0; i < user->gtTotBtsz(); i++) {
        if (user->getBoat(i)->cordHshit(coord))
            return false; //if the coord has been shot already
    }
    
    //There are no duplicates at this point
    return true; //Coord DNE; can still be taken
}

Coordinate* AIPlayer::makeAMove(User *user) {
    Coordinate *coord = nullptr;
    
    while (true) {
        coord = new Coordinate(rand() % 10, rand() % 10);
        if (checkPrevMoves(coord, user)) //if coord DNE yet
            return coord;
    }
}

void AIPlayer::RNGCoords(Boat* boat) {
    Coordinate **coords = new Coordinate*[boat->reqsz()]; //temp array of boat coords
    bool badNorth, //if a direction is bad, set to true (4 directions)
            badEast, 
            badSouth, 
            badWest;
    bool badDirections; //if all directions are bad, set to true
    bool goodDirect = false; //if a good direction is found
    bool badCoord1; //will hold true if its a bad coord
    int direct; //the direction of the remaining coords
    
    do {
        /* 0) Reset bools after each loop */
        badNorth = false; 
        badEast = false;
        badSouth = false;
        badWest = false;
        badDirections = false;
        
        /* 1) Rand gen 1st coord */
        do {
            int r = rand() % 10, c = rand() % 10;
            coords[0] = new Coordinate(r, c);
            badCoord1 = !bIsNotTaken(coords[0]);
        } while (badCoord1);
        do {
            
            direct = rand() % 4 + 1; // 2) Rand gen a direction 
            
            switch (direct) { // 3) check coords in this direction 
                case 1: //north
                    if (!(coords[0]->getRow() - boat->reqsz() + 1 > -1)) //if boatsz does not fit in direction
                        badNorth = true;
                    if (!badNorth) //bad direct will not repeat twice
                        for (int i = 1; i < boat->reqsz(); i++) {
                            coords[i] = new Coordinate(coords[0]->getRow() - i, coords[0]->getCol());
                            badNorth = !bIsNotTaken(coords[i]); //test current coord for avail
                            if (badNorth) //if a single coord is not avail, break loop
                                break;
                            else if (!badNorth && i == boat->reqsz() - 1)
                                goodDirect = true;
                        }
                    break;
                case 2: //east
                    if (!(coords[0]->getCol() + boat->reqsz() - 1 < 10)) //if boatsz does not fit in direction
                        badEast = true;
                    if (!badEast) //bad direct will not repeat twice
                        for (int i = 1; i < boat->reqsz(); i++) {
                            coords[i] = new Coordinate(coords[0]->getRow(), coords[0]->getCol() + i);
                            badEast = !bIsNotTaken(coords[i]); //test current coord for avail
                            if (badEast) //if a single coord is not avail, break loop
                                break;
                            else if (!badEast && i == boat->reqsz() - 1)
                                goodDirect = true;
                        }
                    break;
                case 3: //south
                    if (!(coords[0]->getRow() + boat->reqsz() - 1 < 10)) //if boatsz does not fit in direction
                        badSouth = true;
                    if (!badSouth) //bad direct will not repeat twice
                        for (int i = 1; i < boat->reqsz(); i++) {
                            coords[i] = new Coordinate(coords[0]->getRow() + i, coords[0]->getCol());
                            badSouth = !bIsNotTaken(coords[i]); //test current coord for avail
                            if (badSouth) //if a single coord is not avail, break loop
                                break;
                            else if (!badSouth && i == boat->reqsz() - 1)
                                goodDirect = true;
                        }
                    break;
                case 4: //west
                    if (!(coords[0]->getCol() - boat->reqsz() + 1 > -1)) //if boatsz does not fit in direction
                        badWest = true;
                    if (!badWest) //bad direct will not repeat twice
                        for (int i = 1; i < boat->reqsz(); i++) {
                            coords[i] = new Coordinate(coords[0]->getRow(), coords[0]->getCol() - i);
                            badWest = !bIsNotTaken(coords[i]); //test current coord for avail
                            if (badWest) //if a single coord is not avail, break loop
                                break;
                            else if (!badWest && i == boat->reqsz() - 1)
                                goodDirect = true;
                        }
                    break;
            }
            
            if (badNorth && badEast && badSouth && badWest) //if all directions are bad
                badDirections = true;
            
            if (goodDirect) //If a line of coords has succeeded, break loop
                break;
            
        } while (!badDirections); //repeat until all directions have been tried/failed (re-gen direction)
    } while (badDirections); //repeat if there are no avail directions (re-gen coord1)
    
    /* 4) All coords are valid. Copy coords** to boat coords */
        for (int i = 0; i < boat->reqsz(); i++)
            boat->addCord(coords[i]);
    
    delete []coords;
}

AIPlayer::AIPlayer() {
    //Set rand seed
    srand(time(0));
    
    //Initialize all boat types
    Destroyer *aiDes = new Destroyer();
    Submarine *aiSub = new Submarine();
    Cruiser *aiCru = new Cruiser();
    Battleshp *aiBs = new Battleshp();
    Carrier *aiCarr = new Carrier();
    
    //Assign boat types to Boat array
    adBoat(aiDes);
    adBoat(aiSub);
    adBoat(aiCru);
    adBoat(aiBs);
    adBoat(aiCarr);
    
    /* For Destroyer = 2 */
    RNGCoords(aiDes); //Rand gen all coords
    
    /* For Submarine = 3 */
    RNGCoords(aiSub); //Rand gen all coords
    
    /* For Cruiser = 3 */
    RNGCoords(aiCru); //Rand gen all coords
    
    /* For Battleshp = 4 */
    RNGCoords(aiBs); //Rand gen all coords
    
    /* For Carrier = 5 */
    RNGCoords(aiCarr); //Rand gen all coords
    
}