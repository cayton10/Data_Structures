//Included exception class for the purpose of learning
#include <iostream>
#include <string>

using namespace std;

#ifndef Imperfect_h
#define Imperfect_h

class Imperfect
{
public:
    //Default constructor
    Imperfect()
    {
        message = "Not a perfect square: ";
    }
    //User can create their own exception messages
    Imperfect(string str)
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

#endif /* Imperfect_h */
