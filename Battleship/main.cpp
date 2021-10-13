/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: AZ
 *sss sjsjsjjs old
 * Created on September 26, 2021, 12:43 PM
 */

#include <cstdlib>
#include "Game.h"
#include <iostream>
#include "Coordinate.h"
#include "Boat.h"
#include "AbsBoat.h"
#include "Display.h"
#include <cstring>
#include "User.h"
#include "Boat.h"
#include "Board.h"
#include "Prompt.h"
#include <string>
#include "Battleship.h"

using namespace std;

// We need someone to work on: 
// TODO #1: creating the boats (inheritance of diff boats)
// TODO #2: Cordinates 
// TODO #3 Battleship 2 player game - Angel 
// TODO 3b Battleship playing against a PC - Coder Kai 
// TODO #4 the User 
// TODO #5 The file saving/retrieving - Ethanol/Angel
// TODO #6 Prompt class
// TODO #7 Display class  


// method to translate the prompt to coordinates
Coordinate** strTCo(string, int btsz); // takes in a coordinate A1 A2 A3 and returns coordinates (0,1), (0,1), (0,2)
//int Coordinate::cnvrtLet(char letter); // converts a character number to an integer 
                                       // convrting a character letter to a
//int  Coordinate::cnvrt(char digit);
 
   int cnvrtLet(char letter);
   int cnvrt(char digit);
   Coordinate *strToSC(string sC);
    void clearScreen();
    void updUsrViews(Board*Sbrd, Board *Ebrd, User* us1, User *us2); 
   void updUsr2Views(Board*Sbrd2, Board *Ebrd1, User* us2, User *us1); 
    void updUsr2Views();
   
 
   
int main(int argc, char** argv) {
    
    
     Display *distt = new Display; // displays board
    
    
    // create the user 1 
      User *user1 = new User(); // user model
      char user1N[] = "angel";
      Board *brd = new Board(); // View - displays the boats of user 1 and the hits and misses of user 2.
      Board *Sbrd = new Board(); // containts the hits and misses of the user1 
      user1->updNam(user1N, 1);
      
      
   
      
      // create the user 2
      User *user2 = new User(); // user model 
      Board *brd2 = new Board();  // View- displays the boats and the hits and misses of user 1.
      Board *Sbrd2 = new Board();
      char user2N[] = "monster"; 
      user2->updNam(user2N, 1);

 
      // creates a destroyer 
      string des = "a1 a2";
      Coordinate **dest2 = strTCo(des, 2); // reads two pos 
      Destroyer *de = new Destroyer();
//      de->addCord(dest2[0]);
//      de->addCord(dest2[1]);
      
      de->addCords(dest2,2); // testing adding a coordinate
    
      // add the destroyer to user 1
        user1->adBoat(de);
   
      
        
        
        
//     // created a submarine
      string sub = "b1 b2 b3";
      Coordinate **sub1 = strTCo(sub, 3); // reads two pos 
      Submarine *subb = new Submarine();
      subb->addCords(sub1,3);
      user1->adBoat(subb);
      
      
//      
      string crui = "c1 c2 c3";
      Cruiser *cru = new Cruiser();
      Coordinate **crui1 = strTCo(crui, 3); 
      cru->addCords(crui1,3); // adds a cruiser
      
      // adds boat to user 1 
      user1->adBoat(cru);
      
      
//     
//       // created a battle 
      string battl = "d1 d2 d3 d4";
      Battleshp *ballt = new Battleshp(); // creates a batleship game
      Coordinate **battl1 = strTCo(battl, 4); 
      ballt->addCords(battl1,4);
     
      // adds user1 to boat
      user1->adBoat(ballt);
//      
//    
     string carry = "e1 e2 e3 e4 e5";
     Coordinate **carr = strTCo(carry, 5); 
     Carrier *car = new Carrier(); 
     car->addCords(carr,5);
     
     // ads a boat to user1
     user1->adBoat(car); //
       
     brd->adBoat(de);
     brd->adBoat(subb);
     brd->adBoat(cru);
     brd->adBoat(ballt);
     brd->adBoat(car);
     
     distt->displayboard(brd);
     cout << endl;
//     
     //dwmqd qwmdkqwjdnwqkjdnwkqjdnwjkdnq
     //dbhdnjdkqwndjqwnkdjqwnkdjwqnkd
     ///dqwdkqwdkqwndkjwqndkjwqndkjwqndjkqw
     
                                         // add boats to user2
     
//     // creates a destroyer 
      string Udes = "g3 h3";
      Coordinate **Udest2 = strTCo(Udes, 2); // reads two pos 
       Destroyer *Ude = new Destroyer();
      Ude->addCords(Udest2,2); // testing adding a coordinate
      // add the destroyer to user 1
      user2->adBoat(Ude);
//      
//      
//      
//      
//      // creates a sub for user 2
//      
      string su2 = "a6 b6 c6";
      Coordinate **sub2 = strTCo(su2, 3); // reads 3 pos 
      Submarine *subb2 = new Submarine();
      subb2->addCords(sub2, 3); // testing adding a coordinate
      // adds sub the 
      user2->adBoat(subb2);
//      
//      
////      // create cruiser 
      string cru2 = "d5 d6 d7";
      Coordinate **Ucru2 = strTCo(cru2, 3);
      Cruiser *ucru22 = new Cruiser();
      ucru22->addCords(Ucru2,3); // addings 3 coordinates to cruiser      
      user2->adBoat(ucru22);
////
////    
////      // create a battleshp
////      
      string btle2 = "f5 f6 f7 f8";
      Coordinate **Ubtle2 = strTCo(btle2, 4);
      Battleshp *ubtle2 = new Battleshp(); 
      ubtle2->addCords(Ubtle2, 4);
////      
      user2->adBoat(ubtle2);
      // create a crarried 
////      
      string carry2 = "j4 j5 j6 j7 j8";
      Coordinate **Ucarry2 = strTCo(carry2, 5);
      Carrier *car2 = new Carrier();
      car2->addCords(Ucarry2, 5);
      user2->adBoat(car2);
      
       brd2->adBoat(Ude);
       brd2->adBoat(subb2);
       brd2->adBoat(ucru22);
       brd2->adBoat(ubtle2);
       brd2->adBoat(car2);
    
       distt->displayboard(brd2);
      
       
       if (user1->alBrDead()) {
           cout << "boats are dead" << endl;
       }else {
           cout << " not all boats r dead" << endl;
       }
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       // before we begin game
       
       // ask user for the game
       int gmeType = 2; 
      
                                        // game begins 
       Battleship *game = new Battleship(2);
       
       game->setUserOne(user1);
       game->setUserTwo(user2);
       
       User *cUser = user1; // the current player 
       User *oUser = user2; // the other player
       
       
       Board *Cbrd = Sbrd; // The user hits and misses 
       Board *CSbrd = brd2; // the enemy board that contains user hits and misses 
       
          
     
       
       Coordinate *inpC; // inputted coordinate
        Board *bwBoat ;
        Board *hmcUBrd;
        
        (*cUser == *user1) ? (bwBoat = brd) : (bwBoat = brd2); // board with boats and hits and misses of enemy
        (*cUser == *user1) ? (hmcUBrd = Sbrd) : (hmcUBrd = Sbrd2);
        
        
        
        clearScreen();
       
        
        // TODO: 
        
        // get correct input validation using Prompt class 
        
        do {
          cout << "the hits and misses of the enemy + ur boats" << endl;      
          // displays board
          distt->displayboard(bwBoat);
          cout << endl;
                  
          cout << "you hits and misses" << endl;
          distt->displayboard(hmcUBrd);
        
          // it will be here 
          string str; 
          cout << cUser->gtName() << " enter a coordinate: ";
          getline(cin, str);
          cout << str << endl;
          inpC = strToSC(str); 
           
          // makes a move
          game->shotAttempt(cUser, inpC); // make a move with the current user
          
          
                                   // Update views 
         updUsrViews(Sbrd, brd2,user1,user2); 
         updUsrViews(Sbrd2,brd,user2,user1);   
          
           
          cout << "press n to continue " << endl;
          getline(cin, str);
   
        (*cUser == *user1) ? (bwBoat = brd) : (bwBoat = brd2); // board with boats and hits and misses of enemy
        
        (*cUser == *user1) ? (hmcUBrd = Sbrd) : (hmcUBrd = Sbrd2);
       
       }while(!game->gameIsOver()); 
       
       cout << "game us over " << endl;
      
       
       
       // clean up 
       
       
       
    return 0;
}




// the string should be either of size 3 or size 2
// here I convert one coordinate for making a move 
Coordinate *strToSC(string sC) {
    // you prompt class is doing something wrong 
    if (sC.length() != 3 && sC.length() != 2) {
        cout << sC.length() << endl;
        cout << "length of string is not 2 or 3" << endl;
        exit(1);
    }
    
    //this 
    Coordinate *cord = NULL; // set it to null 
    
    // here im assuming the string i got is correct forma a1 or A1 or A10 
    
    // it means user inputted a letter + 10 
    if (sC.length() == 3) {
        // we know the col is ten since size is 3 
        // letter is the first character 
        cord = new Coordinate(cnvrtLet(sC[0]), 9);
        
             
    } else if (sC.length() == 2) { // ther user inputted a letter and a
       
        cord = new Coordinate(cnvrtLet(sC[0]),cnvrt(sC[1]));
//        return new Coordinate(cnvrtLet(sC[0]),cnvrt(sC[1]));
    }
    
    
  
    
    return cord;
}

// TODO:
Coordinate** strTCo( string strC, int btsz) {
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

   int cnvrt(char digit) {
     
       
//       switch(digit) {
//           case '1':
//            return 0;
//           case '2':
//                return 1;
//           case '3':
//              return 2;
//           case '4':
//              return 3; 
//           case '5':
//             return 4;
//           case '6':
//              return 5;
//           case '7':
//               return 6;    
//           case '8':
//               return 7;
//          case '9':
//               return 8; 
//              
//       }
               
               
               
       
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

// convert string to integer 
   int cnvrtLet(char letter) {
    
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
   
   // update the views of user1 
   void updUsrViews(Board* Sbrd, Board *Ebrd, User* us1, User *us2) {
       // you get the misses from user 1 and update it's board
       Sbrd->upmss(us1->gtmiss(), us1->gtTotmiSz());
       
       // update the user 1 hits into Sbr
       // user 1 hits are located in user2 boats
       Sbrd->upHts(us2->gtboats(), us2->gtTotBtsz());
       
       
       Ebrd->upmss(us1->gtmiss(), us1->gtTotmiSz());
       Ebrd->upHts(us2->gtboats(), us2->gtTotBtsz());
       
   }
   
   
   
   // TODO: a input validation class 
   void clearScreen() {
       cout << string(100,'\n');
   }
