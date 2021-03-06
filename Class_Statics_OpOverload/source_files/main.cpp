#include <iostream>
#include <string>

//Include header files
#include "../header_files/TextInt.h"

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
            cout << "Invalid input, please enter an INTEGER between 0 and 9,999: ";
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
            cout << "Invalid input, please enter an INTEGER between 0 and 9,999: ";
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
    //Test output of newly created object
    cout << object3.getNum() << ": " << object3.getText() << endl;
    //Test division operator overload and create new object
    TextInt object4 = object3 / object1;
    //Stream insertion overload test with new object
    cout << object4 << endl;
    
    //Testing stream operator overload
    cout << object1 << endl;


    //Testing comparison operators
    if(object1 > object2)
    {
        cout << "Instance one of TextInt is greater than instance two of TextInt.";
    }
    else if (object1 == object2)
    {
        cout << "Instance one of TextInt is equal to instance two of TextInt.";
    }
    else
    {
        cout << "Instance one of TextInt is less than instance two of TextInt";
    }
    
    return 0;
}

