/* 
 * Author: Team #23232323
 * Created on Sept 28, 2021, 11:40 AM
 * Purpose: 
 *    
 */

#ifndef BOARD_H
#define BOARD_H

#include "Coordinate.h"
#include "AbsBoat.h"
#include "Boat.h"



// test the board
class Board {
private:
    int rowsize;//rowsize for board - Ethan/Yanis
    int colsize;//colsize for board - Ethan/Yanis
    char **board; // the board 
    
public:
    Board();
    void update(Boat**, int size); // adds user boats into board. IDk if we'll need this 
    void upHts(Boat*, int size); // update the hits 
    void upms(Coordinate*); // updates the misses cordinates 
    void adBoat(Boat*); // adds a boat into the Board 
    void adBoat(Boat*, char); // adds a boat with the type of boat
    void updmis(Coordinate**, int size);
    
    int getrowsize(); //get size of row variable for other functions Ethan/Yanis
    int getcolsize(); //get size of colomn variable for other functions Ethan/Yanis
    char getElement(int row, int col) {return board[row][col]; } // retrives an element from the board
    char** rboard() { 
        return board; 
    };
    
    ~Board(); // deinit the *board 
};

// we probably want something that checks if a full ship has been taken down.


#endif /* BOARD_H */

