#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    /*stack<int> intStack;
    cout << intStack.top() << endl;
    intStack.push(1);
    cout << intStack.top() << endl;
    intStack.push(2);
    cout << intStack.top() << endl;
    intStack.push(3);
    cout << intStack.top() << endl;*/
    //Results in bad access exception

    queue<int> que;
    que.push(1);
    cout << que.front() << endl;
    que.push(2);
    cout << que.front() << endl;
    que.push(3);
    cout << que.front() << endl;
    que.pop();
    cout << que.front() << endl;

    

    return 0;
}