/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Board.h"

#include <iostream>

// here we are creating a board of 10 x 10
// TODO 1: our board should be able to update the hits (showing that a hit has been done)
// TODO 2:out boat should update the the misses (showing that a miss has been done)
// TODO 3: out board should show that a full boat has been taken down. 
// TODO 3: our constructor needs to show the col and rows (their letter and numbers)
// TODO 4: Deconstructor 
//  Idk what else we could be missing


// TODO: need to add the row numbers and col letters. 
// TODO: we still need to test 

Board::Board() {
    int row = 10; int col = 10; 
    
    this->rowsize = row;
    this->colsize = col;
    // dynamically create a 10x10 2-D array 
    // allocating the rows 
    board = new char*[row];
            
    // allocating the cols 
    for(int i = 0; i <row;i++) {
        board[i] = new char[col];
    }
    
    // TODO: FIX ME 
    // creating an empty board 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = '*';
        }
    }
            
    
}

// updates the board with the boats of the User. 
// updates the board with the boats of the user
// this will update the hits and deads of boats
void Board::update(Boat** boats, int size) {
     char btType[] = {'d','s','c','b', 'C'};  
     for (int i = 0; i < size; i++) { // loop through the array of boats
         Boat *boat = boats[i]; // the boat in that specific index
         int sz = boat->reqsz();
         
         for (int i = 0; i < sz; i++) {
             Coordinate *cord = boat->cordAt(i);
             if (boat->isDead()) {
                 board[cord->getRow()][cord->getCol()] = 'X';
             } else if (boat->cordHshit(cord)){
                  board[cord->getRow()][cord->getCol()] = 'h';
             } else {
                  board[cord->getRow()][cord->getCol()] = btType[boat->getType()];
             }
         }
         
     }

}

// adds a single boat to the board
// adds a single boat
// updates the hts or deads
void Board::adBoat(Boat* boat) {
    //TODO: adds cordinates to the board
    // 
    char btType[] = {'d','s','c','b', 'C'};
    int sz = boat->reqsz();
   
        for (int i = 0; i < sz; i++) {
           Coordinate *cord = boat->cordAt(i);
           if (boat->isDead()) {
                board[cord->getRow()][cord->getCol()] = 'X';
             } else if (boat->cordHshit(cord)){
                  board[cord->getRow()][cord->getCol()] = 'h';
             } else {
                  board[cord->getRow()][cord->getCol()] = btType[boat->getType()];
             }
         }
}

// update a missed cordinate
void Board::upms(Coordinate* ms) {
    board[ms->getRow()][ms->getCol()] = 'm';
}

void Board::upmss(Coordinate** ms, int s) {
    if (s == 0) {
        std::cout << "it is zero" << std::endl;
    }
    for (int i = 0; i < s; i++) {
     board[ms[i]->getRow()][ms[i]->getCol()] = 'm'; 
    }
}
 
// update the hits 
 void Board::upHts(Boat** boats, int size) {
     
     for (int i = 0; i < size; i++) { // loop through the array of boats
         Boat *boat = boats[i]; // the boat in that specific index
         int sz = boat->reqsz();
         
         for (int i = 0; i < sz; i++) {
             Coordinate *cord = boat->cordAt(i);
             if (boat->isDead()) {
                 board[cord->getRow()][cord->getCol()] = 'X';
             } else if (boat->cordHshit(cord)){
                  board[cord->getRow()][cord->getCol()] = 'h';
             } 
         }
         
     }    

 }


int Board::getrowsize(){
    return rowsize;
}

int Board::getcolsize(){
    return colsize;
}


//deconstructor 
// TODO:
// check if it has any errors 
Board::~Board() {
    int row = 10; int col = 10; 

     //Free each sub-array
    for(int i = 0; i < 10; ++i) {
        delete[] board[i];   
    }
    
    //Free the array of pointers
    delete[] board;
    
    board = NULL;
}
