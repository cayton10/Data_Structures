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
        Item(int num = 1, string newName = "Unnamed Item")
        {
            name = newName;
            number = num;
            //Item is constructed using MIL
            //GO BACK AND REVIEW WHAT THIS IS CALLED IN "BASE CLASS CONSTRUCTORS, INHERITANCE" LECTURE
            cout << "Called Item constructor" << endl;
        }

        //Set Item prototype
        void setItem(string str, int num);

        //Get Item prototype
        string getItem()
        {
            return name;
        }

        //Required virtual function
        virtual void use();


};