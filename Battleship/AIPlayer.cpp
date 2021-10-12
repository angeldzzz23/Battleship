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

void AIPlayer::RNGCoords(Boat* boat) {
    Coordinate **coords = new Coordinate*[boat->reqsz()]; //temp array of boat coords
    bool badNorth = false, 
            badEast = false, 
            badSouth = false, 
            badWest = false; //if a direction is bad, set to true
    bool badCoord1; //will hold true if its a bad coord
    int direct;
    
    do {
        /* 1) Rand gen 1st coord */
        do {
            coords[0]->setRow(rand() % 10);
            coords[0]->setCol(rand() % 10);
            badCoord1 = !bIsNotTaken(coords[0]);
        } while (badCoord1);
        
        do {
            direct = rand() % 4 + 1; /* 2) Rand gen a direction */
            
            switch (direct) { /* 3) check coords in this direction */
                case 1: //north
                    if (!(coords[0]->getRow() - boat->reqsz() + 1 > -1)) //if boatsz does not fit in direction
                        badNorth = true;
                    if (!badNorth) //bad direct will not repeat twice
                        for (int i = 1; i < boat->reqsz(); i++) {
                            coords[i] = new Coordinate(coords[0]->getRow() - i, coords[0]->getCol());
                            badNorth = !bIsNotTaken(coords[i]); //test current coord for avail
                            if (badNorth) //if a single coord is not avail, break loop
                                break;
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
                        }
                    break;
            }
        } while ((badNorth || badEast || badSouth || badWest) && //repeat if a direction was bad (re-gen direction)
                !(badNorth && badEast && badSouth && badWest)); //and if not all directions are bad yet (repeat until all directions are bad)
    } while (badNorth && badEast && badSouth && badWest); //repeat if there are no avail directions (re-gen coord1)
    
    /* 4) All coords are valid. Copy coords** to boat coords */
        for (int i = 0; i < boat->reqsz(); i++)
            boat->addCord(coords[i]);
    
    delete []coords;
}

AIPlayer::AIPlayer() {
    
    //Initialize all boat types
    Destroyer *aiDes = new Destroyer();
    Submarine *aiSub = new Submarine();
    Cruiser *aiCru = new Cruiser();
    Battleshp *aiBs = new Battleshp();
    Carrier *aiCarr = new Carrier();
    
    //Assign boat types to Boat array
    boats[0] = aiDes;
    boats[1] = aiSub;
    boats[2] = aiCru;
    boats[3] = aiBs;
    boats[4] = aiCarr;
    
    
    
    /* For Destroyer = 2 */
    RNGCoords(aiDes); //Rand gen all coords
    
    cout << "Destroyer test case:\n\n";
    
    for (int i = 0; i < aiDes->reqsz(); i++) {
        cout << "Row: " << aiDes->cordAt(i)->getRow() << " Col: " << aiDes->cordAt(i)->getCol() << endl;
    }
    
    /* For Submarine = 3 */
    RNGCoords(aiSub); //Rand gen all coords
    
    /* For Cruiser = 3 */
    RNGCoords(aiCru); //Rand gen all coords
    
    /* For Battleshp = 4 */
    RNGCoords(aiBs); //Rand gen all coords
    
    /* For Carrier = 5 */
    RNGCoords(aiCarr); //Rand gen all coords
}