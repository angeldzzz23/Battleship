/* 
 * Author: Team #23232323
 * Created on Sept 28, 2021, 11:40 AM
 * Purpose: 
 *    
 */

#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
    private: 
        int row; // the row of a cordinte 
        int col; // the col of a cordinate 
                 // you can change those to x and y, up to you. 
        int cnvrt(char digit); // transalteas number  
        int cnvrtLet(char digit);  // transalte a letter 
    public: 
        Coordinate(char*);  // Constructor that takes in a C string
        int getRow() const {return row;} // returns the row
        int getCol() const {return col;} // returns the col 
        friend bool operator==(const Coordinate &lhs, const Coordinate &rhs); // FIX ME: 
//        bool operator==(const Coordinate &lhs ) const { 
//            
//            return ((row == lhs.row) && (col == lhs.col)); 
//        
//        
//        }
           
//        (lhs.row == rhs.row &&  lhs.col == rhs.col)
};

#endif /* COORDINATE_H */

