/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Coordinate.h"

#include <iostream>


using namespace std;



    // a cordinate number is a letter and a number 
    // ex. a1
  Coordinate::Coordinate(char*p) {
      
        
      
      // converting char to int  ascii table 
        row = cnvrtLet(p[0]); // converts char to int
        
        // convert to char -> to int using ascii table 
        col = cnvrt(p[1]); // convets char to int 
        
  }
  
  int Coordinate::getRow() {
       return row;    
  }
            
   int Coordinate::getCol() {
    
       return col;
    }
   
   
   int  Coordinate::cnvrt(char digit) {
     if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
      }
     
    return digit-'0';  
   }
   
   // convert letter to an interger using ascii table 
   // TODO: 
   int Coordinate::cnvrtLet(char digit) {
        // TODO: 
       return 3; 
   }

