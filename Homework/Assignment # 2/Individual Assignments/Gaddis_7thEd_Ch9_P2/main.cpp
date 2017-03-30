/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on March 8, 2017, 8:15 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//function to sort the array and get the average
void prntArr(int*, int);
void mrkSort(int*, int);
void getAvg(int*, int);

int main(int argc, char** argv) {
    //create variables for array size, and arrays using pointer notation
    int numTest, *testArr;
    
    //get the size of the array from the user
    cout<<"Lets take some statistics on test scores"<<endl;
    cout<<"How many tests would you like to work with?"<<endl;
    cin>>numTest;
    
    //dynamically allocate the array
    testArr=new int[numTest];
    
    //for loop to get user inputs
    for(int i=0;i<numTest;i++){
        cout<<"Test # "<<(i+1)<<" score is: ";
        cin>> *(testArr+i);
    }
    
    //print array before sorting
    //prntArr(testArr, numTest);
    
    //send to function for sorting
    mrkSort(testArr, numTest);
    
    cout<<endl;
    cout<<"Scores after sorting"<<endl<<endl;;
    
    //print array after sorting
    prntArr(testArr, numTest);
    
    //get the average test score
    getAvg(testArr, numTest);
    
    //free the dynamically allocated memory
    delete [] testArr;
    
    return 0;
}

void prntArr(int* testArr, int numTest){
    //Test loop to make sure everything is working properly
    for(int j=0;j<numTest;j++){
        cout<<"Score #"<<j+1<<": "<<*(testArr+j)<<endl;
    }
}

//mrkSort changed to sort in asending order
void mrkSort(int* a, int b){
    //nested for loop 
    for(int i=0;i<b;i++){
        for (int j=0;j<b;j++){
            if(a[i]<a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

void getAvg(int* a, int b){
    //variable to hold the sum of the test scores
    float sum;
    
    for(int j=0;j<b;j++){
        sum+=static_cast<float>(a[j]);
    }
    
    cout<<"The average test score is: "<<(sum/static_cast<float>(b))<<endl;
}