/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 * Create a function that accepts an in array and the arrays size as arguments,
 * the function should create a copy of the array, except that the element values
 * should be reversed in that copy. Return a pointer to that array.
 * Created on March 14, 2017, 5:56 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//function that will copy and reverse the array
int* revArr(int*,int);

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
    
    //send array to the function for copy+reversing
    cout<<"The address of the pointer to the reversed array: "<<revArr(testArr, numEle);
    
    //free allocated memory
    delete [] testArr;

    return 0;
}

//function to reverse the array
int* revArr(int* Arr,int size){

    //make new pointer, set size for the array
    int *cArrPntr;
    int cpyArr[size];
    int j=size;
    
    cout<<"The copied and reversed array: "<<endl;
    
    //loop that will copy array in reverse order
    for(int i=0;i<size;i++){
            cpyArr[i]=Arr[j-1];
            j--;
            cout<<"Element #"<<i+1<<" is "<<cpyArr[i]<<endl;
    }
    
    //set pointer to new array created and reversed
    cArrPntr=cpyArr;
    
    //return the pointer
    return cArrPntr;
}

