#include <iostream>
#include <string>

using namespace std;



int main()
{
    //Declare pointer vars
    int* intArrayPtr;
    int* temp;
    //Intialize pointer array
    intArrayPtr = new int[5];
    //Stores 7 in the first memory location
    *intArrayPtr = 7;
    //Assignment stores base address of intArrayPtr in temp
    temp = intArrayPtr;

    //Loads values into each array index
    for(int i=1; i < 5; i++)
    {
        cout << *intArrayPtr << endl;
        intArrayPtr++; //Next memory address
        cout << "After increment intArrayPtr: " << intArrayPtr << " value: " << *intArrayPtr << endl;
        
        *intArrayPtr = *(intArrayPtr - 1) + 2 * i;
        //Contents = *(memoryAddress -1) + 2 * i
        //Ex: [1] 
        //Contents = *(memoryAddress - 1) + 2 * 1
        //Contents = (7) + 2
        //Contents = 9
        //Ex: [2]
        //Contents = *(memoryAddress - 1) + 2 * 2
        //Contents = *(9) + 4
        //Contents = 13  
    }
    //Resets base address of intArrayPtr
    intArrayPtr = temp;

    //Iterative for loop to print array index values
    for (int i=0; i < 5; i++)
    {
        cout << *intArrayPtr << " ";
        intArrayPtr++;
    }
    cout << endl;
}

