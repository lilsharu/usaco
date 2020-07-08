/*
ID: shourya7
LANG: JAVA
TASK: gift1
 */

import java.util.*;
import java.io.*;

class gift1 {
    static String[] people;
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("gift1.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
        
        int num = Integer.parseInt(read.readLine());
        people = new String[num];
        for (byte i =0; i < num; i++) {
            String name = read.readLine();
            people[i] = name;
        }
        int[] account = new int[people.length];
        
        for (byte i = 0; i < num; i++){
            String person = read.readLine();
            StringTokenizer st = new StringTokenizer(read.readLine());
            
            //Gets values determined by the ints
            int taken = Integer.parseInt(st.nextToken());
            int numberOfPeople = Integer.parseInt(st.nextToken());
            int given;
            int retained;
            
            //Makes sure that there is no error when giving to zero people
            if (numberOfPeople == 0) {
                given = 0;
                retained = taken;
            }
            else {
                given = taken / numberOfPeople;
                retained = taken % numberOfPeople;
            }
            
            int pos = position(person);
            account[pos] -= taken;
            account[pos] += retained;
            
            for (byte n = 0; n < numberOfPeople; n++){
                String personName = read.readLine();
                int personPosition = position(personName);
                
                //Adds amount to people's accounts
                account[personPosition] += given;
            }
        }
        //prints output
        for (byte o = 0; o < people.length; o++) {
            out.println(people[o] + " " + account[o]);
        }
        out.close();
    }
    
    public static int position(String s) {
        for (byte i = 0; i < people.length; i++) {
            if (s.equals(people[i])){
                return i;
            }
        }
        return -1;
    }
}
