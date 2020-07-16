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
    /** ************************************* setName() ****************************************
    //Set character name */
        void setName(string str)
        {
            //For loop to interate over user supplied string
            for (unsigned i = 0; i < str.length(); ++i)
            {
                //If any of the characters w/in string is a digit,
                if(isdigit(str[i]))
                {
                    //Reset string
                    str = "";
                    //Prompt again
                    cout << "Nix the numbers. Names only.\nEnter rider name: ";
                    getline(cin, str);
                    name = str;
                }
            }
            //If no numbers are present, accept string as character name and exit function
            name = str;
            return;   
        }

    //Get character name
        string getName()
        {
            return name;
        }
    /** ************************************* setHealth() ****************************************
    //Set character health */
        void setHealth(int num)
        {
            //Qualify input for health
            while(num < 0 || num > 100)
            {
                cout << "Invalid health value.\nPlease enter a value between 0 and 100: ";
                cin >> num;
                if (cin.fail())
                {
                    cout << "We've been through this. Numbers only: ";
                    cin.clear();//Clear input stream
                    cin.ignore(100, '\n');
                    cin >> num;
                }
                
            }

            health = num;
            return;
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
    int health;
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

    //Prompt user to enter health for sprinter racer
    cout << "\nEnter sprinter health (whole number between 0 and 100): ";
    cin >> health;
    //Control flow for input of invalid data type
    do
    {
        cout << "\nInvalid health entry. Please try again: ";
        cin.clear();//Clear input stream
        cin.ignore(100, '\n');//Ignore junk line / new line character
        cin >> health;//Accept input again
    }while(cin.fail());

    //Set health of sprinter instance of character class
    sprinter.setHealth(health);
    //Output single values for inspection
    cout << "Sprinter name: " << sprinter.getName() << endl;
    cout << "Sprinter health: " << sprinter.getHealth() << endl;




    return 0;
}