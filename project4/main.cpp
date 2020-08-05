/*****************************************************
  Author: Benjamin Cayton
  Project: Assignment 4: Inheritance and Polymorphism
  Date: 8.5.2020
  ****************************************************/
/*Project Description: This program is designed to test
  The working knowledge of using inheritance to create
  derived classes. Function overloading and overriding
  has also been employed to test the validity of
  correct inheritance and polymorphism, respectively.
  ****************************************************/

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
    Item sponge("Sponge", 20);
    //Call use function from item class
    sponge.use();


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
    Consumable healing("Potion", 2);
    //Set object info
    healing.setUses(3); //Sets use charges in consumable class
    cout << healing << endl; //Outputs Consumable object remaining uses
    healing.use(); //Use Consumable object
    cout << healing << endl; //Outputs 2 uses remaining
    healing.use(); //Use Consumable
    healing.use(); //Use Consumable
    healing.use(); //Use Consumable


    //Create new instance of consumable for polymorphism testing
    Consumable ether("Ether", 2);
    ether.setUses(1);
    //Create array of pointers
    Item* itemArray[3];
    //Initialize array indeces with addresses to derived classes
    itemArray[0] = &sponge;
    itemArray[1] = &sword;
    itemArray[2] = &ether;

    //Access array of pointers to w/ for loop
    for (int i = 0; i < 3; ++i)
    {
        //Test use() as polymorphic function
        itemArray[i]->use();
    }
   

    return 0;
}