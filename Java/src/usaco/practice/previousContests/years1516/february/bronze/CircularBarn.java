package usaco.practice.previousContests.years1516.february.bronze;

/*
ID: Mastermind
LANG: JAVA
TAK: cbarn
 */

/*
The method for solving this problem is quite simple. It requires testing each door and storing the smallest one in a value. 
To accomplish this, just loop it, changing the door each time which would be stored in an int array. 
*/

import java.util.*;
import java.io.*;

public class CircularBarn {
    public static void main(String[] args) throws IOException {
        //Read File Quickly
        BufferedReader read = new BufferedReader(new FileReader("cbarn.in"));
        //Writes File Quickly
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter ("cbarn.out")));   
        
        //takes input of the first line and stores it as number of roooms
        int roomNumber = Integer.parseInt(read.readLine());
        
        //stores each following value in an array
        int[] cowsNeeded = new int[roomNumber];
        for (int i = 0; i < roomNumber; i++) {
            //reads the line
            int number = Integer.parseInt(read.readLine());
            cowsNeeded[i] = number;
        }
        //Now the algorithm begins
        //Try starting from every door and keeping the lowest value as the answer
        int ans = roomNumber*roomNumber*100;
        for (int i = 0; i < roomNumber; i++){
            int test = 0;
            for (int x = 0; x < roomNumber; x++) {
                int answer = cowsNeeded[x] * (x+1);
                
            }
        }
    }
    
}
