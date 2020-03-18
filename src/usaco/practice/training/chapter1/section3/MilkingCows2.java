/*
ID: shourya7
LANG: JAVA
TASK: milk2
 */

import java.util.*;
import java.io.*;

class milk22 {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("milk2.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));
        
        //Adds 
        int N = Integer.parseInt(read.readLine());
        int[][] times = new int[N][2];
        for (int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(read.readLine());
            times[i][0] = Integer.parseInt(st.nextToken());
            times[i][1] = Integer.parseInt(st.nextToken());
        }
        
        int min = 1000001;
        int max = -1;
        for (int i = 0; i < N; i++) {
            if (times[i][0] < min && times [i][1] > max){
                min = times[i][0];
                max = times[i][1];
            }
        }
    }
    
    public static void sortbyColumn(int arr[][], int col) { 
        // Using built-in sort function Arrays.sort 
        Arrays.sort(arr, new Comparator<int[]>() { 
          @Override              
          // Compare values according to columns 
          public int compare(final int[] entry1,  
                             final int[] entry2) { 
  
            // To sort in descending order revert  
            // the '>' Operator 
            if (entry1[col] > entry2[col]) 
                return 1; 
            else
                return -1; 
          } 
        });  // End of function call sort(). 
    }
}
