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
    string listName = "Unnamed";
    //Declare pointer
    string* array = nullptr;
    //Declare array size, init to 0
    int size = 0;
    //Declare array capactiy
    int capacity = 2;
    //Resize array
    void Resize(int num);
    
public:
    //Default constructor
    Playlist(string name = "Default Playlist");
    //Sets name of playlist array
    void SetName(string str);
    //Gets name of playlist array
    string GetName() const;
    
    //Array index (subscript) operator overload
    string& operator[](int index);
    
    //Playlist destructor
    ~Playlist();
    
    //Copy constructor
    Playlist(Playlist& otherArray);
    
    //Assignment overload
    Playlist& operator=(Playlist& otherArray);
    
    //Display playlist function
    //Const function since values should not be changed by function
    void Display() const;
    
    //Add song function prototype
    void AddSong(string str);
    
    
    


    

    
};
