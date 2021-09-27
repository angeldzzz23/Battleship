/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: AZ
 *
 * Created on September 26, 2021, 1:11 PM
 */

#ifndef GAME_H
#define GAME_H


// this will be the menu of the game 
// will call function to begin a certain

class Game {  
//    private:
        
    public:
        Game();
        void startGame(); // the starting of the game will display the rules 
                          // and contain the game loop 
        bool gameIsNotOver();
        
        void makeAdecision(char); 
        
};


#endif /* GAME_H */

