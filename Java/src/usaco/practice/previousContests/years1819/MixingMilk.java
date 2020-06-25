/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.io.*;
public class MixingMilk {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("mixmilk.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("mixmilk.out")));
        
        int[] max = new int[3];
        int[] current = new int[3];
   
        int cp = 1;
        int pcp;
        
        for (int i = 0; i < 3; i++) {
            StringTokenizer st = new StringTokenizer(read.readLine());
            max[i] = Integer.parseInt(st.nextToken());
            current[i] = Integer.parseInt(st.nextToken());
        }
        
        for (int i = 0; i < 100; i++) {
            if (cp == 0) pcp = 2;
            else pcp = cp - 1;
            
            int total = current[cp] + current[pcp];
            if (total > max[cp]){
                current[cp] = max[cp];
                current[pcp] = total - max[cp];                
            }
            
            else {
                current[cp] = total;
                current[pcp] = 0;
            }
            
            cp++;
            cp %= 3;
        }
        out.println(current[0]);
        out.println(current[1]);
        out.println(current[2]);
        out.close();
    }
}
