/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <iomanip>
#include <ctime> // Needed for the true randomization

using namespace std;

int
main ()
{
    srand( time(0)); // This will ensure a really randomized number by help of time.
    
    //setting the dimentions of the array
    const int numRows = 10;
    const int numColumns = 10;

    //creating the 2-d array
    float arr[numRows][numColumns] = {0};
  
    //creating possibilities for 10 different states
    float states[10] = {0};
  
    //additional variables
    int sum = 0, currstate = 0, nextstate = 0;
    float sum2 = 0, errrate = 0;
    
    //number of symbols and runs
    int symbcount = 0, runcount = 0;
    
    //message vectors 
    vector <int> err;
    cout<<"How many symbols per message do you want? \n";
    cin>>symbcount;
    
    cout<<"How many test runs do you want? \n";
    cin>>runcount;
    
    //array with a number of possible errors
    for (int i=0; i<symbcount; i++)
    {
        err.push_back(0);
    }
    
    //setting up the normalized possibilities of an error
    for (int i = 0; i < 10; i++)
    {
        states[i] = rand()%10000;
        sum += states[i];
    }
    for (int i = 0; i < 10; i++)
    {
        states[i] /= sum;
    }
    sum=0;
    
    
    
    for (int i = 0; i < 10; i++)
    {
        cout<<states[i]<<' ';   
    };
    cout<<" //////////////<-Initialized array////////////// \n";
    
    

    //setting up the normalized matrix
    for (int row = 0; row < numRows; row++)
    for (int column = 0; column < numColumns; column++)
    {
	    arr[row][column] = rand () % 10000;
    }
    for (int row = 0; row < numRows; row++)
    for (int column = 0; column < numColumns; column++)
    {
	    sum += arr[row][column];
	    if (column == numColumns - 1)
	    {
	        for (int i = 0; i < numColumns; i++)
	            arr[row][i] /= sum;
	        sum = 0;
	    }
        
    }
    cout<<"////////////////////////// \n";
    for (int row = 0; row < numRows; row++)
    for (int column = 0; column < numColumns; column++)
    {
        cout << fixed;
        cout << setprecision(6);
        cout << arr[row][column] << ' ';
	    if (column == numColumns - 1)
	    cout << "\n";
    }
    
    currstate = rand()%10;
    
    cout<<currstate<<" ////////////<-Generated first state//////////////// \n";
    
    sum = 0;
    
    
    //TEST RUNS
    
    for (int i = 0; i<runcount; i++)
    for (int j = 0; j<symbcount; j++)
    {
        //generating state, to which the system switches
        nextstate = rand()%10;
        errrate = rand()%10000;
        errrate /= 10000;
        
        if (errrate<=arr[currstate][nextstate])
            currstate = nextstate;
            
        
        errrate = rand()%10000;
        errrate /= 10000;
        
        if (errrate<=states[currstate])
            sum++;
            
        if (j==symbcount-1)
        {
            err[sum]+=1;
            sum = 0;
        }
        
    }    
    cout<<" \n ////Number of errors: ////// \n";  
    for (int i=0; i<symbcount; i++)
        cout<<i<<" error = "<<err[i]<<"\n";
        
    return 0;
}





