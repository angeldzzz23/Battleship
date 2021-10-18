/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controller.cpp
 * Author: Admin
 * 
 * Created on October 12, 2021, 11:55 PM
 */

#include "Controller.h"

   // TODO: a input validation class
   void Controller::clearScreen() {
       cout << string(100,'\n');
   }
   
   
   int Controller::cnvrt(char digit) {
       if(digit<'0'||digit>'9'){
        cout<<"You don't know what you are doing"<<endl;
        exit(0);
      }

      //compensate if 0 is input
     if(digit=='0'){
         return digit-'0';
     }

    return digit-'0'-1;
   }
   
   int Controller::cnvrtLet(char letter) {
       
       switch(letter) {
           case 'a':
               return 0;
           case 'b':
               return 1;
           case 'c':
               return 2;
           case 'd':
               return 3;
           case 'e':
               return 4;
           case 'f':
               return 5;
           case 'g':
               return 6;
           case 'h':
               return 7;
           case 'i':
               return 8;
          case 'j':
               return 9;

       }

       return -1;
   }
   
   Controller:: Controller() {
       
   }
   
   void Controller::gtUsrBts(User *user, Board* brd) {
      Prompt prompt;
     Display dist;
     // the name of the boats
    string name[6] = {"destroyer", "submarine", "cruiser", "battleship", "carrier"};
    
    // translates the boat size to the name 
    map<string, int> boatToSize = {
        {"destroyer", 2}, {"submarine", 3}, {"cruiser", 3}, {"battleship", 4}, {"carrier", 5}, 
    };
    
    
      // create a new destroyer 
      Destroyer *destroyer = new Destroyer();
      Submarine *submarine = new Submarine();
      Cruiser   *cruiser = new Cruiser();
      Battleshp *batle  = new Battleshp(); 
      Carrier  *carrier = new Carrier();
      
     // get the boars for the user 
      Boat **bts = new Boat*[5];
         bts[0] =destroyer; 
         bts[1] = submarine;
         bts[2] = cruiser;
         bts[3] = batle;
         bts[4] = carrier;
     
       
      // gets the boat from the user 
    for (int i = 0; i < user->reqBSz(); i++) {
       // clears the UI
       clearScreen();
       dist.displayboard(brd);
       string chssz = name[i];
       int sz = boatToSize[chssz]; //gets the size for that boat
       string usrCord = prompt.getboatcoord(sz,user->gtName(),chssz);
       Coordinate **bCord = strTCo(usrCord,sz);
       
       // check if the coordinate is unique
       if ( !(user->CrdsNotTaken(bCord,sz )) || (!(bts[i]->alCords(bCord, sz)))) {
           cout << "ask for input again"  << endl;
           
           i--;
           continue; 
       } 
     
       // check if each coordinate is not good
       
       bts[i]->addCords(bCord, sz);
       // add the boat to user   
       user->adBoat(bts[i]);
       
       // update the board view 
        brd->update(user->gtboats(), user->gtTotBtsz());
       
    }
         
       delete [] bts;
      
   }
   
   Coordinate** Controller::strTCo( string strC, int btsz) {
    string inSCrd[10]; // individual string coordinates
    int totInx = 0;
    string str; // adding elements here and then adding them into inSCrd


    for (int i = 0; i < strC.length(); i++) {

        if (isdigit(strC[i]) && !isdigit(strC[i + 1])) { // checks if it is a digit
          str += strC[i]; // this completes the entire  letter
          inSCrd[totInx] = str;

          totInx++; // incrementing sz of this
          str.clear(); // clears the string

          continue;
        }

        if (strC[i] == ' ') { // we read an empty space
            continue;
        }
          str += strC[i];
    }

    // get the sze of the boats
    Coordinate **cords = new Coordinate*[btsz];
    int s = 0; // size of the coordinate

     int row;
     int col;

     for (int i = 0; i < totInx; i++) {
         // length > 3
         if (inSCrd[i].length() == 3) { // there is a letter and a 10
             string cop = inSCrd[i]; // the copy of the
             row =  cnvrtLet(cop[0]); // convert the letter into a digit
             col = 9; // converts the col to 9
             cout << " " << row << " " << col << endl;
             Coordinate *cord = new Coordinate(row, col);
             cords[s] = cord;
             s += 1;
         } else { // a letter and a digit that is 1 through 10
             string cop = inSCrd[i];
             row = cnvrtLet(cop[0]); // get the first letter
             col = cnvrt(cop[1]); // converts the col

             Coordinate *cord = new Coordinate(row, col);
             cords[s] = cord;
             s += 1;
         }

     }

    return cords;
}