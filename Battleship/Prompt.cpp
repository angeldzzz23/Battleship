/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 *Version 1 - Ethan and Yanis - basic prompting for functions + inputs and input validation. Will still need to link up with other classes for full functionality but the bases are made
 * Version 2 - functions now return char* and added functions for getting coordinates of ships + shots from the user.
 */

#include "Prompt.h"
#include "Boat.h"
#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h> //for checking user input is char or letter - from resources online

using namespace std;

Prompt::Prompt(){
    username = NULL;
    inputmain = NULL; //input for main
    inputturn = NULL;

}

char* Prompt::hello(){ //a simple welcome to the game prompt that asks for a username
    cout <<"Welcome to Battleship!" <<endl;
    cout <<"Please enter username: "; //enter their user name
    int size = 50;
    username =new char[size];
    cin.getline(username,size-1);
    cout <<username <<endl;
    return username;
}

char* Prompt::getturn(){ //function for taking turns - all inputs c strings for input validation
    int size = 50;
    inputturn = new char[size]; //sized to 50 to protect against oversized and bad inputs
    bool valid = false; //to test for the do-while loop

    do{
        cout <<"What would you like to do: \n" //main menu prompt for taking a turn
                <<"1. Re-Print board \n"
                <<"2. Print score \n"
                <<"3. Take shot \n"
                <<"4. Quit and save the game \n";

        cin.getline(inputturn,size-1);
        if (strlen(inputturn) > 2){ //to test out garbage inputs with white spaces
            cout <<"Invalid" <<endl;
            valid = false;
        }
        else if(*inputturn == '1'){
            cout <<"Printing out board..." <<endl; //link up with display/user/game
            valid = true;
        }
        else if (*inputturn == '2'){
            cout <<"Printing out score..." <<endl; //link up with display/user class
            valid = true;
        }
        else if (*inputturn == '3'){
            cout <<"Taking shot..." <<endl; //need work with who is doing coordinate class
            valid = true;
        }
        else if (*inputturn == '4'){ //save game to binary file for later and quit
            cout <<"Quitting and Saving the game..." <<endl;
            valid = true;
        }
        else{
            cout <<"Not valid option" <<endl; //input validation
            valid = false;
        }

    }while(valid == false); //while be true if inputs are valid, false and repeat for invalid inputs
    return inputturn; //return the verified input
}

char* Prompt::mainmenu(){ //function for the main menu - all inputs c strings for input validation
    int size = 50;
    inputmain = new char[size]; //sized to 50 to protect against oversized and bad inputs
    bool valid = false; //to test for the do-while loop

    do{
        cout <<"What would you like to do: \n" //main menu prompt
                <<"1. Play Computer \n"
                <<"2. Play two-player \n"
                <<"3. Load saved game \n"
                <<"4. Quit \n";
        cin.getline(inputmain,size-1);     //getline input

        if (strlen(inputmain) > 2){ //to test out garbage inputs with white spaces
            cout <<"Invalid - too many inputs." <<endl;
            valid = false;
        }
        else if(*inputmain == '1'){
            cout <<"le AI revolt" <<endl; //link up with game
            valid = true;
        }
        else if (*inputmain == '2'){
            cout <<"le man on man action" <<endl; //link up with game
            valid = true;
        }
        else if (*inputmain == '3'){ //loads save game
            cout <<"Loading saved game..." <<endl;
            valid = true;
        }
        else if (*inputmain == '4'){
            cout <<"Quitting..." <<endl;  //quits the game
            valid = true;
        }
        else{
            cout <<"Not valid option" <<endl; //input validation
            valid = false;
        }

    }while(valid == false);//while be true if inputs are valid, false and repeat for invalid inputs
    return inputmain; //delete input to free memory
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

void Prompt::winner(char *winner){ //prints out winner of game
    cout <<"Congratulations player: " <<winner <<"!" <<endl //insert username variable of winning player
            <<"You have won! " <<endl; //perhaps also put in their score
}

string Prompt::getboatcoord(int boatsize){//for getting coordinates for boats
    string boat;
    int totalcount = 0;
    bool valid = true;
    do{
        cout <<"Please enter all " <<boatsize <<" coordinates for your ship to be placed:" <<endl
                <<"Ex: A1 A2 A3..." <<endl;
        getline(cin, boat);
        int tracksize = 0; //this is to track the size of the individual coordinates from the whole string, to make sure none are too large
        totalcount = 0;//for keeping track of the total count of coordinates entered
        bool prevone = false; //bool for testing if user enters a 10
        valid = true;
        for (int c = 0; c < boat.length(); c++){

            if (isalpha(boat[c])){ //test for character
                cout <<"Character" <<endl;
                if (tracksize == 1 || tracksize > 3){ //coordinates should always be at least 2, so tracksize of 1 implies no number was entered after a letter - and tracksize greater than 3 implies one that is too large
                    cout <<"Invalid coordinate detected, try again." <<endl;
                    valid = false;
                    break;
                }
                else if(c == (boat.length()-1)){
                    cout <<"Invalid, try again." <<endl;
                    valid = false;
                    break;
                }
                int test = int(boat[c]);
                if ((test >= 65 && test <= 74) || (test >= 96 && test <= 106)){ //to test character is within bounds - capital and lowercase letters
                    tracksize = 0;
                    tracksize++;
                    totalcount++;
                    prevone = false;
                }
                else{
                    cout <<"Invalid coordinate detected - try again." <<endl;
                    break;
                }

            }
            else if (isdigit(boat[c])){//test for number
                cout <<"Digit" <<endl;
                //10 test
                if(boat[c] == '0' || tracksize >= 2){
                    if(prevone == true){
                        if (boat[c] == '0' && tracksize == 2){//because any '10' coordinate must have a letter and a '1' preceding the 0
                            prevone = false; //reset to false
                        }
                        else{
                            cout <<"Invalid coordinate found - try again." <<endl;
                            valid = false;
                            break;
                        }
                    }
                    else{
                        cout <<"Invalid coordinate - please tey again." <<endl;
                        valid = false;
                        break;
                    }
                }
                if (boat[c] == '1'){//if one is found set equal to true
                    prevone = true;
                }
                //10 test end

                tracksize++;

                if(c == (boat.length()-1) && tracksize <= 3){ //for the end of the string
                    tracksize = 0;
                    cout <<"Total coord: " <<totalcount <<endl;
                }
            }
            else if (boat[c] == ' '){//basically just ignore white spaces
                //blank because just needed to filter out special characters, whitespaces are fine
            }
            else{ //to filter out special characters and such
                cout <<"Invalid character - try again." <<endl;
                valid = false;
                break;
            }

        }
        if (totalcount != boatsize){
            cout <<"Incorrect number of coordinates, try again." <<endl;
        }
    }while (totalcount != boatsize || valid != true);

    return boat;
}

string Prompt::getshotcoord(){ //getting a single coordinate for shooting
    bool valid = false; //bool for do while control
    string shot;
    do{
        cout <<"Enter coordinates for the shot sir: " <<endl;
        getline(cin, shot); //take it

        //conversions of data types to make validation easier - also done on separate variables to preserve data
        int comp = (int)shot[0];
        char test = shot[1];
        test -= '0';

        //validate the data
        if ((comp >= 65 && comp <= 74) || (comp >= 96 && comp <= 106)){ //using ascii values to validate the char coordinate
            if(shot.length() == 3 && test == 1){ //test and validate for coord is a '10'
                char test2 = shot[2];
                test2 -= '0';
                if (test2 == 0){
                    cout <<"Coordinates confirmed" <<endl;;
                    valid = true; //set condition to true once coordinate is confirmed valid
                }
                else{
                    cout <<"Out of range! Try again." <<endl;
                    valid = false; //if invalid set condition to false and delete the array to start over
                }
            }
            else if((shot.length() == 2) && test > 0 && test <= 9){ //test and validate if coord is not '10'
                cout <<"Coordinates confirmed" <<endl;
                valid = true; //set condition to true once coordinate is confirmed valid
            }
            else{
                cout <<"Out of range! Try again." <<endl;
                valid = false; //if invalid set condition to false and delete the array to start over
            }
        }
        else{
            cout <<"Out of range! Try again." <<endl;
            valid = false; //if invalid set condition to false and delete the array to start over
        }
    }while (valid == false);
    return shot;
}

Prompt::~Prompt(){
    if(inputturn != NULL)
        delete inputturn; //delete all our dynamic variables down here
    if(inputturn != NULL)
        delete username;
    if(inputturn != NULL)
        delete inputmain;
}
