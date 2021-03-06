//Include guard
#pragma once

#include "Item.h"

class Consumable : public Item
{
    private:
        //Item charges
        int uses;

    protected:

    public:
        //Default constructor
        Consumable(string str = "Unnamed Consumable", int num = 1)
        {
            name = str;
            number = num;
        };
        /******************Setters & Getters*****************/
        //Set consumable number of uses
        void setUses(int num);
        //Get consumable number of uses
        int getUses() const;

        //Declare required function
        bool isEmpty() const;

        //Override item::use()
        virtual void use();
    
        //Ostream operator overload prototype
        friend ostream& operator<<(ostream&, const Consumable&);
};