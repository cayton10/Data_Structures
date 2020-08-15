#ifndef Lottery_h
#define Lottery_h

#include <vector>

using namespace std;

class Lottery
{
public:
    //Default constructor
    Lottery();
    //Lottery overload takes 3 int parameters (upperLimit, lowerLimit, and numberOfPlays)
    Lottery(int num1, int num2, int num3);
    //Set vectorSize;
    void setVectorSize(int size = 5);
    //Display winning numbers
    void displayWinners() const;
    //Random number generator takes upper and lower limit of random generated numbers(inclusive)
    int randomNumber(int num1, int num2);
    //Fill vector with winning numbers. Int parameter determines length of number list
    void fillVector(int vectorSize);
    
    
    
private:
    //Upper limit, lower limit, and total number of lottery numbers
    int upper;
    int lower;
    int vectorSize;
    //Store winning numbers
    vector <int> winningNumbers;
};

#endif /* Lottery_h */
