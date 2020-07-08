/*
ID: shourya7
LANG: JAVA
TASK: beads
 */

import java.util.*;
import java.io.*;

class beads {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("beads.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("beads.out")));
        
        int N = Integer.parseInt(read.readLine());
        String beads = read.readLine();
        
        int count = 0;
        
        for (int i = 0; i < N; i++) {
            String newBeads = new String(beads.substring(i) + beads.substring(0, i));
            //Forward
            char a = newBeads.charAt(0);
            if (a == 'w') {
                for (int x = 0; a == 'w' && x < newBeads.length(); x++) {
                    a = newBeads.charAt(x);
                }
            }
            int countA = 0;
            int position = 0;
            for(int x = 0; x < newBeads.length() && (newBeads.charAt(x) == a || newBeads.charAt(x) == 'w'); x++) {
                countA++;
            }
            
            String reverse = "";
            for (int x = N - 1; x >= 0; x--) {
                if (x > position + countA - 1) reverse += newBeads.charAt(x);
            }
            reverse += 'x';
            
            int countB = 0; 
            try {
                char b = reverse.charAt(0);
                for (int y = 0; b == 'w' && y < reverse.length(); y++) {
                    b = reverse.charAt(y);
                }

                for (int x = 0; reverse.charAt(x) == b || reverse.charAt(x) == 'w'; x++) {
                    countB++;
                }
            }
            catch (Exception e) {
                countB = 0;
            }            

            if (countB + countA > count){
                count = countB + countA;
            } 
        }
        
        out.println(count);
        out.close();
        System.out.println(count);
    }
}
