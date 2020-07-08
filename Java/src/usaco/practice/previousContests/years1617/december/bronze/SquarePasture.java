package usaco.practice.previousContests.years1617.december.bronze;

/*
 ID: shourya7
 LANG: java
 TASK: SquarePasture
 */

import java.io.*;
import java.util.*;


public class SquarePasture {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("square.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("square.out")));

        int smallestX = 10;
        int smallestY = 10;
        int largestX = 0;
        int largestY = 0;
        
        for (int i = 0; i < 2; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            
            if (x1 < smallestX) {
                smallestX = x1;
            }
            if (y1 < smallestY) {
                smallestY = y1;
            }
            if (x2 > largestX) {
                largestX = x2;
            }
            if (y2 > largestY) {
                largestY = y2;
            }
        }
        
        int width = largestX - smallestX;
        int length = largestY - smallestY;
        
        if (width > length) {
            int area = width*width;
            out.println(area);
        }
        else {
            int area = length*length;
            out.println(area);
        }
        out.close();
    }
}
