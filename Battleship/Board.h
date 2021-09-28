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

class Board {
private:
    char **board; // the board 
public:
    Board();
    void update(Boat*, int size); // adds user boats into board. IDk if we'll need this 
    void upHts(Boat*, int size); // update the hits 
    void upms(Boat*, int size); // update the misses 
    ~Board(); // deinit the *board 
};

// we probably want something that checks if a full ship has been taken down.


#endif /* BOARD_H */

