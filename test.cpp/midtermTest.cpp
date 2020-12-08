#pragma once
#include <iostream>
#include <string>
#include "calculator.cpp"

using namespace std;


struct Structure
{
    public:

        int value = 200; 
        int * p;

        
};


int main()
{

    struct Structure s;

    Student student;
    student.gpa = 3.5;

    cout << student.gpa << endl;

    cout << "*s.p:  " << *s.p << endl;

    *s.p = 10;

    cout << *s.p << endl;
    int k = 2;
    int arr[k];

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    cout << arr[k] << endl;
    cout << "&arr[k]: " << &arr[k] << endl;
    cout << "*(arr + k): " << *(arr + k) << endl;
    cout << "arr + k: " << arr + k << endl;
    cout << "*arr + k: " << *arr + k << endl;
}