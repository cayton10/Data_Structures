//Included exception class for the purpose of learning
#include <iostream>
#include <string>

using namespace std;

#ifndef Except_h
#define Except_h

class Exception
{
public:
    //Default constructor
    Exception()
    {
        message = "Not a perfect square: ";
    }
    //User can create their own exception messages
    Exception(string str)
    {
        str = message;
    }
    //Return object containing exception message
    string what()
    {
        return message;
    }
private:
    string message;
};

#endif /* Except_h */
