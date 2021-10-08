/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 *Version 1 - Ethan and Yanis - basic prompting for functions + inputs and input validation. Will still need to link up with other classes for full functionality but the bases are made
 */

#include "Prompt.h"
#include <iostream>
#include <cstring>

using namespace std;

void Prompt::hello(){ //a simple welcome to the game prompt that asks for a username
    cout <<"Welcome to Battleship!" <<endl;
    cout <<"Please enter username: "; //enter their user name
    int size = 50;
    tester.username =new char[size];
    cin.getline(tester.username,size-1);
    cout <<tester.username <<endl;
    delete tester.username; //delete dynamic array
}

void Prompt::getturn(){ //function for taking turns - all inputs c strings for input validation
    char *input;  //dynamically allocate an array of characters for input
    int size = 50;
    input = new char[size]; //sized to 50 to protect against oversized and bad inputs
    bool valid = false; //to test for the do-while loop
    
    do{
        cout <<"What would you like to do: \n" //main menu prompt for taking a turn
                <<"1. Re-Print board \n"
                <<"2. Print score \n"
                <<"3. Take shot \n"
                <<"4. Quit and save the game \n";
        
        cin.getline(input,size-1);        
        
        if(*input == '1'){
            cout <<"Printing out board..." <<endl; //link up with display/user/game
            valid = true;
        } 
        else if (*input == '2'){
            cout <<"Printing out score..." <<endl; //link up with display/user class
            valid = true;
        }
        else if (*input == '3'){
            cout <<"Taking shot..." <<endl; //need work with who is doing coordinate class 
            valid = true;
        }
        else if (*input == '4'){ //save game to binary file for later and quit
            cout <<"Quitting and Saving the game..." <<endl;
            valid == true;
        }
        else if (strlen(input) > 2){ //to test out garbage inputs with white spaces
            cout <<"Invalid" <<endl;
            valid = false;
        }
        else{
            cout <<"Not valid option" <<endl; //input validation
            valid = false;
        }
        
    }while(valid == false); //while be true if inputs are valid, false and repeat for invalid inputs
    delete input; //delete input to free up space
}

void Prompt::mainmenu(){ //function for the main menu - all inputs c strings for input validation
    char *input;  //dynamically allocate an array of characters for input
    int size = 50;
    input = new char[size]; //sized to 50 to protect against oversized and bad inputs
    bool valid = false; //to test for the do-while loop
        
    do{
        cout <<"What would you like to do: \n" //main menu prompt
                <<"1. Play Computer \n"
                <<"2. Play two-player \n"
                <<"3. Load saved game \n"
                <<"4. Quit \n";
        cin.getline(input,size-1);     //getline input        
        
        if(*input == '1'){
            cout <<"le AI revolt" <<endl; //link up with game
            valid = true;
        } 
        else if (*input == '2'){
            cout <<"le man on man action" <<endl; //link up with game
            valid = true;
        }
        else if (*input == '3'){ //loads save game
            cout <<"Loading saved game..." <<endl;
            valid == true;
        }
        else if (*input == '4'){
            cout <<"Quitting..." <<endl;  //quits the game
            valid = true;
        }
        else if (strlen(input) > 2){ //to test out garbage inputs with white spaces
            cout <<"Invalid" <<endl;
            valid = false;
        }
        else{
            cout <<"Not valid option" <<endl; //input validation
            valid = false;
        }
        
    }while(valid == false);//while be true if inputs are valid, false and repeat for invalid inputs
    delete input; //delete input to free memory
}

void Prompt::waitturn(){ //for a two-player game - a little pause for the other player to get on the computer so they do not see each other's boards
    char *input;  //dynamically allocate an array of characters for input
    int size = 50;
    input = new char[size];
    
    cout <<"Thankyou, please let other user take their seat and being their turn. " <<endl //ask other user to get on
            <<"When next player is ready, press any key and enter..." <<endl;   
    cin.getline(input,size-1); //just any input to let program know player is there
    delete input;
}

void Prompt::winner(){ //prints out winner of game - still need to link it up with game class etc,
    cout <<"Congratulations player: " <<"!" <<endl //insert username variable of winning player 
            <<"You have won! " <<endl; //perhaps also put in their score
}