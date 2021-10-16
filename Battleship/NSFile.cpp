/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NSFile.h"

using namespace std;

NSFile::NSFile(){
    transferdes = new Coordinate*[2];
    transfersub = new Coordinate*[3];
    transfercruise = new Coordinate*[3];
    transferbattle = new Coordinate*[4];
    transfercarr = new Coordinate*[5];
}

void NSFile::savethegame(User* user1, User* user2){//saving a game
    gamesaver.index = 1;//game index
    
    //transfer all necessary information from User1 into player1
   // gamesaver.player1.id = user1->getId();   //get user 1 id 
    //gamesaver.player1.isturn = true; //turn
    //gamesaver.player1.missSz = user1->gtTotmiSz(); //size of their miss array
    
    for(int c=0; c < 2; c++){     //destroyer
        cout <<"Destroyer: " <<endl;
        cout <<"Row: " <<user1->getBoat(0)->cordAt(c)->getRow() <<endl;
        cout <<"Col: "  <<user1->getBoat(0)->cordAt(c)->getCol() <<endl;
        gamesaver.player1.destroy.position[c].row = user1->getBoat(0)->cordAt(c)->getRow();
        gamesaver.player1.destroy.position[c].col = user1->getBoat(0)->cordAt(c)->getCol();
        cout <<"Coordinate integers row: " <<gamesaver.player1.destroy.position[c].row <<endl;
        cout <<"Coordinate integers col: " <<gamesaver.player1.destroy.position[c].col <<endl;        
    }
    gamesaver.player1.destroy.dead = user1->getBoat(0)->isDead();
    cout <<"Is dead? " <<gamesaver.player1.destroy.dead <<endl;
    
    for(int c=0; c < 3; c++){   //submarine
        cout <<"Submarine: " <<endl;
        cout <<"Row: " <<user1->getBoat(1)->cordAt(c)->getRow() <<endl;
        cout <<"Col: "  <<user1->getBoat(1)->cordAt(c)->getCol() <<endl;
        gamesaver.player1.sub.position[c].row = user1->getBoat(1)->cordAt(c)->getRow();
        gamesaver.player1.sub.position[c].col = user1->getBoat(1)->cordAt(c)->getCol();
        cout <<"Coordinate integers row: " <<gamesaver.player1.sub.position[c].row <<endl;
        cout <<"Coordinate integers col: " <<gamesaver.player1.sub.position[c].col <<endl;                 
    }
    for(int c=0; c < 3; c++){     //cruiser
        cout <<"Cruiser: " <<endl;
        cout <<"Row: " <<user1->getBoat(2)->cordAt(c)->getRow() <<endl;
        cout <<"Col: "  <<user1->getBoat(2)->cordAt(c)->getCol() <<endl;
        gamesaver.player1.cruisee.position[c].row = user1->getBoat(2)->cordAt(c)->getRow();
        gamesaver.player1.cruisee.position[c].col = user1->getBoat(2)->cordAt(c)->getCol();
        cout <<"Coordinate integers row: " <<gamesaver.player1.cruisee.position[c].row <<endl;
        cout <<"Coordinate integers col: " <<gamesaver.player1.cruisee.position[c].col <<endl;  
    }
    for(int c=0; c < 4; c++){     //battleship
        cout <<"Battleship: " <<endl;
        cout <<"Row: " <<user1->getBoat(3)->cordAt(c)->getRow() <<endl;
        cout <<"Col: "  <<user1->getBoat(3)->cordAt(c)->getCol() <<endl;
        gamesaver.player1.battle.position[c].row = user1->getBoat(3)->cordAt(c)->getRow();
        gamesaver.player1.battle.position[c].col = user1->getBoat(3)->cordAt(c)->getCol();
        cout <<"Coordinate integers row: " <<gamesaver.player1.battle.position[c].row <<endl;
        cout <<"Coordinate integers col: " <<gamesaver.player1.battle.position[c].col <<endl;
    }
    for(int c=0; c < 5; c++){     //carrier
        cout <<"Carrier: " <<endl;
        cout <<"Row: " <<user1->getBoat(4)->cordAt(c)->getRow() <<endl;
        cout <<"Col: "  <<user1->getBoat(4)->cordAt(c)->getCol() <<endl;
        gamesaver.player1.carr.position[c].row = user1->getBoat(4)->cordAt(c)->getRow();
        gamesaver.player1.carr.position[c].col = user1->getBoat(4)->cordAt(c)->getCol();
        cout <<"Coordinate integers row: " <<gamesaver.player1.carr.position[c].row <<endl;
        cout <<"Coordinate integers col: " <<gamesaver.player1.carr.position[c].col <<endl;      
    }
    
    //transfer information from User2 to player2
   // gamesaver.player2.id = user2->getId(); //their ID
    //gamesaver.player2.isturn = false; //if it's their turn
   // gamesaver.player2.missSz = user2->gtTotmiSz(); //their miss array size
    
    
    for(int c=0; c < 2; c++){     
        cout <<"Row: " <<user2->getBoat(0)->cordAt(c)->getRow() <<endl;
        cout <<"Col: "  <<user2->getBoat(0)->cordAt(c)->getCol() <<endl;
        gamesaver.player2.destroy.position[c].row = user2->getBoat(0)->cordAt(c)->getRow();
        gamesaver.player2.destroy.position[c].col = user2->getBoat(0)->cordAt(c)->getCol();
        cout <<"Coordinate integers row: " <<gamesaver.player2.destroy.position[c].row <<endl;
        cout <<"Coordinate integers col: " <<gamesaver.player2.destroy.position[c].col <<endl;        
    }
    
    gamesaver.player2.destroy.dead = user2->getBoat(0)->isDead();
    cout <<"Is dead? " <<gamesaver.player2.destroy.dead <<endl;    
        
    for(int c=0; c < 3; c++){   //submarine
        cout <<"Submarine: " <<endl;
        cout <<"Row: " <<user2->getBoat(1)->cordAt(c)->getRow() <<endl;
        cout <<"Col: "  <<user2->getBoat(1)->cordAt(c)->getCol() <<endl;
        gamesaver.player2.sub.position[c].row = user2->getBoat(1)->cordAt(c)->getRow();
        gamesaver.player2.sub.position[c].col = user2->getBoat(1)->cordAt(c)->getCol();
        cout <<"Coordinate integers row: " <<gamesaver.player2.sub.position[c].row <<endl;
        cout <<"Coordinate integers col: " <<gamesaver.player2.sub.position[c].col <<endl;                 
    }
    for(int c=0; c < 3; c++){     //cruiser
        cout <<"Cruiser: " <<endl;
        cout <<"Row: " <<user2->getBoat(2)->cordAt(c)->getRow() <<endl;
        cout <<"Col: "  <<user2->getBoat(2)->cordAt(c)->getCol() <<endl;
        gamesaver.player2.cruisee.position[c].row = user2->getBoat(2)->cordAt(c)->getRow();
        gamesaver.player2.cruisee.position[c].col = user2->getBoat(2)->cordAt(c)->getCol();
        cout <<"Coordinate integers row: " <<gamesaver.player2.cruisee.position[c].row <<endl;
        cout <<"Coordinate integers col: " <<gamesaver.player2.cruisee.position[c].col <<endl;  
    }
    for(int c=0; c < 4; c++){     //battleship
        cout <<"Battleship: " <<endl;
        cout <<"Row: " <<user2->getBoat(3)->cordAt(c)->getRow() <<endl;
        cout <<"Col: "  <<user2->getBoat(3)->cordAt(c)->getCol() <<endl;
        gamesaver.player2.battle.position[c].row = user2->getBoat(3)->cordAt(c)->getRow();
        gamesaver.player2.battle.position[c].col = user2->getBoat(3)->cordAt(c)->getCol();
        cout <<"Coordinate integers row: " <<gamesaver.player2.battle.position[c].row <<endl;
        cout <<"Coordinate integers col: " <<gamesaver.player2.battle.position[c].col <<endl;
    }
    for(int c=0; c < 5; c++){     //carrier
        cout <<"Carrier: " <<endl;
        cout <<"Row: " <<user2->getBoat(4)->cordAt(c)->getRow() <<endl;
        cout <<"Col: "  <<user2->getBoat(4)->cordAt(c)->getCol() <<endl;
        gamesaver.player2.carr.position[c].row = user2->getBoat(4)->cordAt(c)->getRow();
        gamesaver.player2.carr.position[c].col = user2->getBoat(4)->cordAt(c)->getCol();
        cout <<"Coordinate integers row: " <<gamesaver.player2.carr.position[c].row <<endl;
        cout <<"Coordinate integers col: " <<gamesaver.player2.carr.position[c].col <<endl;      
    }
    
    
    fstream savefile; //open file stream
    savefile.open("savedgames.bin", ios::out|ios::binary|ios::trunc);//open the saved games file
    if(savefile.is_open()){//test that file is indeed open
        savefile.write(reinterpret_cast<char *> (&gamesaver), sizeof(gamesave));//write to the file using our super structure
        savefile.close();//close the file
    }
    else{
        cout <<"File fail!" <<endl;//print out error for if the file fails
    }
}

void NSFile::readingame(User* load1, User* load2){//loading in a game
    fstream loadfile;//start the file stream
    loadfile.open("savedgames.bin", ios::in|ios::binary);//open savedgames.bin
    int i;
    if (loadfile.is_open()){ //test file is open
        long cursor = 0L;
        loadfile.seekg(cursor, ios::beg); //set the cursor
        cursor = sizeof(gamesave);
        loadfile.read(reinterpret_cast<char *> (&gameloader), sizeof(gamesave));//read in the gamesave structure
        loadfile.close();
    }
    else{
        cout <<"File fail!" <<endl;//error for if fail fails to open
    }      
    
    //transfer the data from coordinate structure to coordinate class
    for(int i = 0; i < 2; i++){
        cout <<"Destroyer: " <<endl;
       cout <<"Before adding index " <<i <<": " <<gameloader.player1.destroy.position[i].row <<" " <<gameloader.player1.destroy.position[i].col <<endl;
       Coordinate *tester = new Coordinate(gameloader.player1.destroy.position[i].row, gameloader.player1.destroy.position[i].col);
       cout <<"Tester index " <<i <<": " <<tester->getRow() <<" "  <<tester->getCol() <<endl;
       transferdes[i] = tester;
       cout <<"After adding index " <<i <<": " <<transferdes[i]->getRow() <<" " <<transferdes[i]->getCol() <<endl;
       delete tester;
    }
    Destroyer *transdes1 = new Destroyer();
    cout <<"Adding in boat 1: ";
    transdes1->addCords(transferdes, 2);
    load1->adBoat(transdes1);
    //cruiser
    for(int i = 0; i < 3; i++){
       cout <<"Cruiser: " <<endl;
       cout <<"Before adding index " <<i <<": " <<gameloader.player1.cruisee.position[i].row <<" " <<gameloader.player1.cruisee.position[i].col <<endl;
       Coordinate *tester = new Coordinate(gameloader.player1.cruisee.position[i].row, gameloader.player1.cruisee.position[i].col);
       cout <<"Tester index " <<i <<": " <<tester->getRow() <<" " <<tester->getCol() <<endl;
       transfercruise[i] = tester;
       cout <<"After adding index " <<i <<": " <<transfercruise[i]->getRow() <<" " <<transfercruise[i]->getCol() <<endl;
       delete tester;
    }
    Cruiser *transcruise1 = new Cruiser();
    transcruise1->addCords(transfercruise,3);
    load1->adBoat(transcruise1);
    //submarine
    for(int i = 0; i < 3; i++){
       cout <<"Submarine: " <<endl;
       cout <<"Before adding index " <<i <<": " <<gameloader.player1.sub.position[i].row <<" " <<gameloader.player1.sub.position[i].col <<endl;
       Coordinate *tester = new Coordinate(gameloader.player1.sub.position[i].row, gameloader.player1.sub.position[i].col);
       cout <<"Tester index " <<i <<": " <<tester->getRow() <<" "  <<tester->getCol() <<endl;
       transfersub[i] = tester;
       cout <<"After adding index " <<i <<": " <<transfersub[i]->getRow() <<" " <<transfersub[i]->getCol() <<endl;
       delete tester;
    }
    Submarine *transub1 = new Submarine();
    transub1->addCords(transfersub,3);
    load1->adBoat(transub1);
    //battleship
    for(int i = 0; i < 4; i++){
       cout <<"Battleship: " <<endl;
       cout <<"Before adding index " <<i <<": " <<gameloader.player1.battle.position[i].row <<" "  <<gameloader.player1.battle.position[i].col <<endl;
       Coordinate *tester = new Coordinate(gameloader.player1.battle.position[i].row, gameloader.player1.battle.position[i].col);
       cout <<"Tester index " <<i <<": " <<tester->getRow() <<" "  <<tester->getCol() <<endl;
       transferbattle[i] = tester;
       cout <<"After adding index " <<i <<": " <<transferbattle[i]->getRow() <<" " <<transferbattle[i]->getCol() <<endl;
       delete tester;
    }
    Battleshp *transbat1 = new Battleshp();
    transbat1->addCords(transferbattle,4);
    load1->adBoat(transbat1);
    //carrier
    for(int i = 0; i < 5; i++){
       cout <<"Before adding index " <<i <<": " <<gameloader.player1.carr.position[i].row <<" " <<gameloader.player1.carr.position[i].col <<endl;
       Coordinate *tester = new Coordinate(gameloader.player1.carr.position[i].row, gameloader.player1.carr.position[i].col);
       cout <<"Tester index " <<i <<": " <<tester->getRow() <<" " <<tester->getCol() <<endl;
       transfercarr[i] = tester;
       cout <<"After adding index " <<i <<": " <<transfercarr[i]->getRow() <<" " <<transfercarr[i]->getCol() <<endl;
       delete tester;
    }
    Carrier *transcarr1 = new Carrier();
    transcarr1->addCords(transfercarr, 5);
    load1->adBoat(transcarr1);    
    //user2
   for(int i = 0; i < 2; i++){
       cout <<"Before adding index " <<i <<": " <<gameloader.player2.destroy.position[i].row <<" " <<gameloader.player2.destroy.position[i].col <<endl;
       Coordinate *tester = new Coordinate(gameloader.player2.destroy.position[i].row, gameloader.player2.destroy.position[i].col);
       cout <<"Tester index " <<i <<": " <<tester->getRow() <<" "  <<tester->getCol() <<endl;
       transferdes[i] = tester;
       cout <<"After adding index " <<i <<": " <<transferdes[i]->getRow() <<" " <<transferdes[i]->getCol() <<endl;
       delete tester;
    }
    
    Destroyer *transdes2 =new Destroyer(); 
    cout <<"Adding in boat 2: ";
    transdes2->addCords(transferdes, 2);    
    load2->adBoat(transdes2);    
       for(int i = 0; i < 3; i++){
       cout <<"Cruiser: " <<endl;
       cout <<"Before adding index " <<i <<": " <<gameloader.player2.cruisee.position[i].row <<" " <<gameloader.player2.cruisee.position[i].col <<endl;
       Coordinate *tester = new Coordinate(gameloader.player2.cruisee.position[i].row, gameloader.player2.cruisee.position[i].col);
       cout <<"Tester index " <<i <<": " <<tester->getRow() <<" " <<tester->getCol() <<endl;
       transfercruise[i] = tester;
       cout <<"After adding index " <<i <<": " <<transfercruise[i]->getRow() <<" "  <<transfercruise[i]->getCol() <<endl;
       delete tester;
    }
    Cruiser *transcruise2 = new Cruiser();
    transcruise2->addCords(transfercruise,3);
    load2->adBoat(transcruise2);
    //submarine
    for(int i = 0; i < 3; i++){
       cout <<"Submarine: " <<endl;
       cout <<"Before adding index " <<i <<": " <<gameloader.player2.sub.position[i].row <<" " <<gameloader.player2.sub.position[i].col <<endl;
       Coordinate *tester = new Coordinate(gameloader.player2.sub.position[i].row, gameloader.player2.sub.position[i].col);
       cout <<"Tester index " <<i <<": " <<tester->getRow() <<" " <<tester->getCol() <<endl;
       transfersub[i] = tester;
       cout <<"After adding index " <<i <<": " <<transfersub[i]->getRow() <<" "  <<transfersub[i]->getCol() <<endl;
       delete tester;
    }
    Submarine *transub2 = new Submarine();
    transub2->addCords(transfersub,3);
    load2->adBoat(transub2);
    //battleship
    for(int i = 0; i < 4; i++){
       cout <<"Battleship: " <<endl;
       cout <<"Before adding index " <<i <<": " <<gameloader.player2.battle.position[i].row <<" " <<gameloader.player2.battle.position[i].col <<endl;
       Coordinate *tester = new Coordinate(gameloader.player2.battle.position[i].row, gameloader.player2.battle.position[i].col);
       cout <<"Tester index " <<i <<": " <<tester->getRow() <<" "  <<tester->getCol() <<endl;
       transferbattle[i] = tester;
       cout <<"After adding index " <<i <<": " <<transferbattle[i]->getRow() <<" " <<transferbattle[i]->getCol() <<endl;
       delete tester;
    }
    Battleshp *transbat2 = new Battleshp();
    transbat2->addCords(transferbattle,4);
    load2->adBoat(transbat2);
    //carrier
    for(int i = 0; i < 5; i++){
       cout <<"Before adding index " <<i <<": " <<gameloader.player2.carr.position[i].row <<" " <<gameloader.player2.carr.position[i].col <<endl;
       Coordinate *tester = new Coordinate(gameloader.player2.carr.position[i].row, gameloader.player2.carr.position[i].col);
       cout <<"Tester index " <<i <<": " <<tester->getRow() <<" " <<tester->getCol() <<endl;
       transfercarr[i] = tester;
       cout <<"After adding index " <<i <<": " <<transfercarr[i]->getRow() <<" " <<transfercarr[i]->getCol() <<endl;
       delete tester;
    }
    Carrier *transcarr2 = new Carrier();
    transcarr2->addCords(transfercarr, 5);
    load2->adBoat(transcarr2);
}