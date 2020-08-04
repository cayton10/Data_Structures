//Include guard

#include <iostream>
#include <string>
//Include header
#include "Consumable.h"

using namespace std;

//Set number of uses for consumable item
void Consumable::setUses(int num)
{
    Consumable::uses = num;
}

//Get number of uses for consumable item
int Consumable::getUses() const
{
    return Consumable::uses;
}

//Check if consumable item is empty
bool Consumable::isEmpty() const
{
    if(Consumable::uses == 0)
    {
        return true;
    }
    else
    {
        return false;
    }    
};
//Use consumable item if charges remain
void Consumable::use()
{
    if(Consumable::isEmpty() == false)
    {
        //Calls base class use() function
        Item::use();
        //Decrement uses
        --Consumable::uses;

        //Control flow for item charges and decrementing item inventory
        if(Consumable::uses == 0)
        {
            --Consumable::number;//If last charge is used for use() function, decrement
                                 //the number of this particular item in inventory
            cout << Consumable::number << " " << Consumable::name << " left in inventory." << endl;
            
            //If more of this item are in inventory, reset charges
            if(Consumable::number > 0)
            {
                Consumable::setUses(3);
            }
        }
        //Leave function
        return; 
    }
    else
    {
        //Output message to user that item uses are depleted
        cout << "No uses left for " << Consumable::name << ". " << endl;
        //Decrement number of this item
        --Consumable::number;
    }
}


//Stream insertion operator overload
ostream& operator<<(ostream& output, const Consumable& object)
{
    output << object.getUses() << " " << object.getName() << " uses remaining.";
    return output;
};

