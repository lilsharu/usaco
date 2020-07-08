/*
The Process:
1. Make four ints, one for John and one for Bessie
2. See if Bessie overlaps with John and test for every case (there are  5/6 cases)
 */

import java.util.*;
import java.io.*;

public class FencePainting {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("paint.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("paint.out")));
        
        //tokenizes the input and stores it in ints a and b
        StringTokenizer st = new StringTokenizer(read.readLine());
        
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        
        //reads and tokenizes the next line
        st = new StringTokenizer(read.readLine());
        
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        
        int ans = 0;
        if ((b < c && a < d && a < c && b < d) || (c < a && d < b && d < a && c < b)) {
            ans = (b - a) + (d - c);
        }
        
        else if (c <= b && a < d && a < c && b < d) {
            ans = d - a;
        }
        else if (c < b && b <= d && c <= a && a < d){
            ans = d - c;
        }
        else if (c < a && a <= d && d < b && c < b) {
            ans = b - c;
        }
        else if (a <= c && c < b && d <= b && a < d) {
            ans = b - a;
        }
        
        out.println(ans);
        out.close();
        
    }
    
}
