/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Coordinate.h"

#include <iostream>

// TODO #1: Construsctor 
// TODO #2: cnvrtLet
        // make it cleaner 

using namespace std;


    // a cordinate number is a letter and a number 
    // ex. a1
  Coordinate::Coordinate(char*p) {
      
      // converting char to int  ascii table 
        row = cnvrtLet(p[0]); // converts char to int
        
        // convert to char -> to int using ascii table 
        col = cnvrt(p[1]); // converts char to int 
        
  }
  
  // operator overload for a coordinate
  bool Coordinate::operator==(const Coordinate &c){
      if(this->row==c.row && this->col==c.col);
      return true; 
  }
  
  
  // returns the row 
  int Coordinate::getRow() {
       return row;    
  }
 
  // returns the col 
   int Coordinate::getCol() {
    
       return col;
    }
   
   // converts char to integer
   int  Coordinate::cnvrt(char digit) {
     if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
      }
     
    return digit-'0';  //<-some smart shit right here
   }
   
   
   // convert letter to an interger using ascii table 
   // TODO: make it cleaner
   int Coordinate::cnvrtLet(char digit) {
       
       switch(digit) {
           case 'a': return 1;
           case 'b': return 2;
           case 'c': return 3;
           case 'd': return 4;   
           case 'e': return 5;
           case 'f': return 6;
           case 'g': return 7;
           case 'h': return 8;
           case 'i': return 9;
           case 'j': return 10;
           
           default: 
               return -1;
               
             
       } 
       
       return 2;
       
    
   }

