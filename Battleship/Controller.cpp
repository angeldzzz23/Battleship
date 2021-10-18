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
   
   // 
   Controller:: Controller() {
       
   
     Display *distt = new Display(); // displays board
     Prompt prompt;

     
    // create the user 1
      User *user1 = new User(); // user model
      char user1N[] = "angel";
      Board *brd = new Board(); // View - displays the boats of user 1 and the hits and misses of user 2.
      Board *Sbrd = new Board(); // containts the hits and misses of the user1
      user1->updNam(user1N, 1);

      
      // create the user 2
      User *user2 = new User(); // user model
      Board *brd2 = new Board();  // View- displays the boats and the hits and misses of user 1.
      Board *Sbrd2 = new Board(); // 
      char user2N[] = "monster";
      user2->updNam(user2N, 1);
      
//      string sssr;
      gtUsrBts(user1,brd); // gets the boat from user 1
//      cout << "user 2 press enter to continue" << endl;
//      getline(cin, sssr); // change this later
//      
      gtUsrBts(user2,brd2); // gets the boat from user 1
      
      
      
      
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
        
        
   
        
        do {
          cout << "the hits and misses of the enemy + ur boats" << endl;
          // displays board
          distt->displayboard(bwBoat);
          cout << endl;

          cout << "you hits and misses" << endl;
          distt->displayboard(hmcUBrd);
          cout << endl;
          // it will be here
          string str = prompt.getshotcoord(cUser->gtName());
          inpC = strToSC(str); // transalates coordinate string to coordinate type 
         
          
         
          
          // check if it is a valid hit or if its a valid miss 
          if (!((cUser->isMisB(inpC) || oUser->isHitb(inpC)))) { 
              // clear the screen 
              clearScreen();
              // ask for input again
              continue; // asks for input again 
          }
          
        
             // makes a move 
             game->shotAttempt(cUser, inpC); // make a move with the current user
                                   // Update views
            updUsrViews(Sbrd, brd2,user1,user2);
            updUsrViews(Sbrd2,brd,user2,user1);
            
            
//          cout << "press n to continue " << endl;
//          getline(cin, str);

          // alternate the user 
//          (*cUser == *user1) ? (cUser = user2) :  (cUser = user1);
//          
//          // update the opposite user 
//          (*oUser == *user2) ? (oUser = user1) :  (oUser = user2);
//         
//          // updates the boards
//          (*cUser == *user1) ? (bwBoat = brd) : (bwBoat = brd2); // board with boats and hits and misses of enemy
//
//          (*cUser == *user1) ? (hmcUBrd = Sbrd) : (hmcUBrd = Sbrd2);

       }while(!game->gameIsOver());
       
       clearScreen();
       User *user = game->getWin(); 
       // display winner
       prompt.winner(user->gtName());
      
 
       delete game;
//        delete display;

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
   
   
   Coordinate *Controller::strToSC(string sC) {
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
   
   
   void Controller::updUsrViews(Board* Sbrd, Board *Ebrd, User* us1, User *us2) {
       // you get the misses from user 1 and update it's board
       Sbrd->upmss(us1->gtmiss(), us1->gtTotmiSz());

       // update the user 1 hits into Sbr
       // user 1 hits are located in user2 boats
       Sbrd->upHts(us2->gtboats(), us2->gtTotBtsz());


       Ebrd->upmss(us1->gtmiss(), us1->gtTotmiSz());
       Ebrd->upHts(us2->gtboats(), us2->gtTotBtsz());

   }