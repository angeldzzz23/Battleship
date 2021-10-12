/* 
 * Author: Team #23232323
 * Created on Sept 28, 2021, 11:40 AM
 * Purpose: 
 *    
 */


#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "User.h"

// this is our battleship logic (our viewController)
// our controller is the Battleship class 
// our models are the boats, users,  Coordinates 
// our view is the Board, this is what is being displayed

// our battleship is our controller
class Battleship {  
    private: 
        // user 1 
        User *userOne; // a user One model 
       // usrbrd - contains UserTwo hits and misses
        
        // enmy brd - contains the hits and misses of the user
        
        
        // user 2
        User *userTwo; // a userTwo model 
        // usrbrd - contains UserTwo hits and misses
        
        // enmy brd - contains the hits and misses of the user
            
        
    public:
        Battleship(int); // initializes the game
        void shotAttempt(User*);
        void setUserOne(User*);
        void setUserTwo(User*);
        bool gameIsOver();
      
};



#endif /* BATTLESHIP_H */

