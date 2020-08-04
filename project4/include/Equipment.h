//Include guard
#pragma once

//Include parent class
#include "Item.h"

//Declare equipment derived class from 'Item' base class
class Equipment : public Item
{
    private:
        //Stores boolean for equipped item
        //Initialize to false in default constructor
        bool equipped;

    protected:

    public:

        //Default equipment constructor
        Equipment(string newName)
        {
            name = newName;
            number = 1;
            equipped = false;
            cout << "Equipment constructor" << endl;
            cout << equipped << endl;
        };

        //Equipment setItem(name, quantity)
        void setItem(string str, int num);//Need to override inherited setItem() function for boolean

        //Include function header for override
        virtual void use();

};