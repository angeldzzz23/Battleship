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
    struct userinfo{
        char *username; //class was being weird about accessing username without being in a struct
    };    
    userinfo tester;
    
    
public:
    void hello();//basic welcome prompt
    
    void mainmenu(); //main menu
    
    void getturn(); //for taking turns
    
    void waitturn(); //for waiting for 2nd user
};


#endif /* PROMPT_H */

