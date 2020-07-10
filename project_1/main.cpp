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

//Main function
int main()//Entry point (muay importante)
{
    //Declare variables
    int userChoice;
    int num1;
    int num2;

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
        cout << Random();
    }
    else if (userChoice == 1)
    {
        cout << "Enter upper limit for random number generator." << endl;
        cin >> num1;
        cout << Random(num1);
    }
    else
    {
        cout << "Enter upper limit for random number generator." << endl;
        cin >> num1;
        cout << "Enter lower limit for random number generator." << endl;
        cin >> num2;

        cout << Random(num1, num2);
    }
    
    
    //Apply appropriate error handling to force user to choose. 
    
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
    //Return the result
    return result;
}