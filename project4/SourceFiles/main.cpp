#include <iostream>
#include <string>

//All required file inclusions
//Item Class
#include "../HeaderFiles/Item.h"
#include "../ResourceFiles/Item.cpp"
//Equipment Class
#include "../HeaderFiles/Equipment.h"
#include "../ResourceFiles/Equipment.cpp"
//Consumable Class
#include "../HeaderFiles/Consumable.h"
#include "../ResourceFiles/Consumable.cpp"


using namespace std;

//Entry point
int main()
{
    //Instance of Equipment object
    Equipment sword("Claymore");

    sword.use();

    cout << "Hello world!" << endl;
    return 0;
}