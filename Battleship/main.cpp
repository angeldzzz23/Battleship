/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: AZ
 *
 * Created on September 26, 2021, 12:43 PM
 */

#include <cstdlib>
#include "Game.h"
#include <iostream>
#include "Coordinate.h"
#include "Destroyer.h"
#include "AbsBoat.h"
using namespace std;


int main(int argc, char** argv) {
   
    
    Destroyer des1 = Destroyer();
    Destroyer de2 =  Destroyer();
    Destroyer des3 = Destroyer();

    AbsBoat *ss[10];
    ss[0] = &des1;
    
    cout << ss[0]->reqsz() << endl;
    
    
    
    
    
//    Game game;
//    game.startGame();
    
//    
//    Coordinate cord = Coordinate("12");
//    cout << cord.getRow() << endl;
//    cout << cord.getCol() << endl;
//    cout << "\u24E7" << endl;
    // Hello
    return 0;
}

