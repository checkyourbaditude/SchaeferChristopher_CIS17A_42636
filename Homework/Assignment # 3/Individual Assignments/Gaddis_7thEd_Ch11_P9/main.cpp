/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on March 26, 2017, 2:29 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;
//structures
struct Speaker{
    string name;    //String to hold the speaker's name
    int teleNum;    //int to hold the phone number of the speaker
    string topic;   //string to hold the topic of speaker
    int fee;        //how much the speaker charged
};

//funcitons
Speaker getName(Speaker);
Speaker getTele(Speaker);
Speaker getTop(Speaker);
Speaker getFee(Speaker);
void prntSpkrs(Speaker*,int);
void menuSpkr(Speaker*,int);

int main(int argc, char** argv) {
    //declare size of array
    int size;
    
    cout<<"How many speakers would you like to log?"<<endl;
    cin>>size;
    
    //declare array of speaker structure
    Speaker *arry;
    arry=new Speaker[size];
    
    //loop to get all the speaker's information
    for(int i=0;i<size;i++){
        //ask for the information from the user
        cout<<"Enter the information for the "<<(i+1)<<" speaker"<<endl;
        
        //send the structure to the functions to get speaker's info
        arry[i]=getName(arry[i]);
        arry[i]=getTele(arry[i]);
        arry[i]=getTop(arry[i]);
        arry[i]=getFee(arry[i]);
    }
    
    //print the contents of the array of speakers
    menuSpkr(arry,size);
    
    //delete dynamically allocated array
    delete [] arry;
    
    return 0;
}

//get the speaker's name
Speaker getName(Speaker a){
    //get the info for the speaker name
    cout<<"Speaker Name: ";
    cin>>a.name;
    cout<<endl;
    
    //return entire structure
    return a;
}

//get the telephone number of the speaker
Speaker getTele(Speaker a){
    //data validation loop for the phone number
    do{
        if(a.teleNum<0){
            cout<<"Enter a Number greater than zero!"<<endl;
        }
        
        //get number from user
        cout<<"What was the phone number of the Speaker?: ";
        cin>>a.teleNum;
        cout<<endl;
        
    }while((a.teleNum)<0);
    
    //return entire structure
    return a;
}

//get the topic of the speech
Speaker getTop(Speaker a){
    //get infor for the topic of the speech
    cout<<"What was the topic of the speech?";
    cin>>a.topic; 
    cout<<endl;
    
    //return entire structure
    return a;
}

//get the fee of the speaker
Speaker getFee(Speaker a){
    //data validation loop for the fee requirement
    do{
        if(a.fee<0){
            cout<<"Enter a Number greater than zero!";
        }
        
        //get number from user
        cout<<"What was the fee requirement?";
        cin>>a.fee;
        cout<<endl;
        
    }while((a.fee)<0);
    
    //return entire structure
    return a;
}

void prntSpkrs(Speaker *a, int size){
    cout<<"Speaker\t\t\t\t"<<"Telephone #\t\t\t"<<"Topic\t\t\t"<<"Fee\t\t\t"<<endl;
    
    for(int i=0;i<size;i++){
        cout<<i+1<<". "<<a[i].name<<"\t\t\t\t"<<a[i].teleNum<<"\t\t\t\t"<<a[i].topic<<"\t\t\t"<<a[i].fee<<endl;
    }
    
}

//function that will allow user to change specific elements of a structure
Speaker chngInfo(Speaker *b,int index){
    //variable for user choice
    int choice=0;
    
    //get the user input for what they would like to change
    cout<<"What would you like to edit?"<<endl;
    cout<<"1)"<<b[index].name<<endl;
    cout<<"2)"<<b[index].teleNum<<endl;
    cout<<"3)"<<b[index].topic<<endl;
    cout<<"4)"<<b[index].fee<<endl;
    cin>>choice;
    
    //branching for what users would like to change
    if(choice==1){
        b[index]=getName(b[index]);
        cout<<"The Speaker's name was changed to: "<<b[index].name<<endl;
    }
    else if(choice==2){
        b[index]=getTele(b[index]);
        cout<<"The Speaker's Telephone # was changed to: "<<b[index].teleNum<<endl;
    }
    else if(choice==3){
        b[index]=getTop(b[index]);
        cout<<"The Speaker's topic was changed to: "<<b[index].topic<<endl;
    }
    else if(choice==4){
        b[index]=getFee(b[index]);
        cout<<"The Speaker's fee was changed to: "<<b[index].fee<<endl;
    }
    else{
        cout<<"Number was not recognized!"<<endl;
    }
    
    //return the structure that was edited
    return b[index];
    
}

void menuSpkr(Speaker *a,int size){
    
    //make variable for menu choices and speaker choice
    int x,y;
    
    do{
        //initialize variables back to zero
        x=0;
        y=0;
        
        cout<<endl;
        
        //give the users the options
        cout<<"Welcome to the Speaker Bureau Menu!"<<endl;
        cout<<"Enter the option that you would like"<<endl;
        cout<<"1)Print the full list of Speakers"<<endl;
        cout<<"2)Edit a specific Speaker"<<endl;
        cout<<"3)Exit the program"<<endl;
        
        //get the input from the user
        cin>>x;
        
        //branching for the inputs from the user
        if(x==1) prntSpkrs(a,size);
        if(x==2){  
            //data validation loop for user input with editations
            do{
                if(y>size+1){
                    cout<<"Error!"<<endl;
                }
                
                cout<<"What specific speaker would you like to edit?"<<endl;
                //data validation
                cout<<"Please enter a number between 1 and "<<size<<endl;
                cin>>y;
            }while(y>size);
            
            //make sure user entered value is correct
            y--;
            
            //send for editing
            a[y]=chngInfo(a,y);
        }
        
    }while(x<=2);
    
    cout<<"Exit!"<<endl;
}