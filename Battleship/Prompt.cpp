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

}

string Prompt::hello(){ //a simple welcome to the game prompt that asks for a username
    bool valid = false;//set a control bool variable
    string username; //to take in their username
    cout <<"Welcome to Battleship!" <<endl;
    do{
        cout <<"Please enter username: "; //prompt enter their user name
        getline(cin, username); //take user input
        if (username.length() > 80){ //ensure it is not too long
            cout <<"Too large! Re-enter username... ";      
        }
    }while(valid == false);
    cout <<"Welcome, Captain " <<username <<endl; //welcome them to the game
    return username;
}

string Prompt::mainmenu(){ //function for the main menu - all inputs c strings for input validation
    string inputmain;
    bool valid = false; //to test for the do-while loop

    do{
        cout <<"What would you like to do: \n" //main menu prompt
                <<"1. Play against Computer \n"
                <<"2. Play two-player \n"
                <<"3. Load a saved game \n"
                <<"4. Quit \n";
        getline(cin, inputmain);     //getline input

        if (inputmain.length() > 2){ //to test out garbage inputs 
            cout <<"Invalid - too many inputs." <<endl;
            valid = false;
        }
        else if(inputmain == "1"){
            cout <<"AI is getting ready" <<endl; 
            valid = true;
        }
        else if (inputmain == "2"){
            cout <<"Enemy fleet approaching" <<endl; 
            valid = true;
        }
        else if (inputmain == "3"){ //loads save game
            cout <<"Loading saved game..." <<endl;
            valid = true;
        }
        else if (inputmain == "4"){
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
    string input;
    cout <<"Thankyou, please let other user take their seat and being their turn. " <<endl //ask other user to get on
            <<"When next player is ready, press any key and enter..." <<endl;
    cin >> input; //input doesn't matter, just something to tell they're on
}

void Prompt::winner(char *winner) { //prints out winner of game
    cout <<"Congratulations player: " <<winner <<"!" <<endl //insert username variable of winning player
            <<"You have won! " <<endl; //perhaps also put in their score
}

string Prompt::getboatcoord(int boatsize, char *name, string btName) {//for getting coordinates for boats
    cout <<name<< " choose coordinates for " << btName << endl; // displays the boat name of user
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

string Prompt::getshotcoord(char* name){ //getting a single coordinate for shooting
    bool valid = false; //bool for do while control
    string shot;
    do{
        cout << name << " Enter coordinates for the shot: " <<endl;
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
//                    cout <<"Coordinates confirmed" <<endl;;
                    valid = true; //set condition to true once coordinate is confirmed valid
                }
                else{
//                    cout <<"Out of range! Try again." <<endl;
                    valid = false; //if invalid set condition to false and delete the array to start over
                }
            }
            else if((shot.length() == 2) && test > 0 && test <= 9){ //test and validate if coord is not '10'
//                cout <<"Coordinates confirmed" <<endl;
                valid = true; //set condition to true once coordinate is confirmed valid
            }
            else{
//                cout <<"Out of range! Try again." <<endl;
                valid = false; //if invalid set condition to false and delete the array to start over
            }
        }
        else{
//            cout <<"Out of range! Try again." <<endl;
            valid = false; //if invalid set condition to false and delete the array to start over
        }
    }while (valid == false);
    return shot;
}

string Prompt::gtsavefilename(){
    string savefile;
    cout <<"Please enter the name of the file you wish to save to: " <<endl
            <<"NOTE: If you enter the same name as another file, it will be overwritten. Also remember this name for when you wish to load this game again." <<endl
            <<"File extensions are automatically applied." <<endl;
    getline(cin, savefile);
    savefile +=  ".bin"; //add .bin extension to user input
    return savefile;
}

string Prompt::gtloadfilename(){
    string loadfile;
    cout <<"Please enter the name of the file you wish to load from: " <<endl
            <<"File extensions are automatically applied." <<endl;
    getline(cin, loadfile);
    loadfile +=  ".bin"; //add .bin extension to user input
    return loadfile;
}

Prompt::~Prompt(){

}
