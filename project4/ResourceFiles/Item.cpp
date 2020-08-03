#pragma once
//Include guard
#include <string>
#include "../HeaderFiles/Item.h"

using namespace std;


//Default item constructor w/ default values
Item::Item(string newName, int newNum)
{
    name = newName;
    number = newNum;
};

//Set item with name and quantity parameters (optional)
void Item::setItem(string str = "Unnamed Item", int num = 1)
{
    name = str;
    number = num;
}

//Return message for use() function
void Item::use()
{
    cout << "Using item: " << name << endl;
}

