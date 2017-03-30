/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 * Create a function that expands an array by 2 times as big as the inputs
 * copy the contents of the array, and leave the rest as zeros
 * Created on March 14, 2017, 6:45 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//function that will copy and reverse the array
int* dblSize(int*,int);

int main(int argc, char** argv) {
    //create variables for array size, and arrays using pointer notation
    int numEle, *testArr;
    
    //get the size of the array from the user
    cout<<"Lets take some statistics on test scores"<<endl;
    cout<<"How many tests would you like to work with?"<<endl;
    cin>>numEle;
    
    //dynamically allocate the array
    testArr=new int[numEle];
    
    //for loop to get user inputs
    for(int i=0;i<numEle;i++){
        cout<<"Test # "<<(i+1)<<" score is: ";
        cin>> *(testArr+i);
    }
    
    testArr=dblSize(testArr, numEle);
    
    //send array to the function for copy+reversing
    cout<<"The address of the pointer to the copied array: "<<testArr;
    
    //free allocated memory
    delete [] testArr;

    return 0;
}

//function to reverse the array
int* dblSize(int* Arr,int size){
    
    //pointer and variable for new size
    int newSize=size*2;
    int *pntr;
    
    //create a new array
    int *dblArr=new int[newSize];
    
    //for loop to copy the conents, then add zeros for the rest
    for(int i=0;i<(newSize);i++){
        if(i<=size){
            dblArr[i]=Arr[i];
        }
        else{
            dblArr[i]=0;
        }
    }
    
    //print the new array
    for(int h=0;h<newSize;h++){
        cout<<"The "<<h<<" element is "<<dblArr[h]<<endl;
    }
    
    pntr=dblArr;
    
    //remove unused memory
    delete [] Arr;
    
    //return the new array's address
    return pntr;
    
}
