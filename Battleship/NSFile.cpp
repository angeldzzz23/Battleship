/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NSFile.h"

using namespace std;

void NSFile::savethegame(User* user1, User* user2){//saving a game
    gamesaver.index = 1;//game index
    
    //transfer all necessary information from User1 into player1
    gamesaver.player1.id = user1->getId();   //get user 1 id 
    gamesaver.player1.isturn = true; //turn
    gamesaver.player1.boatsz = user1->gtTotBtsz(); //size of their boat array
    gamesaver.player1.missSz = user1->gtTotmiSz(); //size of their miss array
    
    for (int c = 0; c < gamesaver.player1.boatsz; c++){
        gamesaver.player1.boats[c] = user1->getBoat(c);
    }
    
    //transfer information from User2 to player2
    gamesaver.player2.id = user2->getId(); //their ID
    gamesaver.player2.isturn = false; //if it's their turn
    gamesaver.player2.boatsz = user2->gtTotBtsz(); //their boat array size
    gamesaver.player2.missSz = user2->gtTotmiSz(); //their miss array size
    
    for (int c = 0; c < gamesaver.player2.boatsz; c++){
        gamesaver.player2.boats[c] = user2->getBoat(c);
    }
    
    //print data back out to ensure it has been received correctly (TEST)
    cout <<"Data to be saved... " <<endl;
    cout <<gamesaver.index <<endl;
    cout <<"Player 1 Id: "<<gamesaver.player1.id <<endl;
    cout <<"Player 1 turn: "<<gamesaver.player1.isturn <<endl;
    cout <<"Player 1 boat size: " <<gamesaver.player1.boatsz <<endl;
    cout <<"Player 1 miss size: " <<gamesaver.player1.missSz <<endl;
    cout <<"Player 2 Id: " <<gamesaver.player2.id <<endl;
    cout <<"Player 2 turn: " <<gamesaver.player2.isturn <<endl;
    cout <<"Player 2 boat size: " <<gamesaver.player2.boatsz <<endl;
    cout <<"Player 2 miss size: " <<gamesaver.player2.missSz <<endl;
    
    fstream savefile; //open file stream
    savefile.open("savedgames.bin", ios::out|ios::binary|ios::trunc);//open the saved games file
    if(savefile.is_open()){//test that file is indeed open
        savefile.write(reinterpret_cast<char *> (&gamesaver), sizeof(gamesave));//write to the file using our super structure
    }
    else{
        cout <<"File fail!" <<endl;//print out error for if the file fails
    }
    savefile.close();//close the file
    cout <<"File closed... deleting..." <<endl;
    

}

void NSFile::readingame(){//loading in a game
    fstream loadfile;//start the file stream
    loadfile.open("savedgames.bin", ios::in|ios::binary);//open savedgames.bin
    if (loadfile.is_open()){ //test file is open
        long cursor = 0L;
        loadfile.seekg(0); //set the cursor
        loadfile.read(reinterpret_cast<char *> (&gameloader), sizeof(gamesave));//read in the gamesave structure
        loadfile.close();
    }
    else{
        cout <<"File fail!" <<endl;//error for if fail fails to open
    }   
    //print out to ensure that data was loaded correctly (TEST)
    cout <<"Data loaded in... " <<endl;
    cout <<gameloader.index <<endl;
    cout <<"Player 1: " <<endl;
    cout <<"Player 1 Id: "<<gameloader.player1.id <<endl;
    cout <<"Player 1 turn: "<<gameloader.player1.isturn <<endl;
    cout <<"Player 1 boat size: " <<gameloader.player1.boatsz <<endl;
    cout <<"Player 1 miss size: " <<gameloader.player1.missSz <<endl;
    
    cout <<endl <<"Player 2: " <<endl;
    cout <<"Player 2 Id: " <<gameloader.player2.id <<endl;
    cout <<"Player 2 turn: " <<gameloader.player2.isturn <<endl;
    cout <<"Player 2 boat size: " <<gameloader.player2.boatsz <<endl;
    cout <<"Player 2 miss size: " <<gameloader.player2.missSz <<endl;
    
            
}