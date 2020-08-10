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
    array = nullptr;
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

//Gets name of playlist
string Playlist::GetName() const
{
    return listName;
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
Playlist& Playlist::operator=(Playlist& otherArray)
{
    //Copy name
    listName = otherArray.listName;
    //Copy size
    size = otherArray.size;
    //Copy capacity
    capacity = otherArray.capacity;
    //Delete array if not nullptr
    if(array != nullptr)
        delete[] array;
    //Declare new pointer array
    array = new string[capacity];
    //Copy tracks from otherArray
    for(int i = 0; i < size; ++i)
        array[i] = otherArray[i];
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
    //Check for valid array pointer
    if (array == nullptr)
    {
        array = new string[capacity];
    }
    
    //Control flow for array size vs. array capacity
    if(size == capacity)
        Resize(capacity * 2);
    //Increment array index and set assign name
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




