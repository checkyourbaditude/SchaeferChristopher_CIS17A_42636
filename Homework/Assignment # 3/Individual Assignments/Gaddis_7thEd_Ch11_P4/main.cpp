/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on March 28, 2017, 6:22 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;
//structure for monthly weather
struct wStat{
    float totRain;
    float hTemp;
    float lTemp;
    float aTemp;
};

//functions
wStat fillStat(wStat);
void prntStat(wStat,int);

int main(int argc, char** argv) {
    //declare size of array
    int size=12;
    float totAvgT,totAvgR;
    
    //declare array of speaker structure
    wStat *arry;
    arry=new wStat[size];
    
    //get the user to fill the array
    for(int i=0;i<size;i++){
        cout<<"Enter the data for month # "<<i+1<<endl;
        arry[i]=fillStat(arry[i]);
        totAvgT+=arry[i].aTemp;
        totAvgR+=arry[i].totRain;        
    }
    
    //print the array of structures
    for(int k=0;k<size;k++){
        prntStat(arry[k],k);
    }
    
    cout<<"The average temp over the past 12 months was: "<<(totAvgT/static_cast<float>(size))<<endl;
    cout<<"The average rainfall over the past 12 months was: "<<(totAvgR/static_cast<float>(size))<<endl;
    
    //delete dynamically allocated array
    delete [] arry;
    
    return 0;
}

wStat fillStat(wStat a){
    cout<<"What was the total rainfall during the month (in inches)?"<<endl;
    cin>>a.totRain;
    
    cout<<"What was the high temp during the month? (in fahrenheit)"<<endl;
    cin>>a.hTemp;
    
    cout<<"What was the low temp during the month? (in fahrenheit)"<<endl;
    cin>>a.lTemp;
    
    //calculations
    a.aTemp=(((a.hTemp+a.lTemp)/static_cast<float>(2)));
    
    cout<<"The average temp for this month was: "<<a.aTemp<<endl;
    
    //return the structure
    return a;
}

//output the stats
void prntStat(wStat b,int j){
    cout<<"Weather Statistics for month #"<<j+1<<endl;
    cout<<b.totRain<<" inches of rain"<<endl;
    cout<<b.hTemp<<" was the highest tempurature"<<endl;
    cout<<b.lTemp<<" was the lowest tempurature"<<endl;
}