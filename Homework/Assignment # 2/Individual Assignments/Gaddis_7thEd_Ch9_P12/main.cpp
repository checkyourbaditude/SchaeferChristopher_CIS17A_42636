/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on March 14, 2017, 8:33 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//function that will copy and reverse the array
int* shftArr(int*,int);

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
    
    testArr=shftArr(testArr, numEle);
    
    //send array to the function for copy+reversing
    cout<<"The address of the pointer to the copied array: "<<testArr;
    
    //free allocated memory
    delete [] testArr;

    return 0;
}

int* shftArr(int* Arr,int size){
    
    //pointer and variable for new size
    int newSize=size+1;
    int *pntr;
    
    //create a new array
    int *newArr=new int[newSize];
    
    //for loop to copy the contents, then add zeros for the rest
    for(int i=0;i<(newSize);i++){
        if(i==0){
            newArr[i]=0;
        }
        else{
            newArr[i]=Arr[i-1];
        }
    }
    
    //print the new array
    for(int h=0;h<newSize;h++){
        cout<<"The "<<h+1<<" element is "<<newArr[h]<<endl;
    }
    
    pntr=newArr;
    
    //remove unused memory
    delete [] Arr;
    
    //return the new array's address
    return pntr;
    
}

