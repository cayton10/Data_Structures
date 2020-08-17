/*
 Name: Ben Cayton
 Course: CIT236 - Data Structures
 Date: 8.15.2020
 **************************************************************************
 Program Description: Create a lottery simulator using vectors
 */

#include <iostream>
#include <string>
#include <time.h>
#include <random>

//Include user defined classes
#include "Lottery.h"

using namespace std;

int main()
{
    //Declare variables
    int size;
    int number;
    vector<int> userPicks;
    
    cout << "How many numbers would you like to play? ";
    cin >> size;
    //Call Lottery member function to set size
    cout << endl << "Enter " << size << " numbers in any order. Do not pick any number more than once." << endl << endl;
    //Iterative for loop to enter user picks
    for(int i = 0; i < size; ++i)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> number;
        userPicks.push_back(number);
    }
    
    
    //Instantiate winning numbers vector with default constructor
    Lottery Winner;
    
    //Display winning numbers (unsorted>
    Winner.displayWinners();
    
    return 0;
}
