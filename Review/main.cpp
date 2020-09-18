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
#include <string>

//Negates use of std::cin, etc.
using namespace std;

//Function prototypes
//Random includes default values for lack of user input 
int Random(int num1 = 99, int num2 = 0);
int RandomFill(int array[], int size);
bool IsFactor(int div1, int div2);
//Practice with passing parameters by reference
void FlipString(string &str);

//Main function
int main()//Entry point (muay importante)
{
    //Declaration of variables
    //Variable declarations for Random()
    int userChoice;
    int num1;
    int num2;
    //Array for RandomFill()
    const int arraySize = 5;
    int randoArray[arraySize];
    //Variables for IsFactor()
    int dividend;
    int divisor;
    int factorAnswer;
    //Variable for FlipString()
    string str;

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

    //Terminal formatting
    cout << endl << endl;
    
    /********************* PROMPTS FOR IsFactor() ********************************/

    cout << "Now we're going to check if one integer is a factor of another." << endl;
    cout << "First, enter a dividend: ";
    //User entry
    cin >> dividend;
    //Error handling control flow
    if(cin.fail())
    {
        //Do... While error handling for user mistakes
        do
        {
            cout << "Please enter a whole number." << endl;
            cin.clear();//Clear input stream
            cin.ignore(100, '\n');//Ignore newline (return)
            cin >> dividend;//Allow user to reenter correct choice

        } while (cin.fail());
        //Condition is: failure (incorrect data type)
    }

    cout << "Next, enter the divisor: ";
    cin >> divisor;

    if(cin.fail())
    {
        //Do... While error handling for user mistakes
        do
        {
            cout << "Please enter a whole number." << endl;
            cin.clear();//Clear input stream
            cin.ignore(100, '\n');//Ignore newline (return)
            cin >> divisor;//Allow user to reenter correct choice

        } while (cin.fail());
        //Condition is: failure (incorrect data type)
    }

    //Call IsFactor() and output returned result
    factorAnswer = IsFactor(dividend, divisor);
    //Apropriate control flow gives result to user
    if(factorAnswer == 1)
    {
        cout << endl << divisor << " is a factor of " << dividend << "!" << endl;
    }
    else
    {
        cout << endl << divisor << " is NOT a factor of " << dividend << "!" << endl;
    }

    /********************* PROMPTS FOR FlipString() ********************************/
    cout << "Now we'll FLIP THE SCRIPt, pLaYbOi!!!" << endl << endl;
    cout << "Enter a string, like a name or PlAyBoI or something." << endl;
    //Get string from user
    cin.clear();//Clear input stream
    cin.ignore(100, '\n');//Ignore new line (CR)
    getline(cin, str);

    //Call FlipString()
    cout << "You entered: " << str << endl << endl;
    FlipString(str);
    //Output user string
    cout << "After FlipString() we have: " << str << endl << endl;

    
    return 0; 
}

/** *******************************************************************************
 ****************************   RANDOM FUNCTION  **********************************
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

/** *********************************************************************************
 * **************************** IS FACTOR FUNCTION **********************************
 * Boolean function determines if divisor is a factor of dividend (no remainder *****
 * *********************************************************************************/

bool IsFactor(int div1, int div2)
{
    if (div1 % div2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** *********************************************************************************
 * ************************** FLIP STRING FUNCTION **********************************
 * Changes user defined string from uppercase to lower and vice versa ************* *
 * *********************************************************************************/

void FlipString(string &str)
{
    //For loop to iterate through string
    for(int i = 0; i < str.length(); ++i)
    {
        //Control flow for isupper()
        //If string at index [i] is uppercase
        if(isupper(str[i]))
        {
            //Change to lowercase
            str[i] = tolower(str[i]);
        }
        else
        //If string at index [i] is lowercase
        {
            //Change to uppercase
            str[i] = toupper(str[i]);
        }
        
    }
}