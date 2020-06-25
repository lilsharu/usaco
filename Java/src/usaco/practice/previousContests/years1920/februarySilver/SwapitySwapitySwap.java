import java.io.*;
import java.util.*;

/**
 * Farmer John's N cows (1≤N≤105) are standing in a line. The ith cow from the left has label i for each 1≤i≤N.
 * Farmer John has come up with a new morning exercise routine for the cows. He has given the cows M pairs of integers
 * (L1,R1)…(LM,RM), where 1≤M≤100. He then tells the cows to repeat the following M-step process exactly K (1≤K≤109) times:
 * <p>
 * For each i from 1 to M:
 * * The sequence of cows currently in positions Li…Ri from the left reverse their order.
 * * After the cows have repeated this process exactly K times, please output the label of the ith cow from the left for each 1≤i≤N.
 */
public class SwapitySwapitySwap {
    static int[] compare;
    static int rounds = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("swap.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("swap.out")));
        StringTokenizer st = new StringTokenizer(read.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] cows = new int[N];
        int[] compare = new int[N];

        //Initializes the Arrays
        for (int i = 0; i < N; i++) {
            cows[i] = i + 1;
            compare[i] = i + 1;
        }

        //Gets the Value of the Integer Pairs
        Point[] pairs = new Point[M];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(read.readLine());
            pairs[i] = new Point(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1);
        }

        boolean foundIt = false;
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < M; j++) {
                reverseArray(cows, pairs[j].x, pairs[j].y);
            }
            if (Arrays.equals(cows, compare)) {
                K %= rounds;
                cows = compare;
                compare = null;
                i = 0;
                foundIt = true;
            }
            else if (!foundIt) {
                rounds++;
            }
            System.out.println(rounds);
        }

        for (int a : cows) {
            out.println(a);
        }

        out.close();
    }

    public static void reverseArray(int[] array, int begin, int end) {
        for (int i = begin; i < begin + (end - begin) / 2.0 + 0.5; i++) {
            int temp = array[i];
            array[i] = array[end + begin - i];
            array[end + begin - i] = temp;
        }
    }

    static class Point implements Comparable<Point> {
        public int x;
        public int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Point(String x, String y) {
            this.x = Integer.parseInt(x);
            this.y = Integer.parseInt(y);
        }

        @Override
        public String toString() {
            return "(" + x + ", " + y + ")";
        }

        @Override
        public int compareTo(Point o) {
            if (this.x - o.x != 0) return this.x - o.x;
            else return this.y - o.y;
        }
    }
}
