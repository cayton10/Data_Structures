//Class Implementations for Lottery.h

#include <iostream>
#include <time.h>
#include <random>
#include <stdio.h>
#include <algorithm>

#include "Lottery.h"
//Performance include
#include "Timer.h"
Timer timer;
//Default lottery constructor
Lottery::Lottery(int num1, int num2, int num3)
: upper(num1), lower(num2), vectorSize(num3)
{
    //Seed unique random numbers for each instance of lottery object
    //Seed unique RNG between program runs
    //Must cast to unsigned int to avoid changing to 'long' dataType
    srand(static_cast<unsigned int>(time(0)));

    //Call fillVector to set up winning numbers for default lottery construction
    winningNumbers = fillVector();
};

//Display winning numbers
void Lottery::displayWinners() const
{
    for(int i = 0; i < vectorSize; ++i)
    {
        //Appropriate comma formatting
        if(i != (vectorSize - 1))
            cout << winningNumbers[i] << ", " ;
        else
            cout << "and " << winningNumbers[i] << endl;
    }
}

//Set winning numbers takes int as size of vector
vector<int> Lottery::fillVector()
{
    vector<int> vec;
    //Set capacity / size for winning numbers
    vec.resize(vectorSize);
    //Access private member and fill with randomNumber()

    for(int i = 0; i < vectorSize; ++i)
        vec[i] = randomNumber(upper, lower, vec);
    
    //Sort vector for search and comparison down the road
    sort(vec.begin(), vec.end());
    

    return vec;
}

//Random number generator takes upper and lower limit of random generated numbers(inclusive)
int Lottery::randomNumber(const int& upper, const int& lower, vector<int>& vec)
{
    //Declare result variable
    int result = rand();//Flush sink
    int index = 0;
    bool found = false;
    int range;
    //Use modulus for either user provided or default param values
    //Calculate appropriate range
    range = upper - lower;
    result = rand() % range + lower;
    //Use while loop to search vector, find and replace duplicate values
    //Sequential search isn't most efficient, but algorithms is next semester, right?
    while (index < vec.size() && !found && vec[index] != 0)
    {
        if(vec[index] == result)
        {
            found = true;
            
            //While duplicates are found, generate new random
            while(vec[index] == result && found)
                result = rand() % upper + lower;
            //Reset index and bool to process again
            index = 0;
            found = false;
        }
        else
            index++;
    }
    return result;
}

//Populates userPicks vector with user's choices. Takes 1 int parameter to size vector
void Lottery::fillUserPicks(const int& vectorSize)
{
    //Stores user's number selection
    int userNumber = 0;
    //Set capacity / size for user numbers
    userPicks.resize(vectorSize);
    //for loop to read in user input
    for (int i = 0; i < vectorSize; ++i) {
        cout << "Enter pick number " << i + 1 << ": ";
        cin >> userNumber;
        userPicks[i] = userNumber;
    }
    //Sort userPicks for comparison
    sort(userPicks.begin(), userPicks.end());
}

//Check winner.
void Lottery::checkWinner()
{
    //Condition
    bool winner = false;
    for(int i = 0; i < vectorSize; ++i)
    {
        if(winningNumbers[i] == userPicks[i])
            winner = true;
        else
        {
            winner = false;
            //Increment attempts
            ++attempts;
            break;
        }
    }
    if(winner == true)
        cout << "Congratulations!!! You won!!!";
    else
        cout << "Better luck next time :'(" << endl << endl;
    //Report attempts
    cout << "Attempts: " << attempts << endl;
}

//Check winner for computer while loop
bool Lottery::checkComputerWin(const vector<int>& compVector)
{
    //Condition
    bool winner = false;
    for(int i = 0; i < vectorSize; ++i)
    {
        if(winningNumbers[i] == compVector[i])
            winner = true;
        else
        {
            winner = false;
            //Increment attempts
            ++attempts;
            break;
        }
    }
    if(winner == true)
    {
        cout << "Computer wins after " << attempts << " attempts." << endl;
        return winner;
    }
    else
        return winner;
}


