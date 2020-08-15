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
    //Instantiate winning numbers vector with default constructor
    Lottery Winner;
    
    //Display winning numbers (unsorted>
    Winner.displayWinners();
    
    return 0;
}
