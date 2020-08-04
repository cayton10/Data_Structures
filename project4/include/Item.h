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
        //Default constructor prototype
        Item(string str = "Unnamed Item", int num = 1);

        //Set Item prototype
        void setItem(string str, int num);

        //Get Item inline function
        inline int getItem() const
        {
            return number;
        }
        inline string getName() const
        {
            return name;
        }

        //Required virtual function to use item
        virtual void use();


};