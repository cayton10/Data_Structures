# Assignment 5 – The Rule of 3

1.    Create a project including the provided main.cpp and MemLeakDetector.h files. Write a class called Playlist to get the code in main.cpp working - the expected output is provided in the comments.

a.    If you know what vectors are, you are NOT allowed to use them on this assignment – that’d be too easy. :)

b.    You are NOT allowed to change main.cpp to get it working, except to comment things out temporarily or change song names if you don’t like my musical choices... All your work should be in Playlist.h/.cpp

c.    Your Playlist class should contain, among other things, a dynamic array of strings with a default size of 2, and ints counting how many strings have been added and how many the array will hold. When a song has been added but won’t fit, you must make a new, larger dynamic array, copy the contents of the original into it, then delete the old one. Do this in a private function called Resize();

d.    You should have no memory leaks when you are done. That means you will have to obey the Rule of 3 for the Playlist class.    
