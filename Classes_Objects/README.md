# Project 2

## Learning Outcomes

This was a very helpful exercise in familiarizing myself with classes and objects. I added a small user input feature so the user can rename their sprinter character to personalize, somewhat. Had I just followed the flat syllabus directions, I could have finished this much quicker, but I kept trying to find ways to personalize the project. 

Creation of the public functions and altering private variables was very helpful. I'm looking forward to becoming more fluent and skilled with OOP and OOD methodologies.

## From Syllabus

Assignment 2 – Classes and Objects
Submit to MUOnline as a compressed (.zip) file containing your code project.
1.	<strike>Create 2 classes. A Character class representing a generic character in a game, and an Ability class representing a generic ability a character can perform.</strike>

<strike>At a minimum a character should have a name and numeric values for health, power, and strength. An ability should have a name and numeric values for power cost and health effect. All variables should be private, with public functions for getting them and for setting them. Setter functions should validate that the result is valid (for instance setting their hp below 0 shouldn’t be allowed). An ability’s health affect could be positive (like a healing spell) or negative (like a damaging sword swing).</strike>

<strike>The class’s should each have a default constructor that initializes all their member variables to appropriate values, and optionally accepts a string for setting the object’s name variable as soon as they are created.</strike>

<strike>Remember that a class is a blueprint for any object of that type, not a single specific object. If you have a character named Jim, you wouldn’t make a class called Jim or a class member variable called Jim, just a generic ‘character’ class with a generic ‘name’ string, and you would make an instance like Character jim; jim.SetName(“Jim”);.</strike>	25%
		
2.	<strike>Add an Ability member variable to the Character class. Then add a function to the Character class called SetAbility. This should have 2 overloads: 1 takes an existing Ability instance and copies its data into the character’s ability variable. The other takes the individual components of an ability (name string, power cost int, etc.) and sets them 1 by 1 on the character’s ability variable.</strike>

EXAMPLE:

//Overload 1
Character superman;
Ability heatVision(“Heat Vision”);
heatVision.SetHealthEffect(-5);
heatVision.SetCost(-2);
superman.SetAbility(heatVision);//copies heatvision ability into superman’s ability.

//Overload 2:
Character dragon(“Bob”);
dragon.SetAbility(“Fire Breath”, -10, 10);//Sets dragon’s ability with the name “Fire Breath”, -10 health effect, 10 power cost.	25%
		
3.	<strike>Add a Display function to both classes to show their names, values, etc. The Character’s Display function should call the Character’s Ability’s Display function.</strike> 

<strike>Create instances of both in main() to demonstrate your classes work properly. For this assignment you do not have to use user input to let the user enter the values; just hardcode the names and abilities (have fun with it) to show your class working.</strike>	20%
		
4.	<strike>Finally, add a function to the Character class called UseAbility. It should take 1 parameter of the Character type and apply the current character’s ability (the one calling the function) on the character passed into the function.</strike> 

EXAMPLE:

Ability fireSpell(“Fireball”);
fireSpell.SetHealthEffect(-5);
fireSpell.SetCost(-5); 
character.SetAbility(fireSpell); 
vampireCharacter.Display();//should show full health.
character.UseAbility(vampireCharacter); 
vampireCharacter.Display();//should show lower health.

would result in vampireCharacter losing 5 health and character losing 5 power. Include some console output so it says something ‘Fireball cast on Modern Sexy Vampire. Modern Sexy Vampire’s stats are now: (and then call the Display function for the character)’. (Hint: This step won’t work without one particular concept I asked you to review on assignment 1...)	30%



