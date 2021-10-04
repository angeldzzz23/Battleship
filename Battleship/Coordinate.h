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
        int getRow(); // returns the row
        int getCol(); // returns the col 
        bool operator==(const Coordinate &); //comparing cordinates 
           
};

#endif /* COORDINATE_H */

