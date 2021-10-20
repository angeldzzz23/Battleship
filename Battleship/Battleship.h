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
    protected: 
        // user 1 
        User *userOne; // a user One model 
    //  usrbrd - contains UserTwo hits and misses
        Board *usOnBrd; // contains user one boats, and contains UserTwo hits and misses     
        Board *usOnHS; // contains hits and misses of user 
        
        //user 2
        Board *usTwBrd; // contains user two boats, and contains UserTwo hits and misses     
        Board *usTwHS; // contains hits and misses of user 
        
    private:
        // user 2
        User *userTwo; // a userTwo model 
       
            
        
    public:// for some reason
        Battleship(int); // initializes the game
        void shotAttempt(User*, Coordinate *);
        void setUserOne(User* user);
        void setUserTwo(User* user);
        bool gameIsOver();
      
};

#endif /* BATTLESHIP_H */


