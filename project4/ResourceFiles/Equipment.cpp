//Include guard
#pragma once

#include <string>
#include "../HeaderFiles/Equipment.h"

using namespace std;
//Overrideing Item function setItem()
void Equipment::setItem(string str, int num)
{
    Equipment::name = str;
    Equipment::number = num;
    //Here's the important guy
    Equipment::equipped = false;//Need to reset the equipped boolean when a new Equipment item is set
}

//Overriding Item function use()
void Equipment::use()
{
    if (Equipment::equipped == false)
    {
        Equipment::equipped = true;
        cout << name << " has been equipped.";
    }
    else
    {
        Equipment::equipped = false;
        cout << name << " has been unequipped.";
    } 
};



