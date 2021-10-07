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
      cout << p << endl;
     
      // converting char to int  ascii table 
        row = cnvrtLet(p[0]); // converts char to int
        cout << row << endl;
        
        // convert to char -> to int using ascii table 
        col = cnvrt(p[1]); // converts char to int 
        cout << col << endl;
        
  }
  
  // Constructor for the cordinate
  Coordinate::Coordinate(int r, int c) {
      row = r;   
      col = c;
  }
  
  
  
//   bool operator==(const Coordinate &lhs, const Coordinate &rhs)  {
////       
//       cout << "hereswsw" << endl;
//       if (lhs.getRow() == rhs.getRow() &&  lhs.getCol() == rhs.getCol()) {
//           return true; 
//       }
////       
//       return false; 
//   }

  
   bool Coordinate::operator==(const Coordinate &c){
       cout << "here we are" << endl;
      if(this->row==c.getRow() && this->col==c.getCol())
            return true; 
      
      return false;
  }
  
  
  
   // converts char to integer
   int  Coordinate::cnvrt(char digit) {
     if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
      }
     
      //compensate if 0 is input
     if(digit=='0'){
         return digit-'0'; 
     }
     
     
     
    return digit-'0'-1;  //<-some smart shit right here
   }
   
   
   // convert letter to an interger using ascii table 
   // TODO: make it cleaner
   // ADD new version 
   int Coordinate::cnvrtLet(char letter) {
      
       switch(letter) {
           case 'a':
               return 0; 
           case 'b':
               return 1; 
           case 'c':
               return 3; 
           case 'd':
               return 4; 
           case 'e':
               return 5; 
           case 'f':
               return 6; 
           case 'g':
               return 7; 
           case 'h':
               return 8; 
           case 'i':
               return 9; 
          case 'j':
               return 10;
               
            
               
               
       }
       
       
//    if((letter<'A'||letter>'Z')&&(letter<'a'||letter>'z')){
//                //out of bounds 
//       if((letter<'A'||letter>'Z')&&(letter<'a'||letter>'z')){
//           cout<<"You don't know what you are doing"<<endl; 
//           exit(0); 
//       }
//       
//       //in bounds
//       if(letter>='A'&&letter<='Z'){
//           return letter-'A';
//       }else if(letter>='a'&&letter<='z'){
//           return letter-'a'; 
//       } else {
//           cout << "somethign wrong happened here" << endl;
//           exit(0);
//           
//       }
//
//   }
//        return 5;
    
   
   
   }

