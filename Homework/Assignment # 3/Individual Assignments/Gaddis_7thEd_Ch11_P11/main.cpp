/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on March 26, 2017, 4:41 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//structure that holds all expense catagories for the monthly budget
struct mnthBud{
    float hous;     
    float util;     
    float hExp;     
    float trans;
    float food;
    float med;
    float ins;
    float ent;
    float clth;
    float misc;
};

//functions to get the array elements of the structure 
mnthBud getMny(mnthBud);
void comp(mnthBud,mnthBud);

int main(int argc, char** argv) {
    //delciare instances of the monthly budget structure
    mnthBud month;
    mnthBud goal = {500.00,150.00,65.00,50.00,250.00,30.00,100.00,150.00,75.00,50.00};
    
    cout<<"Lets see how you did this month in your budgeting!"<<endl;
    
        
    //send the structure to the functions to get the amount spent in the month info
    month=getMny(month);
    
    //compare the goal with what the user entered
    comp(month,goal);
    
    return 0;
}

//function for getting the user's budget information
mnthBud getMny(mnthBud a){
    cout<<"How much did you spend on housing?"<<endl;
    cin>>a.hous;
    
    cout<<"How much did you spend on Utilities?"<<endl;
    cin>>a.util;
    
    cout<<"How much did you spend on Household expenses?"<<endl;
    cin>>a.hExp;
    
    cout<<"How much did you spend on Transportation?"<<endl;
    cin>>a.trans;
    
    cout<<"How much did you spend on food?"<<endl;
    cin>>a.food;
    
    cout<<"How much did you spend on Medical expenses?"<<endl;
    cin>>a.med;
    
    cout<<"How much did you spend on Insurance?"<<endl;
    cin>>a.ins;
    
    cout<<"How much did you spend on Entertainment?"<<endl;
    cin>>a.ent;
    
    cout<<"How much did you spend on Clothing?"<<endl;
    cin>>a.clth;
    
    cout<<"How much did you spend on Miscellaneous?"<<endl;
    cin>>a.misc;
    
    return a;
}

//Function for comparing the budget and actual money spent
void comp(mnthBud a,mnthBud b){
    //store compared differences
    float dHouse=a.hous-b.hous;
    float dUtil=a.util-b.util;
    float dHExp=a.hExp-b.hExp;
    float dTrans=a.trans-b.trans;
    float dFood=a.food-b.food;
    float dMed=a.med-b.med;
    float dIns=a.ins-b.ins;
    float dEnt=a.ent-b.ent;
    float dClth=a.clth-b.clth;
    float dMisc=a.misc-b.misc;
    float sum=dHouse+dUtil+dHExp+dTrans+dFood+dMed+dIns+dEnt+dClth+dMisc;
    
    //output the comparison
    cout<<"Lets see how much you spent compared to your budget!"<<endl;
    cout<<"Catagory\t\t\t"<<"Budged\t\t\t\t"<<"Spent \t\t\t\t"<<"Difference"<<endl;
    cout<<"Housing"<<"\t\t\t\t"<<a.hous<<"\t\t\t\t"<<b.hous<<"\t\t\t\t"<<dHouse<<endl;
    cout<<"Utilities"<<"\t\t\t"<<a.util<<"\t\t\t\t"<<b.util<<"\t\t\t\t"<<dUtil<<endl;
    cout<<"Household Expenses"<<"\t\t"<<a.hExp<<"\t\t\t\t"<<b.hExp<<"\t\t\t\t"<<dHExp<<endl;
    cout<<"Transportation"<<"\t\t\t"<<a.trans<<"\t\t\t\t"<<b.trans<<"\t\t\t\t"<<dTrans<<endl;
    cout<<"Food"<<"\t\t\t\t"<<a.food<<"\t\t\t\t"<<b.food<<"\t\t\t\t"<<dFood<<endl;
    cout<<"Medical"<<"\t\t\t\t"<<a.med<<"\t\t\t\t"<<b.med<<"\t\t\t\t"<<dMed<<endl;
    cout<<"Insurance"<<"\t\t\t"<<a.ins<<"\t\t\t\t"<<b.ins<<"\t\t\t\t"<<dIns<<endl;
    cout<<"Entertainment"<<"\t\t\t"<<a.ent<<"\t\t\t\t"<<b.ent<<"\t\t\t\t"<<dEnt<<endl;
    cout<<"Clothing"<<"\t\t\t"<<a.clth<<"\t\t\t\t"<<b.clth<<"\t\t\t\t"<<dClth<<endl;
    cout<<"Miscellaneous"<<"\t\t\t"<<a.misc<<"\t\t\t\t"<<b.misc<<"\t\t\t\t"<<dMisc<<endl;
    
    if(sum<0){
        cout<<"You were under budget by $ "<<sum<<endl;
    }
    else{
        cout<<"You were over budget by $ "<<sum<<endl;
    }
    
}