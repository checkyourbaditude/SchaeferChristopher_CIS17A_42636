/*
 * Calculate the sales tax based on gross sales. 4% state and 2% county
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on February 28, 2017, 5:44 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//functional prototypes
void calcS(float,string,short);

int main(int argc, char** argv) {
    //variables
    string month;
    short year;
    float collect;
    
    //make sure user knows the purpose of the program
    cout<<"Lets Calculate the Taxes owed"<<endl;
    
    //get information or Inputs
    cout<<"What is the year?"<<endl;
    cin>>year;
    
    cout<<"What month is it?"<<endl;
    cin>>month;
    
    cout<<"What was the total collected at the register in the month of "<<month<<" in the year "<<year<<"?"<<endl;
    cin>>collect;
    
    calcS(collect,month,year);
    //cout<<year;
    //cout<<month;
    
    return 0;
}

void calcS (float collect, string M, short Y){
    //cout<<"The Function Works!";
    float S, sTax, cTax;
    
    S=collect/(1.06);
    sTax=S*(0.04);
    cTax=S*(0.02);
    
    cout<<cTax;
    
    //output of the information
    cout<<"Month:"<<M<<endl;
    cout<<"---------------------"<<M<<endl;
    cout<<"Collected: "<<setprecision(2)<<fixed<<collect<<endl;
    cout<<"Sales: "<<setprecision(2)<<fixed<<S<<endl;
    cout<<"County Sales Tax: "<<setprecision(2)<<fixed<<cTax<<endl;
    cout<<"State Sales Tax: "<<setprecision(2)<<fixed<<sTax<<endl;
    cout<<"Total Sales Tax: "<<setprecision(2)<<fixed<<cTax+sTax<<endl;
}