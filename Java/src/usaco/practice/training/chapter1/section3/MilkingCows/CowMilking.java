package usaco.practice.training.chapter1.section3.MilkingCows;

import java.io.*;
import java.util.*;

class milk2 {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("milk2.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));

        int n = Integer.parseInt(read.readLine());
        String[] times = new String[n];

        for (int i = 0; i < n; i++) {
            times[i] = read.readLine();
        }

        Arrays.sort(times);
        System.out.println(Arrays.toString(times));


    }
}
