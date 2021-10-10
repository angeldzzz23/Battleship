/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prompt.h
 * Author: AZ
 * Version 1 - Ethan and Yanis - basic prompting for functions + inputs and input validation. Will still need to link up with other classes for full functionality but the bases are made
 * Version 2 - Added some more prompting for taking turns and printing the winner of the game 
 * Version 3 - Added in prompt for loading/saving a game from/to a binary file - still need to implement Prompt class into other classes
 * Created on September 28, 2021, 10:43 AM
 */

#ifndef PROMPT_H
#define PROMPT_H
#include <cstring>

using namespace std;
// TODO: THink of all the type of user input that we will need
// might want to talk to the person working on game and cruiserclass
// this class is in charge of taking all different type of the userput from users 
// TODO #1 define function properties (header file)
// TODO #2 create function definitions (cpp file)
// hint: for user input you will use the getline function

class Prompt {
private:
    char *username; //class was being weird about accessing username without being in a struct
    char *bcoordinate; //this one for working with boat coordinates
    char *scoordinate;//this one is for the shooting
    char *inputmain; //input for main
    char *inputturn;//input for turn
    
public:
    char* hello();//basic welcome prompt
    
    char* mainmenu(); //main menu
    
    char* getturn(); //for taking turns
    
    void waitturn(); //for waiting for 2nd user
    
    void winner(char *winner); //for printing out the winner
    
    char** getboatcoord(int boatsize); //getting boat 
    
    char* getshotcoord();
    
    ~Prompt();//destructor 
};


#endif /* PROMPT_H */