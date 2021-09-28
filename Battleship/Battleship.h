/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Battleship.h
 * Author: AZ
 *
 * Created on September 26, 2021, 3:05 PM
 */



#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "User.h"

class Battleship {  
    private: 
        // user 1 
        User userOne;
        // user 2
        User userTwo;
        
        
    public:
        Battleship(int); // initializes the game
     
        void startTwoPlayer();  // 
        void startAIGame();

};



#endif /* BATTLESHIP_H */

// Helper information 
// This is how you can create an array with different types of boats
//    Destroyer des1 = Destroyer();
//    Destroyer de2 =  Destroyer();
//    Destroyer des3 = Destroyer();
//
//    AbsBoat *ss[10];
//    ss[0] = &des1;
//    
//    cout << ss[0]->reqsz() << endl;
//    
