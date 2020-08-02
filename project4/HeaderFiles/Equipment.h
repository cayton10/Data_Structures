//Include guard
#pragma once

//Include parent class
#include "Item.h"

//Declare equipment derived class from 'Item' base class
class Equipment : public Item
{
    private:

    protected:

    public:

        //Default equipment constructor
        Equipment(string newName)
        {
            name = newName;
            number = 1;
            cout << "Equipment constructor" << endl;
        };
};