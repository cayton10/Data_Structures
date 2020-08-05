#pragma once//Include guard


//Text to int class header file
class TextInt
{
    public:
        /************************OPERATOR OVERLOADS****************************/
        /********************ARITHMETIC OPERATOR OVERLOADS*********************/
        /***************************PROTOTYPES*********************************/
        //Addition overload
        TextInt operator+(const TextInt &addedValue) const;
        //Subtraction overload
        TextInt operator-(const TextInt &subtractedValue) const;
        //Multiplication overload
        TextInt operator*(const TextInt &multipliedBy) const;
        //Division overload
        TextInt operator/(const TextInt &dividedBy) const;
        //Modulus overload
        TextInt operator%(const TextInt &modVal) const;

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
        
        /*********************RELATIONAL OPERATOR OVERLOADS***********************/
        //Must be non-member functions
        //Greater than overload
        bool operator>(const TextInt& comparison)const
        {
            return number > comparison.number;
        };
        
        //Less than overload
        bool operator<(const TextInt& comparison)const
        {
            return number < comparison.number;
        };
        
        //Greater than or equal overload
        bool operator>=(const TextInt& comparison)const
        {
            return number >= comparison.number;
        };

        //Less than or equal overload
        bool operator<=(const TextInt& comparison)const
        {
            return number <= comparison.number;
        };

        //Equality overlad
        bool operator==(const TextInt& comparison)const
        {
            return number == comparison.number;
        };

        bool operator!=(const TextInt& comparison)const
        {
            return number != comparison.number;
        };

        //Stream insertion operator overload
        friend ostream& operator<<(ostream& output, TextInt& object);
        
};




