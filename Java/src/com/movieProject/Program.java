

package com.movieProject;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/** Don't know if you're going to be doing any more Java
 *  development, but I highly recommend this IntelliJ IDE(A)
 */

public class Program {

    //Main program entry point
    public static void main(String[] args) throws InterruptedException { //<- InterruptedException for Thread.sleep()

        //Declare required variables
        int numberOfMovies;


        Scanner input = new Scanner(System.in);//Scanner system in for reading user input


        //Prompt user to enter number for the number of films they'll be entering
        System.out.println("We're going to have you enter information for some of your favorite movies.");

        Thread.sleep(1500); //Pause for 1.5 seconds between messages
        System.out.println("Enter how many movies you want to answer questions for?");


        numberOfMovies = input.nextInt();
        //Since we're not reading "\n" w/ the above function do...
        input.nextLine();

        //Declare and construct ArrayList
        ArrayList<ArrayList<String>> movieList = new ArrayList<ArrayList<String>>();

        //Iterate over user's choice of # of movies, have them enter information
        for(int i = 0; i < numberOfMovies; ++i)
        {
            //Declare variables for user input
            String userTitle = "";
            String userStar = "";
            double userRevenue = 0;

            //Start iterative prompt w/ movie title
            System.out.println("Movie #" + (i + 1) + " title: ");
            userTitle = input.nextLine();

            //Prompt for star actor/actress
            System.out.println("Movie #" + (i + 1) + " star actor/actress: ");
            userStar = input.nextLine();

            //Prompt for gross revenue
            System.out.println("Movie #" + (i + 1) + " gross revenue: ");
            userRevenue = input.nextDouble();
            //Since we're not reading "\n" w/ the above function do...
            input.nextLine();

            //Convert from double to string
            String stringRevenue = Double.toString(userRevenue);

            //Allocate space for new row, this feels weird
            movieList.add(new ArrayList<>());
            //Load user's supplied information into ArrayList
            movieList.get(i).add(0, userTitle);
            movieList.get(i).add(1, userStar);
            movieList.get(i).add(2, stringRevenue);
        }

        System.out.println(Arrays.deepToString(movieList.toArray()));


    }
}
