/** Name: Benjamin Cayton
 *  Course: CIT 236 - Data Structures
 *  Assignment: Project 2
 * *****************************************************************
 *  Description: Assignment 1 for this course serves to review concepts previously covered
 *  in CIT 163 - Intro to Programming. The objective is to create functions requested
 *  by the assignment outline provided.
 */

#include <iostream>

using namespace std;

//Define classes
//Character class
class Character
{
    //Private variables "Can't Touch This..."
    private: 
        string name; 
        int health;
        int power;
        int strength;
    //CAN Touch These
    public:
    //Default character constructor
        Character()
        {
            name = "Unnamed Rider";
            health = 100;
            power = 200;
            strength = 100;
        }
    //Set character name
        void setName(string str)
        {
            name = str;
        }
    //Get character name
        string getName()
        {
            return name;
        }
    //Set character health
        void setHealth(int num)
        {
            health = num;
        }
    //Get Character health
        int getHealth()
        {
            return health;
        }
};
//Ability class
class Ability
{
    //Can't Touch This
    private:
        string name;
        int powerCost;
        int healthEffect;
    
    //Public functions
    public:
        
};

int main()
{
    //Name placeholder for entry.
    string newName;
    string charName;
    //Instantiating object calls default Character constructor
    Character sprinter;
    Character climber;

    cout << "\n" << sprinter.getName();
    cout << "\n" << sprinter.getName() << "'s health: " << sprinter.getHealth();

    //Set racer name
    sprinter.setName("Peter Sagan");
    //Display racer name
    charName = sprinter.getName();
    cout << "\nYour sprinter's name is: " << charName;
    //Set values for remaining rider attributes


    return 0;
}