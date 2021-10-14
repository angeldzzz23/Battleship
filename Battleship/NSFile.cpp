/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NSFile.h"

using namespace std;

void NSFile::savethegame(User* user1, User* user2){//saving a game
    gamesaver.index = 1;
    
    gamesaver.player1.id = user1->getId();    
    gamesaver.player1.isturn = true;
    gamesaver.player1.boatsz = user1->gtTotBtsz();
    gamesaver.player1.missSz = user1->gtTotmiSz();
    
    gamesaver.player1.boats = new Boat*[gamesaver.player1.boatsz];
    for (int c = 0; c < gamesaver.player1.boatsz; c++){
        gamesaver.player1.boats[c] = user1->getBoat(c);
    }
    
    
    gamesaver.player2.id = user2->getId();
    gamesaver.player2.isturn = false;
    gamesaver.player2.boatsz = user2->gtTotBtsz();
    gamesaver.player2.missSz = user2->gtTotmiSz();
    
    gamesaver.player2.boats = new Boat*[gamesaver.player2.boatsz];
    for (int c = 0; c < gamesaver.player2.boatsz; c++){
        gamesaver.player2.boats[c] = user2->getBoat(c);
    }
    
    
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
    
    fstream savefile;
    savefile.open("savedgames.bin", ios::out|ios::binary|ios::trunc);
    if(savefile.is_open()){
        savefile.write(reinterpret_cast<char *> (&gamesaver), sizeof(gamesave));
    }
    else{
        cout <<"File fail!" <<endl;
    }
    savefile.close();
    cout <<"File closed... deleting..." <<endl;
    for(int i = 0; i <gamesaver.player1.boatsz;i++ ) {
        delete gamesaver.player1.boats[i]; 
        gamesaver.player1.boats[i] = NULL; 
    }    
    delete [] gamesaver.player1.boats;

    for(int i = 0; i <gamesaver.player2.boatsz;i++ ) {
        delete gamesaver.player2.boats[i]; 
        gamesaver.player2.boats[i] = NULL; 
    }    
    delete [] gamesaver.player2.boats;
}

void NSFile::readingame(){//loading in a game
    fstream loadfile;
    loadfile.open("savedgames.bin", ios::in|ios::binary);
    if (loadfile.is_open()){
        long cursor = 0L;
        loadfile.seekg(0);
        loadfile.read(reinterpret_cast<char *> (&gameloader), sizeof(gamesave));
        loadfile.close();
    }
    else{
        cout <<"File fail!" <<endl;
    }
    
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