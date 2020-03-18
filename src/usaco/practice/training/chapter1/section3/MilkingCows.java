/*
ID: shourya7
LANG: JAVA
TASK: milk2
 */

import java.util.*;
import java.io.*;

class milk21 {
    public static void main(String[] args) throws IOException{
        BufferedReader read = new BufferedReader(new FileReader("milk2.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));
        
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
        System.out.println(min + " " + max);
        sortbyColumn(times, 1 - 1);
        System.out.println(times.length);
        
        int contLength = 0;
        int difference = 0;
        int contLengthTest = 0;
        for (int i = 0; i < N; i++) {
            if (times[i][0] > min && times[i][1] < max) continue;
            
            try {
                if (times[i][1] >= times[i+1][0]) {
                    if (times[i-1][1] >= times[i][0]) { 
                        contLengthTest += (times[i+1][1] - times[i][0] - difference);
                        difference = times[i+1][1] - times[i+1][0];
                    }
                    else {
                        difference = times[i+1][1]-times[i+1][0];
                        contLengthTest = difference;
                    }
                }
            }
            
            catch (Exception e) {
                try {
                    if (times[i-1][1] >= times[i][0]) { 
                        contLengthTest += times[i+1][1] - times[i][0] - difference;
                    }
                }
                
                catch (Exception a) {
                    contLengthTest = times[i][1] - times[i][0];
                }
            }
             if (contLengthTest > contLength) contLength = contLengthTest;
        }
        
        if (contLength == 0) {
            for (int i = 0; i < N; i++) {
                int dif = times[i][1] - times[i][0];
                if (dif > contLength) contLength = times[i][1] - times[i][0];
            }
        }
        
        int maxGap = 0;
        int maxGapTest = 0;

        for (int i = 0; i < N; i++) {
            try {
                maxGapTest = times[i+1][0] - times[i][1];
            }
            
            catch (Exception e) {
                maxGapTest = 0;
            }
            
            if (times[i][0] > min && times[i][1] < max) maxGapTest = 0;
            
            if (maxGapTest > maxGap) maxGap = maxGapTest;
        }
        
        out.println(contLength + " " + maxGap);
        System.out.println(contLength + " " + maxGap);
        out.close();
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
    
    public static int getMaxContinuous(int[][] arr, int min, int max) {
        int cont = 0; 
        int N = arr.length;
        for (int i = 0; i < N; i++) {
            if (arr[i][0] > min && arr[i][1] < max) continue;
            int contTest = 0;
            try {
                for (int x = 0; arr[x - 1][1] >= arr[x][0]; x++){
                    contTest += arr[x][1] - arr[x - 1][0];
                }
            }
            
            catch (Exception e) { 
                contTest = arr[i][1]-arr[i][0];
            }
            
            if (contTest > cont) cont = contTest;
        }
        return cont;
    }

}
