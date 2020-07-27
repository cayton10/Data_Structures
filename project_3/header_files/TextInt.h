#pragma once//Include guard

//Text to int class header file
class TextInt
{
    private:
        int number;
    //Pass an integer into the function to return the text version
    public:

        //Default constructor
        inline TextInt(int defaultNumber = 666)//Mark of the BEAST
        {
            number = defaultNumber;
        };

        //Sets value of TextInt 'number' member variable.
        void setNum(int num);

        //Returns object 'number' member variable value
        inline int getNum() const//set as constant function
        {
            return number;
        };

};




