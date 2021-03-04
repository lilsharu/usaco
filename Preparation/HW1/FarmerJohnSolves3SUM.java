import java.util.*;
import java.io.*;

// Solves 14/15 (Gets 10 Wrong)
public class FarmerJohnSolves3SUM {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("threesum.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("threesum.out")));

		StringTokenizer st = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());

		int[] v = new int[n + 1];
		st = new StringTokenizer(in.readLine());

		for (int i = 0; i < n; i++) {
			v[i] = Integer.parseInt(st.nextToken());
		}

		int[][] tot = new int[n + 5][n + 5];

		for (int i = n; i >= 0; i--) {
			HashMap<Integer, Integer> val = new HashMap<>();
			for (int k = i + 1; k <= n; k++) {
				int needed = -(v[i] + v[k]);
				tot[i][k] += val.getOrDefault(needed, 0) + tot[i][k - 1] + tot[i + 1][k] - tot[i + 1][k - 1];
				Integer added = val.putIfAbsent(v[k], 1);
				if (added != null) {
					val.put(v[k], added + 1);
				}
			}
		}

		while (q-- > 0) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--; b--;
			out.println(tot[a][b]);
		}

		in.close();
		out.close();
	}
}