/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Assignment_3.h
 * Author: chris
 * This header file is for the entirety of the Assignment # 3
 * Created on March 27, 2017, 3:00 PM
 */

#ifndef ASSIGNMENT_3_H
#define ASSIGNMENT_3_H
#include <cstdlib>
#include <iostream>
#include <string>

//structure from Gaddis 7th Edition Chapter 11 problem #1
struct MovieData{
    std::string title;      //String to hold the title of the movie
    std::string director;   //String to hold the direct of the movie
    std::string relDate;    //Release date Variable
    int runTime;            //Run time in minutes
};

//structure from Gaddis 7th Edition Chapter 11 problem #2
struct MovieDataP2{
    std::string title;      //String to hold the title of the movie
    std::string director;   //String to hold the direct of the movie
    std::string relDate;    //Release date Variable
    int runTime;            //Run time in minutes
    int cost;
    int rev;
};

//structures from Gaddis 7th Edition Chapter 11 problem #3
struct saleData{
    std::string div;    //String to hold the name of the division
    float oneQu;        //sales data for various quarters
    float twoQu;
    float threeQu;
    float fourQu;
    float annSale;      //annual sales total
    float avgQu;        //average quarterly sales
};

//structure from Gaddis 7th Edition Chapter 11 problem #4
struct wStat{
    float totRain;
    float hTemp;
    float lTemp;
    float aTemp;
};

//structures from Gaddis 7th Edition Chapter 11 problem #6
struct Player{
    std::string name;   //String to hold the player name
    int num;            //String to hold the number of the player
    int points;         //number of points scored
};

//structures from Gaddis 7th Edition Chapter 11 problem #9
struct Speaker{
    std::string name;       //String to hold the speaker's name
    int teleNum;            //int to hold the phone number of the speaker
    std::string topic;      //string to hold the topic of speaker
    int fee;                //how much the speaker charged
};

//structure from Gaddis 7th Edition Chapter 11 problem #11
struct mnthBud{
    float hous;     
    float util;     
    float hExp;     
    float trans;
    float food;
    float med;
    float ins;
    float ent;
    float clth;
    float misc;
};

//structure from Gaddis 7th Edition Chapter 11 problem #14
struct invBins{
    std::string desc;
    int num;
};
#endif /* ASSIGNMENT_3_H */

