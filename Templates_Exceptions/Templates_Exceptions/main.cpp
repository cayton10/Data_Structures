//Name: Benjamin Cayton
//Course: CIT236-Data Structures
//Date: 8.13.2020
/*******************************************************************/
//Program Description: This simple console app serves to give some
//practice with exception handling and function templates.

#include <iostream>
#include <string>
#include <cmath>
//For squareroot function


using namespace std;

//Takes an int parameter and returns its square
int sqRoot(int num);

int main()
{
    //Declare variables
    int userChoice = 0;
    
    cout << "Please enter a perfect square: ";
    cin >> userChoice;
    cout << endl << userChoice << endl;
    cout << sqrt(userChoice) << endl;
    
    try
    {
        {sqRoot(userChoice);
            cout << "Perfect square is: " << sqRoot(userChoice);
        }
    } catch (string exc) {
        cout << exc << endl;
    }
    return 0;
}

//Takes an int parameter and returns its square
int sqRoot(int num)
{
    //Declare variable to store square root
    int squareRoot;
    string exc = string("Not a perfect square.");
    squareRoot = sqrt(num);
    
    if(squareRoot % 2 == 0)
        return squareRoot;
    else
        throw exc;
};


