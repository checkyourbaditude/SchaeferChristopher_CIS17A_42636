/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 * Find the mean, median, and mode of a set of numbers
 * Created on March 11, 2017, 3:55 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//function to sort the array and get the average
void mrkSort(int*, int);
void getMean(int*, int);
void getMed(int*, int);
void getMode(int*, int);

//Functions from class for testing
int *fillAry(int);
int *fillAry(int,int);
void prntAry(int *,int,int);

int main(int argc, char** argv) {
    //create variables for array size, and arrays using pointer notation
    int numTest, *testArr;
    
    //get the size of the array from the user
    cout<<"Lets take some statistics on test scores"<<endl;
    cout<<"How many tests would you like to work with?"<<endl;
    cin>>numTest;
    
    //get numbers into the array
    testArr=fillAry(numTest,4);
    
    //send to function for sorting
    mrkSort(testArr, numTest);
    
    //get the mean
    getMean(testArr, numTest);
    
    //get the median
    getMed(testArr, numTest);
    
    //get the average test score
    getMode(testArr, numTest);
    
    //free the dynamically allocated memory
    delete [] testArr;
    
    return 0;
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

void getMean(int* a, int b){
    float sum=0;
    
    for(int i=0;i<b;i++){
        sum+=a[i];
        cout<<sum<<endl;
    }
    cout<<"The mean is: "<<(sum/static_cast<float>(2.00))<<endl;
}

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

void getMode(int* a, int b){
    
    //print out sorted array
    //prntAry(a,b,3);
    
    //variable to hold the mode of the test scores
    int *modeArr;
    int number=a[0];
    int mode=number;
    int count=1;
    int modeCnt=1;
    int numModes=0;
    
    //create array the size of half
    modeArr=new int[b/2];
    
    //fill the array with zeros
    for(int h=0;h<b/2;h++){
        modeArr[h]=0;
    }
    
    //print new array to see what we get
    //prntAry(modeArr,b/2,3);
    
    for(int j=0;j<b;j++){
        //test to see if there is a match between the two numbers
        if(a[j]==a[j+1]){
            count++;
        }
        //if they do not match
        else{
            //if a new mode was found, must reset the mode array
            if(count>modeCnt){
                //reset the number of modes
                numModes=0;
                
                modeCnt=count;
                mode=a[j];
                //reset the old array, the add the new value to the new array
                for(int a=0;a<(b/2);a++){
                    modeArr[a]=0;
                }
                
                //add the new mode as the first element of the array
                modeArr[0]=mode;
                
                //resent the count
                count=1;
                
                //increment the number of modes
                numModes++;
            }
            
            //just add the value to the new array if it is equal
            else if(count==modeCnt){
                
                //increment the number of modes
                numModes++;
                
                mode=a[j];
                modeArr[numModes-1]=mode;
                
                //resent the count
                count=1;
            }
        }
    }
    
    //output the results
    if(modeCnt==1){
        cout<<"There was no number in the set beyond a single occurance"<<endl;
        cout<<"there is no mode";
    }
    else{  
        cout<<"The highest number of occurances was: "<<modeCnt<<endl;
        cout<<"The number of modes in the set was: "<<numModes<<endl;
        //print list of modes
        prntAry(modeArr,b/2,1);
    }
    
    
    prntAry(modeArr,b/2,3);

    delete [] modeArr;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<(a[i]<10?"  ":" ")<<a[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n,int mod){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i%mod;
    }
    return a;
}

int *fillAry(int n){
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    return a;
}