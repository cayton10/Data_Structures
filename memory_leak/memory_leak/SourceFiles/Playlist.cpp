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
};

//Display number of songs and name of playlist
void Playlist::Display() const
{
    cout << Playlist::numberOfSongs << " Songs in Playlist \"" << Playlist::listName << "\".";
};






