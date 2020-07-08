package usaco.real.sophomore.march;

public class Cereal {
    static Cow[] cows;
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("cereal.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cereal.out")));

        StringTokenizer st = new StringTokenizer(read.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        cows = new Cow[N];

        Comparator<Cow> fav = (o1, o2) -> o1.favorite - o2.favorite;
        Comparator<Cow> sFav = (o1, o2) -> o1.secondFavorite - o2.secondFavorite;

        for (int i = N - 1; i >= 0; i--) {
            st = new StringTokenizer(read.readLine());
            cows[i] = new Cow(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1);
        }

        for (int i = 0; i < N; i++) {
            int favIndex = 0;
            int sFavIndex = 0;
            int currentN = 0;
            Cow[] newCowFav = Arrays.copyOf(cows, N - i);
            Arrays.sort(newCowFav, fav);
            Cow[] newCowSFav = Arrays.copyOf(newCowFav, N - i);

        }

        out.close();
    }

    public static boolean foundFav(Cow[] cows, int i) {
        int l = 0, r = cows.length - 1;
        while (l <= r) {
            int m = l + (r - 1) / 2;
            if (cows[m].favorite == i || cows[m].secondFavorite == i) return true;

            if (cows[m].favorite < i) {
                l = m + 1;
            }
            else r = m - 1;
        }
        return false;
    }

    public static boolean foundSFav(Cow[] cows, int i) {
        int l = 0, r = cows.length - 1;
        while (l <= r) {
            int m = l + (r - 1) / 2;
            if (cows[m].favorite == i || cows[m].secondFavorite == i) return true;

            if (cows[m].secondFavorite < i) {
                l = m + 1;
            }
            else r = m - 1;
        }
        return false;
    }
}

class Cow {
    public int favorite;
    public int secondFavorite;

    public Cow(int favorite, int secondFavorite) {
        this.favorite = favorite;
        this.secondFavorite = secondFavorite;
    }

    public boolean equals(Cow b) {
        return favorite == b.favorite && secondFavorite == b.secondFavorite;
    }
}
