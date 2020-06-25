package usaco.practice.previousContests.years1617.december.bronze;

/*
ID: shourya7
LANG: JAVA
TASK: COWSIGNAL
 */

import java.util.*;
import java.io.*;

public class CowSignal {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("cowsignal.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowsignal.out")));
        StringTokenizer st = new StringTokenizer(read.readLine());
        
        int rows = Integer.parseInt(st.nextToken());
        int columns = Integer.parseInt(st.nextToken());
        int scaleFactor = Integer.parseInt(st.nextToken());
        
        String outLine = "";
        
        for (int m = 0; m < rows; m++){
            String inLine = read.readLine();
            for (int n = 0; n < columns; n++) {
                char letter = inLine.charAt(n);
                for (int x = 0; x < scaleFactor; x++) {
                    outLine += letter;
                }
            }
            for (int i = 0; i < scaleFactor; i++) {
                out.println(outLine);
            }
            outLine = "";
        }
        out.close();
    }
    
}
