# Assignment 7 – Vectors 

1.    Create a Lottery class based on the following rules: 

<strike>Generate 5 random numbers between 1 and 30 (inclusive, meaning include 1 and 30) and store them in a vector. 

It should generate different numbers each time you run the program.</strike>

The 5 numbers generated must be unique (no duplicates). Many of you will look online and find the function ‘unique()’, it is NOT the best way to make sure they are unique; read its documentation carefully if you use it, or figure out a different way. 

Have a user type in 5 numbers and store those in a separate vector. They should be able to type the numbers in in any order.

Determine if the player ‘won’ the lottery by comparing their numbers to the sorted vector of lottery numbers. Remember, the order they chose doesn’t matter. If the lottery numbers were 1-2-3-4-5, and the user picked 3-2-5-1-4, then they won. Use the sort function to make it more efficient to compare the two sets of numbers.    50%


2.    Add and demonstrate functions to the Lottery class to change how many numbers will be in the game, and what possible values they are (the default being 5 and between 1 and 30). It should keep track of how many attempts have been made, and this number should reset if the lottery numbers reset.    20%

3.    Use a while loop to let a ‘computer player’ play the lottery game automatically until it wins. Count and output how many times it tried. If done right, it should only need a few seconds to win with the default game parameters of 5 numbers between 1 and 30.    30%


