package usaco.aUsefulClasses;

/**
 * A Regular Class for a Point to replace 2D Arrays
 */
class Point implements Comparable<Point> {
    public int x;
    public int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Point(String x, String y) {
        this.x = Integer.parseInt(x);
        this.y = Integer.parseInt(y);
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    @Override
    public int compareTo(Point o) {
        if (this.x - o.x != 0) return this.x - o.x;
        else return this.y - o.y;
    }
}
