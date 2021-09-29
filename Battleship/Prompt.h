/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prompt.h
 * Author: AZ
 *
 * Created on September 28, 2021, 10:43 AM
 */

#ifndef PROMPT_H
#define PROMPT_H
#include <string>

using namespace std;
// TODO: THink of all the type of user input that we will need
// might want to talk to the person working on game and cruiserclass
// this class is in charge of taking all different type of the userput from users 
// TODO #1 define function properties (header file)
// TODO #2 create function definitions (cpp file)
// hint: for user input you will use the getline function
// 

class Prompt {
private:
    struct userinfo{
        char *username;
    };
    
    userinfo tester;
public:
    void hello();
};


#endif /* PROMPT_H */

