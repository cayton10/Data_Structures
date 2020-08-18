#ifndef Lottery_h
#define Lottery_h

#include <vector>

using namespace std;

class Lottery
{
public:
    //Default constructor int1 = upper range, int2 = lower range, int3 = number of picks
    Lottery(int num1 = 30, int num2 = 1, int num3 = 5);
    //Display winning numbers
    void displayWinners() const;
    //Returns a vector with random numbers sorted.
    vector<int> fillVector();
    //Random number generator takes upper and lower limit of random generated numbers(inclusive)
    int randomNumber(const int& num1, const int& num2, vector<int>& vec);
    //Fill vector with user picks. Int parameter determines size of lottery plays
    void fillUserPicks(const int& vectorSize);
    //Check winner. Pass two vectors as parameters to compare their values
    void checkWinner();
    //Check winner for computer player
    bool checkComputerWin(const vector<int>& compVector);
    
    
    
private:
    //Upper limit, lower limit, and total number of lottery numbers
    int upper;
    int lower;
    int vectorSize;
    int attempts;
    //Store winning numbers
    vector <int> winningNumbers;
    //Store user numbers
    vector <int> userPicks;
    //Store computer 'player' numbers
    vector <int> computerPicks;
    
};

#endif /* Lottery_h */
