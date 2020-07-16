/** Name: Benjamin Cayton
 *  Course: CIT 236 - Data Structures
 *  Assignment: Project 2
 * *****************************************************************
 *  Description: Assignment 1 for this course serves to review concepts previously covered
 *  in CIT 163 - Intro to Programming. The objective is to create functions requested
 *  by the assignment outline provided.
 */

#include <iostream>
//Check user inputs: "isdigit()"
#include <ctype.h>

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
            //For loop to interate over user supplied string
            for (unsigned i = 0; i < str.length(); ++i)
            {
                if(isdigit(str[i]))
                {
                    str = "";
                    cout << "Nix the numbers. Names only.\nEnter rider name: ";
                    getline(cin, str);
                    name = str;
                }
                name = str;
            }   
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
    //Set character power
        void setPower(int num)
        {
            power = num;
        }
    //Get character power
        int getPower()
        {
            return power;
        }
    //Set character strength
        void setStrength(int num)
        {
            strength = num;
        }
    //Get character strength
        int getStrength()
        {
            return strength;
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
        //Default ability constructor
        Ability()
        {
            name = "Suffering";
            powerCost = 20;
            healthEffect = -15;
        }
        //Set ability name
        void setName(string str)
        {
            name = str;
        }
        //Get ability name
        string getName()
        {
            return name;
        }
        //Set ability powerCost
        void setPowerCost(int num)
        {
            powerCost = num;
        }
        //Get ability powerCost
        int getPowerCost()
        {
            return powerCost;
        }
        //Set ability healthEffect
        void setHealthEffect(int num)
        {
            healthEffect = num;
        }
        //Get ability healthEffect
        int getHealthEffect()
        {
            return healthEffect;
        }
};

int main()
{
    //Name placeholder for entry.
    string newName;
    //Variable to store name after "getting"
    string charName;
    //Instantiating object calls default Character constructor
    Character sprinter;
    Character climber;

    cout << "\n" << sprinter.getName();
    cout << "\n" << sprinter.getName() << "'s health: " << sprinter.getHealth();

    //Prompt user to enter name for sprinter racer
    cout << "\nEnter sprinter name: ";
    getline(cin, newName);
    //Set name of sprinter instance of character class
    sprinter.setName(newName); 

    //Display racer name
    charName = sprinter.getName();
    cout << "\nYour sprinter's name is: " << charName << endl;
    //Set values for remaining rider attributes


    return 0;
}