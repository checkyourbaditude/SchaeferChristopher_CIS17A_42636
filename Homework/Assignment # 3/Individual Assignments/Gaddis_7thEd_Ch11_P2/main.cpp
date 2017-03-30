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
struct MovieDataP2{
    string title;   //String to hold the title of the movie
    string director;//String to hold the direct of the movie
    string relDate;    //Release date Variable
    int runTime;    //Run time in minutes
    int cost;
    int rev;
};

//funcitonal Prototypes
MovieDataP2 getInfo(MovieDataP2);
void prntDataP2(MovieDataP2);

int main(int argc, char** argv) {
    
    //declare two instances of the movie structure, for outputs
    MovieDataP2 movieOne;
    MovieDataP2 movieTwo;
    
    //fill the strutures
    movieOne=getInfo(movieOne);
    movieTwo=getInfo(movieTwo);
    
    //print the data
    cout<<"Movie # 1:"<<endl<<endl;
    prntDataP2(movieOne);
    cout<<"Movie # 2:"<<endl<<endl;
    prntDataP2(movieTwo);
    
    
    return 0;
}

//this function gets the data for the structures
MovieDataP2 getInfo(MovieDataP2 a){
    //get the info for the movie
    cout<<"Enter the Data for the Movie"<<endl<<endl;
    
    cout<<"what is the title?"<<endl;
    cin>>a.title;
    
    cout<<"Who was the director?"<<endl;
    cin>>a.director;
    
    cout<<"what is the release date?"<<endl;
    cin>>a.relDate;
    
    cout<<"what is the run time?"<<endl;
    cin>>a.runTime;
    
    cout<<"what is the production cost?"<<endl;
    cin>>a.cost;
    
    cout<<"what is the revenue?"<<endl;
    cin>>a.rev;
    
    //return the structure MovieData
    return a;
}

//print the structure data
void prntDataP2(MovieDataP2 a){
    //create variable for the amount of money made or lost
    int money=(a.rev)-(a.cost);
    
    cout<<"Movie:           "<<a.title<<endl;
    cout<<"Director:        "<<a.director<<endl;
    cout<<"Release Date:    "<<a.relDate<<endl;
    cout<<"Run Time:        "<<a.runTime<<endl;
    
    //output if loss or profit
    if(money<0){
        cout<<"The loss was:    "<<money<<endl;
    }
    else{
        cout<<"The profit was:  "<<money<<endl;
    }
    
    cout<<endl<<endl;
}