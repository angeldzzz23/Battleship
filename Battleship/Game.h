/* 
 * Author: Team #23232323
 * Created on Sept 28, 2021, 11:40 AM
 * Purpose: 
 *    
 */

#ifndef GAME_H
#define GAME_H
#include "Board.h"

// this will be the main menu of the game 

// TODO: 
    // Input User validation 
   

class Game {  
//    private:
        
    public:
        Game();
        void startGame(); // the starting of the game will display the rules 
                          // and contain the game loop 
        bool gameIsNotOver();
        
        void makeAdecision(char); // makes a decision given the user input 
        
};


#endif /* GAME_H */

