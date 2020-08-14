//Name: Benjamin Cayton
//Course: CIT236-Data Structures
//Date: 8.13.2020
/*******************************************************************/
//Program Description: This simple console app serves to give some
//practice with exception handling and function templates.

#include <iostream>
#include <string>
//For squareroot function
#include <cmath>
//For Exception Handling
#include "Exception.h"


using namespace std;

//Takes an int parameter and returns its square
int sqRoot(int num);

int main()
{
    //Declare variables
    int userChoice = 0;
    //Prompt user
    cout << "Please enter a perfect square: ";
    cin >> userChoice;

    //Try - catch block
    try
    {
        //Pass user choice to sqRoot function
        {
            sqRoot(userChoice);
            //Outputs perfect square
            cout << "Perfect square is: " << sqRoot(userChoice) << endl;
        }
    }
    //Catch Exception block
    catch (Exception message)
    {
        //Use .what() to output Exception object, "message"
        cout << message.what() << endl;
    }
    return 0;
}

//Takes an int parameter and returns its square
int sqRoot(int num)
{
    //Declare variable to store square root
    int squareRoot;
    squareRoot = sqrt(num);
    
    //If mod by 2 is equal to zero then no remainder... perfect square
    if(squareRoot % 2 == 0)
        return squareRoot;
    else
        throw Exception();
};


