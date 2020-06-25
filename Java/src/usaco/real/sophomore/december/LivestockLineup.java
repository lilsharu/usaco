import java.io.*;
import java.util.*;

public class LivestockLineup {
    static String[] cows = {"Bessie\n", "Buttercup\n", "Belinda\n", "Beatrice\n", "Bella\n", "Blue\n", "Betsy\n", "Sue\n"};
    public static void main(String[] args) throws IOException{
        BufferedReader read = new BufferedReader(new FileReader("lineup.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lineup.out")));

        int n = Integer.parseInt(read.readLine());
        String[] constraints = new String[n];
        String[] answer = new String[8 - n];
        String c = "";
        String d = "";
        int j = 0;
        boolean bool = true;
        for (int i = 0; i < n; i ++) {
            StringTokenizer st = new StringTokenizer(read.readLine());
            String a = st.nextToken();
            st.nextToken();
            st.nextToken();
            st.nextToken();
            st.nextToken();
            String b = st.nextToken();
            if (a.equals(c)) {
                j--;
                String[] test = {d, b};
                Arrays.sort(test);
                answer[j] = test[0] + "\n" + a + "\n" + test[1] + '\n';
                j++;
                bool = false;
            }
            else if (a.equals(d)) {
                j--;
                String[] test = {c, b};
                Arrays.sort(test);
                answer[j] = test[0] + "\n" + a + "\n" + test[1] + '\n';
                j++;
                bool = false;
            }
            else if (b.equals(c)) {
                j--;
                String[] test = {a, d};
                Arrays.sort(test);
                answer[j] = test[0] + "\n" + b + "\n" + test[1] + '\n';
                j++;
                bool = false;
            }
            else if (b.equals(d)) {
                j--;
                String[] test = {a, c};
                Arrays.sort(test);
                answer[j] = test[0] + '\n' + b + "\n" + test[1] + '\n';
                j++;
                bool = false;
            }
            c = a;
            d = b;
            String[] test = {a, b};
            Arrays.sort(test);
            constraints[i] = test[0] + "\n" + test[1] + '\n';
            if (bool){
                answer[j] = constraints[i];
                j++;
            }
            bool = true;

            //a
            try {
                cows[Arrays.asList(cows).indexOf(a+'\n')] = "z";
            }
            catch (Exception e) {
            }

            //b
            try {
                cows[Arrays.asList(cows).indexOf(b+'\n')] = "z";
            }
            catch (Exception e) {
            }
        }
        Arrays.sort(cows);
        System.out.println(Arrays.toString(cows));
        int x = 0;
        for (int i = j; i < answer.length; i++) {
            System.out.println(cows[x]);
            if (cows[x].equals("z")){
                answer[j] = "";
            }
            else{
                answer[j] = cows[x];
            }
            j++;
            x++;
        }
        Arrays.sort(answer);
        for (int i = 0; i < answer.length; i++) {
            out.print(answer[i]);
        }
        out.close();
    }
}
