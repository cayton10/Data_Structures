#include <iostream>
#include <string>

//Include class files
#include "../header_files/TextInt.h"
#include "../resource_files/TextInt.cpp"

using namespace std;



int main()
{
    //Declare user input variables
    int userNum;//Stores user selection for number
    TextInt object1;//Create instance of TextInt class
    TextInt object2;//Create second instance of TextInt class to test operator overloading
    cout << "Enter a number between 0 and 9,999: ";//Prompt user to enter a valid number

    cin >> userNum;
    //User input control flow
    if(cin.fail() || userNum < 0 || userNum > 9999)
    {
        do
        {
            cout << "Invalid input, please enter a number between 0 and 9,999: ";
            cin.clear();//Clear input buffer stream
            cin.ignore(100, '\n');//Ignore 100 characters or newline, whichever is first
            cin >> userNum; //Try again
        } while (cin.fail() || userNum < 0 || userNum > 9999); 
    }
    //Call setNum 
    object1.setNum(userNum);
    //Print value to test
    cout << "Your first number: " << object1.getNum() << endl << endl;

    cout << "Enter a second number, also between 0 and 9,999: ";

    cin >> userNum;
    //User input control flow
    if(cin.fail() || userNum < 0 || userNum > 9999)
    {
        do
        {
            cout << "Invalid input, please enter a number between 0 and 9,999: ";
            cin.clear();//Clear input buffer stream
            cin.ignore(100, '\n');//Ignore 100 characters or newline, whichever is first
            cin >> userNum; //Try again
        } while (cin.fail() || userNum < 0 || userNum > 9999); 
    }

    //Call setNum
    object2.setNum(userNum);
    //Print value to test
    cout << "Your second number: " << object2.getNum() << endl << endl;



    return 0;
}

