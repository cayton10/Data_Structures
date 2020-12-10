/**Movie class for project 7: "No Vectors JUST JAVA"
 * Started using IntelliJ IDEA because that Netbeans IDE is trash, just sayin'
 * */


package com.movieProject.movie;

import java.util.ArrayList;

public class Movie {

    //Declare our private class variables
    private String star = "";
    private String name = "";
    private double revenue;



    //Setters
    public void setStar(String str) {
        this.star = str;
    }

    public void setName(String str) {
        this.name = str;
    }

    public void setRevenue(double rev) {
        this.revenue = rev;
    }

    //Getters
    public String getStar() {
        return this.star;
    }

    public String getName() {
        return this.name;
    }

    public double getRevenue() {
        return this.revenue;
    }

    /**Required method 'Display'
     * Takes no parameter as input and prints object's member variables
     */

    public void Display() {
        //Use some string interpolation. I will say I like C#'s interpolated strings more.
        //But overall, I think I'm actually liking Java more... strange.
        System.out.println("Film: " + this.name + ", Starring: " + this.star + "; Gross Revenue: " + this.revenue);
    }

    /**Required method 'highestGrossingMovie(ArrayList<<>>)'
     * Method takes an ArrayList object and returns the element with the highest double value
     * @return ArrayList element
     */
    public Movie highestGrossingMovie(ArrayList<ArrayList<Movie>> arrayList) {
        
        //Declare variable to store highest revenue value
        double highestGross = 0;
        double tempGross;//Temp gross for comparison
        Movie bigMovie = null;//Declare object variable to store the highest earning movie and return
        Movie tempMovie;
        
        //Iterate through individual list elements and find highest value using foreach
        for (ArrayList<Movie> item : arrayList)
        {
            for(Movie movie : item)
            {
                tempMovie = movie;
                tempGross = movie.revenue;
                //Check revenue values
                if(tempGross > highestGross)
                {
                    highestGross = tempGross;
                    bigMovie = tempMovie;
                }
            }
        }
        return bigMovie;
    }

    /**Required method: 'totalRevenue(ArrayList<<>>)'
     * Method takes an ArrayList object and returns the sum of all element double values
     * @return double
     */
    public double totalRevenue(ArrayList<ArrayList<Movie>> arrayList) {

        //Declare variable to store total revenue
        double totalRevenue = 0;

        //Process movies in nested foreach
        for(ArrayList<Movie> item : arrayList)
        {
            for(Movie movie : item)
            {
                totalRevenue += movie.revenue;
            }
        }

        return totalRevenue;
    }

    /**Required method: 'findMovieWithStar(ArrayList<<>>, String)
     * Method takes an ArrayList object, String and returns ArrayList object element matching the input string
     * @return ArrayList element
     */
    public Movie findMovieWithStar(ArrayList<ArrayList<Movie>> arrayList, String name)
    {
        Movie featuredMovie = null;

        for (ArrayList<Movie> item : arrayList)
        {
            for (Movie movie : item)
            {
                String star = movie.getStar();
                if(star.equalsIgnoreCase(name)) //If names are same
                {
                    featuredMovie = movie; //Assign movie object
                    break; //Break the foreach
                }

            }

            if(featuredMovie != null) //If movie has been assigned
            {
                break; //Break foreach
            }
        }

        return featuredMovie;
    }

}
