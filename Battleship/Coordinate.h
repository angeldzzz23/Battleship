/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coordinate.h
 * Author: AZ
 *
 * Created on September 26, 2021, 3:19 PM
 */

#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
    private: 
        int row; 
        int col; 
    public: 
        Coordinate(char*);  
        int getRow();
        int getCol();
        int  cnvrt(char digit); // returns a translated row or col 
        int cnvrtLet(char digit); 
};

#endif /* COORDINATE_H */

