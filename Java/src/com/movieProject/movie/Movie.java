/**Movie class for project 7: "No Vectors JUST JAVA"
 * Started using IntelliJ IDEA because that Netbeans IDE is trash, just sayin'
 * */


package com.movieProject.movie;

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
    public String getStart() {
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


}
