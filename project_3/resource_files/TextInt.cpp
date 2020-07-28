#pragma once//Include guard

#include <string>
#include "../header_files/TextInt.h"

using namespace std;
//TextInt implementation file contains function definitions

//Initialize static string members
string TextInt::thousand = "Thousand";
string TextInt::hundred = "Hundred";
string TextInt::tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string TextInt::lessThanTwenty[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                     "Seventeen", "Eighteen", "Nineteen"};
string TextInt::lessThanTen[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                                "Eight", "Nine"};

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

