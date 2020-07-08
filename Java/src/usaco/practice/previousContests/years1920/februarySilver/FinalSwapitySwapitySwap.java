
import java.util.*;
import java.io.*;

public class FinalSwapitySwapitySwap {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("swap.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("swap.out")));
        StringTokenizer st = new StringTokenizer(read.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] cows = new int[N];
        for (int i = 1; i <= N; i++) {
            cows[i-1] = i;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(read.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            reverseArray(cows, a, b);
        }

        int[] positions = Arrays.copyOf(cows, N);
        ArrayList<ArrayList<Point>> map = new ArrayList<>();
        int position = 0;
        for (int i = 0; i < N; i++) {
            if (positions[i] != -1) {
                map.add(new ArrayList<Point>());
                int k = i;
                do {
                    map.get(position).add(new Point(positions[k] - 1, k));
                    k = positions[k] - 1;
                }while (k != i);
            }
        }

        System.out.println(map);
    }

    public static void reverseArray(int[] array, int begin, int end) {
        while (begin < end) {
            int temp = array[begin];
            array[begin] = array[end];
            array[end] = temp;
            begin++;
            end--;
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
