//Mark E. Lehr
//October 27th, 2011
//Menu to be used for the midterm
//homework and midterm, etc....

#include "Assignment_3.h"
using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();

//funcitonal Prototypes Gaddis 7th Edition Chapter 11 Problem # 1
MovieData getInfoP1(MovieData);
void prntDataP1(MovieData);

//funcitonal Prototypes Gaddis 7th Edition Chapter 11 Problem # 2
MovieDataP2 getInfo(MovieDataP2);
void prntDataP2(MovieDataP2);

//functions Prototypes Gaddis 7th Edition Chapter 11 Problem # 3
saleData getSData(saleData);
void prntSData(saleData);

//functions Prototypes Gaddis 7th Edition Chapter 11 Problem # 4
wStat fillStat(wStat);
void prntStat(wStat,int);

//functional Prototypes Gaddis 7th Edition Chapter 11 Problem # 6
Player getInfo(Player);
void prntTeam(Player*,int);

//functional Prototypes Gaddis 7th Edition Chapter 11 Problem # 9
Speaker getName(Speaker);
Speaker getTele(Speaker);
Speaker getTop(Speaker);
Speaker getFee(Speaker);
void prntSpkrs(Speaker*,int);
void menuSpkr(Speaker*,int);

//functional Prototypes Gaddis 7th Edition Chapter 11 Problem # 11
mnthBud getMny(mnthBud);
void comp(mnthBud,mnthBud);

//functional Prototypes Gaddis 7th Edition Chapter 11 Problem # 14
invBins *iniInv(invBins*);
void prntInv(invBins*,int);
invBins editInv(invBins,int);


    int main(int argv,char *argc[])
    {
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          case 8:    problem7();break;
          default:   def(inN);}
        }while(inN<9);
        return 1;
    }
    void Menu()
    {
       cout<<"Type 1 for problem 1: Gaddis 7th Edition Chapter 11 Problem # 1"<<endl;
       cout<<"Type 2 for problem 2: Gaddis 7th Edition Chapter 11 Problem # 2"<<endl;
       cout<<"Type 3 for problem 3: Gaddis 7th Edition Chapter 11 Problem # 3"<<endl;
       cout<<"Type 4 for problem 4: Gaddis 7th Edition Chapter 11 Problem # 4"<<endl;
       cout<<"Type 5 for problem 5: Gaddis 7th Edition Chapter 11 Problem # 6"<<endl;
       cout<<"Type 6 for problem 6: Gaddis 7th Edition Chapter 11 Problem # 9"<<endl;
       cout<<"Type 7 for problem 7: Gaddis 7th Edition Chapter 11 Problem # 11"<<endl;
       cout<<"Type 8 for problem 8: Gaddis 7th Edition Chapter 11 Problem # 14"<<endl;;
       cout<<"Type 9 to exit \n"<<endl;
    }
    int getN()
    {
       int inN;
       cin>>inN;
       return inN;
    }
    void problem1()
    {
        cout<<"In problem # 1 Gaddis 7th Edition Chapter 11 Problem # 1"<<endl<<endl;
        //declare two instances of the movie structure, for outputs
        MovieData movieOne;
        MovieData movieTwo;

        //fill the strutures
        movieOne=getInfoP1(movieOne);
        movieTwo=getInfoP1(movieTwo);

        //print the data
        cout<<"Movie # 1:"<<endl<<endl;
        prntDataP1(movieOne);
        cout<<"Movie # 2:"<<endl<<endl;
        prntDataP1(movieTwo);
    }
    void problem2()
    {
        cout<<"In problem # 2 Gaddis 7th Edition Chapter 11 Problem # 2"<<endl<<endl;
        //declare two instances of the movie structure, for outputs
        MovieDataP2 movieOne;
        MovieDataP2 movieTwo;

        //fill the strutures
        movieOne=getInfo(movieOne);
        movieTwo=getInfo(movieTwo);

        //print the data
        cout<<"Movie # 1:"<<endl<<endl;
        prntDataP2(movieOne);
        cout<<"Movie # 2:"<<endl<<endl;
        prntDataP2(movieTwo);
    }
    void problem3()
    {
        cout<<"In problem # 3 Gaddis 7th Edition Chapter 11 Problem # 3"<<endl<<endl;
        //declare structures to hold data
        saleData East={"East"};
        saleData West={"West"};
        saleData South={"South"};
        saleData North={"North"};

        //get the data from each division
        East=getSData(East);
        West=getSData(West);
        South=getSData(South);
        North=getSData(North);

        //display the information
        prntSData(East);
    }
    void problem4()
    {
        cout<<"In problem # 4 Gaddis 7th Edition Chapter 11 Problem # 4"<<endl<<endl;
        //declare size of array
        int size=12;
        float totAvgT,totAvgR;

        //declare array of speaker structure
        wStat *arry;
        arry=new wStat[size];

        //get the user to fill the array
        for(int i=0;i<size;i++){
            cout<<"Enter the data for month # "<<i+1<<endl;
            arry[i]=fillStat(arry[i]);
            totAvgT+=arry[i].aTemp;
            totAvgR+=arry[i].totRain;        
        }

        //print the array of structures
        for(int k=0;k<size;k++){
            prntStat(arry[k],k);
        }

        cout<<"The average temp over the past 12 months was: "<<(totAvgT/static_cast<float>(size))<<endl;
        cout<<"The average rainfall over the past 12 months was: "<<(totAvgR/static_cast<float>(size))<<endl;

        //delete dynamically allocated array
        delete [] arry;
    }
    void problem5()
    {
        cout<<"In problem # 5 Gaddis 7th Edition Chapter 11 Problem # 6"<<endl<<endl;
        //declare size of array
        int teamSize=12;

        //declare array of player structure
        Player *team;
        team=new Player[teamSize];

        //loop to get all the player's information
        for(int i=0;i<teamSize;i++){
            //ask for the information from the user
            cout<<"Enter the information for the "<<(i+1)<<" player"<<endl;

            //send the structure to the function to get player info
            team[i]=getInfo(team[i]);
        }

        //print the team in a table!
        prntTeam(team,teamSize);

        //delete dynamically allocated array
        delete [] team;
    }
    void problem6()
    {
        cout<<"In problem # 6 Gaddis 7th Edition Chapter 11 Problem # 9"<<endl<<endl;
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
    }
    void problem7()
    {
        cout<<"In problem # 7 Gaddis 7th Edition Chapter 11 Problem # 11"<<endl<<endl;
         //delciare instances of the monthly budget structure
        mnthBud month;
        mnthBud goal = {500.00,150.00,65.00,50.00,250.00,30.00,100.00,150.00,75.00,50.00};

        cout<<"Lets see how you did this month in your budgeting!"<<endl;


        //send the structure to the functions to get the amount spent in the month info
        month=getMny(month);

        //compare the goal with what the user entered
        comp(month,goal);
    }
    void problem8()
    {
        cout<<"In problem # 8 Gaddis 7th Edition Chapter 11 Problem # 14"<<endl<<endl;
        //declare size of array
        int size=10;
        int bin=0;

        //declare array of inventory structure
        invBins *arry;
        arry=new invBins[size];

        //pass array to function for initialization of array
        arry=iniInv(arry);

        //Loop to update the inventory with new sizes
        do{
            //variables for the choices the user is making
            bin=0;

            //print the array of structures so far
            prntInv(arry, size);
            cout<<"Select a bin, or enter 11 to exit"<<endl;
            cin>>bin;

            //lower the bin to reflect actual value in the array
            bin-=1;

            //send to the edit function if user chooses to edit
            if((bin<=10)&&(bin>0)){
                arry[bin]=editInv(arry[bin],bin);
            }
        }while(bin<10);

        //delete dynamically allocated array
        delete [] arry;
    }
    void def(int inN)
    {
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
    
MovieData getInfoP1(MovieData a){
    //get the info for the movie
    cout<<"Enter the Data for the Movie"<<endl<<endl;
    
    cout<<"what is the title?"<<endl;
    cin>>a.title;
    
    cout<<"Who was the director?"<<endl;
    cin>>a.director;
    
    cout<<"what is the release date?"<<endl;
    cin>>a.relDate;
    
    cout<<"what is the run time?"<<endl;
    cin>>a.runTime;
    
    //return the structure MovieData
    return a;
}
void prntDataP1(MovieData a){
    cout<<"Movie:           "<<a.title<<endl;
    cout<<"Director:        "<<a.director<<endl;
    cout<<"Release Date:    "<<a.relDate<<endl;
    cout<<"Run Time:        "<<a.runTime<<endl;
}
    
//this function gets the data for the structures
MovieDataP2 getInfo(MovieDataP2 a){
    //get the info for the movie
    cout<<"Enter the Data for the Movie"<<endl<<endl;
    
    cout<<"what is the title?"<<endl;
    cin>>a.title;
    
    cout<<"Who was the director?"<<endl;
    cin>>a.director;
    
    cout<<"what is the release date?"<<endl;
    cin>>a.relDate;
    
    cout<<"what is the run time?"<<endl;
    cin>>a.runTime;
    
    cout<<"what is the production cost?"<<endl;
    cin>>a.cost;
    
    cout<<"what is the revenue?"<<endl;
    cin>>a.rev;
    
    //return the structure MovieData
    return a;
}

//print the structure data
void prntDataP2(MovieDataP2 a){
    //create variable for the amount of money made or lost
    int money=(a.rev)-(a.cost);
    
    cout<<"Movie:           "<<a.title<<endl;
    cout<<"Director:        "<<a.director<<endl;
    cout<<"Release Date:    "<<a.relDate<<endl;
    cout<<"Run Time:        "<<a.runTime<<endl;
    
    //output if loss or profit
    if(money<0){
        cout<<"The loss was:    "<<money<<endl;
    }
    else{
        cout<<"The profit was:  "<<money<<endl;
    }
    
    cout<<endl<<endl;
}    

//function to get information from user
saleData getSData(saleData a){    
    cout<<"Lets get the sales information for the "<<a.div<<" division"<<endl;
    
    //get information from user
    cout<<"What was the first quarter sales?"<<endl;
    cin>>a.oneQu;
    
    cout<<"What was the second quarter sales?"<<endl;
    cin>>a.twoQu;
    
    cout<<"What was the third quarter sales?"<<endl;
    cin>>a.threeQu;
    
    cout<<"What was the fourth quarter sales?"<<endl;
    cin>>a.fourQu;
    
    //calcuations
    a.annSale=a.oneQu+a.twoQu+a.threeQu+a.fourQu;
    a.avgQu=(a.annSale/(static_cast<float>(4)));
    
    //return structure
    return a;
}

//print out the data
void prntSData(saleData e){
    cout<<"Here are the summations of the sales Data"<<endl;
    cout<<"Division: "<<e.div<<endl;
    cout<<"Q1: "<<e.oneQu<<endl;
    cout<<"Q2: "<<e.twoQu<<endl;
    cout<<"Q3: "<<e.threeQu<<endl;
    cout<<"Q4: "<<e.fourQu<<endl;
    cout<<"Total Sales for the year: "<<e.annSale<<endl;
    cout<<"Quarterly Avg: "<<e.avgQu<<endl;
}

wStat fillStat(wStat a){
    cout<<"What was the total rainfall during the month (in inches)?"<<endl;
    cin>>a.totRain;
    
    cout<<"What was the high temp during the month? (in fahrenheit)"<<endl;
    cin>>a.hTemp;
    
    cout<<"What was the low temp during the month? (in fahrenheit)"<<endl;
    cin>>a.lTemp;
    
    //calculations
    a.aTemp=(((a.hTemp+a.lTemp)/static_cast<float>(2)));
    
    cout<<"The average temp for this month was: "<<a.aTemp<<endl;
    
    //return the structure
    return a;
}

//output the stats
void prntStat(wStat b,int j){
    cout<<"Weather Statistics for month #"<<j+1<<endl;
    cout<<b.totRain<<" inches of rain"<<endl;
    cout<<b.hTemp<<" was the highest tempurature"<<endl;
    cout<<b.lTemp<<" was the lowest tempurature"<<endl;
}

//get the info for each player
Player getInfo(Player a){
    cout<<"Player Name: ";
    cin>>a.name;
    cout<<endl;
    
    //data validation loop
    do{
        if(a.num<0){
            cout<<"Enter a Number greater than zero!"<<endl;
        }
        
        //get number from user
        cout<<"Player Number: ";
        cin>>a.num;
        cout<<endl;
        
    }while((a.num)<0);
    
    cout<<"Number of Goals: ";
    cin>>a.points; 
    cout<<endl;
    
    cout<<endl<<endl;
    return a;
}

//funciton that prints a table of the players and their information
void prntTeam(Player *a, int size){
    cout<<"Player\t\t\t"<<"Number\t\t\t"<<"Goals\t\t\t"<<endl;
    
    for(int i=0;i<size;i++){
        cout<<a[i].name<<"\t\t\t"<<a[i].num<<"\t\t\t"<<a[i].points<<endl;
    }
    
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

//function for getting the user's budget information
mnthBud getMny(mnthBud a){
    cout<<"How much did you spend on housing?"<<endl;
    cin>>a.hous;
    
    cout<<"How much did you spend on Utilities?"<<endl;
    cin>>a.util;
    
    cout<<"How much did you spend on Household expenses?"<<endl;
    cin>>a.hExp;
    
    cout<<"How much did you spend on Transportation?"<<endl;
    cin>>a.trans;
    
    cout<<"How much did you spend on food?"<<endl;
    cin>>a.food;
    
    cout<<"How much did you spend on Medical expenses?"<<endl;
    cin>>a.med;
    
    cout<<"How much did you spend on Insurance?"<<endl;
    cin>>a.ins;
    
    cout<<"How much did you spend on Entertainment?"<<endl;
    cin>>a.ent;
    
    cout<<"How much did you spend on Clothing?"<<endl;
    cin>>a.clth;
    
    cout<<"How much did you spend on Miscellaneous?"<<endl;
    cin>>a.misc;
    
    return a;
}

//Function for comparing the budget and actual money spent
void comp(mnthBud a,mnthBud b){
    //store compared differences
    float dHouse=a.hous-b.hous;
    float dUtil=a.util-b.util;
    float dHExp=a.hExp-b.hExp;
    float dTrans=a.trans-b.trans;
    float dFood=a.food-b.food;
    float dMed=a.med-b.med;
    float dIns=a.ins-b.ins;
    float dEnt=a.ent-b.ent;
    float dClth=a.clth-b.clth;
    float dMisc=a.misc-b.misc;
    float sum=dHouse+dUtil+dHExp+dTrans+dFood+dMed+dIns+dEnt+dClth+dMisc;
    
    //output the comparison
    cout<<"Lets see how much you spent compared to your budget!"<<endl;
    cout<<"Catagory\t\t\t"<<"Budged\t\t\t\t"<<"Spent \t\t\t\t"<<"Difference"<<endl;
    cout<<"Housing"<<"\t\t\t\t"<<a.hous<<"\t\t\t\t"<<b.hous<<"\t\t\t\t"<<dHouse<<endl;
    cout<<"Utilities"<<"\t\t\t"<<a.util<<"\t\t\t\t"<<b.util<<"\t\t\t\t"<<dUtil<<endl;
    cout<<"Household Expenses"<<"\t\t"<<a.hExp<<"\t\t\t\t"<<b.hExp<<"\t\t\t\t"<<dHExp<<endl;
    cout<<"Transportation"<<"\t\t\t"<<a.trans<<"\t\t\t\t"<<b.trans<<"\t\t\t\t"<<dTrans<<endl;
    cout<<"Food"<<"\t\t\t\t"<<a.food<<"\t\t\t\t"<<b.food<<"\t\t\t\t"<<dFood<<endl;
    cout<<"Medical"<<"\t\t\t\t"<<a.med<<"\t\t\t\t"<<b.med<<"\t\t\t\t"<<dMed<<endl;
    cout<<"Insurance"<<"\t\t\t"<<a.ins<<"\t\t\t\t"<<b.ins<<"\t\t\t\t"<<dIns<<endl;
    cout<<"Entertainment"<<"\t\t\t"<<a.ent<<"\t\t\t\t"<<b.ent<<"\t\t\t\t"<<dEnt<<endl;
    cout<<"Clothing"<<"\t\t\t"<<a.clth<<"\t\t\t\t"<<b.clth<<"\t\t\t\t"<<dClth<<endl;
    cout<<"Miscellaneous"<<"\t\t\t"<<a.misc<<"\t\t\t\t"<<b.misc<<"\t\t\t\t"<<dMisc<<endl;
    
    if(sum<0){
        cout<<"You were under budget by $ "<<sum<<endl;
    }
    else{
        cout<<"You were over budget by $ "<<sum<<endl;
    }
    
}

//initialize all the information into the inventory bin array
invBins *iniInv(invBins* a){
    a[0]={"valve   ",10};
    a[1]={"bearing ",5};
    a[2]={"bushing ",15};
    a[3]={"coupling",21};
    a[4]={"flange  ",7};
    a[5]={"gear    ",5};
    a[6]={"gear housing",5};
    a[7]={"vacuum grip",25};
    a[8]={"cable   ",18};
    a[9]={"rod     ",12};
    
    return a;
}

void prntInv(invBins* a, int size){
    cout<<" Description\t\t\t\t"<<"Quantity"<<endl;
    
    for(int i=0;i<size;i++){
        cout<<i+1<<")"<<a[i].desc<<"\t\t\t\t"<<a[i].num<<endl;
    }
}

//This function allows the user to edit the inventory
invBins editInv(invBins a,int ele){
    int choice=0;
    int chng=0;
    bool valid=false;
    
    //loop for user input (if they would like to add or subtract)
    do{
        cout<<"Press 1 to add parts"<<endl;
        cout<<"Press 2 to subtract parts"<<endl;
        cin>>choice;
    }while((choice<0)||(choice>3));
    
    //if the user chooses to add
    if(choice==1){
        int tempTot=a.num;
        //validate input
        do{
            cout<<"Lets Add!"<<endl;
            cout<<"How many "<<a.desc<<" would you like to add?"<<endl;
            cout<<"We have "<<a.num<<" in inventory right now"<<endl;
            cin>>chng;
            a.num+=chng;

            if(tempTot>=31){
                cout<<"Error! Your value will make the inventory larger than 30"<<endl;
            }
            else{
                valid=true;
                a.num+=chng;
            }
        }while(valid==false);
    }

    //if the user decides to subtract
    if(choice==2){
        int tempTot=a.num;
        //validate input
        do{
            cout<<"Lets Subtract!"<<endl;
            cout<<"How many "<<a.desc<<" would you like to subtract?"<<endl;
            cout<<"We have "<<a.num<<" in inventory right now"<<endl;
            cin>>chng;
            tempTot-=chng;
            
            if(tempTot<=-1){
                cout<<"Error! Your value will make the inventory less than zero"<<endl;
            }
            else{
                valid=true;
                a.num-=chng;
            }
                    
        }while(valid==false);
    }
    
    //show the results
    cout<<"We now have "<<a.num<<" of "<<a.desc<<" in inventory"<<endl;
    
    return a;
}