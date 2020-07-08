import java.io.*;

public class MadScientist {
    static String a;
    static String b;

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("breedflip.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("breedflip.out")));

        int n = Integer.parseInt(read.readLine());
        a = read.readLine();
        b = read.readLine();

        int differenceParts = 0;
        for (int i = 0; i < n; i++) {
            if (a.charAt(i) != b.charAt(i)) {
                for (int k = i; k < n; k++) {
                    i = k;
                    if (a.charAt(k) == b.charAt(k)) {
                        break;
                    }
                }
                differenceParts++;
            }
        }

        out.println(differenceParts);
        out.close();
    }
}
