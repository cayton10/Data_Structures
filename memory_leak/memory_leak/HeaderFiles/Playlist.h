//Required Playlist class to finish project5

//Include guard
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Playlist
{
    
private:
    //Stores name of playlist
    string listName;
    //Declare pointer
    string* array;
    //Declare array size, init to 0
    int size = 0;
    //Declare array capactiy
    int capacity;
    //Resize array
    void Resize(int num);
    
public:
    //Default constructor
    Playlist(string name = "Default Playlist");
    //Sets name of playlist array
    void SetName(string str);
    
    //Array index (subscript) operator overload
    string& operator[](int index);
    
    //Playlist destructor
    ~Playlist();
    
    //Copy constructor
    Playlist(Playlist& otherArray);
    
    //Assignment overload
    const Playlist& operator=(const Playlist&);
    
    //Display playlist function
    //Const function since values should not be changed by function
    void Display() const;
    
    //Add song function prototype
    void AddSong(string str);
    
    
    


    

    
};
