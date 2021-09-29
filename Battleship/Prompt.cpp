/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Prompt.h"
#include <iostream>

using namespace std;

void Prompt::hello(){
    cout <<"Welcome to Battleship!" <<endl;
    cout <<"Please enter username: ";
    int size = 15;
    tester.username =new char[size];
    cin.getline(tester.username,size-1);
    cout <<tester.username <<endl;
}