/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on March 27, 2017, 10:09 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

//structure that holds all inventory catagories
struct invBins{
    string desc;
    int num;
};

//functions
invBins *iniInv(invBins*);
void prntInv(invBins*,int);
invBins editInv(invBins,int);

int main(int argc, char** argv) {
    //declare size of array
    int size=10;
    int bin=0;
    
    //declare array of inventory structure
    invBins *arry;
    arry=new invBins[size];
    
    //pass array to function for initialization of array
    arry=iniInv(arry);
    
    //Loop to update the inventory with new sizes
    do{
        //variables for the choices the user is making
        bin=0;
        
        //print the array of structures so far
        prntInv(arry, size);
        cout<<"Select a bin, or enter 11 to exit"<<endl;
        cin>>bin;
        
        //lower the bin to reflect actual value in the array
        bin-=1;
        
        //send to the edit function if user chooses to edit
        if((bin<=10)&&(bin>0)){
            arry[bin]=editInv(arry[bin],bin);
        }
    }while(bin<10);
    
    //delete dynamically allocated array
    delete [] arry;
    
    return 0;
}

//initialize all the information into the inventory bin array
invBins *iniInv(invBins* a){
    a[0]={"valve   ",10};
    a[1]={"bearing ",5};
    a[2]={"bushing ",15};
    a[3]={"coupling",21};
    a[4]={"flange  ",7};
    a[5]={"gear    ",5};
    a[6]={"gear housing",5};
    a[7]={"vacuum grip",25};
    a[8]={"cable   ",18};
    a[9]={"rod     ",12};
    
    return a;
}

void prntInv(invBins* a, int size){
    cout<<" Description\t\t\t\t"<<"Quantity"<<endl;
    
    for(int i=0;i<size;i++){
        cout<<i+1<<")"<<a[i].desc<<"\t\t\t\t"<<a[i].num<<endl;
    }
}

//This function allows the user to edit the inventory
invBins editInv(invBins a,int ele){
    int choice=0;
    int chng=0;
    bool valid=false;
    
    //loop for user input (if they would like to add or subtract)
    do{
        cout<<"Press 1 to add parts"<<endl;
        cout<<"Press 2 to subtract parts"<<endl;
        cin>>choice;
    }while((choice<0)||(choice>3));
    
    //if the user chooses to add
    if(choice==1){
        int tempTot=a.num;
        //validate input
        do{
            cout<<"Lets Add!"<<endl;
            cout<<"How many "<<a.desc<<" would you like to add?"<<endl;
            cout<<"We have "<<a.num<<" in inventory right now"<<endl;
            cin>>chng;
            a.num+=chng;

            if(tempTot>=31){
                cout<<"Error! Your value will make the inventory larger than 30"<<endl;
            }
            else{
                valid=true;
                a.num+=chng;
            }
        }while(valid==false);
    }

    //if the user decides to subtract
    if(choice==2){
        int tempTot=a.num;
        //validate input
        do{
            cout<<"Lets Subtract!"<<endl;
            cout<<"How many "<<a.desc<<" would you like to subtract?"<<endl;
            cout<<"We have "<<a.num<<" in inventory right now"<<endl;
            cin>>chng;
            tempTot-=chng;
            
            if(tempTot<=-1){
                cout<<"Error! Your value will make the inventory less than zero"<<endl;
            }
            else{
                valid=true;
                a.num-=chng;
            }
                    
        }while(valid==false);
    }
    
    //show the results
    cout<<"We now have "<<a.num<<" of "<<a.desc<<" in inventory"<<endl;
    
    return a;
}