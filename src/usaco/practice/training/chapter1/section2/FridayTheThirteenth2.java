/*
ID: shourya7
LANG: JAVA
TASK: friday
 */

import java.util.*;
import java.io.*;

class friday {
    //0 is Monday
    static int dayOfWeek = 0;
    static int[] thirteenths = new int[7];
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("friday.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("friday.out")));
        
        int N = Integer.parseInt(read.readLine());
        int february;
        for (int i = 0; i < N; i++) {
            int year = i + 1900;
            
            if ((year % 100 == 0 && year % 400 == 0)) february = 29; 
            
            else if (year % 4 == 0 && year % 100 != 0) february = 29;
            
            else february = 28;
            
            //january
            update(31);
            //february
            update(february);
            //march
            update(31);
            //april
            update(30);
            //may
            update(31);
            //june
            update(30);
            //july
            update(31);
            //august
            update(31);
            //september
            update(30);
            //october
            update(31);
            //november
            update(30);
            //december
            update(31);
        }
        out.println(thirteenths[6] + " " + thirteenths[0] + " " + thirteenths[1] + " " + thirteenths[2] + " " + thirteenths[3] + " " + thirteenths[4] + " " + thirteenths[5]);
        out.close();
    }
    
    public static void update(int monthDays){
        dayOfWeek += 13;
        dayOfWeek %= 7;
        thirteenths[dayOfWeek]++;
        dayOfWeek += (monthDays - 13);
        dayOfWeek %= 7;
    }
}
