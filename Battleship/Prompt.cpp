/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 *Version 1 - Ethan and Yanis - basic prompting for functions + inputs and input validation. Will still need to link up with other classes for full functionality but the bases are made
 */

#include "Prompt.h"
#include "Boat.h"
#include <iostream>
#include <cstring>


using namespace std;

char* Prompt::hello(){ //a simple welcome to the game prompt that asks for a username
    cout <<"Welcome to Battleship!" <<endl;
    cout <<"Please enter username: "; //enter their user name
    int size = 50;
    username =new char[size];
    cin.getline(username,size-1);
    cout <<username <<endl;
    return username; //delete dynamic array
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
            valid == true;
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
            valid == true;
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
    int size = 50;
    winner = new char[size];
    cout <<"Congratulations player: " <<winner <<"!" <<endl //insert username variable of winning player 
            <<"You have won! " <<endl; //perhaps also put in their score
    delete winner; //delete here since this funciton will not be returning anything
}

char** Prompt::getboatcoord(int boatsize){//for getting coordinates for boats
    int size = 25;//having a large size helps prevent infinite loops
    char *array[boatsize];//int boatsize depends on how large ship is = number of coordinates
    int c = 0;
    for ( ;c < boatsize; c++){ //loop depending on the size of the ship - battleship = 4 iterations, crusier = 3, etc.
        bool valid = false;
        do{
            array[c] = new char[size];//initialize the char array within the character array
            cout <<"Please enter coordinate " <<c+1 <<" of " <<boatsize <<" for the position of your ship: " <<endl;
            cin.getline(array[c], size-1);//get user input
            
            //assign data to variables, then convert them to make data validation easier - since it's on variables the data itself will be preserved
            int comp = (int)array[c][0]; //ascii 2 of the ch coordinate (A-J) to make testing easier
            char test = array[c][1];
            test -= '0'; //the two following ch are also converted to integers, the -'0' to clear up ascii stuff
            char test2 = array[c][2];
            test2 -= '0'; //the two following ch since the largest coord will be x10 - anything larger is invalid

            if(strlen(array[c])>3){ //anything larger than 3 is invalidated
                cout <<"Input too long, try again" <<endl;
                valid = false; //set the condition as being false
                delete array[c]; //delete the char array to make room for a new one with better data
            }
            else{
                if ((comp >= 65 && comp <= 74) || (comp >= 96 && comp <= 106)){ //test the char part of coord is correct - done with ascii values so much easier
                    if(strlen(array[c]) == 3 && test == 1 && test2 == 0){ //to see if the coordinate is a '10'
                        cout <<"Coordinates registered" <<endl;
                        valid = true; //everything checks out - char and number, so condition is true
                        array[c][3] = '\0'; //set null terminator to the 4th position, since the maximum size should be 3
                    }
                    else if((strlen(array[c]) == 2) && test > 0 && test <= 9){ //check number if it is not a '10'
                        cout <<"Coordinates registered" <<endl;
                        valid = true; //everything checks out - char and number, so condition is true
                        array[c][2]='\0'; //set null terminator to the 3rd position - since size of this array is only 2
                    }
                    else{ //for if the number coordinate is bad
                        cout <<"Out of bounds, please reenter." <<endl;
                        valid = false; //set condition to false
                        delete array[c]; //delete array
                    }
                }
                else{//letter no good
                    cout <<"Out of bounds, please reenter." <<endl;
                    valid = false; //set false
                    delete array[c]; //delete
                }
            }
        }while (valid == false); //test condition - is a bool to simplify it since it would be aggregious to retype all the conditions that must be meet up above back in here
    } //end of for loop
    cout <<"Here!" <<endl;
    return array;        //return the completed array
}

char* Prompt::getshotcoord(){ //getting a single coordinate for shooting
    int size = 5;
    bool valid = false; //bool for do while control
    do{
        scoordinate = new char[size];    //dynamically allocate char array for coordinate
        cout <<"Enter coordinates for the shot sir: " <<endl;
        cin.getline(scoordinate,size-1); //take it

        //conversions of data types to make validation easier - also done on seperate variables to preserve data
        int comp = (int)scoordinate[0];
        char test = scoordinate[1];
        test -= '0';
        char test2 = scoordinate[2];
        test2 -= '0';

        //validate the data
        if ((comp >= 65 && comp <= 74) || (comp >= 96 && comp <= 106)){ //using ascii values to validate teh char coordinate
            if(strlen(scoordinate) == 3 && test == 1 && test2 == 0){ //test and validate for coord is a '10'
                cout <<"Coordinates confirmed" <<endl;;
                valid = true; //set condition to true once coordinate is confirmed valid
            }
            else if((strlen(scoordinate) == 2) && test > 0 && test <= 9){ //test and validate if coord is not '10'
                cout <<"Coordinates confirmed" <<endl;
                valid = true; //set condition to true once coordinate is confirmed valid
            }
            else{
                cout <<"Out of range! Try again." <<endl;
                valid = false; //if invalid set condition to false and delete the array to start over
                delete scoordinate;
            }
        }
        else{
            cout <<"Out of range! Try again." <<endl;
            valid = false; //if invalid set condition to false and delete the array to start over
            delete scoordinate;
        }
    }while (valid == false);
    return scoordinate;
}

Prompt::~Prompt(){
    delete inputturn; //delete all our dynamic variables down here
    delete username;
    delete inputmain;
    delete bcoordinate;
    delete scoordinate;
}

