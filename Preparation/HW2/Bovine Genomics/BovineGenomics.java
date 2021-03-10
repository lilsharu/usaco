import java.io.*;
import java.util.*;

public class BovineGenomics {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("cownomics.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cownomics.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        String[] spot = new String[n];
        String[] plan = new String[n];

        for (int i = 0; i < n; i++) spot[i] = in.readLine();
        for (int i = 0; i < n; i++) plan[i] = in.readLine();

        int mingap = m;

        Set<String> spst = new TreeSet<>();
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < Math.min(mingap, m - i); j++) {
                spst.clear();
                for (String s : spot) {
                    spst.add(s.substring(i, i + j));
                }
                boolean found = true;
                for (String s : plan) {
                    if (spst.contains(s.substring(i, i + j))) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    mingap = Math.min(mingap, j);
                    break;
                }
            }
        }

        out.println(mingap);
        in.close();
        out.close();
    }

}
