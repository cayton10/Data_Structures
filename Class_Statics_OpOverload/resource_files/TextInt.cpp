#pragma once//Include guard

#include <string>
#include <iostream>
#include "../header_files/TextInt.h"

using namespace std;
//TextInt implementation file contains function definitions

//Initialize static string members
const string TextInt::thousand = "Thousand";
const string TextInt::hundred = "Hundred";
const string TextInt::tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const string TextInt::lessThanTwenty[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                     "Seventeen", "Eighteen", "Nineteen"};
const string TextInt::lessThanTen[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                                "Eight", "Nine"};

//Arithmetic operator overload definitions
//Addition overload
TextInt TextInt::operator+(const TextInt &addedValue) const
{
    TextInt addition(number + addedValue.number);
    return addition;
};

//Subtraction overload
TextInt TextInt::operator-(const TextInt &subtractedValue) const
{
    TextInt subtraction(number - subtractedValue.number);
    return subtraction;
};

//Multiplication overload
TextInt TextInt::operator*(const TextInt &multipliedBy) const
{
    TextInt multiply(number * multipliedBy.number);
    return multiply;
};

//Division overload
TextInt TextInt::operator/(const TextInt &dividedBy) const
{
    TextInt divide(number / dividedBy.number);
    return divide;
};

//Modulus overload
TextInt TextInt::operator%(const TextInt &modVal) const
{
    TextInt modulus(number % modVal.number);
    return modulus;
};

//Stream insertion operator overload
ostream& operator<<(ostream& output, TextInt& object)
{
    output << object.getNum() << ": " << object.getText();
    return output;
};

/***********************DEFAULT CONSTRUCTOR********************/
TextInt::TextInt(int defaultNumber)
{
    number = defaultNumber;
            //Set control flow for clamping values after operator overloads
            //Creating new object w/ operator overloads results in calling default
            //Constructor. That's why conditions are here
    if(number > 9999)
    {
        number = 9999;
    } else if (number < 0)
    {
        number = 0;
    }
    //Call setNum() function to set number and string member variables
    setNum(number);
};

//Could have made this an inline function, but... practice, ya know?
void TextInt::setNum(int num)
{   
    number = num;//Stores user supplied number into object member variable 'number'
    //Since we're setting the number, let's go ahead and translate it to text
    TextInt::translateNum(num);   
};

//Translate translate int value to text
void TextInt::translateNum(int num)
{
    int storeQ; //Stores result of division
    int tempNum; //Stores temporary number as it's processed
    string tempText;//Declare temp variable to store final

    tempNum = num;

    //Number size control flow
    //If entered number has thousands digit... process this way
    if (tempNum > 999)
    {
        /**************PROCESS THOUSANDS**************/
        storeQ = tempNum / 1000;//Store result of division
        tempText = TextInt::lessThanTen[storeQ] + " " + TextInt::thousand + " ";//Store thousands result
        tempNum -= (storeQ * 1000);//Remove thousands and move to next decimal

        //Number size control flow
        if(tempNum > 99)
        {
            /**************PROCESS HUNDREDS***************/
            storeQ = tempNum / 100;//Store result of division
            tempText += TextInt::lessThanTen[storeQ] + " " + TextInt::hundred + " ";//Concat with hundreds value
            tempNum -= (storeQ * 100);//Remove hundreds and move to next decimal
        }

        //Number size control flow
        if(tempNum > 10)
        {
            /**************PROCESS TENS*******************/
            storeQ = tempNum / 10;//Store result of division
            tempText += TextInt::tens[storeQ - 2] + " ";//Index of 0 is value 'Twenty'
                                                        //Reduce storeQ by two for appropriate index value
            tempNum -= (storeQ * 10);//Remove tens digit and move to next decimal
        }

        //Number size control flow
        if(tempNum > 0)
        {
            /*************PROCESS SINGLE DIGIT***********/
            tempText += TextInt::lessThanTen[tempNum]; 
        }

            //Stub to test values
            number = num;
            text = tempText;

    } else if (tempNum < 999 && tempNum > 100)//If number has hundreds digit... process this way

    {
        /**************PROCESS HUNDREDS***************/
        storeQ = tempNum / 100;//Store result of division
        tempText += TextInt::lessThanTen[storeQ] + " " + TextInt::hundred + " ";//Concat with hundreds value
        tempNum -= (storeQ * 100);//Remove hundreds and move to next decimal

        //Number size control flow
        if(tempNum > 10)
        {
            /**************PROCESS TENS*******************/
            storeQ = tempNum / 10;//Store result of division
            tempText += TextInt::tens[storeQ - 2] + " ";//Index of 0 is value 'Twenty'
                                                        //Reduce storeQ by two for appropriate index value
            tempNum -= (storeQ * 10);//Remove tens digit and move to next decimal
        }

        //Number size control flow
        if(tempNum > 0)
        {
            /*************PROCESS SINGLE DIGIT***********/
            tempText += TextInt::lessThanTen[tempNum]; 
        }

            //Stub to test values
            number = num;
            text = tempText;

    } else if (tempNum < 100 && tempNum > 10)

    {
        /**************PROCESS TENS*******************/
        storeQ = tempNum / 10;//Store result of division
        tempText += TextInt::tens[storeQ - 2] + " ";//Index of 0 is value 'Twenty'
                                                    //Reduce storeQ by two for appropriate index value
        tempNum -= (storeQ * 10);//Remove tens digit and move to next decimal

        //Number size control flow
        if(tempNum > 0)
        {
            /*************PROCESS SINGLE DIGIT***********/
            tempText += TextInt::lessThanTen[tempNum]; 
        }

        //Stub to test values
        number = num;
        text = tempText;

    } else if (tempNum < 10 && tempNum > 0)

    {
        /****************PROCESS SINGLE DIGIT**************/
        tempText += TextInt::lessThanTen[tempNum];

        //Stub to test values
        number = num;
        text = tempText;

    } else //With the control flow in place, everything but '0' has been factored out
           //This will process the number zero for text output
    {
        tempText += TextInt::lessThanTen[tempNum];

        //Stub to test values
        number = num;
        text = tempText;
    }
};

