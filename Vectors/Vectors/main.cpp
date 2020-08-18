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

string promptUser(int num1, int num2, int num3);

int main()
{

    //Declare variables
    int size = 5;
    int min = 1;
    int max = 30;
    string prompt;
    vector<int> computerVector;
    bool winner = false;
    
    /************************************************************
     THIS BLOCK OF CODE TESTS THE DEFAULT PARAMETERS OF THE PROGRAM
     TO SATISFY THE REQUIREMENTS OF ITEM NO. 1 OF PROJECT 7.
     ***********************************************************/
    //Instantiate winning numbers vector with default constructor
    //Automatically creates vector with random numbers
    
    Lottery Fiver;
    cout << promptUser(min, max, size) << endl;
    //Calls object function to fill userPicks vector
    Fiver.fillUserPicks(size);
    cout << endl;
    cout << "The winning numbers are: ";
    //Displays winning numbers
    Fiver.displayWinners();
    //Check for winner
    Fiver.checkWinner();

    cout << endl;
    
    /***********************************************************
                        END ITEM NO. 1
     **********************************************************/
    
    //Begin item 2
    cout << "Enter the number of picks you would like to make: ";
    cin >> size;
    cout << "Enter the pick range." << endl;
    cout << "Enter smallest number: ";
    cin >> min;
    cout << "Enter largest number: ";
    cin >> max;
    cout << endl << endl;
    
    //Create lottery object with user defined parameters
    Lottery Player(max, min, size);
    cout << promptUser(min, max, size) << endl;
    Player.fillUserPicks(size);
    cout << endl;
    cout << "The winning numbers are: ";
    //Displays winning numbers
    Player.displayWinners();
    //Check for winner
    Player.checkWinner();
    
    cout << endl;
    
    /**********************************************************
                        END ITEM NO. 2
     **********************************************************/
    
    //Begin item 3
    //Create instance of computer run
    Lottery Computer;
    computerVector.resize(5);
    while(winner == false)
    {
        //Fill computer choice vector
        computerVector = Computer.fillVector();
        //Check winner
        winner = Computer.checkComputerWin(computerVector);
    }
    
    return 0;
}


//Function to reset prompt after user enters lottery specifics
string promptUser(int num1, int num2, int num3)
{
    string low = to_string(num1);
    string high = to_string(num2);
    string range = to_string(num3);
    string prompt;
    prompt = "Enter " + range + " numbers between " + low + " - " + high + ".";
    
    return prompt;
}
