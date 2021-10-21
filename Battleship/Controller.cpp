/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Controller.cpp
 * Author: Angel Zambrano 
 *
 * Created on October 12, 2021, 11:55 PM
 */

#include "Controller.h"
#include <string.h>
#include <cstring>


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

    void  Controller::updNm(User* user, string usr) {
        prompt.user(usr);
        string usrName = prompt.hello();
        char userN[usrName.length() + 1];
        strcpy(userN, usrName.c_str());
        user->updNam(userN, strlen(userN));
    }
   
   // allocates memory for all the models and views
    void Controller::crtUsNBrd() {
       // allocates memory for a first player and their boards
     user1 = new User(); // user model
     brd = new Board(); // View - displays the boats of user 1 and the hits and misses of user 2.
     Sbrd = new Board(); // view - containts the hits and misses of the user1
     
    
     // allocates memory for a second player and their boards
     user2 = new User(); // user model
     brd2 = new Board();  // View- displays the boats and the hits and misses of user 1.
     Sbrd2 = new Board(); // view- creates the board for the user
    }
    
    
    // save the game 
    // in order to save a game the user be playing the
    void Controller::saveGame() {
        // ask the user to enter a file name 
        
        // save their game status using NSFIle 
        
        // quit the game.. do nothing
    }
    
              
   // the game controller for the 2 player game 
 void Controller::gameController() {
    
     // this means the users havent been created
     if (lgame == false) {
        // allocates memory for a first player (n brd) and second player 
      crtUsNBrd();  // allocating memory for first player (n its boards) and user2 and its boards
      // gets the name of two users 
      updNm(user1, gtuser1()); // updates the name of the user
      distt.clearScreen(); // clears the screen 
      updNm(user2, gtuser2()); // updates the name of the user
      
      // gets user bts 
      gtUsrBts(user1,brd); // gets the boat from user 1
      prompt.waitturn(); // lets the other player wait for their turn 
      gtUsrBts(user2,brd2); // gets the boat from user 1
      
//      user1->setCurUrs(true);
//     user2->setCurUrs(false);
      
     }
     
     // if lgame is true, the that means data has already beeen allocated in the loaded method 
     // so we dont need to allocate memory, or ask for user names or ask for usr boats
     

          // game begins
       Battleship *game = new Battleship(2);

       game->setUserOne(user1);
       game->setUserTwo(user2);
       

       User *cUser = user1; // the current player
       User *oUser = user2; // the other player

       Board *Cbrd = Sbrd; // The user hits and misses
       Board *CSbrd = brd2; // the enemy board that contains user hits and misses

        Coordinate *inpC; // inputted coordinate variable 
        Board *bwBoat ;
        Board *hmcUBrd;
        
        // assigns the bwboat to the approatiate board 
        (*cUser == *user1) ? (bwBoat = brd) : (bwBoat = brd2); // board with boats and hits and misses of enemy
         // assigns the Sbrd, to the appropriate user
        (*cUser == *user1) ? (hmcUBrd = Sbrd) : (hmcUBrd = Sbrd2);

        // beginning of the do while loop 
        do {
         
          distt.htsNMisTle(); // displays the title 
          // displays board
          distt.displayboard(bwBoat); // displasy the boats of current user along with the 
          cout << endl; // displays a new line 

          distt.yHmTle(); // displays title of hits and misses 
          distt.displayboard(hmcUBrd); // displays the hits and misses of current user
          cout << endl;
          
          string str = prompt.getshotcoord(cUser->gtName());
          // check if the user quit 
          if (str == "q" || "Q") { saveGame(); break;}
          // if the user quit, save their game
          
          inpC = strToSC(str); // translates coordinate string to coordinate type

          // check if it is a valid hit or if its a valid miss
          if (!((cUser->isMisB(inpC) || oUser->isHitb(inpC)))) {
              // clear the screen
              distt.clearScreen();
              // ask for input again
              continue; // asks for input again
          }
          
             // makes a move
             game->shotAttempt(cUser, inpC); // make a move with the current user
                                   // Update views
            updUsrViews(Sbrd, brd2,user1,user2);
            updUsrViews(Sbrd2,brd,user2,user1);

          // alternate the user
          (*cUser == *user1) ? (cUser = user2) :  (cUser = user1);
          // update the opposite user
          (*oUser == *user2) ? (oUser = user1) :  (oUser = user2);
         // assigns the bwboat to the approatiate board 
          (*cUser == *user1) ? (bwBoat = brd) : (bwBoat = brd2); // board with boats and hits and misses of enemy
          //  assigns the current user to 
          (*cUser == *user1) ? (hmcUBrd = Sbrd) : (hmcUBrd = Sbrd2);

       }while(!game->gameIsOver());

       clearScreen();
       
       if (game->gameIsOver()) {
            User *user = game->getWin();
             // display winner
            distt.winner(user->gtName());
       }
      
      


       delete game;
       // delete the boards 
       
    

 }
 
 void Controller::loadGame() {
      // load the game stuff here 
      // ask the user to input a file name 
      // set lname to the name of the file 
     
     
     // call the crtUsNBrd() method 
     
    // call the NSfile method to load the game 
      
     // set the lfile to true
     lfile = true;
     
     // if the game is playing against an AI, call the AI game method 
     
    // if the game is playing a 2 player game, Call gameController()
      
 }
 
 void Controller::mnMnCntrl() {
             
       string userI = prompt.mainmenu();
       Display dist;
       if (userI == "1") {
           cout << "1111" << endl;
       } else if (userI == "2") {
        // play a 2 player game 
           dist.clearScreen();
           gameController();
           
       } else if ((userI == "3")) {
           lgame = true; 
           loadGame();
        
       } else if (userI == "4") {
           return;
       }
      
   }
   
 // the constructor decides which game will be played 
   Controller:: Controller() {
       distt = Display();
       // calls the main menu control 
        mnMnCntrl();
   }
   
   // this is called 
   void Controller::cleanUp() {
       cout << "here 1" << endl;
       delete user1;
        cout << "here 2" << endl;
       delete user2;
        cout << "here 3" << endl;
       delete brd;
        cout << "here 4" << endl;
       delete Sbrd;
        cout << "here 5" << endl;
       delete brd2;
        cout << "here 6" << endl;
       delete Sbrd2;
        cout << "here 7" << endl;
       
   }
   
   
   // helps get the userBts, and updates the user board 
   void Controller::gtUsrBts(User *user, Board* brd) {
      
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
       // check if the user quit the game 
      
       if (usrCord == "q" || usrCord == "Q") { 
           
           // clean up the rest of thee array
           for (int j = i ; j < user->reqBSz(); j++) {
               cout << j << endl;
               delete bts[j];
           }
           
         
           // clean up 
           cleanUp();
           
           // deletes the array 
           delete [] bts;
           
           // go back to main menu
           mnMnCntrl();
           
       }
       
       Coordinate **bCord = strTCo(usrCord,sz);

       // check if the coordinate is unique
       // if it is not unique, we ask for input again
       if ( !(user->CrdsNotTaken(bCord,sz )) || (!(bts[i]->alCords(bCord, sz)))) {
           i--;
           continue;
       }

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

   // converts a string to a coordinate array 
   // the string size will always be 2 or 3. 
   // our prompt class takes care of this 
   Coordinate *Controller::strToSC(string sC) {
    // you prompt class is doing something wrong
    if (sC.length() != 3 && sC.length() != 2) {
        inptval.memStr(); // displays the an error before exiting 
        exit(1);
    }

    //
    Coordinate *cord = NULL; // set it to null

    // here im assuming the string i got is correct forma a1 or A1 or A10

    // it means user inputted a letter + 10
    if (sC.length() == 3) {
        // we know the col is ten since size is 3
        // letter is the first character
        cord = new Coordinate(cnvrtLet(sC[0]), 9);


    } else if (sC.length() == 2) { // ther user inputted a letter and a
        cord = new Coordinate(cnvrtLet(sC[0]),cnvrt(sC[1]));
   }
    
    return cord;
} // end of strToSC

   // helps updUsrViews
   void Controller::updUsrViews(Board* Sbrd, Board *Ebrd, User* us1, User *us2) {
       // you get the misses from user 1 and update it's board
       Sbrd->upmss(us1->gtmiss(), us1->gtTotmiSz());

       // update the user 1 hits into Sbr
       // user 1 hits are located in user2 boats
       Sbrd->upHts(us2->gtboats(), us2->gtTotBtsz());

       // update the enemey board of user 1 with the user1 misses 
       Ebrd->upmss(us1->gtmiss(), us1->gtTotmiSz());
       
       // update the enemy board of user1 with the user2 boat hits. 
       Ebrd->upHts(us2->gtboats(), us2->gtTotBtsz());

   }
