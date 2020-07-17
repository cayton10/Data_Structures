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
/**************************************CHARACTER CLASS*****************************************/
//Character class
class Character
{
    //Private variables "Can't Touch This..."
    private: 
        string name;
        string ability; 
        int health;
        int power;
        int strength;
    //CAN Touch These
    public:
    //Default character constructor
        Character()
        {
            name = "Andre Greipel";
            health = 93;
            power = 350;
            strength = 88;
        }

    /** ************************************ wipeChar() ****************************************
     * function wipes values of default constructed character class to prep for user input ****
     * ****************************************************************************************/
        void wipeChar()
        {
            name = "";
            health = 0;
            power = 0;
            strength = 0;
        }
    /** ************************************* setName() ****************************************
    //Set character name */
        void setName(string str)
        {
            //For loop to interate over user supplied string
            for (unsigned i = 0; i < str.length(); ++i)
            {
                //If any of the character w/in string is a digit,
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
        {   //Set health 
            health += num;
            if(health < 0)
            {    
                health = 0;
            }
            else if(health > 100)
            {
                health = 100;
            }
            //Exit function
            return;
        }

    //Get Character health
        int getHealth()
        {
            return health;
        }

    /** ************************************* setPower() ****************************************
    //Set character power*/
        void setPower(int num)
        {
            //Upadate power
            power += num;

            //Qualify updated values
            if(power < 50)
            {
                power = 50;
            }
            else if(power > 500)
            {
                power = 500;
            }
            return;
        }

    //Get character power
        int getPower()
        {
            return power;
        }

    /** ************************************* setStrength() ****************************************
    //Set character strength */
        void setStrength(int num)
        {
            //If everything checks out:
            strength = num;

            if(strength < 0)
            {
                strength = 0;
            }
            else if(strength > 100)
            {
                strength = 100;
            }
            return;
        }
    //Get character strength
        int getStrength()
        {
            return strength;
        }
};

/********************************************************************************************/
/**************************************ABILITY CLASS*****************************************/
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

/***********************************************************************************************
 * ********************************MAIN FUNCTION************************************************
 * Let's race some bikes!**********************************************************************/

int main()
{
    //Name placeholder for entry.
    string newName;
    int userChoice;
    int health;
    int power;
    int strength;
    //Instantiating object calls default Character constructor w/ option
    Character sprinter;
    

    //Allow user to change default sprinter information
    cout << "\nWould you like to name your sprinter?\n\nEnter 1 to enter name:\nEnter 2 for default:\n";
    cin >> userChoice;
    if(cin.fail() || userChoice < 1 || userChoice > 2)
    {
        do
        {
            cout << "Please enter a valid choice.\n1. Enter name:\n2. Accept default:\n ";
        } while (cin.fail() || userChoice != 1 || userChoice != 2);
        
    }

    //Control flow for userChoice

    if(userChoice == 1)//If user wants to name their sprinter character and provide attributes
    {
        //Call wipeChar() function to prep class for user input
        sprinter.wipeChar();   
        //Prompt user to enter name for sprinter racer
        cout << "\nEnter sprinter name: ";
        cin.clear();//Clear input buffer stream
        cin.ignore(100, '\n');//Ignore newline character(return)
        getline(cin, newName);
        //Set name of sprinter instance of character class
        sprinter.setName(newName); 

        //Prompt user to enter health for sprinter racer
        cout << "\nEnter sprinter health (whole number between 0 and 100): ";
        cin >> health;
        //Control flow for input of invalid data type
        if(cin.fail() || health < 0 || health > 100)
        { 
            do
            {
                cout << "\nInvalid health entry. Please try again: ";
                cin.clear();//Clear input stream
                cin.ignore(100, '\n');//Ignore junk line / new line character
                cin >> health;//Accept input again
            }while(cin.fail() || health < 0 || health > 100);
        }

        //Set health of sprinter instance of character class
        sprinter.setHealth(health);


        //Prompt user to enter power for sprinter racer
        cout << "\nEnter sprinter power in Watts (whole number between 50 and 500): ";
        cin >> power;
        //Control flow for input of invalid data type
        if(cin.fail() || power < 50 || power > 500)
        {
            do
            {
                cout << "\nInvalid power entry. Please try again: ";
                cin.clear();//Clear input stream
                cin.ignore(100, '\n');//Ignore junk line / new line character
                cin >> power;//Accept input again
            }while(cin.fail() || power < 50 || power > 500);
        }

        //Set power of sprinter instance of character class
        sprinter.setPower(power);

        //Prompt user to enter strength for sprinter racer
        cout << "\nEnter sprinter power strength (whole numbers between 0 and 100): ";
        cin >> strength;
        //control flow for input of invalid data type
        if(cin.fail() || strength < 0 || strength > 100)
        {
            do
            {
                cout << "\nInvalid power entry. Please try again: ";
                cin.clear();
                cin.ignore(100, '\n');//Ignore junk line
                cin >> strength;//Accept input again
            } while (cin.fail() || strength < 0 || strength > 100);   
        }

        //If entry checks out, call setStrength
        sprinter.setStrength(strength);
    }
    
    
    //Climber instance of character class will be sprinter's rival
    Character climber;
    //Hard coding climber character class member attributes
    climber.setName("Chris Froome");
    climber.setHealth(75);
    climber.setPower(400);
    climber.setStrength(70);
    


    //Output single values for inspection
    cout << "\nSprinter name: " << sprinter.getName() << endl;
    cout << "Sprinter health: " << sprinter.getHealth() << endl;
    cout << "Sprinter power: " << sprinter.getPower() << endl;
    cout << "Sprinter strength: " << sprinter.getStrength() << endl;

    cout << endl << "\nClimber name: " << climber.getName() << endl;
    cout << "Climber health: " << climber.getHealth() << endl;
    cout << "Climber power: " << climber.getPower() << endl;
    cout << "Climber strength: " << climber.getStrength() << endl;




    return 0;
}