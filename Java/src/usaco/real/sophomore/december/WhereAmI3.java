import java.io.*;
import java.util.*;

public class WhereAmI3 {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("whereami.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("whereami.out")));

        int n = Integer.parseInt(read.readLine());
        String string = read.readLine();
        int smallest = 100;
        for (int x = 0; x < string.length(); x++) {
            String s = string.substring(x) + string.substring(0, x);
            for (int i = 1; i <= s.length(); i++) {
                String a = s.substring(0, i);
                String b = s.substring(i);
                if (!b.contains(a) && a.length() < smallest && a.length() > 1) {
                    smallest = a.length();
                    break;
                }
            }
        }
        out.print(smallest);
        out.close();
    }
}
