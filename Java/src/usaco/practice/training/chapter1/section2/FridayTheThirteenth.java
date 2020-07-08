/*
ID: shourya7
LANG: JAVA
TASK: friday
 */

import java.util.*;
import java.io.*;

class fridayFail {
    static int dayOfWeek = 0;
    static int[] days;
    public static void main(String[] args) throws IOException {
        //Reads input file    static int dayOfWeek = 0;

        BufferedReader read = new BufferedReader(new FileReader("friday.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("friday.out")));
        
        //Stores int value
        int years = Integer.parseInt(read.readLine());
        days = new int[7];
        
        //loops for each year
        int febLength;
        for (int i = 0; i < years; i++){
            if (i % 4 == 0) {
                febLength = 29;
            }
            else {
                febLength = 28;
            }
                //january
                monthTest(31, 0);
                //february
                monthTest(febLength, 1);
                //march
                monthTest(31, 2);
                //april
                monthTest(30, 3);
                //may
                monthTest(31, 4);
                //june
                monthTest(30, 5);
                //july
                monthTest(31, 6);
                //august
                monthTest(31, 7);
                //september
                monthTest(30, 8);
                //october
                monthTest(31, 9);
                //novemeber
                monthTest(30, 10);
                //december
                monthTest(31, 11);
        }
    for (int x = 0; x <7; x++) {
        int temp = x + 5;
        temp %= 7;
        out.print(days[temp] + " ");
    }
    out.close();
    }
    public static void monthTest(int monthLength, int monthIndex){
        for (int x = 1; x <= monthLength; x++){
            if (x == 13 && dayOfWeek == 5) {
                days[monthIndex]++;
                dayOfWeek+=(monthLength - x + 1);
                dayOfWeek %= 7;
                break;
            }
            else {
                dayOfWeek++;
                dayOfWeek %= 7;
            }
    }
    }
}
