/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on March 8, 2017, 7:43 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int *mkPntr(int);

/*
 * 
 */
int main(int argc, char** argv) {
    int num;
    int *pntr;
    
    cout<<"Enter the size of the array you would like to allocate"<<endl;
    cin>>num;
    
    pntr=mkPntr(num);
    
    cout<<pntr;
    
    return 0;
}

int *mkPntr(int size){
    int *arr;
    
    if(size<0){
        return NULL;
    }
    
    arr= new int[size];
    
    return arr;
}