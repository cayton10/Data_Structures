//Class Implementations for Lottery.h

#include <iostream>
#include <time.h>
#include <random>
#include <stdio.h>

#include "Lottery.h"

//Default lottery constructor
Lottery::Lottery()
{
    //Seed unique random numbers for each instance of lottery object
    //Seed unique RNG between program runs
    //Must cast to unsigned int to avoid changing to 'long' dataType
    srand(static_cast<unsigned int>(time(0)));
    
    
    //Call fillVector to set up winning numbers for default lottery construction
    fillVector(vectorSize);
};

void Lottery::displayWinners() const
{
    for(int i = 0; i < vectorSize; ++i)
        cout << winningNumbers[i] << endl;
}

//Random number generator takes upper and lower limit of random generated numbers(inclusive)
int Lottery::randomNumber(int upper, int lower)
{
    //Declare result variable
    int result = rand();//Flush sink
    int index = 0;
    bool found = false;
    //Use modulus for either user provided or default param values
    //Calculate appropriate range
    upper = upper - lower;
    result = rand() % upper + lower;
    //Use while loop to search vector and replace duplicate values
    while (index < winningNumbers.size() && !found)
    {
        if(winningNumbers[index] == result)
        {
            found = true;
            cout << "found duplicate: " << winningNumbers[index] << " and " << result << endl;
            cout << index << endl;
            //If found, make another number
            if(found)
                result = rand() % upper + lower;
            
        }
        else
            index++;
    }
    
    return result;
}

//Set winning numbers takes int as size of vector
void Lottery::fillVector(int size)
{
    //Access private member and fill with randomNumber()
    for(int i = 0; i < size; ++i)
        winningNumbers.push_back(randomNumber());
    
}
