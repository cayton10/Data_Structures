//Implementation file for Playlist class

#include "Playlist.h"

#include <iostream>
#include <string>

using namespace std;

//Default constructor can be created with string
Playlist::Playlist(string str)
{
    //Sets playlist name
    listName = str;
    //Set initial capacity
    capacity = 2;
    //Initialize playlist array
    array = new string [capacity];
};



//Sets name of playlist
void Playlist::SetName(string str)
{
    listName = str;
};

string& Playlist::operator[](int index)
{
    if(index > size) {
        cout << "Index out of bounds" <<endl;
        // return first element.
        return array[0];
    }
    
    return array[index];
}

//Playlist desctructor
Playlist::~Playlist()
{
    delete[] array;
};

//Copy constructor
Playlist::Playlist(Playlist& otherArray)
{   //Calls assignment overload
    *this = otherArray;
};


//Assignment operator overload
const Playlist& Playlist::operator=(const Playlist& otherArray)
{
    return *this;
};

//Display number of songs and name of playlist
void Playlist::Display() const
{
    //Output playlist vitals
    cout << Playlist::size << " Songs in Playlist \"" << Playlist::listName << "\"" <<endl;
    //Output track listing
    for(int i = 0; i < size; ++i)
    {
        cout << i + 1 << ". " << array[i] << endl;
    }
    
};

//AddSong() Pass string as parameter
void Playlist::AddSong(string name)
{
    //Control flow for array size vs. array capacity
    if(size == capacity)
        Resize(capacity * 2);
    array[size++] = name;
}

//Resize array function
void Playlist::Resize(int newCapacity)
{
    capacity = newCapacity;
    
    //1 Make new bigger array
    string* temp = new string[capacity];
    
    //2 Copy elements from old array
    for(int i = 0; i < size; ++i)
    {
        temp[i] = array[i];
    }
    
    //3 Delete old array
    delete[] array;
    
    //4 Use new array
    array = temp;
}




