/* 
 * Author: Team #23232323
 * Created on Sept 28, 2021, 11:40 AM
 * Purpose: 
 *    
 */


#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "User.h"

class Battleship {  
    private: 
        // user 1 
        User userOne;
        // user 2
        User userTwo;
        
        
    public:
        Battleship(int); // initializes the game
     
        void startTwoPlayer();  // 
        void startAIGame();

};



#endif /* BATTLESHIP_H */

// Helper information 
// for dealing with the abstract boats
// This is how you can create an array with different types of boats
//    Destroyer des1 = Destroyer();
//    Destroyer de2 =  fffefff();
//    Destroyer des3 = Destroyer();
//
//    AbsBoat *ss[10];
//    ss[0] = &des1;
//    
//    cout << ss[0]->reqsz() << endl;
//    
