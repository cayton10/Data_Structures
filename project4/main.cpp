
#include <iostream>
#include <string>

//All required file inclusions
//Item Class
#include "Item.h"
//Equipment Class
#include "Equipment.h"
//Consumable Class
#include "Consumable.h"


using namespace std;

//Entry point
int main()
{
    //Declare instance of item
    Item thing("Potion", 20);
    //Call use function from item class
    thing.use();

    Item thing2;
    cout << thing2.getName() << endl;
    cout << thing2.getItem() << endl;

    //Instance of Equipment object
    Equipment sword("Claymore");
    //Call use function from Equipment class
    sword.use();
    //Set paramters for 'sword' object
    sword.setItem("Broad Sword", 1);
    sword.getItem();
    //Use again
    sword.use();
    cout << endl;
    
    //Instace of Consumable object
    Consumable item;
    //Set object info
    item.setItem("Potion", 2); //Name of item is potion. Adds 3 potions to inventory
    item.setUses(3); //Sets use charges in consumable class
    cout << item << endl; //Outputs Consumable object remaining uses
    item.use(); //Use Consumable object
    cout << item << endl; //Outputs 2 use remaining
    item.use(); //Use Consumable
    item.use(); //Potion charges are empty.
    item.use();
    item.use();
    item.use();
    item.use();
    item.use();
    item.use();
    item.use();

    return 0;
}