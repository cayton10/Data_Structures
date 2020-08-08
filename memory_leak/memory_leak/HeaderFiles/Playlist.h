//Required Playlist class to finish project5

//Include guard
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Playlist
{
public:
    //Default constructor
    Playlist(string name = "Default Playlist");
    
    //Display playlist function
    //Const function since values should not be changed by function
    void Display() const;
    
private:
    //Stores number of songs and initialize to 0
    int numberOfSongs = 0;
    //Stores name of playlist
    string listName;

    
};
