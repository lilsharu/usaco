/*
 * Made by Shourya Bansal
 */
import java.util.*;
import java.io.*;

public class CowGymnastics {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("gymnastics.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gymnastics.out")));

        StringTokenizer st = new StringTokenizer(read.readLine());
        //number of sessions
        int k = Integer.parseInt(st.nextToken());
        //number of cows
        int n = Integer.parseInt(st.nextToken());
        String[][] place = new String[k][n];
        int[][] place1 = new int[n][k];

        int amount = 0;

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(read.readLine());
            for (int x = 0; x < n; x++) {
                place[i][x] = (st.nextToken());
            }
        }
        for (int x = 0; x < n; x++) {
            for (int i = 0; i < k; i++) {
                place1[x][i] = Arrays.asList(place[i]).indexOf("" + (x + 1)) + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (isSame(place1[i])){
                if (place1[i][0] == 1) {
                    amount += n - 1;
                }
            }
            else {
                for (int x = 1; x < n; x++) {
                    if (compare(place1[i], place1[(i + x)%n])) {
                        amount += 1;
                    }
                }
            }
        }
        out.println(amount);
        out.close();
        for (int i = 0; i < n; i ++) {
            System.out.println(Arrays.toString(place1[i]));
        }
    }
    public static boolean isSame(int[] place) {
            Integer first = place[0];
            for (int i=1; i<place.length; i++)
                if (place[i] != first)
                    return false;
            return true;
    }
    public static boolean compare(int[] place, int[] place2) {
        for (int i = 1; i < place.length; i ++)
            if (place[i] > place2[i])
                return false;
        return true;
    }
}