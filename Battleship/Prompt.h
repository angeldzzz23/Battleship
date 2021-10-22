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
 * Version 4 (in save file branch) - Adjusted inputs and methods to match new needs of controller, added functions for loading and saving a game
 * Created on September 28, 2021, 10:43 AM
 */

#ifndef PROMPT_H
#define PROMPT_H
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
// TODO: THink of all the type of user input that we will need
// might want to talk to the person working on game and cruiserclass
// this class is in charge of taking all different type of the userput from users 
// TODO #1 define function properties (header file)
// TODO #2 create function definitions (cpp file)
// hint: for user input you will use the getline function

class Prompt {
private:
    
public:
    
    Prompt();
    void user(string usr) {cout << usr << endl;}
    string hello();//basic welcome prompt - adjusted to be string
    
    string mainmenu(); //main menu adjusting to be string
    
    void waitturn(); //for waiting for 2nd user
    
    void winner(char *winner); //for printing out the winner
    
    string getboatcoord(int boatsize, char *name, string btName); //getting boat 
    
    string getshotcoord(char*);
    
    string gtsavefilename();
    
    string gtloadfilename();
    
    ~Prompt();//destructor 
};


#endif /* PROMPT_H */