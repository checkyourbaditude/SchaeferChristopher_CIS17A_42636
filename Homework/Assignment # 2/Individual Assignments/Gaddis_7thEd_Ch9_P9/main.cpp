/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 * Create a function that will give the median of a set of values in an array
 * Created on March 11, 2017, 2:56 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//function to sort the array and get the average
void prntArr(int*, int);
void mrkSort(int*, int);
void getMed(int*, int);

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
    getMed(testArr, numTest);
    
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

//this will get the median of the array
void getMed(int* a, int b){
    
    //get float to display the median result
    float median;
    
    //if it is an odd number
    if(b%2==1){
        cout<<"The number of elements in the array is odd"<<endl;
        median=a[(b/2)];
    }
    
    //if it is a even number
    else{
        cout<<"The number of elements in the array is even"<<endl;
        median=static_cast<float>(a[((b/2))]+(a[(b/2)-1]))/static_cast<float>(2.00);
    }
    
    //output the result
    cout<<"The Median is: "<<median<<endl;
    
}



