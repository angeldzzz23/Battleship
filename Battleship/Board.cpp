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
void Board::update(Boat** boats, int size) {
     char btType[] = {'d','s','c','b', 'C'};
  
    for (int i = 0; i < size; i++) { // looops through the array of boats
        Boat *boat = boats[i]; // the boat in that specific index
        Coordinate **cord = boat->getcordinates(); // the cordinates of the boat
        
          for (int j = 0; j < boat->reqsz();j++ )   {
             board[cord[j]->getRow()][cord[j]->getCol()] = btType[boat->getType()];  // initializes the location of the board
          }
    }
   
}

// adds a single boat to the board
void Board::adBoat(Boat* boat) {
    //TODO: adds cordinates to the board
    // 
    char btType[] = {'d','s','c','b', 'C'};
    Coordinate **cord = boat->getcordinates();

            
    for (int i = 0; i < boat->reqsz(); i++) {
        
        board[cord[i]->getRow()][cord[i]->getCol()] = btType[boat->getType()];
    }


}


// updates hits of  a sppecific 
void Board::upHts(Boat*, int size) {
    // TODO:
    
    
}

// updates the misses of a specific boat
// unsure if I need this
void Board::upms(Boat*, int size) {
    // TODO: 
}

// update a hts cordinate 
// do not need 
void Board::upHts(Coordinate* hts) {
    board[hts->getRow()][hts->getCol()] = 'h';
}

// update a missed cordinate 
// call this ms
void Board::upms(Coordinate* ms) {
    board[ms->getRow()][ms->getCol()] = 'm';
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
