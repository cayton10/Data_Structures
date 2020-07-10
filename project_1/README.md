# Project 1

## From Syllabus:
Please complete the following in a single project:
<strike>1. 	Write a function called Random() that takes up to 2 int parameters. If no numbers are passed in when the function is called, it returns a random number between 0 and 99. If 1 number is passed in, it returns a random number between 0 and that number. If 2 numbers are passed in, it returns a random number between the two numbers. (Hint: There are 2 different ways you could make a function that can be called with 0, 1, or 2 parameters; 1 way technically means writing 3 different functions, but I’d accept it.) (Note: Remember you can use this as a convenient tool in future projects!)</strike>	20%
		
2. 	Write a function called RandomFill() that takes an array of ints, its size, and fills the array with random numbers. To generate the random numbers use the function you wrote in problem 1. Test the function by calling it and displaying the resulting array.	20%
 		
3.	Write a function called IsFactor() that takes 2 int parameters. The function returns true if the 1st of the 2 values can be evenly divided (aka have no remainder) by the 2nd of the 2 values.

Let the user type in 2 numbers to test IsFactor(). The program should not break if they enter invalid values like non-numeric characters. (Hint: use cin.fail() like we reviewed in class) and should let them try again until they type in valid values.	25%
		
4.	Passing function parameters by reference is an important technique that everyone forgets before this class or never covered well enough to begin with. Review the concept (pages 380-399) and then write a function called FlipString(). It should have 1 string parameter. It should replace each capital letter with its lowercase letter, and each lowercase letter with its capital letter. Use the functions toupper() and tolower() to help you. It must work without returning the string, printing the string with a cout in the function, or using a global variable. Using the function should look like:

cout << str << endl; //Outputs John Doe
FlipString(str);
cout << str << endl; //Outputs jOHN dOE	25%
		
5.	Add comments to your code to at least include your name at the top, specify the purpose of each function and describe each section of code (for example, comments to distinguish between testing of the problems above). (Note: On future assignments this will just be a standard Penalty if you Don’t do it; on this one you get points For doing it.)	10%
