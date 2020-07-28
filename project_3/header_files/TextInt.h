#pragma once//Include guard

using namespace std;

//Text to int class header file
class TextInt
{
    //Private member variabels
    private:
        int number;
        string text;

    //Public member variables    
    public:
        //Static string members for translation
        static const string thousand;
        static const string hundred;
        static const string tens[];
        static const string lessThanTwenty[];
        static const string lessThanTen[];


        //Sets value of TextInt 'number' member variable.
        void setNum(int num);

        //Translates int value to equivalent text value.
        void translateNum(int num);

        /*************************INLINE FUNCTIONS*******************************/
        //Default constructor
        inline TextInt(int defaultNumber = 666);//INITIALIZE TO MARK OF THE BEAST
        
        //Returns object 'number' member variable value
        inline int getNum() const//set as constant function
        {
            return number;
        };
        //Return object 'text' member variable value
        inline string getText() const//set as constant function
        {
            return text;
        }

        /************************OPERATOR OVERLOADS****************************/
        /********************ARITHMETIC OPERATOR OVERLOADS*********************/
        /**********************************************************************/
        
        //Addition overload
        TextInt operator+(const TextInt &addedValue) const
        {
            TextInt addition(number + addedValue.number);
            return addition;
        };

        //Subtraction overload
        TextInt operator-(const TextInt &subtractedValue) const
        {
            TextInt subtraction(number - subtractedValue.number);
            return subtraction;
        };

        //Multiplication overload
        TextInt operator*(const TextInt &multipliedBy) const
        {
            TextInt multiply(number * multipliedBy.number);
            return multiply;
        };

        //Division overload
        TextInt operator/(const TextInt &dividedBy) const
        {
            TextInt divide(number / dividedBy.number);
            return divide;
        };

        //Modulus overload
        TextInt operator%(const TextInt &modVal) const
        {
            TextInt modulus(number % modVal.number);
            return modulus;
        };

};




