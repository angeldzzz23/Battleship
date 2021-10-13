/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NSFile.h"

using namespace std;

void NSFile::savethegame(){//saving a game
    gamesaver.index = 1;
    gamesaver.player1.id = 1111;
    gamesaver.player2.id = 2222;
    gamesaver.player1.isturn = true;
    gamesaver.player2.isturn = false;
    
    cout <<"Data to be saved... " <<endl;
    cout <<gamesaver.index <<endl;
    cout <<"Player 1 Id: "<<gamesaver.player1.id <<endl;
    cout <<"Player 1 turn: "<<gamesaver.player1.isturn <<endl;
    cout <<"Player 2 Id: " <<gamesaver.player2.id <<endl;
    cout <<"Player 2 turn: " <<gamesaver.player2.isturn <<endl;
    
    fstream savefile;
    savefile.open("savedgames.bin", ios::out|ios::binary|ios::trunc);
    if(savefile.is_open()){
        savefile.write(reinterpret_cast<char *> (&gamesaver), sizeof(gamesave));
    }
    else{
        cout <<"File fail!" <<endl;
    }
    savefile.close();
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
    cout <<"Player 1 Id: "<<gameloader.player1.id <<endl;
    cout <<"Player 1 turn: "<<gameloader.player1.isturn <<endl;
    cout <<"Player 2 Id: " <<gameloader.player2.id <<endl;
    cout <<"Player 2 turn: " <<gameloader.player2.isturn <<endl;
            
}