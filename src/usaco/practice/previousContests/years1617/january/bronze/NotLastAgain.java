/*
ID: shourya7
LANG: JAVA
TASK: notLast
 */

import java.util.*;
import java.io.*;

public class NotLastAgain {
    static String[] cows;
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("notlast.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("notlast.out")));
        
        //Array for cows
        cows = new String[]{
            "Bessie", 
            "Elsie", 
            "Daisy",
            "Gertie",
            "Annabelle",
            "Maggie",
            "Henrietta"
        };
        //New array for cow values
        int[] milk = new int[cows.length];
        
        //Number of Datat Poitns
        int number = Integer.parseInt(read.readLine());

        for (byte i = 0; i < number; i++){
            StringTokenizer st = new StringTokenizer(read.readLine());
            
            String cowName = st.nextToken();
            //The amount of milk produced
            int increaseBy = Integer.parseInt(st.nextToken());
            
            //finds index of cow needed to increase
            milk[cowIndex(cowName)] += increaseBy;
        }
        
        //finds minimum value
        int minimum = 10000000;
        for (byte i = 0; i < cows.length; i++){
            if (milk[i] < minimum){
                minimum = milk[i];
            }            
        }
        
        //finds second smallest value
        int secondSmallest = 10000;
        final int NOT_FOUND = -1;
        final int TIE = -2;
        int indexOfSecondSmallest = NOT_FOUND;
        for (byte i = 0; i < cows.length; i++) {
            if (milk[i] > minimum && milk[i] < secondSmallest) {
                secondSmallest = milk[i];
            }
        }
        final int Tie = -2;
        for (byte i =0; i < cows.length; i++) {
            if (milk[i] == secondSmallest){
                if (indexOfSecondSmallest == NOT_FOUND){
                    indexOfSecondSmallest = i;
                }
                else {
                    indexOfSecondSmallest = TIE;
                }
            }
        }
        
        if (indexOfSecondSmallest >= 0) {
            out.println(cows[indexOfSecondSmallest]);
        }
        else {
            out.println("Tie");
        }
        out.close();
    }
    public static int cowIndex (String s) {
        for (byte i = 0; i < cows.length; i++) {
            if (s.equals(cows[i])){
                return i;
            }
        }
        return -1;
    }
    
}
