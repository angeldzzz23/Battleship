/* 
 * Author: Team #23232323
 * Created on Sept 28, 2021, 11:40 AM
 * Purpose: 
 *    
 */


#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "User.h"
#include "Boat.h"

// this is our battleship logic (our viewController)
// our controller is the Battleship class 
// our models are the boats, users,  Coordinates 
// our view is the Board, this is what is being displayed

enum GameType {AIGme = 0, twoPlyr};

// our battleship is our controller
class Battleship {  
    private: 
        // user 1 
        User *userOne; // a user One model 
        // enemy board
        Board *enemyBoardOne; // contains your misses and hits.
                             // contains your misses.
                             // contains your hits.   
     
       // user board
        Board *myBoardOne; // contains the location of your boats
                          // and the hits and misses of the enemy
        
        
       
        // user 2
        User *userTwo; // a userTwo model 
      
        
      Board *enemyBoardTwo; // contains your misses and hits.
                             // contains your misses.
                             // contains your hits.   
     
       // user board
      Board *myBoardTwo; // contains the location of your boats
                          // and the hits and misses of the enemy
        
        
    public:
        Battleship(GameType); // initializes the game
        void takeShot(User* n, Coordinate* cor);
        void access();
        void setPlayerOne(User*);
        void setPlayerTwo(User*);
        void startTwoPlayer(); 
        void startAIGame();
//        void displyBoard();
//        void displayEnemybrd();
        bool gameIsOver(); // checks if the game is over
        ~Battleship();
};



#endif /* BATTLESHIP_H */

