/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 * Modify program 9-17 so i can be used with any set of donations
 * Dynamically allocate the donations array and ask the user to input its values
 * Created on March 11, 2017, 11:47 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//functional prototypes
void selSort(int *[], int);
void prntArr(const int [], int);
void prntPtr(int *[], int);

int main(int argc, char** argv) {
    const int NUM_DONATIONS =15;
   
    //An array container the donation amounts
    int donations[NUM_DONATIONS]={5, 100, 5, 25, 10, 5, 25, 5,
                                  5, 100, 10, 15, 10, 5, 10};
    
    //An array of pointers to int
    int *arrPtr[NUM_DONATIONS];
    
    //each element of arrPTR is a point to int. Make each
    //element point to an element in the donations array
    for(int i=0;i<NUM_DONATIONS;i++){
        arrPtr[i]=&donations[i];
    }
    
    //Sort the elements of the array of points
    selSort(arrPtr, NUM_DONATIONS);
    
    //display the dontaions using the array of pointers
    //This will display them in sorted order
    cout<<"The dontaions, sorted in ascending order are: \n";
    prntPtr(arrPtr, NUM_DONATIONS);
    
    //Display the donations in their original order
    cout<<"The donations, in their original order, are: \n";
    prntArr(donations, NUM_DONATIONS);
    return 0;
}

void selSort(int *arr[], int size){
    int startScan, minIndex;
    int *minElem;
    
    for(startScan=0; startScan<(size-1); startScan++){
        minIndex=startScan;
        minElem=arr[startScan];
        
        for(int index=startScan+1; index<size; index++){
            if(*(arr[index]) < *minElem){
                minElem = arr[index];
                minIndex=index;
            }
        }
        
        arr[minIndex]=arr[startScan];
        arr[startScan]=minElem;
    }
}

void prntArr(const int arr[], int size){
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void prntPtr(int *arr[], int size){
    for(int j=0;j<size;j++){
        cout<<*(arr[j])<<" ";
    }
    cout<<endl;
}