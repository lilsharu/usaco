package usaco.practice.training.chapter1.section3.MilkingCows;/*
 USER: shourya7
 LANG: JAVA
 TASK: milk2
 */
import java.util.*;
import java.io.*;

class milk25 {
    public static int N; //Number of terms
    public static int[][] sortedData;
    public static void main(String[] args) throws IOException{
        BufferedReader read = new BufferedReader(new FileReader("milk2.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));

        int A = Integer.parseInt(read.readLine());
        N = A;
        sortedData = new int[2][N];
        int[][] data = new int[2][N];

        //runs to store data in a 2D Array
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(read.readLine());
            data[0][i] = Integer.parseInt(st.nextToken());
            data[1][i] = Integer.parseInt(st.nextToken());
        }
        java.util.Arrays.sort(data, new java.util.Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });
        sortArray(data, 0, 0);
        for (int i = 0; i < N; i++) {
            System.out.println(sortedData[0][i] + " " + sortedData[1][i]);
        }

    }
    public static int[][] longestWhile(int[][] array) {
        return null;
    }

    public static void sortArray(int[][] array, int i, int row) {
        try {
            if (array[0][i] >= array[0][i + 1] && array[1][i] <= array[1][i + 1]) {
                sortedData[0][row] = array[0][i + 1];
                sortedData[1][row] = array[1][i + 1];
                sortArray(array, i, row + 1);
            } else if (array[0][i] <= array[0][i + 1] && array[1][i] >= array[1][i + 1]) {
                sortedData[0][row] = array[0][i];
                sortedData[1][row] = array[1][i];
                sortArray(array, i, row + 1);
            } else if (array[0][i] < array[0][i + 1] && array[1][i] >= array[0][i + 1]) {
                sortedData[0][row] = array[0][i];
                sortedData[1][row] = array[1][i + 1];
                sortArray(array, i, row + 1);
            } else {
                sortedData[0][row] = array[0][i];
                sortedData[1][row] = array[1][i];
                sortedData[0][row + 1] = array[0][i + 1];
                sortedData[1][row + 1] = array[1][row + 1];
                sortArray(array, i + 1, row + 2);
            }
        }
        catch (Exception e) {

        }
    }
}
