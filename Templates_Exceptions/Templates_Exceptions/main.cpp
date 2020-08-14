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
//Takes two int params - 1st base, 2nd exponent
int myPower(int base, int exp);
//Template function
template <class Type>
Type larger(Type x, Type y, Type z);


int main()
{
    //Declare variables
    int userChoice = 0;
    string str1 = "Lando is the best.";
    string str2 = "Checo always wins.";
    string str3 = "Larry can't sleep.";
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
            cout << "The square root of " << userChoice << " is: " << sqRoot(userChoice) << endl;
        }
    }
    //Catch Exception block
    catch (Exception message)
    {
        //Use .what() to output Exception object, "message"
        cout << message.what() << endl;
    }
    
    //Call function myPower
    cout << myPower(8, 3) << endl; //Outputs 512
    
    cout << "Largest of integers: " << larger(10, 20, 30) << endl;
    cout << "Largest of doubles: " << larger(2.5, 1.5, 8.75) << endl;
    cout << "Largest of strings: " << larger(str1, str2, str3) << endl;
    
    return 0;
}

/************************************************************************
 *********************SQROOT FUNCTION***********************************/

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

/************************************************************************
 **************************RECURSIVE FUNCTION***************************/
//Takes base int followed by exponent int
int myPower(int base, int exp)
{
    //Base condition
    if(exp == 0)
        return 1;
    else
        return base * myPower(base, exp - 1);
};

/************************************************************************
 *************************FUNCTION TEMPLATE*****************************/
//Takes two parameters and compares their 'size'. Returns largest
template <class Type>
Type larger(Type x, Type y, Type z)
{
    //Pretty self explanatory logic
    if (x > y && x > z)
        return x;
    else if(y > x && y > z)
        return y;
    else
        return z;
}




