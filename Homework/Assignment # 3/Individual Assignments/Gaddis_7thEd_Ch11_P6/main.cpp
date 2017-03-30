/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on March 23, 2017, 7:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
//structures
struct Player{
    string name;    //String to hold the player name
    int num;        //String to hold the number of the player
    int points;     //number of points scored
};

//functional Prototypes
Player getInfo(Player);
void prntTeam(Player*,int);


int main(int argc, char** argv) {
    //declare size of array
    int teamSize=12;
    
    //declare array of player structure
    Player *team;
    team=new Player[teamSize];
    
    //loop to get all the player's information
    for(int i=0;i<teamSize;i++){
        //ask for the information from the user
        cout<<"Enter the information for the "<<(i+1)<<" player"<<endl;
        
        //send the structure to the function to get player info
        team[i]=getInfo(team[i]);
    }
    
    //print the team in a table!
    prntTeam(team,teamSize);
    
    //delete dynamically allocated array
    delete [] team;
    
    return 0;
}

//get the info for each player
Player getInfo(Player a){
    cout<<"Player Name: ";
    cin>>a.name;
    cout<<endl;
    
    //data validation loop
    do{
        if(a.num<0){
            cout<<"Enter a Number greater than zero!"<<endl;
        }
        
        //get number from user
        cout<<"Player Number: ";
        cin>>a.num;
        cout<<endl;
        
    }while((a.num)<0);
    
    cout<<"Number of Goals: ";
    cin>>a.points; 
    cout<<endl;
    
    cout<<endl<<endl;
    return a;
}

//funciton that prints a table of the players and their information
void prntTeam(Player *a, int size){
    cout<<"Player\t\t\t"<<"Number\t\t\t"<<"Goals\t\t\t"<<endl;
    
    for(int i=0;i<size;i++){
        cout<<a[i].name<<"\t\t\t"<<a[i].num<<"\t\t\t"<<a[i].points<<endl;
    }
    
}