

package com.movieProject;

import com.movieProject.movie.Movie;

import java.util.ArrayList;
import java.util.Scanner;


public class Program {

    //Main program entry point
    public static void main(String[] args) throws InterruptedException { //<- InterruptedException for Thread.sleep()

        //Declare required variables
        int numberOfMovies;
        Movie highestRevenue = new Movie();


        Scanner input = new Scanner(System.in);//Scanner system in for reading user input


        //Prompt user to enter number for the number of films they'll be entering
        System.out.println("We're going to have you enter information for some of your favorite movies.");

        Thread.sleep(1500); //Pause for 1.5 seconds between messages
        System.out.println("Enter how many movies you want to answer questions for?");


        numberOfMovies = input.nextInt();
        //Since we're not reading "\n" w/ the above function do...
        input.nextLine();

        //Declare and construct ArrayList
        ArrayList<ArrayList<Movie>> movieList = new ArrayList<>();

        //Iterate over user's choice of # of movies, have them enter information
        for(int i = 0; i < numberOfMovies; ++i)
        {
            //Instantiate a new movie object
            Movie movie = new Movie();

            //Start iterative prompt w/ movie title
            System.out.println("Movie #" + (i + 1) + " title: ");
            movie.setName(input.nextLine());

            //Prompt for star actor/actress
            System.out.println("Movie #" + (i + 1) + " star actor/actress: ");
            movie.setStar(input.nextLine());

            //Prompt for gross revenue
            System.out.println("Movie #" + (i + 1) + " gross revenue: ");
            movie.setRevenue(input.nextDouble());
            //Since we're not reading "\n" w/ the above function do...
            input.nextLine();

            //Allocate space for new row, this feels weird
            movieList.add(new ArrayList<>());
            movieList.get(i).add(movie);
        }

        //Store highest revenue movie by calling function
        highestRevenue = highestRevenue.highestGrossingMovie(movieList);
        //Print message for first of 3 methods
        System.out.println("The highest grossing movie is: " + highestRevenue.getName());






    }
}
