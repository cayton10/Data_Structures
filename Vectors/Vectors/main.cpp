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

//Performance includes
#include "Timer.h"
//Include user defined classes
#include "Lottery.h"

using namespace std;

int main()
{

    //Declare variables
    int size = 5;
    bool winner = false;
    /*int number;
    int min;
    int max;*/
    
    //Create Timer object
    Timer timer;
    
    timer.Start();
    //Instantiate winning numbers vector with default constructor
    //Automatically creates vector with random numbers
    Lottery Fiver;
    
    Fiver.fillUserPicks(size);
    //Display winning numbers
    Fiver.displayWinners();
    //Set winner bool value by calling checkWinner
    winner = Fiver.checkWinner(size);
    if (winner == true)
        cout << "Congratulations!!! You won!!!";
    else
        cout << "Better luck next time :'(" << endl;
    timer.Stop();
    timer.Report();
    return 0;
}
