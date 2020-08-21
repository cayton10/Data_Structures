//Name: Ben Cayton
//Course: CIT236 - Data Structures
//Date: 8.21.2020
/****************************************************************/
//Program Description: Use LinkedList.h to implement the class
//functions of a linked list.


#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#include "LinkedList.h"

using namespace std;

int main()
{
    //Create instance of LinkedList
    LinkedList<int> intList;
    intList.PushFront(8);
    intList.PushBack(20);
    intList.PushBack(25);
    intList.GetHeadValue();
    intList.Display();
    
    
    return 0;
}
