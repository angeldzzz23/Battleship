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

Board::Board() {
    int row = 10; int col = 10; 
    
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
void Board::update(Boat* boats, int size) {
    // TODO:
}

// updates hits of the board
void Board::upHts(Boat*, int size) {
    // TODO:
    
}

// updates the misses of the boat 
void Board::upms(Boat*, int size) {
    // TODO: 
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
