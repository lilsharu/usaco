/*
ID: shourya7
LANG: JAVA
TASK: beads
 */

import java.util.*;
import java.io.*;

class beadsFail {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("beads.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("beads.out")));
        
        int N = Integer.parseInt(read.readLine());
        int N2 = 2 * N;
        String reads = read.readLine();
        System.out.println(reads);
        //loops the beads together
        String beads = reads + reads;
        
        //loops twice, one in either direction
        //First one
        int count1 = 0;
        int position = 0;
        for (int i = 0; i < N; i++) {
            int count = 0;
            
            char a = beads.charAt(i);
            
            int x = i;
            while (beads.charAt(x) == a || beads.charAt(x) == 'w') {
                count++;
                x++;
            }
            
            if (count > count1){
                count1 = count;
                position = i;
            }
        }
        //reverses beads
        String beads2 = "";
        int count2 = 0;
        for (int i = N2 - 1; i >= 0; i--) {
            if (i < position || i > position + count1) {
                if (i < position + N| i > position + N + count1){
                    beads2 += beads.charAt(i);
                }
            }
        }
        System.out.println(beads);
        System.out.println(beads2);
        
        for (int i = 0; i < N - count1; i++) {
            int count = 0;
            
            char a = beads2.charAt(i);
            
            int x = i;
            while (beads2.charAt(x) == a || beads2.charAt(x) == 'w') {
                count++;
                x++;
            }
            
            if (count > count2) count2 = count;
        }
        
        out.println(count1+count2);
        out.close();
    }
}
