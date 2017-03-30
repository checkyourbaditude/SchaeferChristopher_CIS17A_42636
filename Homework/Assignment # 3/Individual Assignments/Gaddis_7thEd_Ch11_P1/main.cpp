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
#include <sstream>
#include <limits>
#include <string>

using namespace std;
//structures
struct MovieData{
    string title;   //String to hold the title of the movie
    string director;//String to hold the direct of the movie
    string relDate;    //Release date Variable
    int runTime;    //Run time in minutes
};

//funcitonal Prototypes
MovieData getInfo(MovieData);
void prntData(MovieData);

int main(int argc, char** argv) {
    
    //declare two instances of the movie structure, for outputs
    MovieData movieOne;
    MovieData movieTwo;
    
    //fill the strutures
    movieOne=getInfo(movieOne);
    movieTwo=getInfo(movieTwo);
    
    //print the data
    cout<<"Movie # 1:"<<endl<<endl;
    prntData(movieOne);
    cout<<"Movie # 2:"<<endl<<endl;
    prntData(movieTwo);
    
    
    return 0;
}

//this function gets the data for the structures
MovieData getInfo(MovieData a){
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
    
    //return the structure MovieData
    return a;
}

//print the structure data
void prntData(MovieData a){
    cout<<"Movie:           "<<a.title<<endl;
    cout<<"Director:        "<<a.director<<endl;
    cout<<"Release Date:    "<<a.relDate<<endl;
    cout<<"Run Time:        "<<a.runTime<<endl;
}