import java.io.*;
import java.util.*;

public class WhereAmI2 {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("whereami.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("whereami.out")));

        int n = Integer.parseInt(read.readLine());
        String s = read.readLine();
        int smallest = 100;
        int len = 100;
        boolean bool = true;

        for (int i = 1; i <= s.length(); i++) {
            String a = s.substring(0, i);
            String b = s.substring(i);
            if (!b.contains(a) && a.length() < smallest) {
                for (int x = 0; x < s.length(); x ++) {
                    String string = s.substring(x) + s.substring(0, x);
                    String test = string.substring(0, a.length() - 1);
                    String tester = string.substring(string.indexOf(test) + test.length());
                    if (tester.contains(test)){
                        bool = false;
                        len = 100;
                        break;
                    }
                    else {
                        len = test.length();
                        bool = true;
                    }
                }
                if (bool) {
                    break;
                }
            }
        }
        out.println(len);
        out.close();
    }
}
