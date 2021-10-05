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
  
  
   bool operator==(const Coordinate &lhs, const Coordinate &rhs)  {
//       
       cout << "hereswsw" << endl;
       if (lhs.getRow() == rhs.getRow() &&  lhs.getCol() == rhs.getCol()) {
           return true; 
       }
//       
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
       
          //out of bounds 
       if((letter<'A'||letter>'Z')&&(letter<'a'||letter>'z')){
           cout<<"You don't know what you are doing"<<endl; 
           exit(0); 
       }
       
       //in bounds
       if(letter>='A'&&letter<='Z'){
           return letter-'A';
       }else if(letter>='a'&&letter<='z'){
           return letter-'a'; 
       } else {
           cout << "somethign wrong happened here" << endl;
           exit(0);
           
       }
       
    
   }

