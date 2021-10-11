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
        int cnvrtLet(char letter);  // transalte a letter 
    public: 
        Coordinate(char*);  // Constructor that takes in a C string
        Coordinate(int r, int c); // this initializer takes in an int row and an in col
        int getRow() const {return row;} // returns the row
        int getCol() const {return col;} // returns the col  
        void setRow(int r) {row = r;}
        void setCol(int c) {col = c;}
        bool operator==(const Coordinate &);
};

#endif /* COORDINATE_H */

