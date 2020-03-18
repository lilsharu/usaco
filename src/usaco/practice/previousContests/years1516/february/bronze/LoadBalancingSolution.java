//(Analysis by Nick Wu)
//There are a lot of possible fence combinations to consider - if we simply consider every possible even x-coordinate and every possible event y-coordinate, there would be 5000002 different combinations which is far too many.
//
//Let us take an extreme example where there are two cows, one at (1,1) and the other at (999999,999999). Note that every even x-coordinate between 2 and 999998 yields exactly the same division of cows into quadrants, no matter which y-coordinate we pick. By the same logic, every even y-coordinate between 2 and 999998 yields exactly the same division of cows into quadrants.
//
//Therefore, we can make the following observation - if we set the vertical fence at x=a but no cow is placed with an x-coordinate of a−1, we can move the vertical fence to x=a−2 and still preserve the same division of cows into quadrants. Similarly, if we set the horizontal fence at y=b but no cow is placed with a y-coordinate at y=b−1, we can move the horizontal fence to y=b−2.
//
//This means that we only need to place vertical fences where x=a and there is a cow with x-coordinate a−1, and we only need to place vertical fences where y=b and there is a cow with y-coordinate b−1.
//
//This gives us at most ten thousand pairs to try, which is small enough.
//
//Here is my Java code:

import java.io.*;
import java.util.*;
public class LoadBalancingSolution {
	public static void main(String[] args) throws IOException {
		// initialize file I/O
		BufferedReader br = new BufferedReader(new FileReader("balancing.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("balancing.out")));
		
		// read in N, we can safely ignore B so we don't actually read the value
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		
		// create arrays to store locations of cows
		// cow i is at point (xLoc[i], yLoc[i])
		int[] xLoc = new int[n];
		int[] yLoc = new int[n];
		for(int i = 0; i < n; i++) {
			// read in location of cow i
			st = new StringTokenizer(br.readLine());
			xLoc[i] = Integer.parseInt(st.nextToken());
			yLoc[i] = Integer.parseInt(st.nextToken());
		}
		// in the absolute worst case, N cows will be in one quadrant
		int ans = n;
		for(int xIndex = 0; xIndex < n; xIndex++) {
			for(int yIndex = 0; yIndex < n; yIndex++) {
				// identify the fence location
				// vertical fence at x=xDiv
				// horizontal fence at y=yDiv
				int xDiv = xLoc[xIndex]+1;
				int yDiv = yLoc[yIndex]+1;
				int upperLeft = 0;
				int upperRight = 0;
				int lowerLeft = 0;
				int lowerRight = 0;
				// identify which quadrant each cows lands in
				for(int i = 0; i < n; i++) {
					if(xLoc[i] < xDiv && yLoc[i] < yDiv) {
						lowerLeft++;
					}
					if(xLoc[i] < xDiv && yLoc[i] > yDiv) {
						upperLeft++;
					}
					if(xLoc[i] > xDiv && yLoc[i] < yDiv) {
						lowerRight++;
					}
					if(xLoc[i] > xDiv && yLoc[i] > yDiv) {
						upperRight++;
					}
				}
				// figure out which region has the most cows
				int worstRegion = 0;
                                
				if(upperLeft > worstRegion) {
					worstRegion = upperLeft;
				}
				if(upperRight > worstRegion) {
					worstRegion = upperRight;
				}
				if(lowerLeft > worstRegion) {
					worstRegion = lowerLeft;
				}
				if(lowerRight > worstRegion) {
					worstRegion = lowerRight;
				}
				// determine if we have found a better pair of fences
				if(worstRegion < ans) {
					ans = worstRegion;
                                        System.out.println(ans);
				}
			}
		}
		// print the answer
		pw.println(ans);
		// close output stream
		pw.close();
	}
}