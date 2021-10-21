/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Display.h
 * Author: AZ
 *
 * Created on September 28, 2021, 11:02 AM
 * 
 * Version 1 - Ethan and Yanis - Display now uses GEtElement function of the board class to print out the board, also prints out misses, hits, boats, etc..
 */

#ifndef DISPLAY_H
#define DISPLAY_H
#include "Board.h"
#include <iostream>
// this class is in charged of display everything from the board
using namespace std;

class Display {
private:
public:
    void displayboard(Board *board1);
     void clearScreen(); 
     void htsNMisTle() {cout << "the hits and misses of the enemy + ur boats" << endl;} // the title for hits and misses 
     void yHmTle() {cout << "you hits and misses" << endl; }; // displays the hits and misses of the user title
     void winner(char *winner);
     
};
   
#endif /* DISPLAY_H */

