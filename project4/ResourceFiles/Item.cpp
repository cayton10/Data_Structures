#pragma once
//Include guard
#include <string>
#include "../HeaderFiles/Item.h"

using namespace std;

//Return message for use() function
void Item::use()
{
    cout << "Using item " << name << endl;
}