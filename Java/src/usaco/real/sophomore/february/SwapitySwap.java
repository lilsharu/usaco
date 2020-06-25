import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Shourya Bansal
 */
public class SwapitySwap {
    public static void main(String[] args) throws IOException {
        byte n, a1, a2, b1, b2, temp;
        int k;
        byte[] numbers;
        BufferedReader read = new BufferedReader(new FileReader("swap.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("swap.out")));

        //For Values of N and K
        StringTokenizer st = new StringTokenizer(read.readLine());
        n = Byte.parseByte(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(read.readLine());
        a1 = (byte) (Byte.parseByte(st.nextToken()) - 1);
        a2 = (byte) (Byte.parseByte(st.nextToken()) - 1);

        st = new StringTokenizer(read.readLine());
        b1 = (byte) (Byte.parseByte(st.nextToken()) - 1);
        b2 = (byte) (Byte.parseByte(st.nextToken()) - 1);

        numbers = new byte[n];
        byte z = 1;
        do {
            numbers[z - 1] = z;
            z++;
        } while (z <= n);

        int x = 0;
        byte i;
        do {
            i = a1;
            //Swap A
            do {
                temp = numbers[i];
                numbers[i] = numbers[a2 - i + a1];
                numbers[a2 - i + a1] = temp;
                i++;
            } while (i < a1 + (a2 - a1 + 1) / 2);

            //Swap B
            i = b1;
            do {
                temp = numbers[i];
                numbers[i] = numbers[b2 - i + b1];
                numbers[b2 - i + b1] = temp;
                i++;
            } while (i < b1 + (b2 - b1 + 1) / 2);
            x++;
        } while (x < k);

        for (i = 0; i < n; i++) {
            out.println(numbers[i]);
        }
        out.close();
    }
}
