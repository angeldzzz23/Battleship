/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Prompt.h"
#include <iostream>

using namespace std;

void Prompt::hello(){
    cout <<"Welcome to Battleship!" <<endl;
    cout <<"Please enter username: ";
    int size = 15;
    tester.username =new char[size];
    cin.getline(tester.username,size-1);
    cout <<tester.username <<endl;
    delete tester.username;
}

void Prompt::getturn(){
    int input;
    cout <<"What would you like to do: \n"
            <<"1. Re-Print board \n"
            <<"2. Print score \n"
            <<"3. Take shot \n";
    cin >> input;
    
    if(input == 1){
        cout <<"le board" <<endl; //link up with display/user/game
    } 
    else if (input == 2){
        cout <<"le score" <<endl; //link up with display/user class
    }
    else if (input == 3){
        cout <<"Taking shot..." <<endl; //need work with who is doing coordinate class 
    }
    else{
        cout <<"Not valid option" <<endl; //input validation
    }
}

void Prompt::mainmenu(){
    int input;
    cout <<"What would you like to do: \n"
            <<"1. Play Computer \n"
            <<"2. Play two=player \n"
            <<"3. Quit \n";
    cin >> input;
    
    if(input == 1){
        cout <<"le AI revolt" <<endl; //link up with game
    } 
    else if (input == 2){
        cout <<"le man on man action" <<endl; //link up with game
    }
    else if (input == 3){
        cout <<"Quitting..." <<endl; //need work with who is doing coordinate class 
    }
    else{
        cout <<"Not valid option" <<endl; //input validation
    }
}

