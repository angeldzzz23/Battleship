/*
 * Version 1 - prints out a board of *
 * Version 2 - uses GetElement of Board class to print out the board as well as the boats and h/m 
 */

#include "Display.h"
#include "Board.h"
#include <iostream>

using namespace std;

void Display::displayboard(Board *daboard){
    int row = daboard->getrowsize(); //get the row and column sizes from the board class
    int col = daboard->getcolsize();
    
    //printing out the board;
    cout <<" ";//print out a leading space so numbers fall nicely ontop of columns 
    for (int i = 1; i <= row; i++){
        cout <<" " <<i;
    }
    cout <<endl; //print out for next row and start of actual board
    int ascii = 65; //ascii value of A
    
    for (int i = 0; i < row; i++){   
            cout <<char(ascii) <<" ";
            ascii++; //add one to ascii value to move on to next letter of alphabet
        for (int c = 0; c < col; c++){ //get it - c+++ hyuck hyuck hyuck
            cout <<daboard->getElement(i, c) <<" ";//getelement to print out whatever is in the array at that position
        }        
        cout <<endl;
    }
}