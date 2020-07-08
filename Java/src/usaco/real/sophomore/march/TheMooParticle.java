package usaco.real.sophomore.march;

public class TheMooParticle {
    static Particle[] p;
    static int remaining;
    static int primIndex;
    static int intIndex;

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("moop.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("moop.out")));

        int N = Integer.parseInt(read.readLine());
        remaining = N;
        p = new Particle[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(read.readLine());
            p[i] = new Particle(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(p);

        for (primIndex = 0; primIndex < N; primIndex++) {
            for (intIndex = primIndex + 1; intIndex < N; intIndex++) {
                try {
                    interact();
                }
                catch (IndexOutOfBoundsException e) {
                    break;
                }
            }
        }

        System.out.println(remaining);
        out.println(remaining);
        out.close();
    }

    public static void interact() {
        while (p[primIndex] == null) {
            primIndex++;
        }
        while (p[intIndex] == null){
            intIndex++;
        }
        if (p[primIndex].beats(p[intIndex])) {
            System.out.println(p[primIndex] + " " + p[intIndex]);
            p[intIndex] = null;
            remaining--;
        }
    }

//    public static void interact() {
//        if (p[primIndex] == null || p[intIndex] == null) intIndex++;
//        if (p[primIndex].compareTo(p[intIndex]) == 0) {
//            primIndex = intIndex;
//            intIndex++;
//            return;
//        }
//        p[intIndex] = null;
//        remaining--;
//        intIndex++;
//    }
}

class Particle implements Comparable<Particle>, Comparator<Particle> {

    public int x;
    public int y;

    public Particle(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Particle o) {
        if (o.x > this.x) return 1;
        else return o.y - this.y;
    }

    @Override
    public int compare(Particle o1, Particle o2) {
        if (o1.x < o2.x) return 1;
        else return -o1.y + o2.y;
    }

    public boolean beats(Particle p2) {
        return (this.x >= p2.x && this.y >= p2.y);
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}
