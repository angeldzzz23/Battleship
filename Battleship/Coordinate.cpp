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
  
  // Constructor for the cordinate
  Coordinate::Coordinate(int r, int c) {
      if (r > 9 || r < 0 || c >9 || c < 0 ) {
          std::cout << "Coordinate is out of bounds" << std::endl;
          exit(1);
      }
      
      row = r;   
      col = c;
  }
  
  // operarator over
   bool Coordinate::operator==(const Coordinate &c) {
      if(this->row==c.getRow() && this->col==c.getCol())
            return true; 
      
      return false;
  }
  
  
