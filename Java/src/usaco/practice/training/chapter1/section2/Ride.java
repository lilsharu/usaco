/*
ID: shourya7
LANG: JAVA
TASK: ride
 */

import java.util.*;
import java.io.*;

class ride {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("ride.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));
        
        int value1 = 1;
        int value2 = 1;
        
        String first = read.readLine();
        String second = read.readLine();
        
        for (byte i = 0; i < first.length(); i++) {
            //Use Char's int value to calculate number equivalent
            //Add 1 to make A 1 instead of 0
            int charValue = (int)(first.charAt(i)-'A'+1);
            value1 *= charValue;
        }
        for (byte i = 0; i < second.length(); i++) {
            int charValue = (int)(second.charAt(i)-'A'+1);
            value2 *= charValue;
        }
        
        //Need to find modulo 47 of the value
        value1 = value1 % 47;
        value2 = value2 % 47;
        
        if (value1 == value2) {
            out.println("GO");
        }
        else {
            out.println("STAY");
        }
        
        out.close();
    }
    
}
