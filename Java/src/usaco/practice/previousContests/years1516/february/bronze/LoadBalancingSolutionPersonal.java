/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.io.*;

public class LoadBalancingSolutionPersonal {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("balancing.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("balancing.out")));
        StringTokenizer st = new StringTokenizer(read.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        
        int[] xLoc = new int[n];
        int[] yLoc = new int[n];
        
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(read.readLine());
            xLoc[i] = Integer.parseInt(st.nextToken());
            yLoc[i] = Integer.parseInt(st.nextToken());
        }
        
        int ans = n;
        for (int xIndex = 0; xIndex < n; xIndex++) {
            for (int yIndex = 0; yIndex < n; yIndex++) {
                //Find fence location
                //Vertical fence x=xFence
                //Horizontal fence y=yFence
                int xDiv = xLoc[xIndex] +1;
                int yDiv = yLoc[yIndex] +1;
                int upperLeft = 0;                
                int upperRight = 0;
                int lowerLeft = 0;
                int lowerRight = 0;
                for (int i = 0; i < n; i++) {
                    if (xLoc[i] < xDiv && yLoc[i] < yDiv){
                        lowerLeft++;
                    }
                    if (xLoc[i] < xDiv && yLoc[i] > yDiv) {
                        upperLeft++;
                    }
                    if (xLoc[i] > xDiv && yLoc[i] < yDiv) {
                        lowerRight++;
                    }
                    if (xLoc[i] > xDiv && yLoc[i] > yDiv) {
                        upperRight++;
                    }
                    
                }
                
                
                int worstRegion = 0;
                if (upperLeft > worstRegion) {
                    worstRegion = upperLeft;
                }
                if (upperRight > worstRegion) {
                    worstRegion = upperRight;
                }
                if (lowerLeft > worstRegion) {
                    worstRegion = lowerLeft;
                }
                if (lowerRight > worstRegion) {
                    worstRegion = lowerRight;
                }
                if (worstRegion < ans) {
                    ans = worstRegion;
                }
            }
        }
        //prints out value
        out.println(ans);
        out.close();
    }
    
}
