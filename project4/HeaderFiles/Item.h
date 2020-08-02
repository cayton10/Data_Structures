#pragma once
//Include guard
#include <string>

using namespace std;

//Declare base (parent) class Item for all derived (children) classes
class Item
{
    //Declare private member variables
    private:

    //Declare protected member variables
    protected:
        string name;
        int number;
    //Declare public member functions
    public:
        //Item constructor
        Item(string newName)
        : name(newName),
        number(1)
        {
            //Item is constructed using MIL
            //GO BACK AND REVIEW WHAT THIS IS CALLED IN "BASE CLASS CONSTRUCTORS, INHERITANCE" LECTURE
        }

        //Set Item prototype
        void setItem(string str, int num);

        //Get Item prototype
        string getItem()
        {
            return name;
        }

        //Required virtual function
        virtual void use(string name);


};