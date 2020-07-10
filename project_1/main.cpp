/** Name: Benjamin Cayton
 *  Course: CIT 236 - Data Structures
 *  Assignment: Project 1
 * *****************************************************************
 *  Description: Assignment 1 for this course serves to review concepts previously covered
 *  in CIT 163 - Intro to Programming. The objective is to create functions requested
 *  by the assignment outline provided.
 */

//Required inclusions
#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>

//Negates use of std::cin, etc.
using namespace std;

//Function prototypes
//Random includes default values for lack of user input 
int Random(int num1 = 99, int num2 = 0);
int RandomFill(int array[], int size);

//Main function
int main()//Entry point (muay importante)
{
    //Declaration of variables
    //Variable declarations for Random()
    int userChoice;
    int num1;
    int num2;
    //Array for RandomFill()
    int arraySize = 5;
    int randoArray[arraySize];

    //Seed RNG for unique runs
    srand(time(0));

    cout << "We're going to generate some numbers here. " << endl 
         << "Enter '0' for a random number between 0 and 99. " << endl
         << "Enter '1' to define the upper limit of the random number." << endl
         << "Enter '2' to define the upper and lower limits of the random number." << endl;
    
    //Accept user input for random number option
    cin >> userChoice;

    //Error handling control flow
    if(cin.fail() || userChoice < 0 || userChoice > 2)
    {

        //Do... While error handling for user mistakes
        do
        {
            cout << "Use one of the choices outlined. (0, 1, or 2)." << endl;
            cin.clear();//Clear input stream
            cin.ignore(100, '\n');//Ignore newline (return)
            cin >> userChoice;//Allow user to reenter correct choice

        } while (cin.fail() || userChoice < 0 || userChoice > 2);
        //Condition is: failure (incorrect data type), or value not described from prompt
    }

    //User choice control flow for passing (or not passing) appropriate parameters
    if (userChoice == 0)
    {   //Call Random function w/ default parameters
        cout << "Your random number is: " << Random() << endl;
    }
    else if (userChoice == 1)
    {
        cout << "Enter upper limit for random number generator." << endl;
        cin >> num1;
        cout << "Your random number is: " << Random(num1) << endl;    
    }
    else
    {
        //Appropriate user prompts and entries
        cout << "Enter upper limit for random number generator." << endl;
        cin >> num1;
        cout << "Enter lower limit for random number generator." << endl;
        cin >> num2;
        //Call random function with user defined RNG limits
        cout << "Your random number is: " << Random(num1, num2) << endl << endl;    
    }
    

    //Console output for RandomFill() 
    cout << "Next we'll fill an array with 5 random numbers." << endl;
    RandomFill(randoArray, arraySize);
    cout << "Your 5 random numbers are: ";
    //For loop to print randoArray
    for (int i = 0; i < arraySize; ++i)
    {
        //If the loop hasn't reached the last value, add a comma after printing value
        if(i < arraySize - 1)
        {
            cout << randoArray[i] << ", ";
        }
        //If all numbers are displayed, ommit comma and endl
        else
        {
            cout << randoArray[i] << endl;
        }
        
    }
    

    
    
    return 0; 
}

/** *******************************************************************************
 *  Random function returns random number based on user choice from main function *
 *  *******************************************************************************/

int Random(int num1, int num2)
{
    //Declare result variable
    int result = rand();//Flush sink
    //Use modulus for either user provided or default param values
    //Calculate appropriate range
    num1 = num1 - num2;
    result = rand() % num1 + num2;

    return result;
}


/** *********************************************************************************
 * ****************************RANDOM FILL FUNCTION**********************************
 * Fills function array indeces with random numbers and does so based on array size *
 * *********************************************************************************/

int RandomFill(int array[], int size)
{
    //For loop to populate array
    for (int i = 0; i < size; ++i)
    {
        //Array at index [i] populated with Random() function
        array[i] = Random();
    }
    
    return array[size];
    
}