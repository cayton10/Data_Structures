#ifndef Lottery_h
#define Lottery_h

#include <vector>

using namespace std;

class Lottery
{
public:
    //Default constructor
    Lottery();
    //Set vectorSize;
    void setVectorSize(int size = 5);
    //Display winning numbers
    void displayWinners() const;
    //Random number generator takes upper and lower limit of random generated numbers(inclusive)
    int randomNumber(int upper = 31, int lower = 1);
    //Fill vector with winning numbers. Int parameter determines length of number list
    void fillVector(int vectorSize);
    
    
    
private:
    int upper;
    int lower;
    int vectorSize;
    vector <int> winningNumbers;
};

#endif /* Lottery_h */
