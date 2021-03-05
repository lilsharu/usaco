import java.io.*;
import java.util.*;

public class theBovineShuffle {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("shuffle.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("shuffle.out")));

        int n = Integer.parseInt(in.readLine());
        int[] v = new int[n];
        int[] visited = new int[n];

        StringTokenizer st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            v[i] = Integer.parseInt(st.nextToken()) - 1;
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (i == v[i]) {
                    total++;
                    visited[i] = 1;
                    continue;
                }
                int previous = i;
                int cur = v[i];
                int size = 1;
                visited[i] = size;
                while (visited[cur] == 0) {
                    visited[cur] = ++size;
                    previous = cur;
                    cur = v[cur];
                }
                if (visited[cur] != -1) {
                    total += visited[previous] - visited[cur] + 1;
                    cur = previous;
                    do {
                        visited[cur] = -1;
                        cur = v[cur];
                    } while (cur != previous);
                }
            }
        }
        out.println(total);
        System.out.println(total);
        out.close();
        in.close();
    }
}
