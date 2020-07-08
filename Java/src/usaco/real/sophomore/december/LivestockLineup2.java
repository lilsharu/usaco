package usaco.real.sophomore.december;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class LivestockLineup2 {
    static String[] cowsN = {"Bessie\n", "Buttercup\n", "Belinda\n", "Beatrice\n", "Bella\n", "Blue\n", "Betsy\n", "Sue\n"};
    static String[] cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("lineup.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lineup.out")));

        int n = Integer.parseInt(read.readLine());
        String[] constraints1 = new String[n];
        String[] constraints2 = new String[n];
        String[] constraints = new String[n];
        String[] answers = new String[n];
        int j = 0;

        for (int i = 0; i < n; i ++) {
            StringTokenizer st = new StringTokenizer(read.readLine());
            String a = st.nextToken();
            st.nextToken();
            st.nextToken();
            st.nextToken();
            st.nextToken();
            String b = st.nextToken();
            constraints1[i] = a ;
            constraints2[i] = b;
            constraints[i] = a + " " + b;
        }
        for (int i = 0; i < n; i++) {
            int index = Arrays.asList(constraints1).indexOf(constraints2[i]);
            if ((index != -1)) {
                String[] test = {constraints1[i], constraints2[index]};
                Arrays.sort(test);
                answers[j] = test[0] + "\n" + constraints2[i] + "\n" + test[1];
            }
        }
    }
    public static void main1(String[] args) throws IOException{
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
                cowsN[Arrays.asList(cowsN).indexOf(a+'\n')] = "z";
            }
            catch (Exception e) {
            }

            //b
            try {
                cowsN[Arrays.asList(cowsN).indexOf(b+'\n')] = "z";
            }
            catch (Exception e) {
            }
        }
        Arrays.sort(cowsN);
        System.out.println(Arrays.toString(cowsN));
        int x = 0;
        for (int i = j; i < answer.length; i++) {
            System.out.println(cowsN[x]);
            if (cowsN[x].equals("z")){
                answer[j] = "";
            }
            else{
                answer[j] = cowsN[x];
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
