
/**
 * Created by Shourya Bansal on 12/12/2019 at 9:42 PM
 */

import java.util.*;
import java.io.*;

public class NumTrans2 {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("1int_testdata.txt"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("solutions.txt")));

        for (int i = 0; i < 5; i++) {
            StringTokenizer st = new StringTokenizer(read.readLine());
            String N = st.nextToken();
            int P2 = Integer.parseInt(st.nextToken()) - 1;
            int P = Math.abs(P2 - N.length()) - 1;
            int pos = Integer.parseInt("" + N.charAt(P));
            String output = "";
            for (int x = 0; x < P; x++) {
              int a = Integer.parseInt("" + N.charAt(x));
              a += pos;
              a %= 10;
              output += a;
            }
            output += pos;
            for (int x = P + 1; x < N.length(); x++) {
              int a = Integer.parseInt("" + N.charAt(x));
              a = Math.abs(a - pos);
              a %= 10;
              output += a;
          }
          out.println(output);
        }
        out.close();
        read.close();
    }
}
