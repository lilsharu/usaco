import java.util.*;
import java.io.*;

public class WhereAmI {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("whereami.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("whereami.out")));

        int n = Integer.parseInt(read.readLine());
        String s = read.readLine();

        char init = s.charAt(0);
        String s2 = s.substring(1);
        if (s2.indexOf(init) == -1) {
            out.println("1");
        }
        else {
            String test = s.substring(0, s2.indexOf(init) + 1);
            int ind = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s2.contains(test)){
                    s2 = new String(s.substring(i));
                    System.out.println(s2);
                    ind++;
                    System.out.println(ind);
                }
            }
            out.println(test.length() + ind);
        }
        out.close();
    }
}
