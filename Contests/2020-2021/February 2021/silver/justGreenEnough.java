import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class justGreenEnough {
 
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int[][] pasture = new int[n][n];
        for (int y = 0; y < n; y++) {
            StringTokenizer tokenizer = new StringTokenizer(in.readLine());
            for (int x = 0; x < n; x++) {
                pasture[y][x] = Integer.parseInt(tokenizer.nextToken());
            }
        }
        int[][] sumsBelow = new int[n][n + 1];
        int[][] sumsAtMost = new int[n][n + 1];
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                sumsBelow[y][x + 1] = sumsBelow[y][x] + (pasture[y][x] < 100 ? 1 : 0);
                sumsAtMost[y][x + 1] = sumsAtMost[y][x] + (pasture[y][x] <= 100 ? 1 : 0);
            }
        }
        long answer = 0;
        for (int x1 = 0; x1 < n; x1++) {
            for (int x2 = x1 + 1; x2 <= n; x2++) {
                int y1 = -1;
                int y2 = -1;
                for (int y0 = 0; y0 < n; y0++) {
                    while (y1 < n && (y1 < y0 || sumsAtMost[y1][x2] - sumsAtMost[y1][x1] == 0)) {
                        y1++;
                    }
                    while (y2 < n && (y2 < y0 || sumsBelow[y2][x2] - sumsBelow[y2][x1] == 0)) {
                        y2++;
                    }
                    answer += y2 - y1;
                }
            }
        }
        System.out.println(answer);
    }
}