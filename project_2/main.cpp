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
    //Set name
        void setName(string str)
        {
            name = str;
        }
    //Get name
        string getName()
        {
            return name;
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
};

int main()
{
    //Name placeholder for entry.
    string newName;
    string charName;
    //Instantiate object
    Character sprinter;
    //Testing console output
    cout << "Hello world!";
    //Prompt to enter racer name
    cout << "Enter a sprinter's name: ";
    getline(cin, newName);

    //Set racer name
    sprinter.setName(newName);
    //Display racer name
    charName = sprinter.getName();
    cout << "\nYour sprinter's name is: " << charName;

    return 0;
}