#include <ios>

#include "NSFile.h"

using namespace std;

NSFile::NSFile(){ //initiate all those dynamic transfer variables for loading back in a game
    transferdes = new Coordinate*[2];
    transfersub = new Coordinate*[3];
    transfercruise = new Coordinate*[3];
    transferbattle = new Coordinate*[4];
    transfercarr = new Coordinate*[5]; //sizes are the sizes of the boats (2 for destroyer, 3 for sub and cruiser, etc.)
}

//saving a game
void NSFile::savethegame(User* user1, User* user2, string savename){   
    gamesaver.player1.isAI = false;
//take in the username string and put it in our array
    for(int i = 0; i < strlen(user1->gtName()); i++){ //use the strlen to get the string length, and loop for that many characters
        gamesaver.player1.name[i] =  user1->gtName()[i]; //put in the username characters one at a time
    }
    gamesaver.player1.name[strlen(user1->gtName())] = '\0'; //set the null terminator at the end of the username string
    cout <<gamesaver.player1.name <<endl; //print back out for testing purposes
//user turn - an integer file to determine if it's this users turn ot not    
    gamesaver.player1.curruser = user1->isCurrentUser();
//miss array
    gamesaver.player1.missSz = user1->gtTotmiSz(); //size of user 1 miss array       
    if( gamesaver.player1.missSz > 0){ //if there are misses to store
        for (int i=0; i <  gamesaver.player1.missSz; i++){ //loop through that many misses and add their information into our miss array 
             gamesaver.player1.misses[i].row = user1->gtMiCrd(i)->getRow(); //get the row in integers
             gamesaver.player1.misses[i].col = user1->gtMiCrd(i)->getCol(); //get the col in integers
        } 
    }
//destroyer
    for(int c=0; c < 2; c++){     //destroyer coordinates along with its hit coordinates - same process for every boat
        gamesaver.player1.destroy.position[c].row = user1->getBoat(0)->cordAt(c)->getRow();//extract the digits for the coordinates in the boat class and put them in our boat structure
        gamesaver.player1.destroy.position[c].col = user1->getBoat(0)->cordAt(c)->getCol();
    }        
    gamesaver.player1.destroy.dead = user1->getBoat(0)->isDead();//get the dead variable
    gamesaver.player1.destroy.hitsz = user1->getBoat(0)->gtHsz();//get how many hits have been made on the ship
    if (gamesaver.player1.destroy.hitsz > 0){//determine if there are any hits to begin with
        for (int i=0; i < gamesaver.player1.destroy.hitsz; i++){//if there are, copy them down into our hit array
            gamesaver.player1.destroy.hits[i].row = user1->getBoat(0)->hcordAt(i)->getRow(); //get row
            gamesaver.player1.destroy.hits[i].col = user1->getBoat(0)->hcordAt(i)->getCol(); //get column
        }
    } //this process is repeated for all boats, for both users
//submarine
    for(int c=0; c < 3; c++){   
        gamesaver.player1.sub.position[c].row = user1->getBoat(1)->cordAt(c)->getRow();//more conversions
        gamesaver.player1.sub.position[c].col = user1->getBoat(1)->cordAt(c)->getCol();
    }
    gamesaver.player1.sub.dead = user1->getBoat(1)->isDead();    
    gamesaver.player1.sub.hitsz = user1->getBoat(1)->gtHsz();
    if (gamesaver.player1.sub.hitsz > 0){
        for (int i=0; i < gamesaver.player1.sub.hitsz; i++){
            gamesaver.player1.sub.hits[i].row = user1->getBoat(1)->hcordAt(i)->getRow();
            gamesaver.player1.sub.hits[i].col = user1->getBoat(1)->hcordAt(i)->getCol();
        }
    }
//cruiser
    for(int c=0; c < 3; c++){     
        gamesaver.player1.cruisee.position[c].row = user1->getBoat(2)->cordAt(c)->getRow();
        gamesaver.player1.cruisee.position[c].col = user1->getBoat(2)->cordAt(c)->getCol();
    }            
    gamesaver.player1.cruisee.dead = user1->getBoat(2)->isDead();
    gamesaver.player1.cruisee.hitsz = user1->getBoat(0)->gtHsz();
    if (gamesaver.player1.cruisee.hitsz > 0){
        for (int i=0; i < gamesaver.player1.cruisee.hitsz; i++){
            gamesaver.player1.cruisee.hits[i].row = user1->getBoat(2)->hcordAt(i)->getRow();
            gamesaver.player1.cruisee.hits[i].col = user1->getBoat(2)->hcordAt(i)->getCol();
        }
    }
//battleship
    for(int c=0; c < 4; c++){     
        gamesaver.player1.battle.position[c].row = user1->getBoat(3)->cordAt(c)->getRow();
        gamesaver.player1.battle.position[c].col = user1->getBoat(3)->cordAt(c)->getCol();
    }
    gamesaver.player1.battle.dead = user1->getBoat(3)->isDead();
    gamesaver.player1.battle.hitsz = user1->getBoat(0)->gtHsz();
    if (gamesaver.player1.battle.hitsz > 0){
        for (int i=0; i < gamesaver.player1.battle.hitsz; i++){
            gamesaver.player1.battle.hits[i].row = user1->getBoat(3)->hcordAt(i)->getRow();
            gamesaver.player1.battle.hits[i].col = user1->getBoat(3)->hcordAt(i)->getCol();
        }
    }
//carrier
    for(int c=0; c < 5; c++){     
        gamesaver.player1.carr.position[c].row = user1->getBoat(4)->cordAt(c)->getRow();
        gamesaver.player1.carr.position[c].col = user1->getBoat(4)->cordAt(c)->getCol();
    }
    gamesaver.player1.carr.dead = user1->getBoat(4)->isDead();
    gamesaver.player1.carr.hitsz = user1->getBoat(4)->gtHsz();
    if (gamesaver.player1.carr.hitsz > 0){
        for (int i=0; i < gamesaver.player1.carr.hitsz; i++){
            gamesaver.player1.carr.hits[i].row = user1->getBoat(4)->hcordAt(i)->getRow();
            gamesaver.player1.carr.hits[i].col = user1->getBoat(4)->hcordAt(i)->getCol();
        }
    }       
    
//transfer information from User2 to player2 - same process and information as User1
     gamesaver.player1.isAI = false;
//username
    for(int i = 0; i < strlen(user2->gtName()); i++){ //use the strlen to get the string length, and loop for that many characters
        gamesaver.player2.name[i] =  user2->gtName()[i]; //put in the username characters one at a time
    }
    gamesaver.player2.name[strlen(gamesaver.player2.name)] = '\0';//set null terminator
    cout <<gamesaver.player2.name <<endl; //print back out for testing purposes
//user turn - an integer file to determine if it's this users turn ot not    
    gamesaver.player2.curruser = user2->isCurrentUser();
//User 2 Miss array    
    gamesaver.player2.missSz = user2->gtTotmiSz(); //their miss array size
    if( gamesaver.player2.missSz > 0){
        for (int i=0; i <  gamesaver.player2.missSz; i++){ //once more we test their miss array size, and if there are misses, we transfer that information into our array
             gamesaver.player2.misses[i].row = user2->gtMiCrd(i)->getRow();
             gamesaver.player2.misses[i].col = user2->gtMiCrd(i)->getCol();
        } 
    }   
//destroyer
    for(int c=0; c < 2; c++){     
        gamesaver.player2.destroy.position[c].row = user2->getBoat(0)->cordAt(c)->getRow();
        gamesaver.player2.destroy.position[c].col = user2->getBoat(0)->cordAt(c)->getCol();
    }    
    gamesaver.player2.destroy.dead = user2->getBoat(0)->isDead();
    gamesaver.player2.destroy.hitsz = user1->getBoat(0)->gtHsz();
    if (gamesaver.player2.destroy.hitsz > 0){
        for (int i=0; i < gamesaver.player2.destroy.hitsz; i++){
            gamesaver.player2.destroy.hits[i].row = user2->getBoat(0)->hcordAt(i)->getRow();
            gamesaver.player2.destroy.hits[i].col = user2->getBoat(0)->hcordAt(i)->getCol();
        }
    }
//submarine    
    for(int c=0; c < 3; c++){   
        gamesaver.player2.sub.position[c].row = user2->getBoat(1)->cordAt(c)->getRow();
        gamesaver.player2.sub.position[c].col = user2->getBoat(1)->cordAt(c)->getCol();
    }
    gamesaver.player2.sub.dead = user2->getBoat(1)->isDead();
    gamesaver.player2.sub.hitsz = user1->getBoat(1)->gtHsz();
    if (gamesaver.player2.sub.hitsz > 0){
        for (int i=0; i < gamesaver.player2.sub.hitsz; i++){
            gamesaver.player2.sub.hits[i].row = user2->getBoat(1)->hcordAt(i)->getRow();
            gamesaver.player2.sub.hits[i].col = user2->getBoat(1)->hcordAt(i)->getCol();
        }
    }
//cruiser
    for(int c=0; c < 3; c++){     
        gamesaver.player2.cruisee.position[c].row = user2->getBoat(2)->cordAt(c)->getRow();
        gamesaver.player2.cruisee.position[c].col = user2->getBoat(2)->cordAt(c)->getCol();
    }
    gamesaver.player2.cruisee.dead = user2->getBoat(2)->isDead();
    gamesaver.player2.cruisee.hitsz = user1->getBoat(2)->gtHsz();
    if (gamesaver.player2.cruisee.hitsz > 0){
        for (int i=0; i < gamesaver.player2.cruisee.hitsz; i++){
            gamesaver.player2.cruisee.hits[i].row = user2->getBoat(2)->hcordAt(i)->getRow();
            gamesaver.player2.cruisee.hits[i].col = user2->getBoat(2)->hcordAt(i)->getCol();
        }
    }
//battleship
    for(int c=0; c < 4; c++){     
        gamesaver.player2.battle.position[c].row = user2->getBoat(3)->cordAt(c)->getRow();
        gamesaver.player2.battle.position[c].col = user2->getBoat(3)->cordAt(c)->getCol();
    }
    gamesaver.player2.battle.dead = user2->getBoat(3)->isDead();
    gamesaver.player2.battle.hitsz = user1->getBoat(3)->gtHsz();
    if (gamesaver.player2.battle.hitsz > 0){
        for (int i=0; i < gamesaver.player2.battle.hitsz; i++){
            gamesaver.player2.battle.hits[i].row = user2->getBoat(3)->hcordAt(i)->getRow();
            gamesaver.player2.battle.hits[i].col = user2->getBoat(3)->hcordAt(i)->getCol();
        }
    }
//carrier
    for(int c=0; c < 5; c++){     
        gamesaver.player2.carr.position[c].row = user2->getBoat(4)->cordAt(c)->getRow();
        gamesaver.player2.carr.position[c].col = user2->getBoat(4)->cordAt(c)->getCol();    
    }
    gamesaver.player2.carr.dead = user2->getBoat(4)->isDead();
    gamesaver.player2.carr.hitsz = user2->getBoat(4)->gtHsz();
    if (gamesaver.player2.carr.hitsz > 0){
        for (int i=0; i < gamesaver.player2.carr.hitsz; i++){
            gamesaver.player2.carr.hits[i].row = user2->getBoat(4)->hcordAt(i)->getRow();
            gamesaver.player2.carr.hits[i].col = user2->getBoat(4)->hcordAt(i)->getCol();
            cout <<gamesaver.player2.carr.hits[i].row <<gamesaver.player2.carr.hits[i].col <<endl;
        }
    }
    

cout <<savename <<endl;
    fstream savefile; //open file stream
    savefile.open( savename.c_str(), ios::out|ios::binary);//create the save games file with name specified by the user - use .c_str() to make it a c_string and avoid conflicts
    if(savefile.is_open()){//test that file is indeed open
        savefile.write(reinterpret_cast<char *> (&gamesaver), sizeof(gamesave));//write to the file using our super structure
        savefile.close();//close the file
    }
    else{
        cout <<"File fail!" <<endl;//print out error for if the file fails
    }
    
}

void NSFile::readingame(User* load1, User* load2, string loadname){//loading in a game
    cout <<loadname <<endl; //test to ensure it got through
    fstream loadfile;//start the file stream
    loadfile.open(loadname.c_str(), ios::in|ios::binary);//open .bin specified by the user - use .c_str() to make it a c_string and avoid conflicts
    if (loadfile.is_open()){ //test file is open
        long cursor = 0L; //cursor
        loadfile.seekg(cursor, ios::beg); //set the cursor
        loadfile.read(reinterpret_cast<char *> (&gameloader), sizeof(gamesave));//read in the gamesave structure
        loadfile.close(); //close file
    }
    else{
        cout <<"File fail! Please double check file name." <<endl;//error for if fail fails to open
        exit(1); //exit value
    }  
    
//transfer from player1 in gameloader into load1 user
//username  testing - print back out to ensure it's good  
    cout <<"Loading in name from file... " <<endl;
    cout <<gameloader.player1.name <<endl;
//curruser update
    load1->setCurUrs(gameloader.player1.curruser);
//transfer username from player1 to user load1 using a load1 method
    load1->updNam(gameloader.player1.name,strlen(gameloader.player1.name));
//miss array
    if(gameloader.player1.missSz > 0){//check to see if there is anything to transfer to  begin with
        for (int c = 0; c < gameloader.player1.missSz; c++){ //loop through how many misses are in the array
            Coordinate *transfermiss = new Coordinate(gameloader.player1.misses[c].row,gameloader.player1.misses[c].col);//translate our coordinate back into Coordinate class using a temp variable
            load1->adMiss(transfermiss);//after translation, add it into user (load1) information 
        }
    }
//destroyer
    for(int i = 0; i < 2; i++){
       Coordinate *tester = new Coordinate(gameloader.player1.destroy.position[i].row, gameloader.player1.destroy.position[i].col);//translate our coordinates back into temp Coordinate class
       transferdes[i] = tester;//put the temp Coordinate into an array of Coordinates - who's size correlates to the boat size
    }
    Destroyer *transdes1 = new Destroyer();//declare a new boat
    transdes1->addCords(transferdes, 2);//transfer the array of coordinates into the new boat
    load1->adBoat(transdes1);//put boat into a user 
    if (gameloader.player1.destroy.hitsz > 0){//check to see if their is anything in the boat hit array
        for (int c = 0; c < gameloader.player1.destroy.hitsz; c++){//transfer hit coordinates
            Coordinate *transferhit = new Coordinate(gameloader.player1.destroy.hits[c].row,gameloader.player1.destroy.hits[c].col);//translate them first
            cout <<transferhit->getRow() <<transferhit->getCol() <<endl;//then transfer into a temp Coordinate
            load1->getBoat(0)->setHit(transferhit); //then transfer that temp Coordinate into the boat hit array
        }
    }//this process is repeated for all boats in load1 and load2    
//submarine
    for(int i = 0; i < 3; i++){
       Coordinate *tester = new Coordinate(gameloader.player1.sub.position[i].row, gameloader.player1.sub.position[i].col);
       transfersub[i] = tester;
    }
    Submarine *transub1 = new Submarine();
    transub1->addCords(transfersub,3);
    load1->adBoat(transub1);
        if (gameloader.player1.sub.hitsz > 0){
        for (int c = 0; c < gameloader.player1.sub.hitsz; c++){
            Coordinate *transferhit = new Coordinate(gameloader.player1.sub.hits[c].row,gameloader.player1.sub.hits[c].col);
            cout <<transferhit->getRow() <<transferhit->getCol() <<endl;
            load1->getBoat(1)->setHit(transferhit);
        }
    }
//cruiser
    for(int i = 0; i < 3; i++){
       Coordinate *tester = new Coordinate(gameloader.player1.cruisee.position[i].row, gameloader.player1.cruisee.position[i].col);
       transfercruise[i] = tester;
    }
    Cruiser *transcruise1 = new Cruiser();
    transcruise1->addCords(transfercruise,3);
    load1->adBoat(transcruise1);
        if (gameloader.player1.cruisee.hitsz > 0){
        for (int c = 0; c < gameloader.player1.cruisee.hitsz; c++){
            Coordinate *transferhit = new Coordinate(gameloader.player1.cruisee.hits[c].row,gameloader.player1.cruisee.hits[c].col);
            cout <<transferhit->getRow() <<transferhit->getCol() <<endl;
            load1->getBoat(2)->setHit(transferhit);
        }
    }           
//battleship
    for(int i = 0; i < 4; i++){
       Coordinate *tester = new Coordinate(gameloader.player1.battle.position[i].row, gameloader.player1.battle.position[i].col);
       transferbattle[i] = tester;
    }
    Battleshp *transbat1 = new Battleshp();
    transbat1->addCords(transferbattle,4);
    load1->adBoat(transbat1);
    if (gameloader.player1.battle.hitsz > 0){
        for (int c = 0; c < gameloader.player1.battle.hitsz; c++){
            Coordinate *transferhit = new Coordinate(gameloader.player1.battle.hits[c].row,gameloader.player1.battle.hits[c].col);
            cout <<transferhit->getRow() <<transferhit->getCol() <<endl;
            load1->getBoat(3)->setHit(transferhit);
        }
    }
//carrier
    for(int i = 0; i < 5; i++){
       Coordinate *tester = new Coordinate(gameloader.player1.carr.position[i].row, gameloader.player1.carr.position[i].col);
       transfercarr[i] = tester;
    }
    Carrier *transcarr1 = new Carrier();
    transcarr1->addCords(transfercarr, 5);
    load1->adBoat(transcarr1);   
    if (gameloader.player1.carr.hitsz > 0){
        for (int c = 0; c < gameloader.player1.carr.hitsz; c++){
            Coordinate *transferhit = new Coordinate(gameloader.player1.carr.hits[c].row,gameloader.player1.carr.hits[c].col);
            cout <<transferhit->getRow() <<transferhit->getCol() <<endl;
            load1->getBoat(4)->setHit(transferhit);
        }
    }
    
    
//load 2 information
//username testing
    cout <<"Loading in name from file: " <<endl;
    cout <<gameloader.player2.name <<endl;
//username
    load2->updNam(gameloader.player2.name,strlen(gameloader.player2.name));
//player turn
    load2->setCurUrs(gameloader.player2.curruser);
//miss array
    if(gameloader.player2.missSz > 0){
        for (int c = 0; c < gameloader.player2.missSz; c++){
            Coordinate *transfermiss = new Coordinate(gameloader.player2.misses[c].row,gameloader.player2.misses[c].col);
            load2->adMiss(transfermiss);
        }
    }
//destroyer
   for(int i = 0; i < 2; i++){
       Coordinate *tester = new Coordinate(gameloader.player2.destroy.position[i].row, gameloader.player2.destroy.position[i].col);
       transferdes[i] = tester;
    }    
    Destroyer *transdes2 =new Destroyer(); 
    transdes2->addCords(transferdes, 2);    
    load2->adBoat(transdes2);    
    if(gameloader.player2.destroy.hitsz > 0 ){
        for (int c = 0; c <gameloader.player2.destroy.hitsz; c++ ){
            Coordinate *transferhit = new Coordinate(gameloader.player2.destroy.hits[c].row,gameloader.player2.destroy.hits[c].col);
            cout <<transferhit->getRow() <<transferhit->getCol() <<endl;
            load2->getBoat(0)->setHit(transferhit);
        }
    }
//submarine
    for(int i = 0; i < 3; i++){
       Coordinate *tester = new Coordinate(gameloader.player2.sub.position[i].row, gameloader.player2.sub.position[i].col);
       transfersub[i] = tester;
    }
    Submarine *transub2 = new Submarine();
    transub2->addCords(transfersub,3);
    load2->adBoat(transub2);
    if(gameloader.player2.sub.hitsz > 0 ){
        for (int c = 0; c <gameloader.player2.sub.hitsz; c++ ){
            Coordinate *transferhit = new Coordinate(gameloader.player2.sub.hits[c].row,gameloader.player2.sub.hits[c].col);
            cout <<transferhit->getRow() <<transferhit->getCol() <<endl;
            load2->getBoat(1)->setHit(transferhit);
        }
    }
//cruiser
    for(int i = 0; i < 3; i++){
       Coordinate *tester = new Coordinate(gameloader.player2.cruisee.position[i].row, gameloader.player2.cruisee.position[i].col);
       transfercruise[i] = tester;
    }
    Cruiser *transcruise2 = new Cruiser();
    transcruise2->addCords(transfercruise,3);
    load2->adBoat(transcruise2);
    if(gameloader.player2.cruisee.hitsz > 0 ){
        for (int c = 0; c <gameloader.player2.cruisee.hitsz; c++ ){
            Coordinate *transferhit = new Coordinate(gameloader.player2.cruisee.hits[c].row,gameloader.player2.cruisee.hits[c].col);
            cout <<transferhit->getRow() <<transferhit->getCol() <<endl;
            load2->getBoat(2)->setHit(transferhit);
        }
    }
//battleship
    for(int i = 0; i < 4; i++){
       Coordinate *tester = new Coordinate(gameloader.player2.battle.position[i].row, gameloader.player2.battle.position[i].col);
       transferbattle[i] = tester;
    }
    Battleshp *transbat2 = new Battleshp();
    transbat2->addCords(transferbattle,4);
    load2->adBoat(transbat2);
    if(gameloader.player2.battle.hitsz > 0 ){
        for (int c = 0; c <gameloader.player2.battle.hitsz; c++ ){
            Coordinate *transferhit = new Coordinate(gameloader.player2.battle.hits[c].row,gameloader.player2.battle.hits[c].col);
            cout <<transferhit->getRow() <<transferhit->getCol() <<endl;
            load2->getBoat(3)->setHit(transferhit);
        }
    }
//carrier
    for(int i = 0; i < 5; i++){
       Coordinate *tester = new Coordinate(gameloader.player2.carr.position[i].row, gameloader.player2.carr.position[i].col);
       transfercarr[i] = tester;
    }
    Carrier *transcarr2 = new Carrier();
    transcarr2->addCords(transfercarr, 5);
    load2->adBoat(transcarr2);
    if(gameloader.player2.carr.hitsz > 0 ){
        for (int c = 0; c <gameloader.player2.carr.hitsz; c++ ){
            Coordinate *transferhit = new Coordinate(gameloader.player2.carr.hits[c].row,gameloader.player2.carr.hits[c].col);
            cout <<transferhit->getRow() <<transferhit->getCol() <<endl;
            load2->getBoat(4)->setHit(transferhit);
        }
    }
}

NSFile::~NSFile(){
    
}
