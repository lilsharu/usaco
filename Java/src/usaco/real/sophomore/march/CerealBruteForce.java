public class CerealBruteForce {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("cereal.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cereal.out")));

        StringTokenizer st = new StringTokenizer(read.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Cow[] cows = new Cow[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(read.readLine());
            cows[i] = new Cow(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1);
        }

        for (int i = 0; i < N; i++) {
            int count = 0;
            int[] cereals = new int[M];
            for (int k = i; count < M && k < N; k++) {
                if (cereals[cows[k].favorite] != -1) {
                    count++;
                    cereals[cows[k].favorite] = -1;
                }
                else if (cereals[cows[k].secondFavorite] != -1) {
                    count++;
                    cereals[cows[k].secondFavorite] = -1;
                }
            }
            out.println(count);
        }

        out.close();
    }
    static class Cow {
        public int favorite;
        public int secondFavorite;

        public Cow(int favorite, int secondFavorite) {
            this.favorite = favorite;
            this.secondFavorite = secondFavorite;
        }
    }

}
