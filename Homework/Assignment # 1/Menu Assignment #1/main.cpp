//Christopher Schaefer
//March 6th, 2017
//All Problems are from the 7th edition of the textbook


#include <iostream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//constant for array size
const int NUM_NAMES=20;

void Menu();
int getN();
void def(int);
//Chapter 5 Problem 11
void problem1();
//Chapter 6 Problem 7
void problem2();
//Chapter 7 Problem 6
void problem3();
//Chapter 8 Problem 7
void problem4();
//Chapter 3 Problem 12
void problem5();
//Chapter 3 Problem 13
void problem6();

void problem7();
void problem8();
void problem9();
void problem10();

//functional prototypes
float celsius(float conv);
void genNums();
void showArry(string [], int);
void bubbleSort(string [], int);
void biSearch(string [], int);
void calcS(float,string,short);
void getData(float [], int);
float totalRainfall(float [], int);
float averageRainfall(float [], int);
int driestMonth(float [], int);
int wettestMonth(float [], int);
void displayReport(float, float, int, int, float [], int);
string getMonth(int);


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
          case 8:    problem8();break;
          case 9:    problem9();break;
          case 10:   problem10();break;
          default:   def(inN);}
        }while(inN<11);
        return 1;
    }
    void Menu()
    {
           cout<<"Type 1 for problem 1"<<endl;
           cout<<"Type 2 for problem 2"<<endl;
           cout<<"Type 3 for problem 3"<<endl;
           cout<<"Type 4 for problem 4"<<endl;
           cout<<"Type 5 for problem 5"<<endl;
           cout<<"Type 6 for problem 6"<<endl;
           cout<<"Type 7 for problem 7"<<endl;
           cout<<"Type 7 for problem 8"<<endl;
           cout<<"Type 7 for problem 9"<<endl;
           cout<<"Type 7 for problem 10"<<endl;
           cout<<"Type 11 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    //Chapter 5 Problem 11
    void problem1()
    {
            //Declare Variables
            int spop,epop,days;
            float grate;

            //Input
            cout<<"What is the starting population?"<<endl;
            cin>>spop;
            cout<<"What is the growth rate?(by percentage)"<<endl;
            cin>>grate;
            grate/=100.00;
            cout<<"How many days will the population grow?"<<endl;
            cin>>days;

            //loops and output
            for(int i=0;i<=days;i++){
                cout<<"Day "<<i<<": "<<spop<<"\n";
                spop=(spop*grate)+spop;
            }
    }
    //Chapter 6 Problem 7
    void problem2()
    {
            //variables
            float fTemp=0.00f, cTemp=0.00f;

            //output
            cout<<"Lets convert a range of Fahrenheit temps to Celsius!"<<endl;
            cout<<"What is the first temp you would like like to see?"<<endl;
            cin>>fTemp;

            cout<<"Here are the converted temperatures:"<<endl;

            //loop for multiple conversions 
            for(int i=0;i<=20;i++){
                //call the function and assign return to cTemp
                cTemp = celsius(fTemp+i);

                //output the results
                cout<<setprecision(2)<<fixed<<fTemp+i;
                cout<<" degree Fahrenheit is ";
                cout<<setprecision(2)<<fixed<<cTemp<<" degree celsius."<<endl;
            }
    }
    //Chapter 7 Problem 6
    void problem3()
    {
           genNums();
    
            //open the file stream to bring in the numbers to the array
            fstream readIn("numbers.text");
            const int SIZE=100;
            char txtNums[SIZE];
            int i=0;

            //continue reading in until the end of the file is reached
            while(readIn>>txtNums[i]){
                readIn>>txtNums[i];
                cout<<"The "<<i<<" element is:"<<txtNums[i]<<endl;
                i++;
            }

            readIn.close();
    }
    //Chapter 8 Problem 7
    void problem4()
    {
            //variables
            string names[NUM_NAMES]={
                "Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim",
                "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill",
                "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean",
                "Weaver, Jim", "Pore, Bob", "Butherfod, Greg", "Javens, Renee",
                "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};

            cout<<"Unstorted String Array"<<endl;
            showArry(names, NUM_NAMES);
            cout<<endl;

            //sort the string array
            biSearch(names, NUM_NAMES);

            cout<<"Sorted String Array"<<endl;
            showArry(names, NUM_NAMES);
            cout<<endl;
    }
    //Chapter 3 Problem 12
    void problem5()
    {
            //variables
            string month;
            short year;
            float collect;

            //make sure user knows the purpose of the program
            cout<<"Lets Calculate the Taxes owed"<<endl;

            //get information or Inputs
            cout<<"What is the year?"<<endl;
            cin>>year;

            cout<<"What month is it?"<<endl;
            cin>>month;

            cout<<"What was the total collected at the register in the month of "<<month<<" in the year "<<year<<"?"<<endl;
            cin>>collect;

            calcS(collect,month,year);
            //cout<<year;
            //cout<<month;
    }
    //Chapter 3 Problem 13
    void problem6()
    {
            //Declare Variables
            float Pvalue, taxtot;

            //input
            cout<<"What is your property value, we need to take your taxes!"<<endl;
            cin>>Pvalue;

            //calculations
            taxtot=((0.6*Pvalue)/100)*0.64;
            std::cout <<std::fixed;
            std::cout <<std::setprecision(2);

            //output
            cout<<"You owe: "<<taxtot<<" dollars in taxes"<<endl;
    }
    //Chapter 3 Problem 22
    void problem7()
    {
            //Declare Variables
            string name, age, city, college, pro, animal, pname;

            //inputs
            cout<<"What is your name?"<<endl;
            cin>>name;
            cout<<"How old are you?"<<endl;
            cin>>age;
            cout<<"What city are you in?"<<endl;
            cin>>city;
            cout<<"What school do you go to?"<<endl;
            cin>>college;
            cout<<"What profession do you want to be?"<<endl;
            cin>>pro;
            cout<<"What is your favorite animal?"<<endl;
            cin>>animal;
            cout<<"What is the animals name?"<<endl;
            cin>>pname;

            //outputs
            cout<<"There once was a person named "<<name<<" who lived in "<<city<<"\n. At"
                  " the age of "<<age<<", "<<name<<"went to college at "<<college<<"\n. "
                  <<name<<" graduated and went to work as a "<<pro<<"\n. Then,"<<name<<
                  "adopted a(n) "<<animal<<" named "<<pname<<"\n. They both lived"
                  "happily after!";
    }
    //Chapter 4 Problem 10
    void problem8()
    {
            //deglcare Variables
            //q is quantity
            //d1 is discount 1, d2 is discount 2 etc.
            short q,cost=99,totp, totd;
            float d1=0.20f, d2=0.30f, d3=0.40f, d4=0.50f;

            //input
            cout<<"What is the amount of software that you would like to buy?"<<endl;
            cout<<"Each package costs 99$, and our discounts are as follows:"<<endl;
            cout<<"10-19 is 20% \n20-49 is 30%\n50-99 is 40%\n100+ is 50%"<<endl;
            cin>>q;

            //logic/calculations
            if(q>=10 && q<=19){
                totd=q*cost*d1;
                totp=q*cost-totd;
                cout<<"Your discount is "<<totd<<endl;
                cout<<"Your total purchase is "<<totp<<endl;
            }
            else if(q>=20 && q<=49){
                totd=q*cost*d2;
                totp=q*cost-totd;
                cout<<"Your discount is "<<totd<<endl;
                cout<<"Your total purchase is "<<totp<<endl;
            }
            else if(q>=50 && q<=99){
                totd=q*cost*d3;
                totp=q*cost-totd;
                cout<<"Your discount is "<<totd<<endl;
                cout<<"Your total purchase is "<<totp<<endl;
            }
            else if(q>=100){
                totd=q*cost*d4;
                totp=q*cost-totd;
                cout<<"Your discount is "<<totd<<endl;
                cout<<"Your total purchase is "<<totp<<endl;
            }
            else{
                totp=cost*q;
                cout<<"Your discount is "<<totd<<endl;
                cout<<"Your total purchase is "<<totp<<endl;
            }
    }
    //Chapter 4 Problem 22
    void problem9()
    {
            //Declare Variables
            //int mins;
            float mins,tot,stime,chrg1=0.12f,chrg2=0.55f,chrg3=0.35f;

            //Input
            cout<<"I see you are going to make a long distance call"<<endl;
            cout<<"Here are the rates for such a call:"<<endl;
            cout<<"starting time of call    Rate per Minute"<<endl;
            cout<<"0-6:59                   0.12 cents"<<endl;
            cout<<"7-19:00                  0.55 cents"<<endl;
            cout<<"19:01-23:59              0.35 cents"<<endl;
            cout<<"Enter the start time of the call in HH.MM format"<<endl;
            cin>>stime;
            cout<<"How long was the call in minutes"<<endl;
            cin>>mins;

            //Validate data, make sure the number is no greater than 0.59
            //and no larger than 23.59, using modf to split number
            //logic
            if(stime<07.00){
                tot=mins*chrg1;
                cout<<"You Have been charged "<<chrg1<<" per minute for your "<<endl;
                cout<<" call of "<<mins<<" minutes for a total charge of "<<tot<<endl;
                cout<<" dollars"<<endl;
            }
            else if (stime>=07.00&&stime<=19.00){
                tot=mins*chrg2;
                cout<<"You Have been charged "<<chrg2<<" per minute for your "<<endl;
                cout<<" call of "<<mins<<" minutes for a total charge of "<<tot<<endl;
                cout<<" dollars"<<endl;
            }
            else{
                tot=mins*chrg3;
                cout<<"You Have been charged "<<chrg3<<" per minute for your "<<endl;
                cout<<"call of "<<mins<<"minutes for a total charge of "<<tot<<endl;
                cout<<" dollars"<<endl;
            }
    }
    void problem10()
    {
            const int mths = 12;
            float rainfall[mths];
            float Total, Average, Least, Most;

            // Call function getData
            getData(rainfall, mths);

            // Call function totalRainfall
            Total = totalRainfall(rainfall, mths);
            Average = averageRainfall(rainfall, mths);
            Least = driestMonth(rainfall, mths);
            Most = wettestMonth(rainfall, mths);
            displayReport(Total, Average, Least, Most, rainfall, mths);
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
    
    //conversion function
    float celsius(float conv){
            return  ((5.00/9.00)*(conv-32)); 
    }
    
    void genNums(){
            //set random number seed
            srand(static_cast<unsigned int>(time(0)));

            //open File stream
            ofstream fillFile;
            fillFile.open("numbers.dat");

            //figure out how many numbers are going into the file
            int numContents=rand()%100+1;
            const int SIZE=100;
            int numbers[SIZE];
            int nArray=0;

            //fill the file with numbers
            for(int i=0;i<numContents;i++){
                fillFile<<rand()%1000+1<<"/n/r";
            }

            //close the file
            fillFile.close();
    }
    void showArry(string arr[], int S){
            for(int i=0;i<S;i++){
                cout<<"Name #"<<i+1<<": "<<arr[i]<<endl;
            }
    }
   
    void bubbleSort(string strArr[], int S){
            bool swap;
            string temp;

            do{
                swap=false;
                for(int count=0;count<(S-1);count++){
                    if(strArr[count]>strArr[count+1]){
                        temp=strArr[count];
                        strArr[count]=strArr[count+1];
                        strArr[count+1]=temp;
                        swap=true;
                    }
                }
            }while(swap);
    }

    void biSearch(string str[], int S){
            bubbleSort(str,S);
    }
    void calcS (float collect, string M, short Y){
            //cout<<"The Function Works!";
            float S, sTax, cTax;

            S=collect/(1.06);
            sTax=S*(0.04);
            cTax=S*(0.02);

            cout<<cTax;

            //output of the information
            cout<<"Month:"<<M<<endl;
            cout<<"---------------------"<<M<<endl;
            cout<<"Collected: "<<setprecision(2)<<fixed<<collect<<endl;
            cout<<"Sales: "<<setprecision(2)<<fixed<<S<<endl;
            cout<<"County Sales Tax: "<<setprecision(2)<<fixed<<cTax<<endl;
            cout<<"State Sales Tax: "<<setprecision(2)<<fixed<<sTax<<endl;
            cout<<"Total Sales Tax: "<<setprecision(2)<<fixed<<cTax+sTax<<endl;
    }
    //gets user input
        void getData(float rainfall[], int mths){
                float rain;

                cout << "Enter the total rainfall for each of 12 months.\n";
                for (int i = 0; i < mths; i++){
                    do{
                        cout << "Month #" <<  (i + 1) << ": ";
                        cin >> rain;

                        if (rain < 0){
                            cout << "Error! Rainfall amounts must be greater than 0.\n";
                        }
                    }while(rain < 0);

                    rainfall[i] = rain;
                }	 
        }

        float totalRainfall(float rainfall[], int mths){
            float tot = 0;

            for (int i = 0; i < mths; i++){
                tot+=rainfall[i];
            }

            return tot;
        }

        float averageRainfall(float rainfall[], int mths){
                return totalRainfall(rainfall, mths) / mths;
        }

        int driestMonth(float rainfall[], int mths){	
            float Driest = rainfall[0];
            int R;
            for (int i = 0; i < mths; i++){
                if(rainfall[i] < Driest){
                        Driest = rainfall[i];
                        R = i;
                }
            }
            return R;
        }

        int wettestMonth(float rainfall[], int mths){
            float Wettest = rainfall[0];
            int R;
            for (int i = 0; i < mths; i++){
                if(rainfall[i] > Wettest){
                    Wettest = rainfall[i];
                    R = i;
                }
            }
            return R;
        }

        void displayReport(float T, float A, int L, int M, float R[], int S){
            cout << "\n\n    2016 Rain Report for Riverside County\n\n";
            cout << fixed << showpoint << setprecision(2);
            cout << "Total rainfall: " << T << " inches\n";
            cout << "Average monthly rainfall: " << A << " inches\n";
            cout << "The least rain fell in " << getMonth(L) << " with "
                << R[L] << " inches.\n";
            cout << "The most rain fell in " << getMonth(M) << " with "
                << R[M] << " inches.\n";
        }

        string getMonth(int Mth){
            string M;
            switch (Mth + 1){
                case 1:{
                    M="January";
                    break;
                }
                case 2:{
                    M="February";
                    break;
                }
                case 3:{
                    M="March";
                    break;
                }
                case 4:{ 
                    M="April";
                    break;
                }
                case 5:{
                    M="May";
                    break;
                }
                case 6:{
                    M="June";
                    break;
                }
                case 7:{ 
                    M="July";
                    break;
                }
                case 8:{
                    M="August";
                    break;
                }
                case 9:{ 
                    M="September";
                    break;
                }
                case 10:{
                    M="October";
                    break;
                }
                case 11:{
                    M="November";
                    break;
                }
                case 12:{
                    M="December";
                    break;
                }
            }
            return M;
        }
    

