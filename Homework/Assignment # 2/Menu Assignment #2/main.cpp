//Christopher Schaefer
//March 12th, 2017
//

#include <iostream>
#include <iostream>
using namespace std;

//functions for Menu
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
void problem9();

//Functions for the problems
//Problem 1
int *mkPntr(int);

//Problem 2
//functions to sort the array and get the average
void prntArr(int*, int);
void mrkSort(int*, int);
void getAvg(int*, int);

//Problem 3
void mrkSort3(int*, int);

//Problem 6
void selSort(int *[], int);
void prntArr6(const int [], int);
void prntPtr(int *[], int);

//Problem 7
void selSort7(int *[], int);

//Problem 10
int* revArr(int*,int);

//Problem 11
int* dblSize(int*,int);

//Problem 12
int* shftArr(int*,int);

//mean, median, mode from class
void getMean(int*, int);
void getMed(int*, int);
void getMode(int*, int);
int *fillAry(int);
int *fillAry(int,int);
void prntAry(int *,int,int);

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
          default:   def(inN);}
        }while(inN<10);
        return 1;
    }
    void Menu()
    {
           cout<<"Type 1 for Gaddis Chapter 9 Problem 1"<<endl;
           cout<<"Type 2 for Gaddis Chapter 9 Problem 2"<<endl;
           cout<<"Type 3 for Gaddis Chapter 9 Problem 3"<<endl;
           cout<<"Type 4 for Gaddis Chapter 9 Problem 6"<<endl;
           cout<<"Type 5 for Gaddis Chapter 9 Problem 7"<<endl;
           cout<<"Type 6 for Gaddis Chapter 9 Problem 10"<<endl;
           cout<<"Type 7 for Gaddis Chapter 9 Problem 11"<<endl;
           cout<<"Type 8 for Gaddis Chapter 9 Problem 12"<<endl;
           cout<<"Type 9 for Mean, Median, and Mode from Class"<<endl;           
           cout<<"Type 10 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    
    //Gaddis Chapter 9 Problem 1
    void problem1()
    {
           cout<<"In Gaddis Chapter 9 Problem 1"<<endl<<endl;
           
           int num;
           int *pntr;

           cout<<"Enter the size of the array you would like to allocate"<<endl;
           cin>>num;

           pntr=mkPntr(num);

           cout<<pntr<<endl<<endl;
    
    }
    
    //Gaddis Chapter 9 Problem 2
    void problem2()
    {
            cout<<"In Gaddis Chapter 9 Problem 2"<<endl<<endl;
            
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
    }
    
    //Gaddis Chapter 9 Problem 3
    void problem3()
    {
           cout<<"In Gaddis Chapter 9 Problem 3"<<endl<<endl;
           
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
            mrkSort3(testArr, numTest);

            cout<<endl;
            cout<<"Scores after sorting"<<endl<<endl;;

            //print array after sorting
            prntArr(testArr, numTest);

            //get the average test score
            getAvg(testArr, numTest);

            //free the dynamically allocated memory
            delete [] testArr;
    }
    
    //Gaddis Chapter 9 Problem 6
    void problem4()
    {
           cout<<"In Gaddis Chapter 9 Problem 6"<<endl<<endl;
           int NUM_DONATIONS, *donations;
    
            //get the size of the array from the user
            cout<<"How many donations would you like to work with?"<<endl;
            cin>>NUM_DONATIONS;

            donations= new int[NUM_DONATIONS];

            //for loop to get user inputs
            for(int i=0;i<NUM_DONATIONS;i++){
                cout<<"Donation # "<<(i+1)<<" is: ";
                cin>> *(donations+i);
            }

            //An array of pointers to int
            int *arrPtr[NUM_DONATIONS];

            //each element of arrPTR is a point to int. Make each
            //element point to an element in the donations array
            for(int i=0;i<NUM_DONATIONS;i++){
                arrPtr[i]=&donations[i];
            }

            //Sort the elements of the array of points, sorts in ascending order
            selSort(arrPtr, NUM_DONATIONS);

            //display the dontaions using the array of pointers
            //This will display them in sorted order
            cout<<"The dontaions, sorted in ascending order are: \n";
            prntPtr(arrPtr, NUM_DONATIONS);

            //Display the donations in their original order
            cout<<"The donations, in their original order, are: \n";
            prntArr6(donations, NUM_DONATIONS);

            //free the dynamically allocated memory
            delete [] donations;
            
    }
    
    //Gaddis Chapter 9 Problem 7
    void problem5()
    {
            cout<<"In Gaddis Chapter 9 Problem 7"<<endl<<endl;
           
            int NUM_DONATIONS, *donations;
    
            //get the size of the array from the user
            cout<<"How many donations would you like to work with?"<<endl;
            cin>>NUM_DONATIONS;

            donations= new int[NUM_DONATIONS];

            //for loop to get user inputs
            for(int i=0;i<NUM_DONATIONS;i++){
                cout<<"Donation # "<<(i+1)<<" is: ";
                cin>> *(donations+i);
            }

            //An array of pointers to int
            int *arrPtr[NUM_DONATIONS];

            //each element of arrPTR is a point to int. Make each
            //element point to an element in the donations array
            for(int i=0;i<NUM_DONATIONS;i++){
                arrPtr[i]=&donations[i];
            }

            //Sort the elements of the array of points, sorts in ascending order
            selSort7(arrPtr, NUM_DONATIONS);

            //display the dontaions using the array of pointers
            //This will display them in sorted order
            cout<<"The dontaions, sorted in ascending order are: \n";
            prntPtr(arrPtr, NUM_DONATIONS);

            //Display the donations in their original order
            cout<<"The donations, in their original order, are: \n";
            prntArr(donations, NUM_DONATIONS);

            //free the dynamically allocated memory
            delete [] donations;
    }
    
    //Gaddis Chapter 9 Problem 10
    void problem6()
    {
           cout<<"In Gaddis Chapter 9 Problem 10"<<endl;
           
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
            }

    //Gaddis Chapter 9 Problem 11
    void problem7()
    {
            cout<<"In Gaddis Chapter 9 Problem 11"<<endl;
            
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

            testArr=dblSize(testArr, numEle);

            //send array to the function for copy+reversing
            cout<<"The address of the pointer to the copied array: "<<testArr;

            //free allocated memory
            delete [] testArr;
    }
    
    //Gaddis Chapter 9 Problem 12
    void problem8()
    {
            cout<<"In Gaddis Chapter 9 Problem 12"<<endl;
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
    }
    
    //class problem of mean, median, Mode
    void problem9()
    {
            cout<<"In problem the Mean, Median, and Mode Problem"<<endl;
            
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
    }
    
    
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
    
    int *mkPntr(int size){
            int *arr;

            if(size<0){
                return NULL;
            }

            arr= new int[size];

            return arr;
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
    
    //mrkSort changed to sort in asending order
    void mrkSort3(int* a, int b){
            //nested for loop 
            for(int i=0;i<b;i++){
                for (int j=0;j<b;j++){
                    if(a[i]>a[j]){
                        a[i]=a[i]^a[j];
                        a[j]=a[i]^a[j];
                        a[i]=a[i]^a[j];
                    }
                }
            }

            //remove the lowest test score 
            cout<<"The lowest score of "<<a[b-1]<<" has been removed."<<endl;
            a[b-1]=0;
            //cout<<"Does this equal zero? "<<a[b]<<endl;
    }

    //sorts the array in ascending order
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

    void prntArr6(const int arr[], int size){
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
    
    void selSort7(int *arr[], int size){
            int startScan, minIndex;
            int *minElem;

            for(startScan=0; startScan<(size-1); startScan++){
                minIndex=startScan;
                minElem=arr[startScan];

                for(int index=startScan+1; index<size; index++){
                    if(*(arr[index]) > *minElem){
                        minElem = arr[index];
                        minIndex=index;
                    }
                }

                arr[minIndex]=arr[startScan];
                arr[startScan]=minElem;
            }
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
   
    int* dblSize(int* Arr,int size){

            //pointer and variable for new size
            int newSize=size*2;
            int *pntr;

            //create a new array
            int *dblArr=new int[newSize];

            //for loop to copy the conents, then add zeros for the rest
            for(int i=0;i<(newSize);i++){
                if(i<=size){
                    dblArr[i]=Arr[i];
                }
                else{
                    dblArr[i]=0;
                }
            }

            //print the new array
            for(int h=0;h<newSize;h++){
                cout<<"The "<<h<<" element is "<<dblArr[h]<<endl;
            }

            pntr=dblArr;

            //remove unused memory
            delete [] Arr;

            //return the new array's address
            return pntr;

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