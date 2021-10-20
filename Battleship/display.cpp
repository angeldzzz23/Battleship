/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Display.h"
#include <iostream>

using namespace std;

void Display::displayboard(Board *board1){
    int col = board1->getcolsize();
    int row = board1->getrowsize();
    
    //printing out the board;
    cout <<" ";//print out a leading space so numbers fall nicely ontop of columns 
    for (int i = 1; i <= row; i++){
        cout <<" " <<i;
    }
    cout <<endl; //print out for next row and start of actual board
    int ascii = 65; //ascii value of A
    
    for (int i = 0; i < row; i++) {
        cout <<char(ascii) <<" ";
        ascii++; //add one to ascii value to move on to next letter of alphabet
        
        for (int j = 0; j < col; j++) {
            cout << board1->getElement(i,j) << " ";//how to access board
        }
        cout << endl;
    }
    
}

 void Display::clearScreen() {
       cout << string(100,'\n');
   }