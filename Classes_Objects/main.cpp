/** Name: Benjamin Cayton
 *  Course: CIT 236 - Data Structures
 *  Assignment: Project 2
 * *****************************************************************
 *  Description: Assignment 2 for this course serves expand on the concepts
 *  of classes and objects. This is a rudimentary gaming style exercise in which
 *  class objects or instances are created with various functions assigned to test
 *  their legitimacy within a working program. 
 */

#include <iostream>
//Check user inputs: "isdigit()"
#include <ctype.h>

using namespace std;

//Define classes

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
    
    //Public functions for ability class
    public:
        //Default ability constructor
        Ability(string abilityName = "Suffering")
        {
            name = abilityName;
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
        int getPowerCost() const
        {
            return powerCost;
        }
        //Set ability healthEffect
        void setHealthEffect(int num)
        {
            healthEffect = num;
        }
        //Get ability healthEffect
        int getHealthEffect() const
        {
            return healthEffect;
        }

        //Display ability name and attributes
        void displayAbility()
        {
            cout << "Ability name: " << name << endl;
            cout << "Ability power cost: " << powerCost << endl;
            cout << "Ability health effect: " << healthEffect << endl << endl;
        }
};

/**************************************CHARACTER CLASS*****************************************/
//Character class
class Character
{
    //Private variables "Can't Touch This..."
    private: 
        string name;
        Ability characterAbility;
        int health;
        int power;
        int strength;
    //CAN Touch These
    public:
    //Default character constructor
        Character(string newName = "Andre Greipel")
        {
            name = newName;
            health = 88;
            power = 470;
            strength = 95;
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
        string getName() const
        {
            return name;
        }
        
    /** ************************************* setHealth() ****************************************
    //Set character health */
    //Pass parameter by reference for updating character attributes after useAbility()
        void setHealth(int const &num)
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
        int getHealth() const
        {
            return health;
        }

    /** ************************************* setPower() ****************************************
    //Set character power*/
    //Pass parameter by reference for updating character attributes after useAbility()

        void setPower(int const &num)
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
        int getPower() const
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
        int getStrength() const
        {
            return strength;
        }

    /*********************************  setAbility()*****************************************
    ** FUNCTION OVERLOAD TAKES ABILITY CLASS NAME AND COPIES VALUES INTO CHARACTER'S ABILITY
    ** MEMBER VARIABLE **********************************************************************/

        void setAbility(Ability name)
        {
           characterAbility.setName(name.getName());//Sets characterAbility with Ability instance name
           characterAbility.setHealthEffect(name.getHealthEffect());//Sets characterAbility with Ability instance
                                                                    //healthEffect value
           characterAbility.setPowerCost(name.getPowerCost());//Sets characterAbility with Ability instance powerCost
                                                              //value
        }

    /********************************* OVERLOAD 2 *****************************************/

        void setAbility(string name, int powerCost, int healthEffect)
        {
            //Set name of character ability
            characterAbility.setName(name);//Set ability name
            characterAbility.setPowerCost(powerCost);//Set ability powerCost
            characterAbility.setHealthEffect(healthEffect);//Set ability healthEffect
        }

        string getAbility()//Can't set this function as const
        {
            name = characterAbility.getName();
            return name;
        }
    /******************************* END setAbility() **************************************/

    /******************************* displayFunction ***************************************/

        void displayAll()
        {
            //Outputs all pertinent character information
            cout << "Character name: " << getName() << endl;
            cout << "Character health: " << getHealth() << endl;
            cout << "Character strength: " << getStrength() << endl;
            cout << "Character power: " << getPower() << endl << endl;

            cout << name << "'s Ability Information: " << endl;
            //Call displayAbility function from Ability class
            characterAbility.displayAbility();
        }

    /**************************** useAbility() ********************************************
    **USES CHARACTER'S ABILITY. PERFORMS APPROPRIATE ARITHMETIC OPERATIONS ON CHARACTER 
    **ATTRIBUTES BASED ON ABILITY VALUES.*/

        void useAbility(Character &character)//Must pass character by reference, else health effects are overwritten
                                             //upon exiting function
        {
            //Update power of character using ability
            setPower(characterAbility.getPowerCost());
            //Update health of character ability is used on (parameter character)
            character.setHealth(characterAbility.getHealthEffect());
            
        }

};

/***********************************************************************************************
 * ********************************MAIN FUNCTION************************************************
 * Let's race some bikes!**********************************************************************/

int main()
{
    //Declare all required variables
    string newName;
    int userChoice;


    
    //Allow user to change default sprinter information with menu option
    cout << "\nWould you like to name your sprinter?\n\nEnter 1 to enter name:\nEnter 2 for default:\n";
    cin >> userChoice;
    //Qualifies user input
    if(cin.fail() || userChoice < 1 || userChoice > 2)
    {
        do
        {
            cin.clear();//Clear input buffer stream
            cin.ignore(100, '\n');//Ignore CR 
            cout << "Please enter a valid choice.\n1. Enter name:\n2. Accept default:\n";
            cin >> userChoice;
        } while (cin.fail() || userChoice < 1 || userChoice > 2);
        
    }

    //Create Character of sprinter instance with default member variable values
    Character sprinter;

    //Control flow for userChoice
    if(userChoice == 1)//If user wants to name their sprinter character and provide attributes
    {   
        //Prompt user to enter name for sprinter racer
        cout << "\nEnter sprinter name: ";
        cin.clear();//Clear input buffer stream
        cin.ignore(100, '\n');//Ignore newline character(return)
        getline(cin, newName);
        //Set name of sprinter instance of character class
        sprinter.setName(newName);
    }
        
    //Create instance of sprinter's ability. Overload 1
    Ability sprintAbility("Sprint Finish");
    sprintAbility.setHealthEffect(-30);
    sprintAbility.setPowerCost(-320);

    //Call sprinter.setAbility() function overload option 1
    sprinter.setAbility(sprintAbility);//Copies sprintAbility into sprinter's ability

    
    //Call function to display all character information + their ability info
    sprinter.displayAll();
    cout << endl << endl;

        //Climber instance of character class will be sprinter's rival
    Character climber("Chris Froome");
    //Hard coding climber character class member attributes
    climber.setName("Chris Froome");
    climber.setHealth(99);
    climber.setPower(450);
    climber.setStrength(57);

    //Create instance of climber's ability. Overload 2
    climber.setAbility("Pedal Dance", -140, -50);

    //Display stats before ability usage
    cout << endl << endl;
    sprinter.displayAll();
    cout << endl;
    //Call function to display all climber information + their ability info
    climber.displayAll();
    cout << endl << endl;


    //Role play text
    cout << sprinter.getName() << " uses " << sprintAbility.getName() << " against " << climber.getName() << endl;
    //Call useAbility
    sprinter.useAbility(climber);
    //Role play text
    cout << sprinter.getName() << " inflicts " << (sprintAbility.getHealthEffect() * -1) 
         << " damage points to " << climber.getName() << endl << endl;
    
    
    cout << climber.getName() << " recovers and launches a counter attack!!!\n";
    cout << climber.getName() << " uses " << climber.getAbility() << " against " << sprinter.getName() << endl;
    //Call climber useAbility and pass sprinter for health effect
    climber.useAbility(sprinter);
    
    //Display results of each character ability usage
    cout << "Final results: \n\n";
    sprinter.displayAll();
    cout << endl << endl;
    climber.displayAll();
        

    return 0;
}