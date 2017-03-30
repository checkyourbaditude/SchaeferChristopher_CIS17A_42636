/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on March 28, 2017, 6:01 PM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
//structures
struct saleData{
    string div;     //String to hold the name of the division
    float oneQu;    //sales data for various quarters
    float twoQu;
    float threeQu;
    float fourQu;
    float annSale;  //annual sales total
    float avgQu;    //average quarterly sales
};

//functions
saleData getSData(saleData);
void prntSData(saleData);

int main(int argc, char** argv) {
    //declare structures to hold data
    saleData East={"East"};
    saleData West={"West"};
    saleData South={"South"};
    saleData North={"North"};
    
    //get the data from each division
    East=getSData(East);
    West=getSData(West);
    South=getSData(South);
    North=getSData(North);
    
    //display the information
    prntSData(East);
    
    return 0;
}

//function to get information from user
saleData getSData(saleData a){    
    cout<<"Lets get the sales information for the "<<a.div<<" division"<<endl;
    
    //get information from user
    cout<<"What was the first quarter sales?"<<endl;
    cin>>a.oneQu;
    
    cout<<"What was the second quarter sales?"<<endl;
    cin>>a.twoQu;
    
    cout<<"What was the third quarter sales?"<<endl;
    cin>>a.threeQu;
    
    cout<<"What was the fourth quarter sales?"<<endl;
    cin>>a.fourQu;
    
    //calcuations
    a.annSale=a.oneQu+a.twoQu+a.threeQu+a.fourQu;
    a.avgQu=(a.annSale/(static_cast<float>(4)));
    
    //return structure
    return a;
}

//print out the data
void prntSData(saleData e){
    cout<<"Here are the summations of the sales Data"<<endl;
    cout<<"Division: "<<e.div<<endl;
    cout<<"Q1: "<<e.oneQu<<endl;
    cout<<"Q2: "<<e.twoQu<<endl;
    cout<<"Q3: "<<e.threeQu<<endl;
    cout<<"Q4: "<<e.fourQu<<endl;
    cout<<"Total Sales for the year: "<<e.annSale<<endl;
    cout<<"Quarterly Avg: "<<e.avgQu<<endl;
}