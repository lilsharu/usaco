import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Shourya Bansal
 */
public class Triangles {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new FileReader("triangles.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("triangles.out")));

        int n = Integer.parseInt(read.readLine());
        Point[] points = new Point[n];

        for (short i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(read.readLine());
            points[i] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        int highest = -1;
        for (int i = 0; i < n - 2; i++) {
            for (int k = i + 1; k < n - 1; k++) {
                for (int a = k + 1; a < n; a++) {
                    if ((points[i].x == points[k].x || points[i].x == points[a].x || points[k].x == points[a].x)
                            && (points[i].y == points[k].y || points[i].y == points[a].y || points[k].y == points[a].y)) {
                        int h = getNum(points[i], points[k], points[a]);
                        if (h > highest) highest = h;
                    }
                }
            }
        }

        out.println(highest);
        out.close();
    }

    public static int getNum(Point a, Point b, Point c) {
        return Math.abs((a.x * b.y + b.x * c.y + c.x * a.y)
                - (a.y * b.x + b.y * c.x + c.y * a.x));
    }
}

class Point implements Comparable<Point> {
    public int x;
    public int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    @Override
    public int compareTo(Point o) {
        return this.x - o.x;
    }
}