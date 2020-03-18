package usaco.practice.previousContests.years1617.december.bronze;

/*
ID: shourya7
LANG: JAVA
TASK: Block Game
 */

import java.util.*;
import java.io.*;
        
public class BlockGame {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("blocks.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("blocks.out")));
        
        //different letters:
        int[] letters = new int[26];
        
        int N = Integer.parseInt(br.readLine());
        
        for (int count = 0; count < N; count++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            String word1 = st.nextToken();
            String word2 = st.nextToken();
            
            int[] frequency1 = getFrequency(word1);
            int[] frequency2 = getFrequency(word2);
            
            for (int j = 0; j < 26; j++) {
                if (frequency1[j] > frequency2[j]){
                    letters[j] += frequency1[j];
                }
                else {
                    letters[j] += frequency2[j];
                }
            }
        }
            for (int h = 0; h < 26; h++){
                out.println(letters[h]);
            }
            out.close();
    }
    public static int[] getFrequency(String s) {
        int[] blocksNeeded = new int[26];
        System.out.println(s);
        for (int i = 0; i < s.length(); i++){
            int position = (int)(s.charAt(i) - 'a');
            blocksNeeded[position]++;
        }
        return blocksNeeded;
    }
}
