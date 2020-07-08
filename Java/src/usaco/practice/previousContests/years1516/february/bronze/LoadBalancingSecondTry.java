import java.util.*;
import java.io.*;

public class LoadBalancingSecondTry {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("balancing.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("balancing.out")));
        
        //Takes the number of cows and makes two arrays storing the data
        StringTokenizer st = new StringTokenizer(read.readLine());
        int numberOfCows = Integer.parseInt(st.nextToken());
        
        //makes the afformentioned arrays
        int[] xCoord = new int[numberOfCows];
        int[] yCoord = new int[numberOfCows];
        
        //Adds cow values to the array
        for (int i = 0; i < numberOfCows; i++) {
            st = new StringTokenizer(read.readLine());
            xCoord[i] = Integer.parseInt(st.nextToken());
            yCoord[i] = Integer.parseInt(st.nextToken());
        }
        
        //Now begins finding the answer
        //Declares an Answer in its worse case, where all cows are in one quadrant
        int ans = numberOfCows;
        //Since line always has to be next to a coordinate, finds highest and lowest answer values 
        for (int xIndex = 0; xIndex < numberOfCows; xIndex++) {
            for (int yIndex = 0; yIndex < numberOfCows; yIndex++) {
                //finds the line if it was right next to this point
                int xLine = xCoord[xIndex] + 1;
                int yLine = yCoord[yIndex] + 1; 
                int bottomLeft = 0; 
                int bottomRight = 0;
                int topRight = 0; 
                int topLeft = 0;

                for (int r = 0; r < numberOfCows; r++) {
                    //if it is in the bottom left corner
                    if (xCoord[r] < xLine && yCoord[r] < yLine) {
                        bottomLeft++;
                    }
                    //if in bottom right
                    else if (xCoord[r] > xLine && yCoord[r] < yLine){
                        bottomRight++;
                    }
                    //if in Top Right
                    else if (xCoord[r] > xLine && yCoord[r] > yLine) {
                        topRight++;
                    }
                    //if in the Top left
                    else if (xCoord[r] < xLine && yCoord[r] > yLine) {
                        topLeft++;
                    }
                }
                int worstCase = 0;
                if (bottomLeft > worstCase) {
                    worstCase = bottomLeft;
                }
                if (bottomRight > worstCase) {
                    worstCase = bottomRight;
                }
                if (topLeft > worstCase) {
                    worstCase = topLeft;
                }
                if (topRight > worstCase) {
                    worstCase = topRight;
                }
                if (worstCase < ans) {
                    ans = worstCase;
                }
            }
        }
        out.println(ans);
        out.close();   
    }
    
}
