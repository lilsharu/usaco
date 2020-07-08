/* 
Name: Shourya Bansal
ID: Mastermind

Problem Solution:
1. Store each in a 2D array
2. Make a loop: choose an x value and loop it with different y values and store the minimum difference from total cows in a variable
3. Also store the X value which causes the minimum difference + 1
4. Now, do another lo
 */

import java.util.*;
import java.io.*;
public class LoadBalancing {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("balancing.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("balancing.out")));
        StringTokenizer st = new StringTokenizer(read.readLine());
        
        //Gets number of cows and size of plane from input line
            int numberOfCows = Integer.parseInt(st.nextToken());
            int coordinateSize = Integer.parseInt(st.nextToken());
            
        //Coordinate Array Initialization:
            int[][] farm = new int[coordinateSize][coordinateSize];
            
        //Adds value to the array
        for (int i = 0; i < numberOfCows; i++){
            st = new StringTokenizer(read.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            farm[x][y] = 1;
        }
        
        for (int x = 0; x < coordinateSize; x++) {
            for (int y = 0; y < coordinateSize; y++){
                System.out.print(farm[x][y]);
            }
            System.out.print("\n");
        }
        
        //Counts number of cows in a specific line and copmares to a minimum
        double compareTo = numberOfCows/2.0;
        double minX = coordinateSize;
        int minXLine = 0;
        int countX = 0;
        
        for (int X = 0; X < coordinateSize; X++) {
            for (int Y = 0; Y < coordinateSize; Y++){
                if (farm[X][Y] == 1) {
                    countX++;
                }
            }
            
            if (Math.abs(countX-compareTo) < minX) {
                minX = Math.abs(countX-compareTo);
                minXLine = X+1;
            }
        }
        
        //Same but for horizontal line
        double minY = coordinateSize;
        int minYLine = 0;
        int countY = 0;
        
        for (int Y = 0; Y < coordinateSize; Y++) {
            for (int X = 0; X < coordinateSize; X++) {
                if (farm [X][Y] == 1) {
                    countY++;
                }
            }
            
            if (Math.abs(countY - compareTo) < minY) {
                minY = Math.abs(countY - compareTo);
                minYLine = Y + 1;
            }
        }
        
        //Tests maximum for each quadrant
        int max = 0;
        int count = 0;
        
        //First tests when less than x line and y line
            for (int x = 0; x < minXLine; x++) {
                for (int y = 0; y < minYLine; y++) {
                    if (farm[x][y] == 1) {
                        count++;
                    }
                }
            }

            if (count > max) {
                max = count;
            }

        //Tests when less than x line but more than y line
            count = 0;
            for (int x = 0; x < minXLine; x++) {
                for (int y = minYLine; y < coordinateSize; y++) {
                    if (farm [x][y] == 1){
                        count++;
                    }
                }
            }

            if (count > max) {
                max = count;
            }
        
        //Tests when more than x line and more than y line
            count = 0;
            for (int x = minXLine; x < coordinateSize; x++) {
                for (int y = minYLine; y < coordinateSize; y++) {
                    if (farm [x][y] == 1){
                        count++;
                    }
                }
            }

            if (count > max) {
                max = count;
            }
        
        //Tests when more than x line but less than y line
            count = 0;
            for (int x = minXLine; x < coordinateSize; x++) {
                for (int y = 0; y < minYLine; y++) {
                    if (farm [x][y] == 1){
                        count++;
                    }
                }
            }

            if (count > max) {
                max = count;
            }
        
        out.println(max);
        out.close();
    }
}
