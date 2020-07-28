#include <iostream>
#include <string>

//Include class files
#include "../header_files/TextInt.h"
#include "../resource_files/TextInt.cpp"

using namespace std; //For std::*

int main()
{
    //Declare user input variables
    int userNum;//Stores user selection for number
    TextInt object1;//Create instance of TextInt class
    TextInt object2;//Create second instance of TextInt class to test operator overloading
    cout << "Enter an integer between 0 and 9,999: ";//Prompt user to enter a valid number

    cin >> userNum;
    //User input control flow
    if(cin.fail() || userNum < 0 || userNum > 9999)
    {
        do
        {
            cout << "Invalid input, please enter an integer between 0 and 9,999: ";
            cin.clear();//Clear input buffer stream
            cin.ignore(100, '\n');//Ignore 100 characters or newline, whichever is first
            cin >> userNum; //Try again
        } while (cin.fail() || userNum < 0 || userNum > 9999); 
    }
    //Call setNum 
    object1.setNum(userNum);
    //Print value to test
    cout << "Your first integer: " << object1.getNum() << endl << endl;

    cout << object1.getText() << endl;

    cout << "Enter a second integer, also between 0 and 9,999: ";

    cin >> userNum;
    //User input control flow
    if(cin.fail() || userNum < 0 || userNum > 9999)
    {
        do
        {
            cout << "Invalid input, please enter a INTEGER between 0 and 9,999: ";
            cin.clear();//Clear input buffer stream
            cin.ignore(100, '\n');//Ignore 100 characters or newline, whichever is first
            cin >> userNum; //Try again
        } while (cin.fail() || userNum < 0 || userNum > 9999); 
    }

    //Call setNum
    object2.setNum(userNum);
    //Print value to test
    cout << "Your second integer: " << object2.getNum() << endl << endl;

    cout << object2.getText() << endl;

    //Create TextInt object3 by using addition operator overload
    TextInt object3 = object1 + object2;

    cout << object3.getNum() << ": " << object3.getText() << endl;



    return 0;
}

